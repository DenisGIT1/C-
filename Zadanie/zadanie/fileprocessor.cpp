#include "fileprocessor.h"
#include <QFile>

FileProcessor::FileProcessor(const QString& inputFile, const QString& outputFile, const QByteArray& key, bool deleteInput, qint64 fileSize, QObject* parent)
    : QThread(parent), m_inputFile(inputFile), m_outputFile(outputFile), m_key(key), m_deleteInput(deleteInput), m_fileSize(fileSize), m_stop(false) {}

void FileProcessor::run() {
    QFile inputFile(m_inputFile);
    QFile outputFile(m_outputFile);

    if (!inputFile.open(QIODevice::ReadOnly)) {
        emit finishedProcessing(this, "Ошибка открытия входного файла: " + m_inputFile);
        return;
    }

    if (!outputFile.open(QIODevice::WriteOnly)) {
        emit finishedProcessing(this, "Ошибка создания выходного файла: " + m_outputFile);
        inputFile.close();
        return;
    }

    qint64 processed = 0;
    const qint64 blockSize = 1024 * 1024; // 1 МБ блок
    QByteArray buffer;

    while (!inputFile.atEnd() && !m_stop) {
        buffer = inputFile.read(blockSize);
        for (int i = 0; i < buffer.size(); ++i) {
            buffer[i] ^= m_key[i % m_key.size()];
        }
        outputFile.write(buffer);
        processed += buffer.size();
        emit progress(this, processed);
    }

    inputFile.close();
    outputFile.close();

    if (m_deleteInput && !m_stop) {
        QFile::remove(m_inputFile);
    }

    emit finishedProcessing(this, m_stop ? "Обработка остановлена: " + m_outputFile : "Обработка завершена: " + m_outputFile);
}

void FileProcessor::stop() {
    m_stop = true;
    wait();
}
