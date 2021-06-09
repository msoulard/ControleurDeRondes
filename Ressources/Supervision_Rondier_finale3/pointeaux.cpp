/**
   @file pointeaux.cpp
 * @brief The pointeaux class
 * @details Déclaration des méthodes de la classe Pointeaux
 * @authors Letessier Yoann
 * @date 25/05/2021
 */

#include "pointeaux.h"

Pointeaux::Pointeaux(int _ordre, QString _designation, bool _statut, QString _tag, QString _emplacement, int _idPointeau):
    designation(_designation),
    statut(_statut),
    tag(_tag),
    ordre(_ordre),
    idPointeau(_idPointeau),
    emplacement(_emplacement)
{

}

/**
 * @brief Pointeaux::ObtenirIdPointeau
 * @return
 */
int Pointeaux::ObtenirIdPointeau()
{
    return idPointeau;
}

/**
 * @brief Pointeaux::DefinirIdPointeau
 * @param _idPointeau
 */
void Pointeaux::DefinirIdPointeau(int _idPointeau)
{
    idPointeau = _idPointeau;
}

/**
 * @brief Pointeaux::ObtenirDesignation
 * @return
 */
QString Pointeaux::ObtenirDesignation()
{
    return designation;
}

/**
 * @brief Pointeaux::DefinirDesignation
 * @param _designation
 */
void Pointeaux::DefinirDesignation(QString _designation)
{
    designation = _designation;
}

/**
 * @brief Pointeaux::ObtenirStatut
 * @return
 */
QString Pointeaux::ObtenirStatut()
{
    return  (statut?"inactif":"actif");
}

void Pointeaux::DefinirStatut(bool _statut)
{
    statut = _statut;
}

/**
 * @brief Pointeaux::Obtenirtag
 * @return
 */
QString Pointeaux::Obtenirtag()
{
    return  tag;
}

void Pointeaux::Definirtag(QString _tag)
{
    tag = _tag;
}

/**
 * @brief Pointeaux::ObtenirEmplacement
 * @return
 */
QString Pointeaux::ObtenirEmplacement()
{
    return emplacement;
}

/**
 * @brief Pointeaux::DefinirEmplacement
 * @param _emplacement
 */
void Pointeaux::DefinirEmplacement(QString _emplacement)
{
    emplacement = _emplacement;
}

int Pointeaux::ObtenirOdre()
{
    return ordre;
}

void Pointeaux::DefinirOrdre(int _ordre)
{
    ordre = _ordre;
}
