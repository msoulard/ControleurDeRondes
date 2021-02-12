#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "couleurs.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("pointCouleur", new Couleurs());
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
