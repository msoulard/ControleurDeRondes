#include "accesbdd.h"
#include "agent.h"
#include "ronde.h"
#include "pointeau.h"

/**
 * @brief AccesBdd::AccesBdd
 * @param parent
 */
AccesBdd::AccesBdd(QObject *parent) : QObject(parent)
{
    //Indiquer le type de la base de données
    db = QSqlDatabase::addDatabase("QSQLITE");
    //Indiquer l'emplacement de la base de données sur l'odinateur
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
 */
AccesBdd::~AccesBdd()
{
    db.close();
}

/**
 * @brief AccesBdd::obtenirAgent
 * @param _numBadge
 * @return
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

    return agent ;
}

/**
 * @brief AccesBdd::obtenirRondes
 * @param _numBadge
 * @return
 */
QList<Ronde*> AccesBdd::obtenirRondes(QString _numBadge)
{
    QList<Ronde*> _listeNomRondes;
    Ronde *ronde;
    int idAgent = 0;
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
                idAgent = requete_agent.value("id_agent").toInt();
            }
        }
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
                _listeNomRondes.append(ronde);
            }
        }
    }
    qDebug() << _listeNomRondes;
    return _listeNomRondes;
}

QList<Pointeau *> AccesBdd::obtenirPointeau(int _idRonde)
{
    QList<Pointeau*> listePointeaux;
    Pointeau *unPointeau;
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
               unPointeau->setTempsMini(requete.value("tempsmini").toString());
               unPointeau->setTempsMaxi(requete.value("tempsmaxi").toString());
               listePointeaux.append(unPointeau);
            }
        }
    }
    qDebug() << listePointeaux;
    return listePointeaux;
}
