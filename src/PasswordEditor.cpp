#include "PasswordEditor.hpp"

PasswordEditor::PasswordEditor(QObject *parent)
    : QObject{parent}
{
    m_json = FileReader::instance()->json();
}

void PasswordEditor::add(QString title, QString username, QString password)
{
    QJsonObject passwordObj{{"username", username}, {"password", password}};
    m_json.insert(title, QJsonValue(passwordObj));
    qDebug() << m_json.value(title).toObject().keys();
    FileReader::instance()->setJson(m_json);
}

QJsonObject PasswordEditor::edit(QString title)
{
    Q_UNUSED(title)
}

bool PasswordEditor::remove(QString title)
{
    Q_UNUSED(title)
}
