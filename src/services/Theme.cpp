#include "Theme.hpp"

Theme *Theme::m_instance = nullptr;

Theme *Theme::instance()
{
    if (m_instance == nullptr)
        m_instance = new Theme();
    return m_instance;
}

Theme::Theme(QObject *parent)
    : QObject{parent}
{
    // Declare colors here
    m_colors["text"] = hsv(0, 0, 1);
}

QString Theme::hsv(int hue, double sat, double value)
{
    hue = qBound(0, hue, 359);
    sat = qBound(0.0, (double) sat, 1.0) * 255;
    value = qBound(0.0, (double) value, 1.0) * 255;
    return QColor::fromHsv(hue, sat, value).name(QColor::NameFormat::HexArgb);
}

QString Theme::color(QString key, double opacity)
{
    QColor hue(m_colors.value(key, "#fc0fc0"));
    // Default opacity of -1 will not modify the opacity. We don't want the default value to make "transparent" "apparent"
    if (opacity >= 0)
        hue.setAlphaF(qBound<double>(0, opacity, 1));
    return hue.name(QColor::NameFormat::HexArgb);
}
