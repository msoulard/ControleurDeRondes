/**
   @file lieu.cpp
 * @brief The Lieu class
 * @details Déclaration de la classe Lieu
 * @authors Letessier Yoann
 * @date 25/05/2021
 */

#include "lieu.h"

Lieu::Lieu(QString _batiment, QString _etage, QString _emplacement, int _idPointeau, int _idlieu) :
    idLieu(_idlieu),
    batiment(_batiment),
    etage(_etage),
    emplacement(_emplacement),
    idPointeau(_idPointeau)
{

}

/**
 * @brief Lieu::ObtenirIdLieu
 * @return
 */
int Lieu::ObtenirIdLieu()
{
    return  idLieu;
}

/**
 * @brief Lieu::DefinirIdLieu
 * @param _idLieu
 */
void Lieu::DefinirIdLieu(int _idLieu)
{
    idLieu = _idLieu;
}

/**
 * @brief Lieu::ObtenirBatiment
 * @return
 */
QString Lieu::ObtenirBatiment()
{
    return batiment;
}

/**
 * @brief Lieu::DefinirBatiment
 * @param _batiment
 */
void Lieu::DefinirBatiment(int _batiment)
{
    batiment = _batiment;
}

/**
 * @brief Lieu::ObtenirEtage
 * @return
 */
QString Lieu::ObtenirEtage()
{
    return etage;
}
/**
 * @brief Lieu::DefinirEtage
 * @param _etage
 */
void Lieu::DefinirEtage(int _etage)
{
    etage = _etage;
}

/**
 * @brief Lieu::ObtenirEmplacement
 * @return
 */
QString Lieu::ObtenirEmplacement()
{
    return emplacement;
}

/**
 * @brief Lieu::DefinirEmplacement
 * @param _emplacement
 */
void Lieu::DefinirEmplacement(int _emplacement)
{
    emplacement = _emplacement;
}
