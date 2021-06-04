/**
 * @file pointeau.cpp
 * @brief Implémentation de la classe Pointeau
 * @details Classe permettant l'accès aux attributs d'un pointeau
 * @author Maëva Soulard
 * @date 28/05/2021
 */

#include "pointeau.h"

Pointeau::Pointeau(QObject *parent) : QObject(parent)
{

}

void Pointeau::horodater()
{
    horodatage = QDateTime::currentDateTime();
    qDebug() << horodatage;
}

QString Pointeau::getCouleur() const
{
    return couleur;
}

void Pointeau::setCouleur(const QString &value)
{
    couleur = value;
}

int Pointeau::getIdPointeau() const
{
    return idPointeau;
}

void Pointeau::setIdPointeau(int value)
{
    idPointeau = value;
}

QString Pointeau::getDesignation() const
{
    return designation;
}

void Pointeau::setDesignation(const QString &value)
{
    designation = value;
}

QString Pointeau::getTagMifare() const
{
    return tagMifare;
}

void Pointeau::setTagMifare(const QString &value)
{
    tagMifare = value;
}

QString Pointeau::getBatiment() const
{
    return batiment;
}

void Pointeau::setBatiment(const QString &value)
{
    batiment = value;
}

QString Pointeau::getEtage() const
{
    return etage;
}

void Pointeau::setEtage(const QString &value)
{
    etage = value;
}

QString Pointeau::getEmplacement() const
{
    return emplacement;
}

void Pointeau::setEmplacement(const QString &value)
{
    emplacement = value;
}

int Pointeau::getOrdre() const
{
    return ordre;
}

void Pointeau::setOrdre(int value)
{
    ordre = value;
}

QString Pointeau::getTempsMini() const
{
    return tempsMini;
}

void Pointeau::setTempsMini(const QString &value)
{
    tempsMini = value;
}

QString Pointeau::getTempsMaxi() const
{
    return tempsMaxi;
}

void Pointeau::setTempsMaxi(const QString &value)
{
    tempsMaxi = value;
}

QDateTime Pointeau::getHorodatage() const
{
    return horodatage;
}

void Pointeau::setHorodatage(const QDateTime &value)
{
    horodatage = value;
}
