/**
 * @file agent.cpp
 * @brief Implémentation de la classe Agent
 * @details Classe permettant l'accès aux attributs d'un agent
 * @author Maëva Soulard
 * @date 28/05/2021
 */

#include "agent.h"

/**
 * @brief Agent::Agent
 * @param parent
 * @details Constructeur de la classe Agent
 */
Agent::Agent(QObject *parent) :
    QObject(parent)
{

}

/**
 * @brief Agent::obtenirPrenomNom
 * @return
 * @details Méthode permettant de récupérer le prénom et le nom de l'agent
 */
QString Agent::obtenirPrenomNom()
{
       return prenom + " " + nom;
}

/**
 * @brief Agent::getNom
 * @return
 * @details Méthode permmettant de récupérer le nom de l'agent
 */
QString Agent::getNom() const
{
    return nom;
}

/**
 * @brief Agent::setNom
 * @param value
 * @details Méthode permettant de changer le nom de l'agent
 */
void Agent::setNom(const QString &value)
{
    nom = value;
}

/**
 * @brief Agent::getPrenom
 * @return
 * @details Méthode permettant de récupérer le prénom de l'agent
 */
QString Agent::getPrenom() const
{
    return prenom;
}

/**
 * @brief Agent::setPrenom
 * @param value
 * @details Méthode permettant de changer le prénom de l'agent
 */
void Agent::setPrenom(const QString &value)
{
    prenom = value;
}

/**
 * @brief Agent::getId
 * @return
 * @details Méthode permettant de récupérer l'id de l'agent
 */
int Agent::getId() const
{
    return id;
}

/**
 * @brief Agent::setId
 * @param value
 * @details Méthode permettant de changer l'id de l'agent
 */
void Agent::setId(int value)
{
    id = value;
}

/**
 * @brief Agent::getNumBadge
 * @return
 * @details Méthode permettant de récupérer le numéro du badge de l'agent
 */
QString Agent::getNumBadge() const
{
    return numBadge;
}

/**
 * @brief Agent::setNumBadge
 * @param value
 * @details Méthode permettant de changer le numéro du badge de l'agent
 */
void Agent::setNumBadge(const QString &value)
{
    numBadge = value;
}
