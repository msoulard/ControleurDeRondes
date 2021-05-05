#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QList>
#include <QTimer>

#include "pointeau.h"
#include "accesbdd.h"
#include "agent.h"
#include "ronde.h"

int main(int argc, char *argv[])
{
    AccesBdd bdd;
    QGuiApplication app(argc, argv);
    Pointeau *pointeau;
    QList<QObject*> listeDesignationPointeaux;
    QList<Pointeau*> listePointeaux;

    listePointeaux = bdd.obtenirPointeau(1);
    for(int i = 0 ; i < listePointeaux.size() ; i++){
        pointeau=new Pointeau();
        pointeau->setDesignation(listePointeaux.at(i)->getDesignation());
        if (i==0){   // premier pointeau en bleu
            pointeau->setCouleur("#0000FF");
        }
        else{ //les suivant en noir
            pointeau->setCouleur("#000000");
        }
        listeDesignationPointeaux.append(pointeau);
    }

    QQmlApplicationEngine engine;
    //permet de récupérer les valeurs de la liste C++ pour les utiliser en QML
    engine.rootContext()->setContextProperty("pointeauxModel", QVariant::fromValue(listeDesignationPointeaux));
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
