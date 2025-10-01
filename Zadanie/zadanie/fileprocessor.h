#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <QThread>
#include <QByteArray>

class FileProcessor : public QThread {
    Q_OBJECT

public:
    FileProcessor(const QString& inputFile, const QString& outputFile, const QByteArray& key, bool deleteInput, qint64 fileSize, QObject* parent = nullptr);
    void stop();
    qint64 fileSize() const { return m_fileSize; }

signals:
    void progress(FileProcessor* processor, qint64 processedBytes);
    void finishedProcessing(FileProcessor* processor, const QString& message);

protected:
    void run() override;

private:
    QString m_inputFile;
    QString m_outputFile;
    QByteArray m_key;
    bool m_deleteInput;
    qint64 m_fileSize;
    bool m_stop;
};

#endif
