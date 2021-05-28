#include "rondier.h"

Rondier::Rondier(QObject *parent) : QObject(parent)
{
    bdd.connectionBDD();

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

    //permet de récupérer les valeurs de la liste C++ pour les utiliser en QML
    engine.rootContext()->setContextProperty("pointeauxModel", QVariant::fromValue(listeDesignationPointeaux));
    //permet de faire le lien entre QML et classe AccesBdd
    engine.rootContext()->setContextProperty("bdd", &bdd);
    //permet de faire le lien entre QML et classe Pointeau
    engine.rootContext()->setContextProperty("pointeau", new Pointeau());
    //permet de faire le lien entre QML et la classe Agent
    engine.rootContext()->setContextProperty("agent", new Agent(bdd));
    //permet de faire le lien entre QML et la classe Ronde
    engine.rootContext()->setContextProperty("ronde", new Ronde(bdd));
    //emplacement du fichier QML correspondant
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

}
