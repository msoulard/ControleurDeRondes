#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "pointeau.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    Pointeau couleursPointeau;
    QList<Pointeau*> listePointeaux;
    for(int i = 0 ; i < 15 ; i++){
        listePointeaux.append(new Pointeau("Désignation " + QString::number(i), couleursPointeau.changerCouleur((i==0?3:0))));
    }
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("pointeauxModel", QVariant::fromValue(listePointeaux));
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
