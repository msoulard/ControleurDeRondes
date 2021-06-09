/**
   @file ihmidentification.h
 * @brief The IHMIdentification class
 * @details Déclaration de la classe IHMIdentification héritant de la classe QWidget
 * @authors Letessier Yoann
 * @date 25/05/2021
 */
#ifndef IHMIDENTIFICATION_H
#define IHMIDENTIFICATION_H

#include <QWidget>
#include "accesmysql.h"

namespace Ui {
class IHMIdentification;
}

class IHMIdentification : public QWidget
{
    Q_OBJECT

public:
    explicit IHMIdentification(AccesMySQL &mySqlBdd, QWidget *parent = nullptr);
    ~IHMIdentification();
    void AfficherImageClient();

private:
    Ui::IHMIdentification *ui;
    //Méthodes
    bool responsableConnecteBool;
    AccesMySQL bdd;                     //Base de données.

    ///------------------SIGNALS------------------///

signals:
    void responsableConnecte();
private slots:
    void on_pushButtonConnexion_clicked();
};

#endif // IHMIDENTIFICATION_H
