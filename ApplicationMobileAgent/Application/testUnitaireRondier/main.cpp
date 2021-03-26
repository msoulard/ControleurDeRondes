#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "pointeau.h"
#include "accesbdd.h"

using namespace std;

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    Pointeau *couleursPointeau;
    QList<QObject*> listePointeaux;    
    AccesBdd bdd;
    QList<Ronde*> listeRondes;
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
    bdd.obtenirRondes(listeRondes);
    QQmlApplicationEngine engine;
    ///permet de récupérer les valeurs de la liste C++ pour les utiliser en QML
    engine.rootContext()->setContextProperty("pointeauxModel", QVariant::fromValue(listePointeaux));
    ///permet de faire le lien entre QML et classe C++
    engine.rootContext()->setContextProperty("pointeauHorodater", new Pointeau());
    ///permet de faire le lien entre QML et la classe AccesBdd
    engine.rootContext()->setContextProperty("agent", new AccesBdd());
    ///Récupérer en QML la liste des rondes possibles
    engine.rootContext()->setContextProperty("listeRondes", QVariant::fromValue(listeRondes));
    ///emplacement du fichier QML correspondant
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
