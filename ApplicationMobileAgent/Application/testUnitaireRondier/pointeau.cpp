/**
  @file pointeau.cpp
  @brief Implémentation de la classe Pointeau
  @details Classe permettant de gérer un pointeau
  @author Maëva Soulard
  @date 26/03/2021
*/

#include "pointeau.h"

/**
 * @brief Pointeau::Pointeau
 * @param parent
 * @details Constructeur de la classe
 */
Pointeau::Pointeau(QObject *parent) : QObject(parent)
{

}

/**
 * @brief Pointeau::horodater
 * @details Méthode qui permet d'horodater un pointeau
 */
void Pointeau::horodater()
{
    horodatage = QDateTime::currentDateTime();
    qDebug() << horodatage;
}

/**
 * @brief Pointeau::getDesignation
 * @return
 * @details Méthode qui permet de retourner la désignation d'un pointeau
 */
QString Pointeau::getDesignation() const
{
    return designation;
}

/**
 * @brief Pointeau::setDesignation
 * @param value
 * @details Méthode qui permet de mettre à jour la désignation d'un pointeau
 */
void Pointeau::setDesignation(const QString &value)
{
    designation = value;
}

/**
 * @brief Pointeau::getCouleur
 * @return
 * @details Méthode qui permet de retourner la couleur d'un pointeau
 */
QString Pointeau::getCouleur() const
{
    return couleur;
}

/**
 * @brief Pointeau::setCouleur
 * @param value
 * @details Méthode qui permet de mettre à jour la couleur d'un pointeau
 */
void Pointeau::setCouleur(const QString &value)
{
    couleur = value;
}

/**
 * @brief Pointeau::getIdPointeau
 * @return
 * @details Méthode qui permet de retourner l'id d'un pointeau
 */
int Pointeau::getIdPointeau() const
{
    return idPointeau;
}

/**
 * @brief Pointeau::setIdPointeau
 * @param value
 * @details Méthode qui permet de mettre à jour l'id d'un pointeau
 */
void Pointeau::setIdPointeau(int value)
{
    idPointeau = value;
}

/**
 * @brief Pointeau::getTagMifare
 * @return
 * @details Méthode qui permet de retourner le tag MIFARE d'un pointeau
 */
QString Pointeau::getTagMifare() const
{
    return tagMifare;
}

/**
 * @brief Pointeau::setTagMifare
 * @param value
 * @details Méthode qui permet de mettre à jour le tag MIFARE d'un pointeau
 */
void Pointeau::setTagMifare(const QString &value)
{
    tagMifare = value;
}

/**
 * @brief Pointeau::getBatiment
 * @return
 * @details Méthode qui permet de retourner le bâtiment d'un pointeau
 */
QString Pointeau::getBatiment() const
{
    return batiment;
}

/**
 * @brief Pointeau::setBatiment
 * @param value
 * @details Méthode qui permet de mettre à jour le bâtiment d'un pointeau
 */
void Pointeau::setBatiment(const QString &value)
{
    batiment = value;
}

/**
 * @brief Pointeau::getEtage
 * @return
 * @details Méthode qui permet de retourner l'étage d'un pointeau
 */
QString Pointeau::getEtage() const
{
    return etage;
}

/**
 * @brief Pointeau::setEtage
 * @param value
 * @details Méthode qui permet de mettre à jour l'étage d'un pointeau
 */
void Pointeau::setEtage(const QString &value)
{
    etage = value;
}

/**
 * @brief Pointeau::getEmplacement
 * @return
 * @details Méthode qui permet de retourner l'emplacement d'un pointeau
 */
QString Pointeau::getEmplacement() const
{
    return emplacement;
}

/**
 * @brief Pointeau::setEmplacement
 * @param value
 * @details Méthode qui permet de mettre à jour l'emplacement d'un pointeau
 */
void Pointeau::setEmplacement(const QString &value)
{
    emplacement = value;
}

/**
 * @brief Pointeau::getOrdre
 * @return
 */
int Pointeau::getOrdre() const
{
    return ordre;
}

/**
 * @brief Pointeau::setOrdre
 * @param value
 */
void Pointeau::setOrdre(int value)
{
    ordre = value;
}

/**
 * @brief Pointeau::getTempsMini
 * @return
 */
QString Pointeau::getTempsMini() const
{
    return tempsMini;
}

/**
 * @brief Pointeau::setTempsMini
 * @param value
 */
void Pointeau::setTempsMini(const QString &value)
{
    tempsMini = value;
}

/**
 * @brief Pointeau::getTempsMaxi
 * @return
 */
QString Pointeau::getTempsMaxi() const
{
    return tempsMaxi;
}

/**
 * @brief Pointeau::setTempsMaxi
 * @param value
 */
void Pointeau::setTempsMaxi(const QString &value)
{
    tempsMaxi = value;
}

