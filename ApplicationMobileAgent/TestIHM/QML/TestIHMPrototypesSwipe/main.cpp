#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "pointeau.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    Pointeau *couleursPointeau;
    QList<QObject*> listePointeaux;
    for(int i = 0 ; i < 15 ; i++){
        couleursPointeau=new Pointeau();
        couleursPointeau->setLieu("Désignation " + QString::number(i));

        if (i==0)   // premier pointeau
        {
            couleursPointeau->setEtat("#0000FF");
        }
        else
        {
            couleursPointeau->setEtat("#000000");
        }
        listePointeaux.append(couleursPointeau);
    }
    QQmlApplicationEngine engine;
    //permet de récupérer les valeurs de la liste en C++ pour les utiliser en QML
    engine.rootContext()->setContextProperty("pointeauxModel", QVariant::fromValue(listePointeaux));
    //permet de faire le lien entre QML et classe C++
    engine.rootContext()->setContextProperty("pointeauHorodater", new Pointeau());
    //emplacement du fichier QML correspondant
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
