#ifndef RONDIER_H
#define RONDIER_H

#include <QObject>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QList>
#include <QDebug>

#include "accesbdd.h"
#include "agent.h"
#include "ronde.h"
#include "lecteurnfc.h"

class Rondier : public QObject
{
    Q_OBJECT
public:
    explicit Rondier(QQmlApplicationEngine &_engine, QObject *parent = nullptr);
    ~Rondier();
    //méthodes permettant de récupérer les données dans la base de données
    Q_INVOKABLE void mettreAJourAgent(QString _numBadge);
    Q_INVOKABLE QStringList obtenirRondes();
    Q_INVOKABLE QString obtenirNomRondeCourante(int _index);
    Q_INVOKABLE void mettreAJourListePointeaux();
    Q_INVOKABLE QStringList obtenirListeDesignations();
    Q_INVOKABLE QStringList obtenirListeBatiments();
    Q_INVOKABLE QStringList obtenirListeEtages();
    Q_INVOKABLE QStringList obtenirListeTempsMini();
    Q_INVOKABLE QStringList obtenirListeTempsMaxi();
    Q_INVOKABLE QStringList obtenirListeTags();
    Q_INVOKABLE QStringList obtenirListeEmplacements();
    //méthodes permettant de mettre à jour la base de données
    Q_INVOKABLE void mettreAJourTableAEteEffectueeParBDD(int _index);
    Q_INVOKABLE void mettreAJourTableAEteScanneParSansAnomalieBDD(int _index);
    Q_INVOKABLE void mettreAJourTablesAEteScanneParAvecAnomalieEtAnomaliesBDD(QString _description);
    Q_INVOKABLE void mettreAJourTableAEteScanneParDefautOrdreEtPointeauIgnoreBDD(int _index, int _idAnomalie, QString _description = "");

signals:
private:
    QQmlApplicationEngine &engine;
    AccesBdd bdd;
    LecteurNFC leLecteur;
    Agent agent;
    QList<Ronde*> listeRondes;
    QList<Pointeau*> listePointeaux;
    Ronde *rondeCourante;
    int idHistoriqueRonde;
    int idHistoriquePointeau;
    int ordre;
};

#endif // RONDIER_H
