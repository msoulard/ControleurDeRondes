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



class Agent : public QObject
{
    Q_OBJECT
public:
    explicit Agent(AccesBdd &_bdd,QObject *parent = nullptr);
     Q_INVOKABLE QString obtenirNomAgent(QString _numBadge);
private:
    S_Agent agent;
    AccesBdd &bdd;
};

#endif // AGENT_H
