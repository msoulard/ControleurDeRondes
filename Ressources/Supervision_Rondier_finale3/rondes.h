/**
   @file rondes.h
 * @brief The rondes class
 * @details Déclaration des méthodes de la classe Rondes
 * @authors Letessier Yoann
 * @date 25/05/2021
 */
#ifndef RONDES_H
#define RONDES_H

#include <QString>
#include <QList>
#include <QDebug>

#include "pointeaux.h"
#include "tempspointage.h"

class Rondes
{
public:
    //Constructeur - Destructeur
    Rondes(QString _nom, QList<Pointeaux *> _listePointeaux, QList<TempsPointage *> _listeTempsPointage, bool _statut, int _idRonde);
    Rondes(Rondes *modelRonde);
    //Rondes(QString _nom, QList<Pointeaux*> _listePointeaux, QList<TempsPointage *> _listeTempsPointage, bool _statut, int _idRonde = -1);

    //Méthodes
    void ajouterPointeau(Pointeaux *nvPointeau, int idListPointeau);
    void retierPointeau(int idListPointeau);
    void changerOrdrePointeau(int idListPointeau, int nvIdListPointeau);

    // Getters - Setters
    QString ObtenirNom();
    void DefinirNom(const QString &_nom);

    void changerTempsPointage(int idListeTemps, TempsPointage nvTemps);

    bool RondeIdentique(Rondes rondeAVerifier);

    int ObtenirIdRonde();
    void DefinirIdRonde(int _idRonde);

    QList<Pointeaux *> ObtenirListePointeaux() const;
    void DefinirListePointeaux(const QList<Pointeaux *> &_listePointeaux);

    QList<TempsPointage *> ObtenirListeTempsPointage() const;
    void DefinirListeTempsPointage(const QList<TempsPointage *> &_listeTemps);

    ///------------------PRIVATE------------------///

private:
    //Attributs
    QString nom;                                    //Nom de la ronde.
    QList<Pointeaux*> listePointeaux;                //Liste des pointeaux dans la ronde dans l'ordre du déroulement.
    QList<TempsPointage*> listeTempsPointage;       //Liste des temps de pointages dans l'ordre du déroulement.
    int idRonde;                                    //Id de la ronde dans la base de données.
    bool statut;
};

#endif // RONDES_H
