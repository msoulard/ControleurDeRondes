/**
   @file accesmysql.h
 * @brief The AccesMySQL class
 * @details Déclaration de la classe AccesMySQL
 * @authors Letessier Yoann
 * @date 25/05/2021
 */

#ifndef ACCESMYSQL_H
#define ACCESMYSQL_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QList>
#include <QDebug>
#include <QDateTime>

#include "agents.h"
#include "pointeaux.h"
#include "rondes.h"
#include "lieu.h"
#include "associationagentsrondes.h"
#include "tempspointage.h"
#include "message.h"

struct Smartphone
{
    QString nom;
    QString idADB;
};

typedef struct
{
    QString nom;
    int id;

    int idAgent;
    QString nomAgent;
    QString prenomAgent;
    QString numBadgeAgent;
}Agent;

typedef struct
{
    QString nom;
    int id;

    int idRonde;
    QString NomRonde;
}Ronde;

typedef struct
{
    QString nomRonde;
    QDateTime dateHeure;
    int nbAnomalie;
    int idRonde;
    Agent NomPrenomAgent;

}DonneesHistorique;

//typedef struct
//{

//}Agent;

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
    QString designation;
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
    int id;
    int nbAnomalie;
}Anomalie;

typedef struct
{
    int idPhoto;
    QString chemin;
    int idAnomalieFK;
}Photo;

//typedef struct
//{
//    QString batiment;
//    QString etage;
//    QString emplacement;

//}Lieux;
typedef struct
{
    int ordre;
    QDateTime dateHeure;
    Lieux lieuRonde;
    int idAnomalie;
    int idPhoto;
    QString cheminImage;
    QString description;

}DonneesChronologieAnomalie;

class AccesMySQL
{
public:
    AccesMySQL();
    //Connection bdd
    bool Connexion(QString adresse, int port, QString nomBDD, QString utilisateur, QString mdp);
    bool VerifierConnexion();
    //Responsable
    bool VerifierResponsable(QString identifiant, QString mdp);

    int RecupererAgents(QList<Agent> &_ListeAgents);
    int RecupererRonde(QList<Ronde> &_ListeRonde,int idAgent);

    QString RecupererDescription(int idAnomalie);
    QStringList RecupererCheminsImages(int idAnomalie);

    void RecupererDonneeTableauHistoriqueNiveau1(int idAgent, int idRonde,QDateTime dateDebut,QDateTime dateFin, QList<DonneesHistorique> &_ListeHistorique);
    void RecupererTableauNiveauDeux(QList<DonneesChronologieAnomalie> &_ListeChronologieAnomalie, int idHistoriqueRonde, QList<Anomalie> &_historiqueAnomalie);
    void RecupererTabAnomalie(QList<DonneesChronologieAnomalie> &_ListeChronologieAnomalie, int idHistoriqueRonde);

    //Tags
    int AjouterTag(QString numBadge);
    bool SupprimerTag(QString tag);

    //Agents
    QList<Agents*> ObtenirAgents();
    bool AjouterAgent(QString nom, QString prenom, QString badge, bool statut);
    bool ModifierAgent(QString nom, QString prenom, QString badge, int statut, int id);
    int ObtenirIdAgent(QString nom, QString prenom, QString badge, bool statut);
    QList<QString> ObtenirNomAgents(/*QList<QString> listeNomAgents, QList<int> id*/);

    //Pointeaux
    QList<Pointeaux *> ObtenirPointeaux();
    bool AjouterPointeau(Pointeaux *nvPointeau);
    int ModifierPointeau(Pointeaux *modifPointeau);

    //Rondes
    QList<Rondes *> ObtenirRondes();
    Rondes *ObtenirRonde(int idRonde);
    bool AjouterRonde(Rondes *nvRonde);
    int ModifierRonde(Rondes *modifRonde);

    //Lieux
    QList<Lieu *> ObtenirLieux();
    bool AjouterLieux(QString batiment, QString etage, QString emplacement);
    int ModifierLieu(QString batiment, QString etage, QString emplacement);

    //Synchronisation
    int ObtenirNumeroMaxRondeHP();
    bool AjouterHistoriquePointeau(int idEnregistrement, QString nomAgent, QString nomRonde, QString nomPointeau, QString date, int ordrePointeau, int numeroRonde, bool anomalieOrdre, bool anomalieTemps);
    int ObtenirIdHPMax();
    bool AjouterMainCourante(int idEnregistrement, QString texte, int idHistoriquePointeau, QString date, int type);
    QList<AssociationAgentsRondes *> ObtenirAssociationsAR();

    //Filtres
    bool RequeteFiltresAgents();
    bool AppliquerFiltresAgents(QString nom, bool statut, QString badge, QList<Agents *> &listeAgents);
    bool AppliquerFiltresStatutAgents(bool statut, QList<Agents *> &listeAgents);
    bool AppliquerFiltresNomAgents(QString nom, QList<Agents *> &listeAgents);
    bool AppliquerFiltresBadgeAgents(QString badge, QList<Agents *> &listeAgents);
    bool AppliquerFiltresStatutBadgeAgents(bool statut, QString badge, QList<Agents *> &listeAgents);

    //Damien

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
    QSqlDatabase mySqlBdd;
    //QSqlQuery requete;
    //Message boiteMessage;
};

#endif // ACCESMYSQL_H
