#pragma once

#include <QDebug>
#include <QObject>
#include <QRandomGenerator>
#include <QTimer>
#include "src/PasswordEditor.hpp"

class Tester : public QObject
{
    Q_OBJECT
public:
    explicit Tester(PasswordEditor *editor, QObject *parent = nullptr);

public slots:
    Q_INVOKABLE void addRandom();

private:
    PasswordEditor *m_editor = nullptr;

    QTimer *m_addRandom = nullptr;
};
