/**
   @file ihmrondes.h
 * @brief The IHMRondes class
 * @version 1.0
 * @details Déclaration de la classe IHMRondes héritant de la classe QWidget
 * @authors Letessier Yoann
 * @date 25/05/2021
 */
#ifndef IHMRONDES_H
#define IHMRONDES_H

#include <QWidget>
#include "rondes.h"
#include "pointeaux.h"
#include "accesmysql.h"
#include <QSpinBox>
#include <QMap>

namespace Ui {
class IhmRondes;
}

class IhmRondes : public QWidget
{
    Q_OBJECT

public:
    explicit IhmRondes(QList<Rondes *> &_listeRonde, QList<Pointeaux *> &_listePointeaux, AccesMySQL & mySqlBdd, QWidget *parent = nullptr);
    ~IhmRondes();
    void ActualiserListePointeaux();
    void AfficherNomRondes();
    void ActualiserListeRondes();

private:
    Ui::IhmRondes *ui;
    AccesMySQL bdd;
    QList<Pointeaux *> listePointeaux;
    QList<Rondes *> listeRondes;
    QMap<QSpinBox*, QPoint> grilleSpinBox;
    QPixmap iconeHaut, iconeBas, iconeSuppr;
};

#endif // IHMRONDES_H
