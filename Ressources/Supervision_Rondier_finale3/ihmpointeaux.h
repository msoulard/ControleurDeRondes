/**
   @file ihmpointeaux.h
 * @brief The IHMPointeaux class
 * @version 1.0
 * @details Déclaration des méthodes de la classe IHMLieu héritant de la classe QWidget
 * @authors Letessier Yoann
 * @date 25/05/2021
 */
#ifndef IHMPOINTEAUX_H
#define IHMPOINTEAUX_H

#include <QWidget>
#include "pointeaux.h"
#include "accesmysql.h"
#include "modifpointeau.h"
#include "creationpointeau.h"
#include "ihmlieux.h"

namespace Ui {
class IhmPointeaux;
}

class IhmPointeaux : public QWidget
{
    Q_OBJECT

public:
    explicit IhmPointeaux(QList<Pointeaux *> &_listePointeaux, AccesMySQL & mySqlBdd, QWidget *parent = nullptr);
    ~IhmPointeaux();
    void ActualiserListeDesPointeaux();
    void InitialiserTableaux();
    void ActualiserDesignation();

private slots:
         void onpushButtonModifier_clicked();
         void on_pushButton_2_clicked();

private:
    Ui::IhmPointeaux *ui;
    AccesMySQL bdd;
    QList<Pointeaux *> listePointeaux;
    QList<Lieu *> listeLieux;
    QList<QString> designation;
    QList<int> id;
    QList<bool> statut;
    QList<QString> tag;
    ModifPointeau *widgetModifPointeau;
    CreationPointeau *widgetCreationpointeau;
};

#endif // IHMPOINTEAUX_H
