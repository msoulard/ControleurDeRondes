/**
 * @file rondier.cpp
 * @brief Implémentation de la classe Rondier
 * @details Classe permettant de gérer toutes les données nécessaire et du lien avec le QML
 * @author Maëva Soulard
 * @date 28/05/2021
 */

#include "rondier.h"

/**
 * @brief Rondier::Rondier
 * @param _engine
 * @param parent
 * @details Constructeur de la classe Rondier
 */
Rondier::Rondier(QQmlApplicationEngine &_engine, QObject *parent) : QObject(parent),
    engine(_engine)
{
    //emplacement BDD téléphone(/data/data/org.qtproject.rondier/db/Rondier_BDDRemplie.db)
    //emplacement BDD ordi(/home/USERS/ELEVES/SNIR2019/msoulard/ControleurDeRondes2021/ControleurDeRondes/BDDs/Rondier/Rondier_BDDRemplie.db)
    bdd.connexion("C:/Users/soula/Documents/Cours/SNIR2/Projet 2021/Maëva/ControleurDeRondes/BDDs/Rondier/Rondier_BDDRemplie.db");
    ordre = 0;
    idHistoriqueRonde = -1;
    idHistoriquePointeau = -1;
    //permet de faire le lien entre QML et la classe LecteurNFC
    engine.rootContext()->setContextProperty("lecteurNFC", &leLecteur);
}

/**
 * @brief Rondier::~Rondier
 * @details Destructeur de la classe Rondier
 */
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

/**
 * @brief Rondier::mettreAJourAgent
 * @param _numBadge
 * @details Méthode permettant de mettre à jour l'attribut agent de la classe
 */
void Rondier::mettreAJourAgent(QString _numBadge)
{
    if(bdd.obtenirAgent(_numBadge, agent)){
        //permet de faire le lien entre QML et la classe Agent
        engine.rootContext()->setContextProperty("agent", &agent);
    }
}

/**
 * @brief Rondier::obtenirRondes
 * @return
 * @details Méthode permettant de récupérer la liste des noms des rondes et de mettre à jour l'attribut listeRondes de la classe
 */
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

/**
 * @brief Rondier::obtenirNomRondeCourante
 * @param _index
 * @return
 * @details Méthode permettant de mettre à jour l'attribut rondeCourante de la classe et de récupérer le nom de la ronde courante
 */
QString Rondier::obtenirNomRondeCourante(int _index)
{
    rondeCourante = listeRondes.at(_index);
    ordre = 0;
    return rondeCourante->getNom();
}

/**
 * @brief Rondier::mettreAJourListePointeaux
 * @details Méthode permettant de mettre à jour l'attribut listePointeaux de la classe et de récupérer la liste de pointeaux en QML
 */
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

/**
 * @brief Rondier::obtenirListeDesignations
 * @return
 * @details Méthode permettant de récupérer la liste des désignations des pointeaux
 */
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

/**
 * @brief Rondier::obtenirListeBatiments
 * @return
 * @details Méthode permettant de récupérer la liste des bâtiments des pointeaux
 */
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

/**
 * @brief Rondier::obtenirListeEtages
 * @return
 * @details Méthode permettant de récupérer la liste des étages des pointeaux
 */
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

/**
 * @brief Rondier::obtenirListeTempsMini
 * @return
 * @details Méthode permettant de récupérer la liste des temps minimum des pointeaux
 */
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

/**
 * @brief Rondier::obtenirListeTempsMaxi
 * @return
 * @details Méthode permettant de récupérer la liste des temps maximum des pointeaux
 */
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

/**
 * @brief Rondier::obtenirListeTags
 * @return
 * @details Méthode permettant de récupérer la liste des tags MIFARE des pointeaux
 */
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

/**
 * @brief Rondier::obtenirListeEmplacements
 * @return
 * @details Méthode permettant de récupérer la liste des emplacements des pointeaux
 */
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

/**
 * @brief Rondier::mettreAJourTableAEteEffectueeParBDD
 * @param _index
 * @details Méthode permettant de mettre à jour la table aEteEffectueePar dans la base de données
 */
void Rondier::mettreAJourTableAEteEffectueeParBDD(int _index)
{
    Pointeau *p = listePointeaux.at(_index);
    p->horodater();
    idHistoriqueRonde = bdd.mettreAJourTableAEteEffectueePar(agent.getId(), rondeCourante->getId(), p->getHorodatage());
    if(idHistoriqueRonde != -1){
        qDebug() << "bdd à jour (table aEteEffectueePar)";
    }
}

/**
 * @brief Rondier::mettreAJourTableAEteScanneParSansAnomalieBDD
 * @param _index
 * @details Méthode permettant de mettre à jour la table aEteScannePar sans anomalie dans la base de données
 */
void Rondier::mettreAJourTableAEteScanneParSansAnomalieBDD(int _index)
{
    Pointeau *p = listePointeaux.at(_index);
    p->horodater();
    idHistoriquePointeau = bdd.mettreAJourTableAEteScanneParSansAnomalie(idHistoriqueRonde, p->getIdPointeau(), ++ordre, p->getHorodatage());
    if(idHistoriquePointeau != -1){
        qDebug() << "bdd à jour sans anomalie (table aEteScannePar)";
    }
}

/**
 * @brief Rondier::mettreAJourTablesAEteScanneParAvecAnomalieEtAnomaliesBDD
 * @param _description
 * @details Méthode permettant de mettre à jour la table aEteScannePar avec une anomalie et la table anomalies dans la base de données
 */
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

/**
 * @brief Rondier::mettreAJourTableAEteScanneParDefautOrdreEtPointeauIgnoreBDD
 * @param _index
 * @param _idAnomalie
 * @param _description
 * @details Méthode permettant de mettre à jour la table aEteScannePar avec un défaut d'ordre ou un pointeau ignoré et la table anomalies dans la base de données
 */
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

