/**
  @file accesbdd.h
  @brief Déclaration de la classe AccesBdd
  @author Maëva Soulard
  @date 26/03/2021
*/

#ifndef ACCESBDD_H
#define ACCESBDD_H

#include <QObject>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>

class Ronde;
class Pointeau;

struct S_Agent
{
    QString nom;
    QString prenom;
    int id;
    QString numBadge;
};

class AccesBdd : public QObject
{
    Q_OBJECT
public:
    explicit AccesBdd(QObject *parent = nullptr);
    ~AccesBdd();
    void connectionBDD();
    S_Agent obtenirAgent(QString _numBadge);
    QList<Ronde*> obtenirListeRondes();
    QList<Pointeau*> obtenirListePointeaux(int _idRonde);
    Q_INVOKABLE QList<QObject*> obtenirListePointeauxQML();
    Q_INVOKABLE QList<QString> obtenirListeDesignationsPointeaux();
    Q_INVOKABLE QList<QString> obtenirListeNomsRondes();
    Q_INVOKABLE QList<QString> obtenirListeEmplacementPointeaux();
    Q_INVOKABLE QList<QString> obtenirListeTempsMiniPointeaux();
    Q_INVOKABLE QList<QString> obtenirListeTempsMaxiPointeaux();
    Q_INVOKABLE QList<QString> obtenirListeBatimentPointeaux();
    Q_INVOKABLE QList<QString> obtenirListeEtagePointeaux();
    Q_INVOKABLE QList<QString> obtenirListeTagPointeaux();
    Q_INVOKABLE void mettreAJourTableAEteEffectueePar();
    int obtenirIdAgent(QString _numBadge);

    Q_INVOKABLE QList<Ronde *> getListeRondes() const;
    void setListeRondes(const QList<Ronde *> &value);

signals:
private :
    QSqlDatabase db;
    QList<Ronde*> listeRondes;
    int idAgent;
};

#endif // ACCESBDD_H
