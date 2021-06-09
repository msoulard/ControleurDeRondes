/**
   @file associationagentsrondes.cpp
 * @brief The AssociationAgentsRondes class
 * @details Déclaration des méthodes de la classe AssociationAgentsRondes
 * @authors Letessier Yoann
 * @date 25/05/2021
 */

#include "associationagentsrondes.h"

/**
 * @brief AssociationAgentsRondes::AssociationAgentsRondes
 * @param _idAgent
 * @param _idRonde
 */
AssociationAgentsRondes::AssociationAgentsRondes(int _idAgent, int _idRonde) :
    idAgent(_idAgent),
    idRonde(_idRonde)
{

}

/**
 * @brief AssociationAgentsRondes::ObtenirIdAgent
 * @return
 */
int AssociationAgentsRondes::ObtenirIdAgent()
{
    return idAgent;
}

/**
 * @brief AssociationAgentsRondes::ObtenirIdRonde
 * @return
 */
int AssociationAgentsRondes::ObtenirIdRonde()
{
    return idRonde;
}

/**
 * @brief AssociationAgentsRondes::DefinirIdAgent
 * @param _idAgent
 */
void AssociationAgentsRondes::DefinirIdAgent(int _idAgent)
{
    idAgent = _idAgent;
}

/**
 * @brief AssociationAgentsRondes::DefinirIdRonde
 * @param _idRonde
 */
void AssociationAgentsRondes::DefinirIdRonde(int _idRonde)
{
    idRonde = _idRonde;
}
