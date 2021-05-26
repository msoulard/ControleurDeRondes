/**
  @file accesbdd.cpp
  @brief Implémentation de la classe AccesBdd
  @author Maëva Soulard
  @date 26/03/2021
*/

#include "accesbdd.h"
#include "agent.h"
#include "ronde.h"
#include "pointeau.h"

/**
 * @brief AccesBdd::AccesBdd
 * @param parent
 * @details Contructeur de la classe qui permet l'accès à la base de données
 */
AccesBdd::AccesBdd(QObject *parent) : QObject(parent)
{
    //Indiquer le type de la base de données
    db = QSqlDatabase::addDatabase("QSQLITE");
    //Indiquer l'emplacement de la base de données sur l'odinateur (lycée)
    //db.setDatabaseName("/home/USERS/ELEVES/SNIR2019/msoulard/ControleurDeRondes2021/ControleurDeRondes/BDDs/Rondier/Rondier_BDDRemplie.db");
    //Indiquer l'emplacement de la base de données sur l'odinateur (perso)
    db.setDatabaseName("C:/Users/soula/Documents/Cours/SNIR2/Projet 2021/Maëva/ControleurDeRondes/BDDs/Rondier/Rondier_BDDRemplie.db");
    //Indiquer l'emplacement de la base de données sur le téléphone
    //db.setDatabaseName("/data/data/org.qtproject.testRondier/db/Rondier_BDDRemplie.db");
    //Ouverture de la base de données
    db.open();
    //Vérification de l'ouverture de la base de données
    if(! db.isOpen()){ //Si la base données n'a pas réussi à être ouverte
        qDebug() << "Problème à l'ouverture";
    }
    else{ //Si la base de données est ouverte
        qDebug() << "Ouverture réussie" ;
    }
}

/**
 * @brief AccesBdd::~AccesBdd
 * @details Destructeur de la classe
 */
AccesBdd::~AccesBdd()
{
    //fermer la base de données
    db.close();
}

/**
 * @brief AccesBdd::obtenirAgent
 * @param _numBadge
 * @return
 * @details Méthode qui permet d'obtenir un agent en fonction de son numéro de badge
 */
S_Agent AccesBdd::obtenirAgent(QString _numBadge)
{
    S_Agent agent;
    agent.numBadge = _numBadge;
    if(db.isOpen()){
        QSqlQuery requete(db);
        requete.prepare("SELECT agents.nom, agents.prenom, agents.id_agent FROM agents WHERE agents.numbadge=:num");
        requete.bindValue(":num", _numBadge);
        if(!requete.exec()){
            qDebug() << "problème lors de la requête SQL (agents) : " << requete.lastError();
        }
        else{
            while(requete.next()){
                agent.nom = requete.value("nom").toString();
                agent.prenom = requete.value("prenom").toString();
                agent.id=requete.value("id_agent").toInt();
            }
        }
    }
    idAgent = agent.id;

    return agent ;
}

/**
 * @brief AccesBdd::obtenirRondes
 * @param _numBadge
 * @return
 * @details Méthode qui permet de récupérer la liste de rondes en fonction du numéro de badge de l'agent
 */
QList<Ronde*> AccesBdd::obtenirListeRondes()
{
    Ronde *ronde;
    if(db.isOpen()){
        ///Récupérer les rondes correspondantes à l'agent
        QSqlQuery requete(db);
        requete.prepare("SELECT rondes.nom, rondes.id_ronde FROM rondes INNER JOIN peutFaire ON rondes.id_ronde = peutFaire.id_ronde WHERE peutFaire.id_agent=:id");
        requete.bindValue(":id", idAgent);
        if(!requete.exec()){
            qDebug() << "problème lors de la requête SQL (rondes) : " << requete.lastError();
        }
        else{
            while(requete.next()){
                ronde = new Ronde();
                ronde->setNom(requete.value("nom").toString());
                ronde->setId(requete.value("id_ronde").toInt());
                listeRondes.append(ronde);
            }
        }
    }
    //qDebug() << "requête SQL :" << listeRondes;
    return listeRondes;
}

/**
 * @brief AccesBdd::obtenirListePointeaux
 * @param _idRonde
 * @return
 * @details Méthode qui permet d'obtenir la liste des pointeaux en fonctiond de la ronde choisie
 */
QList<Pointeau *> AccesBdd::obtenirListePointeaux(int _idRonde)
{
    Pointeau *unPointeau;
    QList<Pointeau*> listePointeaux;
    if(db.isOpen()){
        QSqlQuery requete(db);
        requete.prepare("SELECT pointeaux.id_pointeau, pointeaux.designation, pointeaux.tag_mifare, pointeaux.batiment, pointeaux.etage, pointeaux.emplacement, comporte.ordre, comporte.tempsmini, comporte.tempsmaxi FROM pointeaux INNER JOIN comporte ON comporte.id_pointeau = pointeaux.id_pointeau WHERE comporte.id_ronde = :id ");
        requete.bindValue(":id", _idRonde);
        if(!requete.exec()){
            qDebug() << "problème lors de la requête SQL (pointeaux) : " << requete.lastError();
        }
        else{
            while(requete.next()){
                unPointeau = new Pointeau();
                unPointeau->setIdPointeau(requete.value("id_pointeau").toInt());
                unPointeau->setDesignation(requete.value("designation").toString());
                unPointeau->setTagMifare(requete.value("tag_mifare").toString());
                unPointeau->setBatiment(requete.value("batiment").toString());
                unPointeau->setEtage(requete.value("etage").toString());
                unPointeau->setEmplacement(requete.value("emplacement").toString());
                unPointeau->setOrdre(requete.value("ordre").toInt());
                //mid(0,8) permet d'afficher les 8 premiers caractères (heures:minutes:secondes)
                unPointeau->setTempsMini(requete.value("tempsmini").toString().mid(0,8));
                //left(8) permet d'afficher les 8 premiers caractères (heures:minutes:secondes)
                unPointeau->setTempsMaxi(requete.value("tempsmaxi").toString().left(8));
                listePointeaux.append(unPointeau);
            }
        }
    }
    //qDebug() << listePointeaux;
    return listePointeaux;
}

/**
 * @brief AccesBdd::obtenirListePointeauxQML
 * @return
 * @details Méthode qui permet de récupérer et d'afficher en QML la liste des pointeaux
 */
QList<QObject*> AccesBdd::obtenirListePointeauxQML()
{
    QList<QObject*> listeDesignationsPointeaux;
    QList<Pointeau*> listePointeaux;
    listePointeaux = obtenirListePointeaux(1);
    foreach (Pointeau *p, listePointeaux) {
        if (p==listePointeaux.first()){   // premier pointeau en bleu
            p->setCouleur("#0000FF");
        }
        else{ //les suivant en noir
            p->setCouleur("#000000");
        }

        listeDesignationsPointeaux.append(p);
    }
    //qDebug() << listeDesignationsPointeaux;
    return listeDesignationsPointeaux;
}

/**
 * @brief AccesBdd::obtenirListeDesignationsPointeaux
 * @return
 * @details Méthode qui permet de récupérer la liste des désignations des pointeaux
 */
QList<QString> AccesBdd::obtenirListeDesignationsPointeaux()
{
    QList<QString> listeDesignations;
    QList<Pointeau*> listePointeaux;
    QString designation;
    listePointeaux = obtenirListePointeaux(1);
    foreach(Pointeau *p, listePointeaux){
        designation = p->getDesignation();
        listeDesignations.append(designation);
    }
    return listeDesignations;
}

/**
 * @brief AccesBdd::obtenirListeNomsRondes
 * @param _numBadge
 * @return
 * @details Méthode qui permet de récupérer la liste des noms des rondes en fonction de l'agent
 */
QList<QString> AccesBdd::obtenirListeNomsRondes()
{
    QList<QString> listeNomRondes;
    setListeRondes(obtenirListeRondes());
    for(int i = 0 ; i < listeRondes.size() ; i++){
        listeNomRondes.append(listeRondes.at(i)->getNom());
    }
    //qDebug() << listeNomRondes;
    return listeNomRondes;
}

/**
 * @brief AccesBdd::obtenirListeEmplacementPointeaux
 * @return
 * @details Méthode qui permet d'obenir la liste des emplacements des pointeaux
 */
QList<QString> AccesBdd::obtenirListeEmplacementPointeaux()
{
    QList<QString> listeEmplacements;
    QList<Pointeau*> listePointeaux;
    QString emplacement;
    listePointeaux = obtenirListePointeaux(1);
    foreach(Pointeau *p, listePointeaux){
        emplacement = p->getEmplacement();
        listeEmplacements.append(emplacement);
    }
    return listeEmplacements;

}

/**
 * @brief AccesBdd::obtenirListeTempsMiniPointeaux
 * @return
 * @details Méthode qui permet d'obtenir la liste des temps minimum des pointeaux
 */
QList<QString> AccesBdd::obtenirListeTempsMiniPointeaux()
{
    QList<QString> listeTempsMini;
    QList<Pointeau*> listePointeaux;
    QString tempsMini;
    listePointeaux = obtenirListePointeaux(1);
    foreach(Pointeau *p, listePointeaux){
        tempsMini = p->getTempsMini();
        listeTempsMini.append(tempsMini);
    }
    return listeTempsMini;
}

/**
 * @brief AccesBdd::obtenirListeTempsMaxiPointeaux
 * @return
 * @details Méthode qui permet d'obtenir la liste des temps maximum des pointeaux
 */
QList<QString> AccesBdd::obtenirListeTempsMaxiPointeaux()
{
    QList<QString> listeTempsMaxi;
    QList<Pointeau*> listePointeaux;
    QString tempsMaxi;
    listePointeaux = obtenirListePointeaux(1);
    foreach(Pointeau *p, listePointeaux){
        tempsMaxi = p->getTempsMaxi();
        listeTempsMaxi.append(tempsMaxi);
    }
    return listeTempsMaxi;
}

/**
 * @brief AccesBdd::obtenirListeBatimentPointeaux
 * @return
 * @details Méthode qui permet d'obtenir la liste des bâtiments des pointeaux
 */
QList<QString> AccesBdd::obtenirListeBatimentPointeaux()
{
    QList<QString> listeBatiment;
    QList<Pointeau*> listePointeaux;
    QString batiment;
    listePointeaux = obtenirListePointeaux(1);
    foreach(Pointeau *p, listePointeaux){
        batiment = p->getBatiment();
        listeBatiment.append(batiment);
    }
    return listeBatiment;
}

/**
 * @brief AccesBdd::obtenirListeEtagePointeaux
 * @return
 * @details Méthode qui permet d'obtenir la liste des étages des pointeaux
 */
QList<QString> AccesBdd::obtenirListeEtagePointeaux()
{
    QList<QString> listeEtage;
    QList<Pointeau*> listePointeaux;
    QString etage;
    listePointeaux = obtenirListePointeaux(1);
    foreach(Pointeau *p, listePointeaux){
        etage = p->getEtage();
        listeEtage.append(etage);
    }
    return listeEtage;
}

/**
 * @brief AccesBdd::obtenirListeTagPointeaux
 * @return
 * @details Méthode qui permet d'obtenir la liste des tags des pointeaux
 */
QList<QString> AccesBdd::obtenirListeTagPointeaux()
{
    QList<QString> listeTag;
    QList<Pointeau*> listePointeaux;
    QString tag;
    listePointeaux = obtenirListePointeaux(1);
    foreach(Pointeau *p, listePointeaux){
        tag = p->getTagMifare();
        listeTag.append(tag);
    }

    return listeTag;
}

/**
 * @brief AccesBdd::mettreAJourTableAEteEffectueePar
 * @details Méthode qui permet de mettre à jour la table aEteEffectueePar dans la base de données
 */
void AccesBdd::mettreAJourTableAEteEffectueePar()
{
    int idAgent = obtenirIdAgent("1B4DBE53");
    int idRonde;
    qDebug() << "idAgent : " << idAgent;
    //int idRonde;
}

/**
 * @brief AccesBdd::obtenirIdAgent
 * @param _numBadge
 * @return
 * @details Méthode qui permet d'obtenir l'id de l'agent
 */
int AccesBdd::obtenirIdAgent(QString _numBadge)
{
    int id = 0;
    if(db.isOpen()){
        ///Récupérer l'id de l'agent
        QSqlQuery requete_agent(db);
        requete_agent.prepare("SELECT agents.id_agent FROM agents WHERE agents.numbadge=:num");
        requete_agent.bindValue(":num", _numBadge);
        if(!requete_agent.exec()){
            qDebug() << "problème lors de la requête SQL (agents) : " << requete_agent.lastError();
        }
        else{
            while(requete_agent.next()){
                id = requete_agent.value("id_agent").toInt();
            }
        }
    }
    return id;
}

/**
 * @brief AccesBdd::getListeRondes
 * @return
 * @details Méthode qui permet de récupérer la liste des rondes dans une autre classe
 */
QList<Ronde *> AccesBdd::getListeRondes() const
{
    return listeRondes;
}

/**
 * @brief AccesBdd::setListeRondes
 * @param value
 * @details Méthode qui permet de mettre à jour la liste des rondes
 */
void AccesBdd::setListeRondes(const QList<Ronde *> &value)
{
    listeRondes = value;
}
