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

    void open();
    void readJson();
    void save();

private:
    explicit FileReader(QObject *parent = nullptr);
    static FileReader *m_instance;

    QFile m_passwordsFile;
    QJsonObject m_json;
};
