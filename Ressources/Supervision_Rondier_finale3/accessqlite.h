/**
   @file AccesSqlite.h
 * @brief Déclaration de la classe AccesSqlite
 * @version 1.0
 * @author Damien CABARET
 * @date 03/04/2021
 */

#ifndef ACCESSQLITE_H
#define ACCESSQLITE_H
#include <QSqlDatabase>
#include <QObject>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDir>
#include "accesmysql.h"

class AccesSqlite
{
public:
    AccesSqlite();
    bool ConnexionBddSqlite();

    //Recuperer les données depuis la BDD SQLite
    void RecupererAnomalies(QList<Anomalie> &_ListeAnomalie);
    void RecupererAEteEffectuePar(QList<aEteEffectueePar> &_ListeaEteEffectueePar);
    void RecupererAEteScannePar(QList<aEteScannePar> &_ListeaEteScannePar);
    void RecupererPhoto(QList<Photo> &_ListePhoto);

    //Transferer les données de la BDD MySQL -> BDD SQLite
    void TransfererRonde(Ronde laRonde);
    void TransfererPointeau(Pointeau lePointeau, Lieux unLieu);
    void TransfererAgent(Agent unAgent);
    void TransfererLieu(Lieux unLieu);
    void TransfererAnomalie1(int IdAnomalie, QString descriptionAnomalie);
    void TransfererPeutFaire(peutFaire unPeutFaire);
    void TransfererComporte(Comporte unComporte);
    void TransfereraEteEffectueePar(aEteEffectueePar unaEteEffectueePar);

    void FermerBDD();

private:
    QSqlDatabase bddSqlite; //Bdd SQLite

};

#endif // ACCESSQLITE_H
