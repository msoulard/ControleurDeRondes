/**
  @file accesbdd.cpp
  @details Définition et déclaration des méthodes de la classe AccesBDD
  @author Maëva Soulard
  @date 19/03/2021
  */

#include "accesbdd.h"

AccesBDD::AccesBDD(QObject *parent) : QObject(parent)
{
    ///Indiquer le type de la base de données
    db = QSqlDatabase::addDatabase("QSQLITE");
    ///Indiquer l'emplacement de la base de données
    db.setDatabaseName("/home/USERS/ELEVES/SNIR2019/msoulard/Controleur de rondes 2021/ControleurDeRondes/BDDs/Rondier/Rondier_BDDRemplie");
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

void AccesBDD::ObtenirPointeaux(int _id_ronde)
{

}

void AccesBDD::ObtenirRondes(int _id_agent)
{

}

void AccesBDD::RecupererLePointeau(QString _tag_mifare)
{

}

void AccesBDD::VerificationBadge(int _numBadge)
{

}

void AccesBDD::MettreAJourBdd()
{

}

void AccesBDD::EnregistrerAnomalie(int _id_pointeau)
{

}
