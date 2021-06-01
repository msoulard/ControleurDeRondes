#ifndef ACCESBDD_H
#define ACCESBDD_H

#include <QObject>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>

#include "agent.h"
#include "ronde.h"
#include "pointeau.h"

class AccesBdd : public QObject
{
    Q_OBJECT
public:
    explicit AccesBdd(QObject *parent = nullptr);
    bool connexion(QString _emplacementFichier);
    //méthodes pour récupérer les données de la base de données
    bool obtenirAgent(QString _numBadge, Agent &_agent);
    bool obtenirListeRondes(QList<Ronde*> &_listeRondes, int _idAgent);
    bool obtenirListePointeaux(QList<Pointeau*> &_listePointeaux,int _idRonde);
    //méthodes pour mettre à jour la base de données
    int mettreAJourTableAEteEffectueePar(int _idAgent, int _idRonde, QDateTime _horodatage);
    int mettreAJourTableAEteScanneParSansAnomalie(int _idHistoriqueRonde, int _idPointeau, int _ordre, QDateTime _horodatage);
    bool mettreAJourTableAEteScanneParAvecAnomalie(int _idAnomalie, int _idHistoriquePointeau);
    bool mettreAJourTableAEteScanneParDefautOrdreEtPointeauIgnore(int _idAnomalie, int _idHistoriqueRonde, int _idPointeau, int _ordre, QDateTime _horodatage);
    int mettreAJourTableAnomalies(QString _description);

signals:
private:
    QSqlDatabase db;

};

#endif // ACCESBDD_H
