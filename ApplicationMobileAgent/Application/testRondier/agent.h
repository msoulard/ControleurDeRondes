#ifndef AGENT_H
#define AGENT_H

#include <QObject>

#include "accesbdd.h"

struct S_Agent
{
    QString nom;
    QString prenom;
    int id;
    QString numBadge;
};

class Agent : public QObject
{
    Q_OBJECT
public:
    explicit Agent(QObject *parent = nullptr);
     Q_INVOKABLE QString obtenirNomAgent(QString _numBadge);
signals:

public:
    AccesBdd *bdd;
    QString nom;
    QString prenom;
    int id;
    QString numBadge;
};

#endif // AGENT_H
