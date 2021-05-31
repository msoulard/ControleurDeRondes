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
    bool obtenirAgent(QString _numBadge, Agent &_agent);
    bool obtenirListeRondes(QList<Ronde*> &_listeRondes, int _idAgent);
    bool obtenirListePointeaux(QList<Pointeau*> &_listePointeaux,int _idRonde);

signals:
private:
    QSqlDatabase db;

};

#endif // ACCESBDD_H
