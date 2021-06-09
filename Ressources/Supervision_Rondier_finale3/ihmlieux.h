/**
   @file ihmlieu.h
 * @brief The IHMLieu class
 * @version 1.0
 * @details Déclaration de la classe IHMLieu héritant de la classe QWidget
 * @authors Letessier Yoann
 * @date 25/05/2021
 */
#ifndef IHMLIEUX_H
#define IHMLIEUX_H

#include <QWidget>
#include "lieu.h"
#include "accesmysql.h"
#include "modiflieu.h"
#include "creationlieu.h"
#include "QList"

namespace Ui {
class IhmLieux;
}

class IhmLieux : public QWidget
{
    Q_OBJECT

public:
    explicit IhmLieux(/*QList<Lieu *> &_listeLieux, */AccesMySQL & mySqlBdd, QWidget *parent = nullptr);
    ~IhmLieux();
    void InitialiserTableaux();
    void ActualiserListeDesLieux();
    void ActualiserListeDesEmplacements();
    void ActualiserListeDesEtage();
    void ActualiserListeDesBatiment();

private slots:
    void onpushButtonModifier_clicked();

    void on_pushButtonNouveau_clicked();

    void on_pushButtonActualiser_clicked();

private:
    Ui::IhmLieux *ui;
    ModifLieu *widgetModifLieu;
    CreationLieu *widgetCreationLieu;
    QList<Lieu *> listeLieux;
    QList<QString> emplacement;
    QList<QString> batiment;
    QList<QString> etage;
    AccesMySQL bdd;
    QString batiment2;
    QString etage2;
    QString emplacement2;
};

#endif // IHMLIEUX_H
