/**
   @file agents.cpp
 * @brief The Agents class
 * @details Déclaration des méthodes de la classe Agents
 * @authors  Gabriel Lemée et Letessier Yoann
 * @date 25/05/2021
 */
#include "agents.h"

/**
 * @brief Agents::Agents
 * @param _idAgent
 * @param _nom
 * @param _prenom
 * @param _badge
 * @param _statut
 */
Agents::Agents(QString _idAgent, QString _nom, QString _prenom, QString _badge, bool _statut):
    nom(_nom),
    prenom(_prenom),
    badge(_badge),
    statut(_statut),
    idAgent(_idAgent)
{

}

/**
 * @brief Agents::ObtenirNom
 * @return
 */
QString Agents::ObtenirNom()
{
    return nom;
}

/**
 * @brief Agents::DefinirNom
 * @param _nom
 */
void Agents::DefinirNom(QString _nom)
{
    nom = _nom;
}

/**
 * @brief Agents::ObtenirPrenom
 * @return
 */
QString Agents::ObtenirPrenom()
{
    return  prenom;
}

/**
 * @brief Agents::DefinirPrenom
 * @param _prenom
 */
void Agents::DefinirPrenom(QString _prenom)
{
    prenom = _prenom;
}

/**
 * @brief Agents::ObtenirBadge
 * @return
 */
QString Agents::ObtenirBadge()
{
    return badge;
}

/**
 * @brief Agents::DefinirBadge
 * @param _badge
 */
void Agents::DefinirBadge(QString _badge)
{
    badge = _badge;
}

/**
 * @brief Agents::ObtenirStatut
 * @return
 */
QString Agents::ObtenirStatut()
{
    return (statut?"inactif":"actif");
}

/**
 * @brief Agents::DefinirStatut
 * @param _statut
 */
void Agents::DefinirStatut(bool _statut)
{
    statut = _statut;
}

/**
 * @brief Agents::ObtenirIdAgent
 * @return
 */
QString Agents::ObtenirIdAgent()
{
    return idAgent;
}

/**
 * @brief Agents::DefinirIdAgent
 * @param _idAgent
 */
void Agents::DefinirIdAgent(int _idAgent)
{
    idAgent = _idAgent;
}
