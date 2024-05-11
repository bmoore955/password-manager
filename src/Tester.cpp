#include "Tester.hpp"

Tester::Tester(PasswordEditor *editor, QObject *parent)
    : QObject{parent}
    , m_editor(editor)
{
    m_addRandom = new QTimer();
    connect(m_addRandom, &QTimer::timeout, this, &Tester::addRandom);
    // m_addRandom->start(1000);
}

void Tester::addRandom()
{
    unsigned short rand = QRandomGenerator::global()->bounded(5000);
    qDebug().noquote() << "adding test with ID" << rand;
    QString title = QString("titletest%1").arg(rand);
    QString username = QString("usertest%1").arg(rand);
    QString password = QString("passtest%1").arg(rand);

    m_editor->add(title, username, password);
}
