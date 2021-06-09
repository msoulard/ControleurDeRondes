/**
   @file pointeaux.h
 * @brief The pointeaux class
 * @details Déclaration de la classe Pointeaux
 * @authors Letessier Yoann
 * @date 25/05/2021
 */
#ifndef POINTEAUX_H
#define POINTEAUX_H

#include <QString>

class Pointeaux
{
public:
    Pointeaux(int _ordre, QString _designation, bool _statut, QString _tag, QString _emplacement, int _idPointeau);

    int ObtenirIdPointeau();
    void DefinirIdPointeau(int _idPointeau);
    QString ObtenirDesignation();
    void DefinirDesignation(QString _designation);
    QString ObtenirStatut();
    void DefinirStatut(bool _statut);
    QString Obtenirtag();
    void Definirtag(QString _tag);
    QString ObtenirEmplacement();
    void DefinirEmplacement(QString _emplacement);
    int ObtenirOdre();
    void DefinirOrdre(int _ordre);

private:
    int idPointeau;
    QString designation;
    bool statut;
    QString tag;
    QString emplacement;
    int ordre;
};

#endif // POINTEAUX_H
