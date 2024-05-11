#pragma once

#include <QDebug>
#include <QJsonObject>
#include <QJsonValue>
#include <QObject>
#include "src/services/FileReader.hpp"

class PasswordEditor : public QObject
{
    Q_OBJECT
public:
    explicit PasswordEditor(QObject *parent = nullptr);

    struct Password
    {
        QString title;
        QString username;
        QString password;
    };

    Q_INVOKABLE void add(QString title, QString username, QString password);
    Q_INVOKABLE Password edit(QString title);
    Q_INVOKABLE bool remove(QString title);

private:
    QJsonObject m_json;
};
