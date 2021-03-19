/**
  @file pointeaux.cpp
  @details Définition et déclaration des méthodes de la classe Pointeaux
  @author Maëva Soulard
  @date 18/03/2021
  */

#include "pointeaux.h"

/**
 * @brief Pointeaux::Pointeaux
 * @param parent
 */
Pointeaux::Pointeaux(QObject *parent) : QObject(parent)
{

}

/**
 * @brief Pointeaux::horodater
 */
void Pointeaux::horodater()
{
    horodatage = QDateTime::currentDateTime();
    qDebug() << horodatage;
}

/**
 * @brief Pointeaux::getDesignation
 * @return
 */
QString Pointeaux::getDesignation() const
{
    return designation;
}

/**
 * @brief Pointeaux::setDesignation
 * @param value
 */
void Pointeaux::setDesignation(const QString &value)
{
    designation = value;
}

/**
 * @brief Pointeaux::getCouleur
 * @return
 */
QString Pointeaux::getCouleur() const
{
    return couleur;
}

/**
 * @brief Pointeaux::setCouleur
 * @param value
 */
void Pointeaux::setCouleur(const QString &value)
{
    couleur = value;
}
