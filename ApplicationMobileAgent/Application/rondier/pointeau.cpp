/**
 * @file pointeau.cpp
 * @brief Implémentation de la classe Pointeau
 * @details Classe permettant l'accès aux attributs d'un pointeau
 * @author Maëva Soulard
 * @date 28/05/2021
 */

#include "pointeau.h"

/**
 * @brief Pointeau::Pointeau
 * @param parent
 * @details Constructeur de la classe Pointeau
 */
Pointeau::Pointeau(QObject *parent) : QObject(parent)
{

}

/**
 * @brief Pointeau::horodater
 * @details Méthode permettant d'horodater un pointeau
 */
void Pointeau::horodater()
{
    horodatage = QDateTime::currentDateTime();
    qDebug() << horodatage;
}

/**
 * @brief Pointeau::getCouleur
 * @return
 * @details Méthode permettant de récupérer la couleur du pointeau
 */
QString Pointeau::getCouleur() const
{
    return couleur;
}

/**
 * @brief Pointeau::setCouleur
 * @param value
 * @details Méthode permettant de changer la couleur du pointeau
 */
void Pointeau::setCouleur(const QString &value)
{
    couleur = value;
}

/**
 * @brief Pointeau::getIdPointeau
 * @return
 * @details Méthode permettant de récupérer l'id du pointeau
 */
int Pointeau::getIdPointeau() const
{
    return idPointeau;
}

/**
 * @brief Pointeau::setIdPointeau
 * @param value
 * @details Méthode permettant de changer l'id du pointeau
 */
void Pointeau::setIdPointeau(int value)
{
    idPointeau = value;
}

/**
 * @brief Pointeau::getDesignation
 * @return
 * @details Méthode permettant de récupérer la désignation du pointeau
 */
QString Pointeau::getDesignation() const
{
    return designation;
}

/**
 * @brief Pointeau::setDesignation
 * @param value
 * @details Méthode permettant de changer la désignation du pointeau
 */
void Pointeau::setDesignation(const QString &value)
{
    designation = value;
}

/**
 * @brief Pointeau::getTagMifare
 * @return
 * @details Méthode permettant de récupérer la tag MIFARE du pointeau
 */
QString Pointeau::getTagMifare() const
{
    return tagMifare;
}

/**
 * @brief Pointeau::setTagMifare
 * @param value
 * @details Méthode permettant de changer le tag MIFARE du pointeau
 */
void Pointeau::setTagMifare(const QString &value)
{
    tagMifare = value;
}

/**
 * @brief Pointeau::getBatiment
 * @return
 * @details Méthode permettant de récupérer le batiment du pointeau
 */
QString Pointeau::getBatiment() const
{
    return batiment;
}

/**
 * @brief Pointeau::setBatiment
 * @param value
 * @details Méthode permettant de changer le batiment du pointeau
 */
void Pointeau::setBatiment(const QString &value)
{
    batiment = value;
}

/**
 * @brief Pointeau::getEtage
 * @return
 * @details Méthode permettant de récupérer l'étage du pointeau
 */
QString Pointeau::getEtage() const
{
    return etage;
}

/**
 * @brief Pointeau::setEtage
 * @param value
 * @details Méthode permettant de changer l'étage du pointeau
 */
void Pointeau::setEtage(const QString &value)
{
    etage = value;
}

/**
 * @brief Pointeau::getEmplacement
 * @return
 * @details Méthode permettant de récupérer l'emplacement du pointeau
 */
QString Pointeau::getEmplacement() const
{
    return emplacement;
}

/**
 * @brief Pointeau::setEmplacement
 * @param value
 * @details Méthode permettant de changer l'emplacement du pointeau
 */
void Pointeau::setEmplacement(const QString &value)
{
    emplacement = value;
}

/**
 * @brief Pointeau::getOrdre
 * @return
 * @details Méthode permettant de récupérer l'ordre du pointeau
 */
int Pointeau::getOrdre() const
{
    return ordre;
}

/**
 * @brief Pointeau::setOrdre
 * @param value
 * @details Méthode permettant de changer l'ordre du pointeau
 */
void Pointeau::setOrdre(int value)
{
    ordre = value;
}

/**
 * @brief Pointeau::getTempsMini
 * @return
 * @details Méthode permettant de récupérer le temps minimum du pointeau
 */
QString Pointeau::getTempsMini() const
{
    return tempsMini;
}

/**
 * @brief Pointeau::setTempsMini
 * @param value
 * @details Méthode permettant de changer le temps minimum du pointeau
 */
void Pointeau::setTempsMini(const QString &value)
{
    tempsMini = value;
}

/**
 * @brief Pointeau::getTempsMaxi
 * @return
 * @details Méthode permettant de récupérer le temps maximum du pointeau
 */
QString Pointeau::getTempsMaxi() const
{
    return tempsMaxi;
}

/**
 * @brief Pointeau::setTempsMaxi
 * @param value
 * @details Méthode permettant de changer le temps maximum du pointeau
 */
void Pointeau::setTempsMaxi(const QString &value)
{
    tempsMaxi = value;
}

/**
 * @brief Pointeau::getHorodatage
 * @return
 * @details Méthode permettant de récupérer l'horodatage du pointeau
 */
QDateTime Pointeau::getHorodatage() const
{
    return horodatage;
}

/**
 * @brief Pointeau::setHorodatage
 * @param value
 * @details Méthode permettant de changer l'horodatage du pointeau
 */
void Pointeau::setHorodatage(const QDateTime &value)
{
    horodatage = value;
}
