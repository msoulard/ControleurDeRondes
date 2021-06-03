#include "rondier.h"

Rondier::Rondier(QQmlApplicationEngine &_engine, QObject *parent) : QObject(parent),
    engine(_engine)
{
    //emplacement BDD téléphone(/data/data/org.qtproject.rondier/db/Rondier_BDDRemplie.db)
    //emplacement BDD ordi(/home/USERS/ELEVES/SNIR2019/msoulard/ControleurDeRondes2021/ControleurDeRondes/BDDs/Rondier/Rondier_BDDRemplie.db)
    bdd.connexion("C:/Users/soula/Documents/Cours/SNIR2/Projet 2021/Maëva/ControleurDeRondes/BDDs/RondierRondier_BDDRemplie.db");
    ordre = 0;
    idHistoriqueRonde = -1;
    idHistoriquePointeau = -1;
    //permet de faire le lien entre QML et la classe LecteurNFC
    engine.rootContext()->setContextProperty("lecteurNFC", &leLecteur);
}

Rondier::~Rondier()
{
    delete rondeCourante;
    foreach(Ronde *r, listeRondes){
        listeRondes.removeFirst();
        delete r;
    }
    foreach(Pointeau *p, listePointeaux){
        listePointeaux.removeFirst();
        delete p;
    }
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
    ordre = 0;
    return rondeCourante->getNom();
}

void Rondier::mettreAJourListePointeaux()
{
    QList<QObject*> listeEmplacementPointeaux;
    listePointeaux.clear();
    if(bdd.obtenirListePointeaux(listePointeaux, rondeCourante->getId())){
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
        engine.rootContext()->setContextProperty("pointeauxModel", QVariant::fromValue(listeEmplacementPointeaux));
    }
}

QStringList Rondier::obtenirListeDesignations()
{
    QStringList listeDesignations;
    QString designation;
    foreach(Pointeau *p, listePointeaux){
        designation = p->getDesignation();
        listeDesignations.append(designation);
    }
    return listeDesignations;
}

QStringList Rondier::obtenirListeBatiments()
{
    QStringList listeBatiments;
    QString batiment;
    foreach(Pointeau *p, listePointeaux){
        batiment = p->getBatiment();
        listeBatiments.append(batiment);
    }
    return listeBatiments;
}

QStringList Rondier::obtenirListeEtages()
{
    QStringList listeEtages;
    QString etage;
    foreach(Pointeau *p, listePointeaux){
        etage = p->getEtage();
        listeEtages.append(etage);
    }
    return listeEtages;
}

QStringList Rondier::obtenirListeTempsMini()
{
    QStringList listeTempsMini;
    QString tempsMini;
    foreach(Pointeau *p, listePointeaux){
        tempsMini = p->getTempsMini();
        listeTempsMini.append(tempsMini);
    }
    return listeTempsMini;
}

QStringList Rondier::obtenirListeTempsMaxi()
{
    QStringList listeTempsMaxi;
    QString tempsMaxi;
    foreach(Pointeau *p, listePointeaux){
        tempsMaxi = p->getTempsMaxi();
        listeTempsMaxi.append(tempsMaxi);
    }
    return listeTempsMaxi;
}

QStringList Rondier::obtenirListeTags()
{
    QStringList listeTags;
    QString tag;
    foreach(Pointeau *p, listePointeaux){
        tag = p->getTagMifare();
        listeTags.append(tag);
    }

    return listeTags;
}

QStringList Rondier::obtenirListeEmplacements()
{
    QStringList listeEmplacementsPointeaux;
    QString emplacement;
    foreach(Pointeau *p, listePointeaux){
        emplacement = p->getEmplacement();
        listeEmplacementsPointeaux.append(emplacement);
    }
    return listeEmplacementsPointeaux;
}

void Rondier::mettreAJourTableAEteEffectueeParBDD(int _index)
{
    Pointeau *p = listePointeaux.at(_index);
    p->horodater();
    idHistoriqueRonde = bdd.mettreAJourTableAEteEffectueePar(agent.getId(), rondeCourante->getId(), p->getHorodatage());
    if(idHistoriqueRonde != -1){
        qDebug() << "bdd à jour (table aEteEffectueePar)";
    }
}

void Rondier::mettreAJourTableAEteScanneParSansAnomalieBDD(int _index)
{
    Pointeau *p = listePointeaux.at(_index);
    p->horodater();
    idHistoriquePointeau = bdd.mettreAJourTableAEteScanneParSansAnomalie(idHistoriqueRonde, p->getIdPointeau(), ++ordre, p->getHorodatage());
    if(idHistoriquePointeau != -1){
        qDebug() << "bdd à jour sans anomalie (table aEteScannePar)";
    }
}

void Rondier::mettreAJourTablesAEteScanneParAvecAnomalieEtAnomaliesBDD(QString _description)
{
    int idAnomalie = bdd.mettreAJourTableAnomalies(_description);
    if(idAnomalie != -1){
        if(!bdd.mettreAJourTableAEteScanneParAvecAnomalie(idAnomalie, idHistoriquePointeau)){
            qDebug() << "bdd à jour avec anomalie (table aEteScannePar)";
        }
    }
    else{
       qDebug() << "pb mise à jour bdd (table anomalies)";
    }

}

void Rondier::mettreAJourTableAEteScanneParDefautOrdreEtPointeauIgnoreBDD(int _index, int _idAnomalie, QString _description)
{
    Pointeau *p = listePointeaux.at(_index);
    p->horodater();
    if(_idAnomalie == 0){
        _idAnomalie = bdd.mettreAJourTableAnomalies(_description);
        if(!bdd.mettreAJourTableAEteScanneParDefautOrdreEtPointeauIgnore(_idAnomalie, idHistoriqueRonde, p->getIdPointeau(), ++ordre, p->getHorodatage())){
            qDebug() << "bdd à jour avec Pointeau ignoré (table aEteScannePar)";
        }
    }
    else{
        if(!bdd.mettreAJourTableAEteScanneParDefautOrdreEtPointeauIgnore(_idAnomalie, idHistoriqueRonde, p->getIdPointeau(), ++ordre, p->getHorodatage())){
            qDebug() << "bdd à jour avec Pointeau ignoré (table aEteScannePar)";
        }
    }
}

