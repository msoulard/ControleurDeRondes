#include "agent.h"

Agent::Agent(QObject *parent) :
    QObject(parent)
{

}

QString Agent::obtenirPrenomNom()
{
       return prenom + " " + nom;
}

QString Agent::getNom() const
{
    return nom;
}

void Agent::setNom(const QString &value)
{
    nom = value;
}

QString Agent::getPrenom() const
{
    return prenom;
}

void Agent::setPrenom(const QString &value)
{
    prenom = value;
}

int Agent::getId() const
{
    return id;
}

void Agent::setId(int value)
{
    id = value;
}

QString Agent::getNumBadge() const
{
    return numBadge;
}

void Agent::setNumBadge(const QString &value)
{
    numBadge = value;
}
