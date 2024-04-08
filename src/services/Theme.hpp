#pragma once

#include <QColor>
#include <QMap>
#include <QObject>

class Theme : public QObject
{
    Q_OBJECT
public:
    // Get the Theme singleton instance
    static Theme *instance();

    // Get an ARGB hex color code from a theme key and opacity
    Q_INVOKABLE QString color(QString key, double opacity = 1);

private:
    explicit Theme(QObject *parent = nullptr);

    // Returns an ARGB hex color code given HSV values
    QString hsv(int hue, double sat, double val);

    // Saves all color keys and values
    QMap<QString, QString> m_colors;
    static Theme *m_instance;
};
