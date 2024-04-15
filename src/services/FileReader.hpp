#pragma once

#include <QByteArray>
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QIODevice>
#include <QJsonDocument>
#include <QJsonObject>
#include <QObject>

#define SAVED_DIR (QDir::homePath() + "/savedfiles")
#define SAVED_PATH (QDir(SAVED_DIR).absoluteFilePath("passwords.json"))

class FileReader : public QObject
{
    Q_OBJECT
public:
    static FileReader *instance();

    // Opens the file that contains all saved passwords.
    // This will create a directory path and file if necessary.
    void open();
    // Read the contents of the file as JSON.
    void readJson();
    // Write the edited passwords JSON back into the file.
    void save();

private:
    explicit FileReader(QObject *parent = nullptr);
    static FileReader *m_instance;

    // The file that contains the saved passwords.
    QFile m_passwordsFile;
    // The JSON object that contains all password objects.
    // This is set to the object of the JSON document taken from the file.
    QJsonObject m_json;
};
