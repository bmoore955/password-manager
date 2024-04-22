#include "PasswordEditor.hpp"

PasswordEditor::PasswordEditor(QObject *parent)
    : QObject{parent}
{}

void PasswordEditor::add(Password passwordObject)
{
    Q_UNUSED(passwordObject)
}

PasswordEditor::Password PasswordEditor::edit(QString title)
{
    Q_UNUSED(title)
}

bool PasswordEditor::remove(QString title)
{
    Q_UNUSED(title)
}
