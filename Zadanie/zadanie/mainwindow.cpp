#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fileprocessor.h"
#include <QTimer>
#include <QFileDialog>
#include <QMessageBox>
#include <QDir>
#include <QThread>
#include <QDebug>
#include <QStandardPaths>
#include <QSettings>
#include <QFileInfo>
#include <QtConcurrent/QtConcurrentRun>
#include <QThreadPool>
#include <QMutex>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_timer(new QTimer(this))
    , m_totalSize(0)
    , m_processedSize(0)
{
    QThreadPool::globalInstance()->setMaxThreadCount(MainWindow::MAX_CONCURRENT_PROCESSORS);

    ui->setupUi(this);
    QSettings settings("zadanie", "MyApp");
    m_inputPath = settings.value("inputPath", "").toString();
    if (!m_inputPath.isEmpty()) {
        ui->inputPathEdit->setText(m_inputPath);
    }

    loadSettings();

    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::startProcessing);
    connect(ui->stopButton, &QPushButton::clicked, this, &MainWindow::stopProcessing);
    connect(ui->selectOutputPathButton, &QPushButton::clicked, this, &MainWindow::selectOutputPath);
    connect(ui->selectInputPathButton, &QPushButton::clicked, this, &MainWindow::selectInputPath);
    connect(m_timer, &QTimer::timeout, this, &MainWindow::on_timerTimeout);

    ui->progressBar->setValue(0);
    ui->totalProgressBar->setValue(0);
    ui->statusLabel->setText("Готово");
}

MainWindow::~MainWindow()
{
    saveSettings();
    stopAllProcessors();
    delete ui;
}

void MainWindow::loadSettings()
{
    QSettings settings("zadanie", "MyApp");
    ui->inputPathEdit->setText(settings.value("inputPath", "").toString());
    ui->outputPathEdit->setText(settings.value("outputPath", "").toString());
    ui->maskEdit->setText(settings.value("mask", "*").toString());
    ui->deleteInputCheck->setChecked(settings.value("deleteInput", false).toBool());
    ui->duplicateCombo->setCurrentText(settings.value("duplicateAction", "Перезапись").toString());
    ui->timerModeRadio->setChecked(settings.value("isTimerMode", false).toBool());
    ui->singleModeRadio->setChecked(!settings.value("isTimerMode", false).toBool());
    ui->periodSpin->setValue(settings.value("period", 60).toInt());
    ui->xorValueEdit->setText(settings.value("keyHex", "").toString());
}

void MainWindow::saveSettings()
{
    QSettings settings("zadanie", "MyApp");
    settings.setValue("inputPath", ui->inputPathEdit->text());
    settings.setValue("outputPath", ui->outputPathEdit->text());
    settings.setValue("mask", ui->maskEdit->text());
    settings.setValue("deleteInput", ui->deleteInputCheck->isChecked());
    settings.setValue("duplicateAction", ui->duplicateCombo->currentText());
    settings.setValue("isTimerMode", ui->timerModeRadio->isChecked());
    settings.setValue("period", ui->periodSpin->value());
    settings.setValue("keyHex", ui->xorValueEdit->text());
}

void MainWindow::selectInputPath() {
    QString dir = QFileDialog::getExistingDirectory(this, "Выберите папку с входными файлами",
                                                    m_inputPath.isEmpty() ? QStandardPaths::writableLocation(QStandardPaths::HomeLocation) : m_inputPath);
    if (!dir.isEmpty()) {
        ui->inputPathEdit->setText(dir);
        m_inputPath = dir;
        QSettings settings("zadanie", "MyApp");
        settings.setValue("inputPath", m_inputPath);
    }
}

void MainWindow::selectOutputPath()
{
    QString dir = QFileDialog::getExistingDirectory(this, "Выберите папку для выходных файлов", m_outputPath.isEmpty() ? QStandardPaths::writableLocation(QStandardPaths::HomeLocation) : m_outputPath);
    if (!dir.isEmpty()) {
        ui->outputPathEdit->setText(dir);
        m_outputPath = dir;
        QSettings settings("zadanie", "MyApp");
        settings.setValue("outputPath", m_outputPath);
    }
}

void MainWindow::startProcessing()
{
    qDebug() << "startProcessing() called, m_inputPath:" << m_inputPath;
    if (m_inputPath.isEmpty()) {
        qDebug() << "m_inputPath is empty, showing warning";
        QMessageBox::warning(this, "Ошибка", "Выберите папку с входными файлами.");
        return;
    }
    qDebug() << "Starting processing...";

    m_mask = ui->maskEdit->text();
    m_deleteInput = ui->deleteInputCheck->isChecked();
    m_outputPath = ui->outputPathEdit->text();
    m_inputPath = ui->inputPathEdit->text();
    m_duplicateAction = ui->duplicateCombo->currentText();
    m_isTimerMode = ui->timerModeRadio->isChecked();
    m_period = ui->periodSpin->value() * 1000;

    QString keyHex = ui->xorValueEdit->text().remove(" ").remove(";");
    if (keyHex.isEmpty() || m_inputPath.isEmpty() || m_outputPath.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Пожалуйста, заполните все поля.");
        return;
    }

    m_key.clear();
    bool ok;
    for (int i = 0; i < keyHex.length(); i += 2) {
        QString byteStr = keyHex.mid(i, 2);
        m_key.append(byteStr.toInt(&ok, 16));
        if (!ok) {
            QMessageBox::warning(this, "Ошибка", "Неверный формат ключа (должен быть hex).");
            return;
        }
    }

    if (m_key.size() != 8) {
        QMessageBox::warning(this, "Ошибка", "Ключ должен быть ровно 8 байт (16 символов hex).");
        return;
    }

    m_pendingFiles.clear();
    m_totalSize = 0;
    m_processedSize = 0;
    ui->progressBar->setValue(0);
    ui->totalProgressBar->setValue(0);
    ui->statusLabel->setText("Обработка...");

    if (m_isTimerMode) {
        m_timer->start(m_period);
        ui->startButton->setEnabled(false);
        ui->stopButton->setEnabled(true);
    } else {
        scanForFiles();
        ui->startButton->setEnabled(false);
        ui->stopButton->setEnabled(true);

        QFuture<void> future = QtConcurrent::run([this]() {
            QMutex mutex;
            while (!m_pendingFiles.isEmpty()) {
                while (QThreadPool::globalInstance()->activeThreadCount() >= MainWindow::MAX_CONCURRENT_PROCESSORS) {
                    QThread::msleep(100);
                }
                QString currentFile;
                {
                    QMutexLocker locker(&mutex);
                    if (m_pendingFiles.isEmpty()) break;
                    currentFile = m_pendingFiles.takeFirst();
                }
                QMetaObject::invokeMethod(this, "processFile", Qt::QueuedConnection, Q_ARG(QString, currentFile));
            }
            QMetaObject::invokeMethod(this, [this]() {
                ui->statusLabel->setText("Готово");
                ui->startButton->setEnabled(true);
                ui->stopButton->setEnabled(false);
            });
        });
    }
}

void MainWindow::stopProcessing()
{
    stopAllProcessors();
    m_timer->stop();
    ui->startButton->setEnabled(true);
    ui->stopButton->setEnabled(false);
    ui->statusLabel->setText("Остановлено");
}

void MainWindow::on_timerTimeout()
{
    scanForFiles();
    while (!m_pendingFiles.isEmpty() && m_processors.size() < 4) {
        processFile(m_pendingFiles.takeFirst());
    }
}

void MainWindow::scanForFiles()
{
    QDir inputDir(m_inputPath);
    QStringList filters;
    if (!m_mask.isEmpty()) {
        filters << m_mask.split(",", Qt::SkipEmptyParts);
    } else {
        filters << "*";
    }
    QFileInfoList fileList = inputDir.entryInfoList(filters, QDir::Files);

    for (QFileInfoList::const_iterator it = fileList.constBegin(); it != fileList.constEnd(); ++it) {
        const QFileInfo& info = *it;
        QString filePath = info.absoluteFilePath();
        if (!m_pendingFiles.contains(filePath)) {
            m_pendingFiles.append(filePath);
            m_totalSize += info.size();
        }
    }
}

void MainWindow::processFile(const QString& filePath)
{
    FileProcessor* processor = new FileProcessor(filePath, generateOutputFileName(filePath), m_key, m_deleteInput, QFileInfo(filePath).size());
    m_processors.append(processor);
    m_processorsProgress[processor] = 0;

    connect(processor, &FileProcessor::progress, this, &MainWindow::updateProgress);
    connect(processor, &FileProcessor::finishedProcessing, this, &MainWindow::onProcessingFinished);


    processor->start();
}

QString MainWindow::generateOutputFileName(const QString& inputFile)
{
    QFileInfo inputInfo(inputFile);
    QString baseName = inputInfo.baseName();
    QString extension = inputInfo.suffix();
    QString outputFileName = baseName + "_processed." + extension;
    QString outputPath = m_outputPath + "/" + outputFileName;

    int counter = 1;
    while (QFile::exists(outputPath) && m_duplicateAction == "Добавить счетчик") {
        outputFileName = baseName + "_processed_" + QString::number(counter) + "." + extension;
        outputPath = m_outputPath + "/" + outputFileName;
        counter++;
    }

    return outputPath;
}

void MainWindow::updateProgress(FileProcessor* processor, qint64 processedBytes)
{
    if (m_processorsProgress.contains(processor)) {
        qint64 totalProcessed = m_processorsProgress[processor] + processedBytes;
        m_processorsProgress[processor] = totalProcessed;

        qint64 fileSize = processor->fileSize();
        if (fileSize > 0) {
            int progress = (totalProcessed * 100) / fileSize;
            ui->progressBar->setValue(progress);
        }

        m_processedSize += processedBytes;
        if (m_totalSize > 0) {
            int totalProgress = (m_processedSize * 100) / m_totalSize;
            ui->totalProgressBar->setValue(totalProgress);
        }
    }
}

void MainWindow::onProcessingFinished(FileProcessor* processor, [[maybe_unused]] const QString& message)
{
    m_processors.removeOne(processor);
    m_processorsProgress.remove(processor);
    delete processor;

    if (m_processors.isEmpty()) {
        ui->statusLabel->setText("Готово");
        ui->startButton->setEnabled(true);
        ui->stopButton->setEnabled(false);
    }
}

void MainWindow::stopAllProcessors()
{
    for (FileProcessor* processor : qAsConst(m_processors)) {
        processor->stop();
    }
    m_processors.clear();
    m_processorsProgress.clear();
}
