#include "agent.h"

Agent::Agent( QObject *parent) :
    QObject(parent)
{

}

QString Agent::obtenirNomAgent(QString _numBadge)
{
    AccesBdd bdd;
    S_Agent unAgent;
    unAgent = bdd.obtenirAgent(_numBadge);
    QString prenomNom = unAgent.prenom + " " + unAgent.nom;
    return prenomNom;
}

