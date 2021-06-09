/**
   @file modifpointeau.h
 * @brief The ModifPointeau class
 * @details Déclaration de la classe ModifPointeau héritant de la classe QWidget
 * @authors Letessier Yoann
 * @date 25/05/2021
 */

#ifndef MODIFPOINTEAU_H
#define MODIFPOINTEAU_H

#include <QWidget>
#include "ihmlieux.h"
#include "accesmysql.h"

namespace Ui {
class ModifPointeau;
}

class ModifPointeau : public QWidget
{
    Q_OBJECT

public:
    explicit ModifPointeau(QWidget *parent = nullptr);
    ~ModifPointeau();
    void InitialiserTableaux();
    void ActualiserListeDesLieux();

private slots:
    void on_pushButtonAnnuler_clicked();

private:
    Ui::ModifPointeau *ui;
    AccesMySQL bdd;
    QList <Lieu *> listeLieux;
};

#endif // MODIFPOINTEAU_H
