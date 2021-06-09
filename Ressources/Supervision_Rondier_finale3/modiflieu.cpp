/**
   @file modiflieu.cpp
 * @brief The ModifLieu class
 * @details Déclaration de la classe ModifLieu
 * @authors Letessier Yoann
 * @date 25/05/2021
 */

#include "modiflieu.h"
#include "ui_modiflieu.h"

ModifLieu::ModifLieu(QString _batiment, QString _etage, QString _emplacement, QWidget *parent) :
    QWidget(parent),
    batiment(_batiment),
    etage(_etage),
    emplacement(_emplacement),
    ui(new Ui::ModifLieu)
{
    ui->setupUi(this);
    AfficherLieu();
}

ModifLieu::~ModifLieu()
{
    delete ui;
}

void ModifLieu::AfficherLieu()
{
    ui->lineEditBatiment->setText(batiment);
    ui->lineEditEtage->setText(etage);
    ui->lineEditEmplacement->setText(emplacement);
}

/**
 * @brief ModifLieu::on_pushButtonAnnuler_clicked
 */
void ModifLieu::on_pushButtonAnnuler_clicked()
{
    close();
}

void ModifLieu::on_pushButtonEnregistrer_clicked()
{
    close();
}
