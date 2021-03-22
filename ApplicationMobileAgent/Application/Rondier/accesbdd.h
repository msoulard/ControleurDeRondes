/**
  @file accesbdd.h
  @brief The AccesBDD class
  @details Déclaration de la classe AccesBDD héritant de la classe QObject
  @author Maëva Soulard
  @date 19/03/2021
  */

#ifndef ACCESBDD_H
#define ACCESBDD_H

#include <QObject>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>

using namespace std;

class AccesBDD : public QObject
{
    Q_OBJECT
public:
    explicit AccesBDD(QObject *parent = nullptr);
    Q_INVOKABLE void ObtenirPointeaux(int _id_ronde);
    Q_INVOKABLE void ObtenirRondes(int _id_agent);
    Q_INVOKABLE void RecupererLePointeau(QString _tag_mifare);
    Q_INVOKABLE void VerificationBadge(int _numBadge);
    Q_INVOKABLE void MettreAJourBdd();
    Q_INVOKABLE void EnregistrerAnomalie(int _id_pointeau);

signals:

private :
    QSqlDatabase db;

};

#endif // ACCESBDD_H
