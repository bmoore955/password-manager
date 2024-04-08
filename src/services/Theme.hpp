#pragma once

#include <QColor>
#include <QMap>
#include <QObject>

class Theme : public QObject
{
    Q_OBJECT
public:
    static Theme *instance();

    Q_INVOKABLE QString color(QString key, double opacity);

private:
    explicit Theme(QObject *parent = nullptr);

    QString hsv(int hue, double sat, double val);

    QMap<QString, QString> m_colors;
    static Theme *m_instance;
};
