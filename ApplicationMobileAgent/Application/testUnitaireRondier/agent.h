/**
  @file agent.h
  @brief Déclaration de la classe Agent
  @author Maëva Soulard
  @date 26/03/2021
*/

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
private:
    S_Agent agent;
};

#endif // AGENT_H
