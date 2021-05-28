#include "rondier.h"

Rondier::Rondier(QQmlApplicationEngine &_engine, QObject *parent) : QObject(parent),
    engine(_engine)
{
    bdd.connexion("/home/USERS/ELEVES/SNIR2019/msoulard/ControleurDeRondes2021/ControleurDeRondes/BDDs/Rondier/Rondier_BDDRemplie.db");


}

void Rondier::mettreAJourAgent(QString _numBadge)
{
    if(bdd.obtenirAgent(_numBadge, agent)){
        //permet de faire le lien entre QML et la classe Agent
        engine.rootContext()->setContextProperty("agent", &agent);
    }
}

QStringList Rondier::obtenirRondes()
{
    QStringList listeNomsRonde;
    if(bdd.obtenirListeRondes(listeRondes, agent.getId())){
        foreach (Ronde *r, listeRondes) {
            listeNomsRonde << r->getNom();
        }
    }
    return listeNomsRonde;
}

QString Rondier::obtenirNomRondeCourante(int _index)
{
    rondeCourante = listeRondes.at(_index);
    return rondeCourante->getNom();
}

