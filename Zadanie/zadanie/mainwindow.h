#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QList>
#include <QMap>
#include "fileprocessor.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    static const int MAX_CONCURRENT_PROCESSORS = 4;  // Максимум одновременных потоков

private slots:
    void loadSettings();
    void saveSettings();
    void stopAllProcessors();
    void startProcessing();
    void stopProcessing();
    void selectOutputPath();
    void selectInputPath();
    void on_timerTimeout();
    void processFile(const QString& filePath);
    void updateProgress(FileProcessor* processor, qint64 processedBytes);
    void onProcessingFinished(FileProcessor* processor, const QString& message);

private:
    void scanForFiles();

    QString generateOutputFileName(const QString& inputFile);

    Ui::MainWindow *ui;
    QTimer* m_timer;
    QList<FileProcessor*> m_processors;
    QMap<FileProcessor*, qint64> m_processorsProgress;
    QStringList m_pendingFiles;
    QString m_mask;
    bool m_deleteInput;
    QString m_outputPath;
    QString m_inputPath;
    QString m_duplicateAction;
    bool m_isTimerMode;
    int m_period;
    QByteArray m_key;
    qint64 m_totalFilesSize;
    qint64 m_totalSize;
    qint64 m_processedSize;
};

#endif
