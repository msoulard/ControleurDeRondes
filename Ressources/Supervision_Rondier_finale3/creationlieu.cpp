/**
   @file creationlieu.cpp
 * @brief The CreationLieu class
 * @details Déclaration des méthodesde la classe ModifAgent
 * @authors Letessier Yoann
 * @date 25/05/2021
 */

#include "creationlieu.h"
#include "ui_creationlieu.h"

/**
 * @brief CreationLieu::CreationLieu
 * @param parent
 */
CreationLieu::CreationLieu(/*QString batiment, QString etage, QString emplacement,*/ QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreationLieu)
{
    ui->setupUi(this);
}

/**
 * @brief CreationLieu::~CreationLieu
 */
CreationLieu::~CreationLieu()
{
    delete ui;
}

/**
 * @brief CreationLieu::on_pushButtonAnnuler_clicked
 */
void CreationLieu::on_pushButtonAnnuler_clicked()
{
    close();
}

/**
 * @brief CreationLieu::on_pushButtonEnregistrer_clicked
 */
void CreationLieu::on_pushButtonEnregistrer_clicked()
{
bdd.AjouterLieux(ui->lineEditBatiment->text().simplified(), ui->lineEditEtage->text().simplified(), ui->lineEditEmplacement->text().simplified());
        close();
}
