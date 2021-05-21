#include "agent.h"

/**
 * @brief Agent::Agent
 * @param parent
 */
Agent::Agent( QObject *parent) :
    QObject(parent)
{

}

/**
 * @brief Agent::obtenirNomAgent
 * @param _numBadge
 * @return
 */
QString Agent::obtenirNomAgent(QString _numBadge)
{
    AccesBdd bdd;
    S_Agent unAgent;
    unAgent = bdd.obtenirAgent(_numBadge);
    QString prenomNom = unAgent.prenom + " " + unAgent.nom;
    return prenomNom;
}

