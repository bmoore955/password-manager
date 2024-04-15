#include "FileReader.hpp"

/*******************************
 * SINGLETON FUNCTIONALITY
 *******************************/

FileReader *FileReader::m_instance = 0;

FileReader *FileReader::instance()
{
    if (m_instance == nullptr)
        m_instance = new FileReader();
    return m_instance;
}

/*******************************
 * CLASS METHODS
 *******************************/

FileReader::FileReader(QObject *parent)
    : QObject{parent}
    , m_passwordsFile(SAVED_PATH)
{}

void FileReader::open()
{
    QDir savedFilesDir(SAVED_DIR);
    if (!savedFilesDir.exists()) {
        savedFilesDir.mkpath(SAVED_DIR); // Creates all necessary subdirectories
    }
    if (!m_passwordsFile.isOpen()) {
        m_passwordsFile.open(QIODevice::ReadWrite);
        qDebug().noquote() << "Opened file" << m_passwordsFile.fileName();
        readJson();
    }
}

void FileReader::readJson()
{
    QByteArray data = m_passwordsFile.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    m_json = doc.object();
    qDebug() << "Number of passwords:" << m_json.count();
}

void FileReader::save()
{
    m_passwordsFile.resize(0);
    QJsonDocument doc(m_json);
    QByteArray data = doc.toJson();
    m_passwordsFile.write(data);
}
