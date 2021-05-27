/**
   @file AccesMySQL.h
 * @brief Déclaration de la classe AccesMySQL
 * @version 1.0
 * @author Damien CABARET
 * @date 03/04/2021
 */

#ifndef ACCESMYSQL_H
#define ACCESMYSQL_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

typedef struct
{
    int idRonde;
    QString NomRonde;
}Ronde;

typedef struct
{
    int idAgent;
    QString nomAgent;
    QString prenomAgent;
    QString numBadgeAgent;
}Agent;

typedef struct
{
    int idPointeau;
    QString designation;
    QString tagMifare;

    int idLieu;
    QString batiment;
    QString etage;
    QString emplacement;
    int idPointeauLieu;
}Pointeau;

typedef struct
{
    int idPeutFaire;
    int idAgent;
    int idRonde;
}peutFaire;

typedef struct
{
    int idLieu;
    QString batiment;
    QString etage;
    QString emplacement;
    int idPointeauLieu;
}Lieux;

typedef struct
{
    int idComporte;
    int idRonde;
    int idPointeau;
    int ordre;
    QString tempsMini;
    QString tempsMaxi;
}Comporte;

typedef struct
{
    int idHistoriqueRonde;
    int idRonde;
    int idAgent;
    QString dateHeure;
}aEteEffectueePar;

typedef struct
{
    int idScanne;
    int idPointeau;
    int idAnomalie;
    int ordre;
    QString dateHeure;
    int idHistoriqueRonde;
}aEteScannePar;

typedef struct
{
    int idAnomalie;
    QString description;
}Anomalie;

typedef struct
{
    int idPhoto;
    QString chemin;
    int idAnomalieFK;
}Photo;

class AccesMySQL
{
public:
    AccesMySQL();
    //Connection
    bool ConnexionMysql();

    //Transferer données vers la BDD SQL
    void TransfererRondes(int idRonde, int idAgent, QString dateHeure);
    void TransfererPointeaux(int idPointeau, int idAgent, int idRonde, int idAnomalie, int ordre, QString temps);
    void TransfererAnomalie(Anomalie anomalieScannee);
    void TransfererPhoto(Photo photoAnomalie);
    void TransfereraEteEffectueePar(aEteEffectueePar rondeEffectuee);
    void TransfereraEteScannePar(aEteScannePar pointeauScanne);

    //Récuperer les données dans la BDD SQL
    void RecupererRonde(QList<Ronde> &_ListeRonde);
    void RecupererAgent(QList<Agent> &_ListeAgent);
    void RecupererPointeaux(QList<Pointeau> &_ListePointeau);
    void RecupererPeutFaire(QList<peutFaire> &_ListePeutFaire);
    void RecupererLieux(QList<Lieux> &_ListeLieu);
    void RecupererComporte(QList<Comporte> &_ListeComporte);
    void RecupererAnomalie1(QString &_description);
    void RecupereraEteEffectueePar(QList<aEteEffectueePar> &_ListeaEteEffectueePar);

    void FermerBDD();

private:
    QSqlDatabase bddMysql; //Bdd MYSQL
};

#endif // ACCESMYSQL_H
