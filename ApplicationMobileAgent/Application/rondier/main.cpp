#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "rondier.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    Rondier leRondier(engine);

    //permet de faire le lien entre QML et la classe Agent
    engine.rootContext()->setContextProperty("rondier", &leRondier);
    //emplacement du fichier QML correspondant
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    return app.exec();
}
