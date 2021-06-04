/**
 * @file accesbdd.cpp
 * @brief Implémentation de la classe AccesBdd
 * @details Classe permettant l'accès à la base de données
 * @author Maëva Soulard
 * @date 28/05/2021
 */

#include "accesbdd.h"

/**
 * @brief AccesBdd::AccesBdd
 * @param parent
 * @details Constructeur de la classe AccesBdd
 */
AccesBdd::AccesBdd(QObject *parent) : QObject(parent)
{

}

/**
 * @brief AccesBdd::connexion
 * @param _emplacementFichier
 * @return
 * @details Méthode permettant l'ouverture de la base de données
 */
bool AccesBdd::connexion(QString _emplacementFichier)
{
    bool retour = false;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(_emplacementFichier);
    if(db.open()){
        retour = true;
        qDebug() << "Ouverture BDD réussie" ;
    }
    else{
        qDebug() << "Problème à l'ouverture de la BDD" << db.lastError();
    }
    return retour;
}

/**
 * @brief AccesBdd::obtenirAgent
 * @param _numBadge
 * @param _agent
 * @return
 * @details Méthode permettant de récupérer l'agent identifié
 */
bool AccesBdd::obtenirAgent(QString _numBadge, Agent &_agent)
{
    bool retour = false;
    if(db.isOpen())
    {
        QSqlQuery requete(db);
        requete.prepare("SELECT agents.nom, agents.prenom, agents.id_agent FROM agents WHERE agents.numbadge=:num");
        requete.bindValue(":num", _numBadge);
        if(!requete.exec()){
            qDebug() << "problème lors de la requête SQL (agents) : " << requete.lastError();
        }
        else{
            while(requete.next()){
                retour = true;
                _agent.setNom(requete.value("nom").toString());
                _agent.setPrenom(requete.value("prenom").toString());
                _agent.setId(requete.value("id_agent").toInt());
                _agent.setNumBadge(_numBadge);
            }
        }
    }
    return retour;
}

/**
 * @brief AccesBdd::obtenirListeRondes
 * @param _listeRondes
 * @param _idAgent
 * @return
 * @details Méthode permettant de récupérer la liste des rondes que l'agent identifié peut faire
 */
bool AccesBdd::obtenirListeRondes(QList<Ronde *> &_listeRondes, int _idAgent)
{
    bool retour = false;
    Ronde *ronde;
    if(db.isOpen()){
        ///Récupérer les rondes correspondantes à l'agent
        QSqlQuery requete(db);
        requete.prepare("SELECT rondes.nom, rondes.id_ronde FROM rondes INNER JOIN peutFaire ON rondes.id_ronde = peutFaire.id_ronde WHERE peutFaire.id_agent=:id");
        requete.bindValue(":id", _idAgent);
        if(!requete.exec()){
            qDebug() << "problème lors de la requête SQL (rondes) : " << requete.lastError();
        }
        else{
            while(requete.next()){
                retour = true;
                ronde = new Ronde;
                ronde->setNom(requete.value("nom").toString());
                ronde->setId(requete.value("id_ronde").toInt());
                _listeRondes.append(ronde);
            }
        }
    }
    //qDebug() << "requête SQL :" << listeRondes;
    return retour;
}

/**
 * @brief AccesBdd::obtenirListePointeaux
 * @param _listePointeaux
 * @param _idRonde
 * @return
 * @details Méthode qui permet d'obtenir la liste des pointeaux en fonction de la ronde choisie
 */
bool AccesBdd::obtenirListePointeaux(QList<Pointeau *> &_listePointeaux, int _idRonde)
{
    Pointeau *unPointeau;
    bool retour = false;
    if(db.isOpen()){
        QSqlQuery requete(db);
        requete.prepare("SELECT pointeaux.id_pointeau, pointeaux.designation, pointeaux.tag_mifare, "
                        "pointeaux.batiment, pointeaux.etage, pointeaux.emplacement, comporte.ordre, "
                        "comporte.tempsmini, comporte.tempsmaxi FROM pointeaux INNER JOIN comporte ON "
                        "comporte.id_pointeau = pointeaux.id_pointeau WHERE comporte.id_ronde = :id ORDER BY ordre");
        requete.bindValue(":id", _idRonde);
        if(!requete.exec()){
            qDebug() << "problème lors de la requête SQL (pointeaux) : " << requete.lastError();
        }
        else{
            while(requete.next()){
                retour = true;
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
                _listePointeaux.append(unPointeau);
            }
        }
    }
    //qDebug() << listePointeaux;
    return retour;
}

/**
 * @brief AccesBdd::mettreAJourTableAEteEffectueePar
 * @param _idAgent
 * @param _idRonde
 * @param _horodatage
 * @return
 * @details Méthode permettant de mettre à jour la table aEteEffectueePar en fonction de l'agent, de la ronde choisie et de la date
 */
int AccesBdd::mettreAJourTableAEteEffectueePar(int _idAgent, int _idRonde, QDateTime _horodatage)
{
    int retour = -1;
    if(db.isOpen()){
        QSqlQuery requete(db);
        requete.prepare("INSERT INTO aEteEffectueePar (id_ronde, id_agent, date_heure) VALUES (:idRonde, :idAgent, :horodatage);");
        requete.bindValue(":idRonde", _idRonde);
        requete.bindValue(":idAgent",_idAgent);
        requete.bindValue(":horodatage", _horodatage.toString("yyyy-MM-dd HH:mm:ss"));
        if(!requete.exec()){
            qDebug() << "problème lors de la requête SQL (mettre à jour table aEteEffectueePar) : " << requete.lastError();
        }
        else{
            retour = requete.lastInsertId().toInt();
        }
    }

    return retour;
}

/**
 * @brief AccesBdd::mettreAJourTableAEteScanneParSansAnomalie
 * @param _idHistoriqueRonde
 * @param _idPointeau
 * @param _ordre
 * @param _horodatage
 * @return
 * @details Méthode qui permet de mettre à jour la table aEteScannePar sans anomalie
 */
int AccesBdd::mettreAJourTableAEteScanneParSansAnomalie(int _idHistoriqueRonde, int _idPointeau, int _ordre, QDateTime _horodatage)
{
    int retour = -1;
    QSqlQuery requete(db);
    if(db.isOpen()){
            requete.prepare("INSERT INTO aEteScannePar (id_pointeau, ordre, date_heure,"
                            " id_historiqueRonde) VALUES (:idPointeau, :ordre, :horodatage, "
                            ":idHistoriqueRonde);");
            requete.bindValue(":idPointeau", _idPointeau);
            requete.bindValue(":ordre", _ordre);
            requete.bindValue(":horodatage", _horodatage.toString("yyyy-MM-dd HH:mm:ss"));
            requete.bindValue(":idHistoriqueRonde", _idHistoriqueRonde);
        if(!requete.exec()){
            qDebug() << "problème lors de la requête SQL (mettre à jour table aEteEffectueePar sans anomalie) : " << requete.lastError();
        }
        else{
            retour = requete.lastInsertId().toInt();
        }
    }
    return retour;
}

/**
 * @brief AccesBdd::mettreAJourTableAEteScanneParAvecAnomalie
 * @param _idAnomalie
 * @param _idHistoriquePointeau
 * @return
 * @details Méthode permettant de mettre à jour la table aEteScannePar avec une anomalie
 */
bool AccesBdd::mettreAJourTableAEteScanneParAvecAnomalie(int _idAnomalie, int _idHistoriquePointeau)
{
    bool retour = false;
    QSqlQuery requete(db);
    if(db.isOpen()){
        requete.prepare("UPDATE aEteScannePar SET id_anomalie = :idAnomalie WHERE id = :idHistoriquePointeau;");
        requete.bindValue(":idAnomalie", _idAnomalie);
        requete.bindValue(":idHistoriquePointeau", _idHistoriquePointeau);
        if(!requete.exec()){
            qDebug() << "problème lors de la requête SQL (mettre à jour table aEteEffectueePar avec anomalie) : " << requete.lastError();
        }
        else{
            retour = true;
        }
    }
    return retour;
}

/**
 * @brief AccesBdd::mettreAJourTableAEteScanneParDefautOrdreEtPointeauIgnore
 * @param _idAnomalie
 * @param _idHistoriqueRonde
 * @param _idPointeau
 * @param _ordre
 * @param _horodatage
 * @return
 * @details Méthode permettant de mettre à jour la table aEteScannePar s'il y a un défaut d'ordre ou un pointeau ignoré
 */
bool AccesBdd::mettreAJourTableAEteScanneParDefautOrdreEtPointeauIgnore(int _idAnomalie, int _idHistoriqueRonde, int _idPointeau, int _ordre, QDateTime _horodatage)
{
    bool retour = false;
    QSqlQuery requete(db);
    if(db.isOpen()){
            requete.prepare("INSERT INTO aEteScannePar (id_pointeau, id_anomalie, ordre, date_heure,"
                            " id_historiqueRonde) VALUES (:idPointeau, :idAnomalie, :ordre, :horodatage, "
                            ":idHistoriqueRonde);");
            requete.bindValue(":idPointeau", _idPointeau);
            requete.bindValue(":idAnomalie", _idAnomalie);
            requete.bindValue(":ordre", _ordre);
            requete.bindValue(":horodatage", _horodatage.toString("yyyy-MM-dd HH:mm:ss"));
            requete.bindValue(":idHistoriqueRonde", _idHistoriqueRonde);
        if(!requete.exec()){
            qDebug() << "problème lors de la requête SQL (mettre à jour table aEteEffectueePar sans anomalie) : " << requete.lastError();
        }
        else{
            retour = true;
        }
    }
    return retour;
}

/**
 * @brief AccesBdd::mettreAJourTableAnomalies
 * @param _description
 * @return
 * @details Méthode permettant de mettre à jour la table Anomalies
 */
int AccesBdd::mettreAJourTableAnomalies(QString _description)
{
    int retour = -1;
    QSqlQuery requete(db);
    if(db.isOpen()){
        requete.prepare("INSERT INTO anomalies (description) VALUES (:description);");
        requete.bindValue(":description", _description);
        if(!requete.exec()){
            qDebug() << "problème lors de la requête SQL (mettre à jour table anomalies) : " << requete.lastError();
        }
        else{
            retour = requete.lastInsertId().toInt();
        }
    }
    return retour;
}
