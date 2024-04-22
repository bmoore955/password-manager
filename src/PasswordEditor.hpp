#pragma once

#include <QObject>

class PasswordEditor : public QObject
{
    Q_OBJECT
public:
    explicit PasswordEditor(QObject *parent = nullptr);
};
