/**
   @file lieu.h
 * @brief The Lieu class
 * @version 1.0
 * @details Déclaration de la classe Lieu héritant de la classe QWidget
 * @authors Letessier Yoann
 * @date 25/05/2021
 */

#ifndef LIEU_H
#define LIEU_H

#include <QWidget>



class Lieu : public QWidget
{
    Q_OBJECT

public:
    Lieu(QString _batiment, QString _etage, QString _emplacement, int _idPointeau, int _idLieu);

    int ObtenirIdLieu();
    void DefinirIdLieu(int _idLieu);
    QString ObtenirBatiment();
    void DefinirBatiment(int _batiment);
    QString ObtenirEtage();
    void DefinirEtage(int _etage);
    QString ObtenirEmplacement();
    void DefinirEmplacement(int _emplacement);

private:
    int idLieu;
    QString batiment;
    QString etage;
    QString emplacement;
    int idPointeau;
};

#endif // LIEU_H
