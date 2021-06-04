/**
 * @file ronde.cpp
 * @brief Implémentation de la classe Ronde
 * @details Classe permettant l'accès aux attributs d'une ronde
 * @author Maëva Soulard
 * @date 28/05/2021
 */

#include "ronde.h"

Ronde::Ronde(QObject *parent) : QObject(parent)
{

}

int Ronde::getId() const
{
    return id;
}

void Ronde::setId(int value)
{
    id = value;
}

QString Ronde::getNom() const
{
    return nom;
}

void Ronde::setNom(const QString &value)
{
    nom = value;
}
