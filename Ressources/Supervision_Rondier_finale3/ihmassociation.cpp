/**
   @file ihmassociation.cpp
 * @brief The IHMAssociation class
 * @details Déclaration des méthodes et des slots de la classe IhmAssociation
 * @authors Letessier Yoann
 * @date 25/03/2021
 */
#include "ihmassociation.h"
#include "ui_ihmassociation.h"

IHMAssociation::IHMAssociation(QList<Rondes *> &_listeRonde, QList<Agents *> &_listeAgent, AccesMySQL & mySqlBdd, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IHMAssociation)
{
    ui->setupUi(this);
    ActualiserListeNomAgent();
}

/**
 * @brief IHMAssociation::~IHMAssociation
 */
IHMAssociation::~IHMAssociation()
{
    delete ui;
}

/**
 * @brief IHMAssociation::ActualiserListeNomAgent
 */
void IHMAssociation::ActualiserListeNomAgent()
{
    //agentActuEnregiste = true;
    listeAgents = bdd.ObtenirAgents();
    ui->comboBoxNomAgents->clear();
    ui->comboBoxNomAgents->addItem("Choisissez un nom",-1);
    for(int i = 1 ; i<listeAgents.size() ; i++)
    {
        ui->comboBoxNomAgents->addItem(listeAgents.at(i)->ObtenirNom() + " ", listeAgents.at(i)->ObtenirIdAgent());
    }
    //selectionAgent = 0;
    ui->comboBoxNomAgents->setCurrentIndex(0);
}
