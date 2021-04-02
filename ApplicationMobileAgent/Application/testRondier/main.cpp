#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QList>

#include "pointeau.h"
#include "accesbdd.h"
#include "agent.h"
#include "ronde.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
//    Pointeau *couleursPointeau;
//    QList<QObject*> listeDesignationPointeaux;
//    QList<Pointeau*> listePointeaux;
//    Ronde ronde;

    AccesBdd bdd;
//    listePointeaux = bdd.obtenirPointeau(1);
//    for(int i = 0 ; i < listePointeaux.size() ; i++){
//        couleursPointeau=new Pointeau();
//        couleursPointeau->setDesignation(listePointeaux.at(i)->getDesignation());
//        if (i==0){   // premier pointeau en bleu
//            couleursPointeau->setCouleur("#0000FF");
//        }
//        else{ //les suivant en noir
//            couleursPointeau->setCouleur("#000000");
//        }
//        listeDesignationPointeaux.append(couleursPointeau);
//    }

    QQmlApplicationEngine engine;
//    //permet de récupérer les valeurs de la liste C++ pour les utiliser en QML
//    engine.rootContext()->setContextProperty("pointeauxModel", QVariant::fromValue(listeDesignationPointeaux));
    //permet de faire le lien entre QML et classe Pointeau
    engine.rootContext()->setContextProperty("pointeau", new Pointeau());
    //permet de faire le lien entre QML et la classe Agent
    engine.rootContext()->setContextProperty("agent", new Agent());
    //permet de faire le lien entre QML et la classe Ronde
    engine.rootContext()->setContextProperty("ronde", new Ronde());
    //emplacement du fichier QML correspondant
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
