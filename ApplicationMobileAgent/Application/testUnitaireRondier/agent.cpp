/**
  @file agent.cpp
  @brief Implémentation de la classe Agent
  @author Maëva Soulard
  @date 26/03/2021
*/

#include "agent.h"

/**
 * @brief Agent::Agent
 * @param parent
 * @details Constructeur de la classe
 */
Agent::Agent( QObject *parent) :
    QObject(parent)
{

}

/**
 * @brief Agent::obtenirNomAgent
 * @param _numBadge
 * @return
 * @details Méthode qui permet de mettre à jour la structure S_Agent et d'obtenir le prénom et le nom de l'agent
 */
QString Agent::obtenirNomAgent(QString _numBadge)
{
    AccesBdd bdd;
    agent = bdd.obtenirAgent(_numBadge);
    QString prenomNom = agent.prenom + " " + agent.nom;
    return prenomNom;
}

