#include "rondier.h"

Rondier::Rondier(QQmlApplicationEngine &_engine, QObject *parent) : QObject(parent),
    engine(_engine)
{
    bdd.connexion("C:/Users/soula/Documents/Cours/SNIR2/Projet 2021/Maëva/ControleurDeRondes/BDDs/Rondier/Rondier_BDDRemplie.db");


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
    QList<QObject*> listeEmplacementPointeaux;
    rondeCourante = listeRondes.at(_index);
    if(bdd.obtenirListePointeaux(listePointeaux, _index)){
        foreach (Pointeau *p, listePointeaux) {
            if (p==listePointeaux.first()){   // premier pointeau en bleu
                p->setCouleur("#0000FF");
            }
            else{ //les suivant en noir
                p->setCouleur("#000000");
            }
            p->setEmplacement(p->getEmplacement());
            listeEmplacementPointeaux.append(p);
        }
        //permet de récupérer les emplacements des pointeaux du C++ en QML
        engine.rootContext()->setContextProperty("listeEmplacements", QVariant::fromValue(listeEmplacementPointeaux));
    }
    return rondeCourante->getNom();
}

