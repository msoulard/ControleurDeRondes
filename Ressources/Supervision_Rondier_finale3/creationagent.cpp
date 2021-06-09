/**
   @file creationagents.cpp
 * @brief The CreationAgents class
 * @details Déclaration des méthodes de la classe CreationAgents
 * @authors Letessier Yoann
 * @date 25/05/2021
 */

#include "creationagent.h"
#include "ui_creationagent.h"

/**
 * @brief CreationAgent::CreationAgent
 * @param parent
 */
CreationAgent::CreationAgent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreationAgent)
{
    ui->setupUi(this);
}

/**
 * @brief CreationAgent::~CreationAgent
 */
CreationAgent::~CreationAgent()
{
    delete ui;
}

/**
 * @brief CreationAgent::on_pushButtonEnregistrer_clicked
 */
void CreationAgent::on_pushButtonEnregistrer_clicked()
{    
    bdd.AjouterAgent(ui->lineEditNom->text().simplified(), ui->lineEditPrenom->text().simplified(), ui->lineEditBadge->text().simplified(),statut);
    close();
}

/**
 * @brief CreationAgent::on_pushButtonAnnuler_clicked
 */
void CreationAgent::on_pushButtonAnnuler_clicked()
{
    close();
}

/**
 * @brief CreationAgent::on_radioButtonActif_clicked
 * @return
 */
bool CreationAgent::on_radioButtonActif_clicked()
{
    return statut = 0;
}

/**
 * @brief CreationAgent::on_radioButtonInactif_clicked
 * @return
 */
bool CreationAgent::on_radioButtonInactif_clicked()
{
    return statut = 1;
}
