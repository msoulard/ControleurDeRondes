#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QList>
#include <QDebug>

#include "pointeau.h"
#include "accesbdd.h"
#include "agent.h"
#include "ronde.h"

int main(int argc, char *argv[])
{
    AccesBdd bdd;
    QGuiApplication app(argc, argv);
    QList<QObject*> listeDesignationPointeaux;
    QList<Pointeau*> listePointeaux;

    listePointeaux = bdd.obtenirListePointeaux(1);
    foreach (Pointeau *p, listePointeaux) {
        if (p==listePointeaux.first()){   // premier pointeau en bleu
            p->setCouleur("#0000FF");
        }
        else{ //les suivant en noir
            p->setCouleur("#000000");
        }

        listeDesignationPointeaux.append(p);
    }
    qDebug() << listePointeaux;

    QQmlApplicationEngine engine;
    //permet de récupérer les valeurs de la liste C++ pour les utiliser en QML
    engine.rootContext()->setContextProperty("pointeauxModel", QVariant::fromValue(listeDesignationPointeaux));
    //permet de faire le lien entre QML et classe AccesBdd
    engine.rootContext()->setContextProperty("bdd", new AccesBdd());
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
