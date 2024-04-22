#pragma once

#include <QObject>

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

    Q_INVOKABLE void add(Password passwordObject);
    Q_INVOKABLE Password edit(QString title);
    Q_INVOKABLE bool remove(QString title);
};
