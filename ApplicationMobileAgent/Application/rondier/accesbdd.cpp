#include "accesbdd.h"

AccesBdd::AccesBdd(QObject *parent) : QObject(parent)
{

}

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

bool AccesBdd::obtenirListePointeaux(QList<Pointeau *> &_listePointeaux, int _idRonde)
{
    Pointeau *unPointeau;
    bool retour = false;
    if(db.isOpen()){
        QSqlQuery requete(db);
        requete.prepare("SELECT pointeaux.id_pointeau, pointeaux.designation, pointeaux.tag_mifare, pointeaux.batiment, pointeaux.etage, pointeaux.emplacement, comporte.ordre, comporte.tempsmini, comporte.tempsmaxi FROM pointeaux INNER JOIN comporte ON comporte.id_pointeau = pointeaux.id_pointeau WHERE comporte.id_ronde = :id ");
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
