#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "src/PasswordEditor.hpp"
#include "src/Tester.hpp"
#include "src/services/FileReader.hpp"
#include "src/services/Theme.hpp"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    // FOR TESTING ONLY
    FileReader::instance()->open();
    FileReader::instance()->save();

    PasswordEditor *passwordEditor = new PasswordEditor();
    Tester *tester = new Tester(passwordEditor);

    QObject::connect(&app,
                     &QCoreApplication::aboutToQuit,
                     FileReader::instance(),
                     &FileReader::close);

    engine.rootContext()->setContextProperty("editor", passwordEditor);
    engine.rootContext()->setContextProperty("tester", tester);
    engine.rootContext()->setContextProperty("theme", Theme::instance());

    const QUrl url("qrc:/qml/main.qml");
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
