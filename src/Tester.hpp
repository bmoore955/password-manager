#pragma once

#include <QObject>

class Tester : public QObject
{
    Q_OBJECT
public:
    explicit Tester(QObject *parent = nullptr);

signals:
};
