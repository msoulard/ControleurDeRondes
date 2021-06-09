/**
   @file rondes.cpp
 * @brief The rondes class
 * @details Déclaration de la classe Rondes
 * @authors Letessier Yoann
 * @date 25/05/2021
 */

#include "rondes.h"

/**
 * @brief Rondes::Rondes
 * @param _nom
 * @param _listePointeaux
 * @param _listeTempsPointage
 * @param _statut
 * @param _idRonde
 */
Rondes::Rondes(QString _nom, QList<Pointeaux*> _listePointeaux, QList<TempsPointage *> _listeTempsPointage, bool _statut, int _idRonde ):
    nom(_nom),
    listePointeaux(_listePointeaux),
    listeTempsPointage(_listeTempsPointage),
    statut(_statut),
    idRonde(_idRonde)
{

}

/**
 * @brief Rondes::ObtenirNom
 * @return
 */
QString Rondes::ObtenirNom()
{
    return nom;
}

/**
 * @brief Rondes::DefinirNom
 * @param _nom
 */
void Rondes::DefinirNom(const QString &_nom)
{
    nom = _nom;
}

/**
 * @brief Rondes::ObtenirIdRonde
 * @return
 */
int Rondes::ObtenirIdRonde()
{
    return idRonde;
}

/**
 * @brief Rondes::DefinirIdRonde
 * @param _idRonde
 */
void Rondes::DefinirIdRonde(int _idRonde)
{
    idRonde = _idRonde;
}

QList<Pointeaux *> Rondes::ObtenirListePointeaux() const
{
    return listePointeaux;
}

QList<TempsPointage *> Rondes::ObtenirListeTempsPointage() const
{
    return listeTempsPointage;
}
