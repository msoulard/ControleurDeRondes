#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "couleurs.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    Couleurs couleursPointeau;
    QList<QObject*> listePointeaux;
    for(int i = 0 ; i < 15 ; i++){
        listePointeaux.append(new Couleurs("Désignation " + QString::number(i), couleursPointeau.changerCouleur((i==0?3:0))));
    }
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("pointeauxModel", QVariant::fromValue(listePointeaux));
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
