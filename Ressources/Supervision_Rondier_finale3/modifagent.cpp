/**
   @file modifagent.cpp
 * @brief The ModifAgent class
 * @details Déclaration de la classe ModifAgent
 * @authors Letessier Yoann
 * @date 25/05/2021
 */


#include "modifagent.h"
#include "ui_modifagent.h"

ModifAgent::ModifAgent(QString _prenom, QString _nom, QString _badge, int _statut, int _id, QWidget *parent) :
    QWidget(parent),
    nom(_nom),
    prenom(_prenom),
    badge(_badge),
    statut(_statut),
    id(_id),
    ui(new Ui::ModifAgent)
{
    ui->setupUi(this);
    AfficherAgent();
}

ModifAgent::~ModifAgent()
{
    delete ui;
}

/**
 * @brief ModifAgent::on_pushButton_3_clicked
 */
void ModifAgent::on_pushButton_3_clicked()
{    
    bdd.ModifierAgent(ui->lineEditNom->text().simplified(), ui->lineEditPrenom->text().simplified(), ui->lineEditBadge->text().simplified(),statut,id);
    close();
}

/**
 * @brief ModifAgent::AfficherAgent
 */
void ModifAgent::AfficherAgent()
{
    ui->lineEditNom->setText(nom);
    ui->lineEditPrenom->setText(prenom);
    ui->lineEditBadge->setText(badge);
    if(statut == 0){
        ui->radioButtonActif->clicked();
    }else{
        ui->radioButtonInactif->clicked();
    }
}

/**
 * @brief ModifAgent::on_pushButton_4_clicked
 */
void ModifAgent::on_pushButton_4_clicked()
{
    close();
}

bool ModifAgent::on_radioButtonActif_clicked()
{
    return statut = 0;
}

bool ModifAgent::on_radioButtonInactif_clicked()
{
    return statut = 1;
}
