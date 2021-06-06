/**
 * @file ronde.cpp
 * @brief Implémentation de la classe Ronde
 * @details Classe permettant l'accès aux attributs d'une ronde
 * @author Maëva Soulard
 * @date 28/05/2021
 */

#include "ronde.h"

/**
 * @brief Ronde::Ronde
 * @param parent
 * @details Constructeur de la classe Ronde
 */
Ronde::Ronde(QObject *parent) : QObject(parent)
{

}

/**
 * @brief Ronde::getId
 * @return
 * @details Méthode permettant de récupérer l'id de la ronde
 */
int Ronde::getId() const
{
    return id;
}

/**
 * @brief Ronde::setId
 * @param value
 * @details Méthode permettant de changer l'id de la ronde
 */
void Ronde::setId(int value)
{
    id = value;
}

/**
 * @brief Ronde::getNom
 * @return
 * @details Méthode permettant de récupérer le nom de la ronde
 */
QString Ronde::getNom() const
{
    return nom;
}

/**
 * @brief Ronde::setNom
 * @param value
 * @details Méthode permettant de changer le nom de la ronde
 */
void Ronde::setNom(const QString &value)
{
    nom = value;
}
