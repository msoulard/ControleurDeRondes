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
    Pointeau *couleursPointeau;
    QList<QObject*> listePointeaux;
    QList<QObject*> listeRondes;

    AccesBdd bdd;
    for(int i = 0 ; i < 15 ; i++){
        couleursPointeau=new Pointeau();
        couleursPointeau->setDesignation("Désignation " + QString::number(i));
        if (i==0){   // premier pointeau en bleu
            couleursPointeau->setCouleur("#0000FF");
        }
        else{ //les suivant en noir
            couleursPointeau->setCouleur("#000000");
        }
        listePointeaux.append(couleursPointeau);
    }

    QQmlApplicationEngine engine;
    ///permet de récupérer les valeurs de la liste C++ pour les utiliser en QML
    engine.rootContext()->setContextProperty("pointeauxModel", QVariant::fromValue(listePointeaux));
    ///permet de faire le lien entre QML et classe C++
    engine.rootContext()->setContextProperty("pointeauHorodater", new Pointeau());
    ///permet de faire le lien entre QML et la classe AccesBdd
    engine.rootContext()->setContextProperty("agent", new Agent());
    ///Récupérer en QML la liste des rondes possibles
    engine.rootContext()->setContextProperty("rondesModel", QVariant::fromValue(listeRondes));
    ///emplacement du fichier QML correspondant
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
