#include "pointeau.h"

/**
 * @brief Pointeau::Pointeau
 * @param parent
 */
Pointeau::Pointeau(QObject *parent) : QObject(parent)
{

}

/**
 * @brief Pointeau::horodater
 */
void Pointeau::horodater()
{
    horodatage = QDateTime::currentDateTime();
    qDebug() << horodatage;
}

/**
 * @brief Pointeau::getDesignation
 * @return
 */
QString Pointeau::getDesignation() const
{
    return designation;
}

/**
 * @brief Pointeau::setDesignation
 * @param value
 */
void Pointeau::setDesignation(const QString &value)
{
    designation = value;
}

/**
 * @brief Pointeau::getCouleur
 * @return
 */
QString Pointeau::getCouleur() const
{
    return couleur;
}

/**
 * @brief Pointeau::setCouleur
 * @param value
 */
void Pointeau::setCouleur(const QString &value)
{
    couleur = value;
}

int Pointeau::getIdPointeau() const
{
    return idPointeau;
}

/**
 * @brief Pointeau::setIdPointeau
 * @param value
 */
void Pointeau::setIdPointeau(int value)
{
    idPointeau = value;
}

/**
 * @brief Pointeau::getTagMifare
 * @return
 */
QString Pointeau::getTagMifare() const
{
    return tagMifare;
}

/**
 * @brief Pointeau::setTagMifare
 * @param value
 */
void Pointeau::setTagMifare(const QString &value)
{
    tagMifare = value;
}

/**
 * @brief Pointeau::getBatiment
 * @return
 */
QString Pointeau::getBatiment() const
{
    return batiment;
}

/**
 * @brief Pointeau::setBatiment
 * @param value
 */
void Pointeau::setBatiment(const QString &value)
{
    batiment = value;
}

/**
 * @brief Pointeau::getEtage
 * @return
 */
QString Pointeau::getEtage() const
{
    return etage;
}

/**
 * @brief Pointeau::setEtage
 * @param value
 */
void Pointeau::setEtage(const QString &value)
{
    etage = value;
}

/**
 * @brief Pointeau::getEmplacement
 * @return
 */
QString Pointeau::getEmplacement() const
{
    return emplacement;
}

/**
 * @brief Pointeau::setEmplacement
 * @param value
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

