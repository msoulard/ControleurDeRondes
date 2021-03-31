#include "accesbdd.h"

AccesBdd::AccesBdd(QObject *parent) : QObject(parent)
{
    ///Indiquer le type de la base de données
    db = QSqlDatabase::addDatabase("QSQLITE");
    ///Indiquer l'emplacement de la base de données
    db.setDatabaseName("/home/USERS/ELEVES/SNIR2019/msoulard/Controleur de rondes 2021/ControleurDeRondes/BDDs/Rondier/Rondier_BDDRemplie.db");
    ///Ouverture de la base de données
    db.open();
    ///Vérification de l'ouverture de la base de données
    if(! db.isOpen()){ ///Si la base données n'a pas réussi à être ouverte
        qDebug() << "Problème à l'ouverture";
    }
    else{ ///Si la base de données est ouverte
        qDebug() << "Ouverture réussie" ;
    }
}

QString AccesBdd::obtenirAgent(QString _numBadge)
{
    if(db.isOpen()){
        QSqlQuery requete(db);
        requete.prepare("SELECT agents.nom, agents.prenom, agents.id_agent FROM agents WHERE agents.numbadge=:num");
        requete.bindValue(":num", _numBadge);
        if(!requete.exec()){
            qDebug() << "problème lors de la requête SQL (agents) : " << requete.lastError();
        }
        else{
            while(requete.next()){
                nomAgent = requete.value("nom").toString();
                prenomAgent = requete.value("prenom").toString();
                idAgent = requete.value("id_agent").toInt();
            }
        }
    }
    //obtenirRondes();
    QString prenomNom = prenomAgent + " " + nomAgent;
    qDebug() << prenomNom;
    return prenomNom;
}

QString AccesBdd::obtenirPointeaux(int _id_ronde)
{

}

QList<QString> AccesBdd::obtenirRondes(QString _numBadge)
{
    QList<QString> _listeNomRondes;
    QString ronde;
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
        QSqlQuery requete(db);
        requete.prepare("SELECT rondes.nom, rondes.id_ronde FROM rondes INNER JOIN peutFaire ON rondes.id_ronde = peutFaire.id_ronde WHERE peutFaire.id_agent=:id");
        requete.bindValue(":id", idAgent);
        if(!requete.exec()){
            qDebug() << "problème lors de la requête SQL (rondes) : " << requete.lastError();
        }
        else{
            while(requete.next()){
                ronde = requete.value("nom").toString();
                _listeNomRondes.append(ronde);
            }
        }
    }
    ronde = "";
    qDebug() << _listeNomRondes;
    return _listeNomRondes;
}


void AccesBdd::RecupererLePointeau(QString _tag_mifare)
{

}

void AccesBdd::MettreAJourBdd()
{

}

void AccesBdd::EnregistrerAnomalie(int _id_pointeau)
{

}
