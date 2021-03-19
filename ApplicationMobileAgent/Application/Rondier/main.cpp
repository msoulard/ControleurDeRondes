/**
  @file main.cpp
  @details Programme principal
  @author Maëva Soulard
  @date 18/03/2021
  */

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "pointeaux.h"
#include "accesbdd.h"

using namespace std;

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    Pointeaux *couleursPointeau;
    QList<QObject*> listePointeaux;
    AccesBDD bdd;
    for(int i = 0 ; i < 15 ; i++){
        couleursPointeau=new Pointeaux();
        couleursPointeau->setDesignation("Désignation " + QString::number(i));
        if (i==0){   // premier pointeau en bleu
            couleursPointeau->setCouleur("#0000FF");
        }
        else{
            couleursPointeau->setCouleur("#000000");
        }
        listePointeaux.append(couleursPointeau);
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
