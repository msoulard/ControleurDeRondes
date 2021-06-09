/**
   @file creationlieu.h
 * @brief The CreationLieus class
 * @version 1.0
 * @details Déclaration de la classe CreationLieu
 * @authors Letessier Yoann
 * @date 25/05/2021
 */

#ifndef CREATIONLIEU_H
#define CREATIONLIEU_H

#include <QWidget>
#include"accesmysql.h"

namespace Ui {
class CreationLieu;
}

class CreationLieu : public QWidget
{
    Q_OBJECT

public:
    explicit CreationLieu(/*QString batiment, QString etage, QString emplacement,*/ QWidget *parent = nullptr);
    ~CreationLieu();

private slots:
    void on_pushButtonAnnuler_clicked();
    void on_pushButtonEnregistrer_clicked();

private:
    Ui::CreationLieu *ui;
    AccesMySQL bdd;
};

#endif // CREATIONLIEU_H
