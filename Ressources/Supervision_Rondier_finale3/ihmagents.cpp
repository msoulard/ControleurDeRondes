/**
   @file ihmagents.cpp
 * @brief The IhmAgents class
 * @details Déclaration des méthodes et des slots de la classe IhmAgents
 * @authors Letessier Yoann
 * @date 25/05/2021
 */

#include "ihmagents.h"
#include "ui_ihmagents.h"
#include "modifagent.h"

IhmAgents::IhmAgents(QList<Agents *> &_listeAgents, AccesMySQL & mySqlBdd, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IhmAgents)
{
    ui->setupUi(this);
    ActualiserListeDesAgents();
    InitialiserTableaux();
    ActualiserListeNomAgent();
    ActualiserListeBadgeAgent();
    ActualiserStatutAgent();
}

IhmAgents::~IhmAgents()
{
    delete ui;
}

/**
 * @brief IhmAgents::ActualiserListeDesAgents
 */
void IhmAgents::ActualiserListeDesAgents()
{
    listeAgents.clear();
    //    nomAgents.clear();
    //    prenomAgents.clear();
    //    badgeAgents.clear();
    //    statutAgents.clear();
    ui->tableWidgetAgents->setRowCount(0);
    listeAgents = bdd.ObtenirAgents();
    ui->tableWidgetAgents->hideColumn(4);

    if(listeAgents.size() > 0){
        for(int i =0; i<listeAgents.size(); i++){

            ui->tableWidgetAgents->setRowCount(ui->tableWidgetAgents->rowCount() + 1);
            QTableWidgetItem *nom = new QTableWidgetItem(listeAgents.at(i)->ObtenirNom());
            QTableWidgetItem *prenom = new QTableWidgetItem(listeAgents.at(i)->ObtenirPrenom());
            QTableWidgetItem *badge = new QTableWidgetItem(listeAgents.at(i)->ObtenirBadge());
            QTableWidgetItem *statut = new QTableWidgetItem(listeAgents.at(i)->ObtenirStatut());
            QTableWidgetItem *idAgent = new QTableWidgetItem(listeAgents.at(i)->ObtenirIdAgent());

            nom->setFlags(nom->flags() ^ Qt::ItemIsEditable);
            prenom->setFlags(prenom->flags() ^ Qt::ItemIsEditable);
            badge->setFlags(badge->flags() ^ Qt::ItemIsEditable);
            statut->setFlags(statut->flags() ^ Qt::ItemIsEditable);
            idAgent->setFlags(idAgent->flags() ^ Qt::ItemIsEditable);

            ui->tableWidgetAgents->setItem(ui->tableWidgetAgents->rowCount() -1, 0, prenom);
            ui->tableWidgetAgents->setItem(ui->tableWidgetAgents->rowCount() - 1, 1, nom);
            ui->tableWidgetAgents->setItem(ui->tableWidgetAgents->rowCount() - 1, 2, badge);
            ui->tableWidgetAgents->setItem(ui->tableWidgetAgents->rowCount() - 1, 3, statut);
            ui->tableWidgetAgents->setItem(ui->tableWidgetAgents->rowCount() - 1, 4, idAgent);
            QPushButton  *QPushbuttonModifier = new QPushButton("Modifier", this);
            ui->tableWidgetAgents->setCellWidget(ui->tableWidgetAgents->rowCount() -1, 5,
                                                 QPushbuttonModifier);
            connect(QPushbuttonModifier, &QPushButton::clicked, this, &IhmAgents::onpushButtonModifier_clicked);
        }
    }
}

/**
 * @brief IhmAgents::ActualiserListeNomAgent
 */
void IhmAgents::ActualiserListeNomAgent()
{
    //agentActuEnregiste = true;
    listeAgents = bdd.ObtenirAgents();
    ui->comboBoxNom->clear();
    ui->comboBoxNom->addItem("Choisissez un nom",-1);
    for(int i = 1 ; i<listeAgents.size() ; i++)
    {
        ui->comboBoxNom->addItem(listeAgents.at(i)->ObtenirNom() + " ", listeAgents.at(i)->ObtenirIdAgent());
    }
    selectionAgent = 0;
    ui->comboBoxNom->setCurrentIndex(0);
}

/**
 * @brief IhmAgents::ActualiserListeBadgeAgent
 */
void IhmAgents::ActualiserListeBadgeAgent()
{
    listeAgents = bdd.ObtenirAgents();
    ui->comboBoxBadge->clear();
    ui->comboBoxBadge->addItem("Choisissez un badge",-1);
    for(int i = 1 ; i<listeAgents.size() ; i++)
    {
        ui->comboBoxBadge->addItem(listeAgents.at(i)->ObtenirBadge() + " ",listeAgents.at(i)->ObtenirIdAgent());
    }
    ui->comboBoxBadge->setCurrentIndex(0);
}

/**
 * @brief IhmAgents::ActualiserStatutAgent
 */
void IhmAgents::ActualiserStatutAgent()
{    
    ui->comboBoxStatut->clear();
    ui->comboBoxStatut->addItem("Choisissez un statut", -1);
    ui->comboBoxStatut->addItem("actif", false);
    ui->comboBoxStatut->addItem("inactif", true);
}

/**
 * @brief IhmAgents::InitialiserTableaux
 */
void IhmAgents::InitialiserTableaux()
{
    //Mode de sélection des tableaux
    ///Sélection par ligne
    ui->tableWidgetAgents->setSelectionBehavior(QAbstractItemView::SelectRows);
    ///Sélection d'une seul ligne à la fois
    ui->tableWidgetAgents->setSelectionMode(QAbstractItemView::SingleSelection);
    ///Largeur des colonnes tableau
    ui->tableWidgetAgents->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
    ui->tableWidgetAgents->setColumnWidth(0,100);
    ui->tableWidgetAgents->setColumnWidth(1,100);
    ui->tableWidgetAgents->setColumnWidth(3,100);
    ui->tableWidgetAgents->setColumnWidth(4,100);
}

/**
 * @brief IhmAgents::ActualiserTableauFiltres
 */
void IhmAgents::ActualiserTableauFiltres()
{
    ui->tableWidgetAgents->hideColumn(4);
    for(int ligne = 0; ligne < listeAgents.size(); ligne++){
        if(listeAgents.at(ligne)->ObtenirNom().simplified().size()
                && listeAgents.at(ligne)->ObtenirBadge().simplified().size()
                && listeAgents.at(ligne)->ObtenirStatut().simplified().size()
                && listeAgents.at(ligne)->ObtenirPrenom().simplified().size()
                && listeAgents.at(ligne)->ObtenirIdAgent().simplified().size()){

            ui->tableWidgetAgents->setRowCount(ligne +1);
            QTableWidgetItem *nom = new QTableWidgetItem(listeAgents.at(ligne)->ObtenirNom());
            QTableWidgetItem *prenom = new QTableWidgetItem(listeAgents.at(ligne)->ObtenirPrenom());
            QTableWidgetItem *badge = new QTableWidgetItem(listeAgents.at(ligne)->ObtenirBadge());
            QTableWidgetItem *statut = new QTableWidgetItem(listeAgents.at(ligne)->ObtenirStatut());
            QTableWidgetItem *idAgent = new QTableWidgetItem(listeAgents.at(ligne)->ObtenirIdAgent());
            ui->tableWidgetAgents->setItem(ui->tableWidgetAgents->rowCount() - 1, 0, prenom);
            ui->tableWidgetAgents->setItem(ui->tableWidgetAgents->rowCount() - 1, 1, nom);
            ui->tableWidgetAgents->setItem(ui->tableWidgetAgents->rowCount() - 1, 2, badge);
            ui->tableWidgetAgents->setItem(ui->tableWidgetAgents->rowCount() - 1, 3, statut);
            ui->tableWidgetAgents->setItem(ui->tableWidgetAgents->rowCount() - 1, 4, idAgent);
            QPushButton  *QPushbuttonModifier = new QPushButton("Modifier", this);
            ui->tableWidgetAgents->setCellWidget(ui->tableWidgetAgents->rowCount() -1, 5,QPushbuttonModifier);
            connect(QPushbuttonModifier, &QPushButton::clicked, this, &IhmAgents::onpushButtonModifier_clicked);
        }
    }
}

/**
 * @brief IhmAgents::DemanderEnregistrement
 * @return
 */
bool IhmAgents::DemanderEnregistrement()
{
    bool valide = false;
    if(boiteMessage.DemmanderConfirmation("L'agent actuel n'est pas enregistré."
                                          "\nSi vous continuez, les modificactions seront perdues."
                                          "\nVoulez-vous continuer ?"))
    {
        valide = true;
    }
    return valide;
}

void IhmAgents::ObtenirNomAgent(QList<Agents *> liste)
{

}

/**
 * @brief IhmAgents::on_pushButtonAppliquer_clicked
 */
void IhmAgents::on_pushButtonAppliquer_clicked()
{
    ui->tableWidgetAgents->setRowCount(0);
    //Seul le nom est séléctionné
    if(ui->comboBoxBadge->itemData(ui->comboBoxBadge->currentIndex()).toInt()==-1 && ui->comboBoxStatut->currentIndex()==-1 && ui->comboBoxNom->itemData(ui->comboBoxNom->currentIndex()).toInt()!=-1){
        listeAgents.clear();
        if(bdd.AppliquerFiltresNomAgents(ui->comboBoxNom->currentText(), listeAgents)){
            ActualiserTableauFiltres();
        }
    }
    //seul le statut est séléctionné
    if(ui->comboBoxNom->itemData(ui->comboBoxNom->currentIndex()).toInt()==-1 && ui->comboBoxBadge->itemData(ui->comboBoxBadge->currentIndex()).toInt()==-1 && ui->comboBoxBadge->itemData(ui->comboBoxBadge->currentIndex()).toInt()!=-1){
        listeAgents.clear();
        if(bdd.AppliquerFiltresStatutAgents(ui->comboBoxStatut->currentIndex() != 1, listeAgents)){
            ActualiserTableauFiltres();
        }
    }
    //seul le badge est sélectionné
    if(ui->comboBoxNom->itemData(ui->comboBoxNom->currentIndex()).toInt()==-1 && ui->comboBoxBadge->itemData(ui->comboBoxBadge->currentIndex()).toInt()!=-1 && ui->comboBoxStatut->currentIndex()==-1){
        listeAgents.clear();
        if(bdd.AppliquerFiltresBadgeAgents(ui->comboBoxBadge->currentText(), listeAgents)){
            ActualiserTableauFiltres();
        }
    }
    //statut et badge sélectionnés
    if(ui->comboBoxNom->itemData(ui->comboBoxNom->currentIndex()).toInt()==-1 && ui->comboBoxBadge->itemData(ui->comboBoxBadge->currentIndex()).toInt()!=-1 && ui->comboBoxStatut->currentIndex()!=-1){
        listeAgents.clear();
        if(bdd.AppliquerFiltresStatutBadgeAgents(ui->comboBoxStatut->currentIndex() != 1, ui->comboBoxBadge->currentText(), listeAgents)){
            ActualiserTableauFiltres();
        }
    }
    //je sais pas
    if(ui->comboBoxBadge->itemData(ui->comboBoxBadge->currentIndex()).toInt()==-1 && ui->comboBoxStatut->currentIndex()==-1 && ui->comboBoxNom->itemData(ui->comboBoxNom->currentIndex()).toInt()!=-1){
        listeAgents.clear();
        if(bdd.AppliquerFiltresNomAgents(ui->comboBoxNom->currentText(), listeAgents)){
            ActualiserTableauFiltres();
        }
    }
    //tous les filtres sélectionnés
    if(ui->comboBoxNom->itemData(ui->comboBoxNom->currentIndex()).toInt()!=-1 && ui->comboBoxBadge->itemData(ui->comboBoxBadge->currentIndex()).toInt()!=-1 && ui->comboBoxStatut->currentIndex()==-1){
        listeAgents.clear();
        if(bdd.AppliquerFiltresAgents(ui->comboBoxNom->currentText(),
                                      (ui->comboBoxStatut->currentIndex() == 0 ? false:true) ,
                                      ui->comboBoxBadge->currentText(),listeAgents)){
            ActualiserTableauFiltres();
        }
    }
}

/**
 * @brief IhmAgents::onpushButtonModifier_clicked
 */
void IhmAgents::onpushButtonModifier_clicked()
{
    int statutAgent;
    int indexLigne=ui->tableWidgetAgents->currentRow();
    prenom=ui->tableWidgetAgents->item(indexLigne,0)->text();
    nom=ui->tableWidgetAgents->item(indexLigne,1)->text();
    badge=ui->tableWidgetAgents->item(indexLigne,2)->text();
    statutInitial=ui->tableWidgetAgents->item(indexLigne,3)->text();
    id_Agent=ui->tableWidgetAgents->item(indexLigne,4)->text().toInt();

    if(statutInitial == "actif"){
        statutAgent = 0;
    }else{
        statutAgent = 1;
    }
    ModifAgent *agent = new ModifAgent(prenom,nom,badge,statutAgent,id_Agent);
    agent->show();
}

/**
 * @brief IhmAgents::on_comboBoxStatut_currentIndexChanged
 * @param index
 */
void IhmAgents::on_comboBoxStatut_currentIndexChanged(int index)
{
    // recuperer le statut de l'agent
    bool statut = ui->comboBoxStatut->itemData(index).toBool();
}

//void IhmAgents::on_comboBoxNom_currentIndexChanged(int index)
//{
//    QString idAgent = ui->comboBoxNom->itemData(index).toString();
//}

/**
 * @brief IhmAgents::on_pushButtonNouveau_clicked
 */
void IhmAgents::on_pushButtonNouveau_clicked()
{
    CreationAgent *agent = new CreationAgent();
    agent->show();
}

void IhmAgents::on_pushButtonActualiser_clicked()
{
    ActualiserListeDesAgents();
}
