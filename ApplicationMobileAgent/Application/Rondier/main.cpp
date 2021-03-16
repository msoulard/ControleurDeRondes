#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "pointeaux.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    Pointeaux couleursPointeau;
    QList<QObject*> listePointeaux;
    for(int i = 0 ; i < 15 ; i++){
        listePointeaux.append(new Pointeaux("Désignation " + QString::number(i), couleursPointeau.changerCouleur((i==0?3:0))));
    }
    QQmlApplicationEngine engine;
    //permet de récupérer les valeurs de la liste en C++ pour les utiliser en QML
    engine.rootContext()->setContextProperty("pointeauxModel", QVariant::fromValue(listePointeaux));
    //permet de faire le lien entre QML et classe C++
    engine.rootContext()->setContextProperty("pointeauHorodater", new Pointeaux());
    //emplacement du fichier QML correspondant
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
