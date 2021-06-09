/**
   @file modifpointeau.cpp
 * @brief The ModifPointeau class
 * @details Déclaration de la classe ModifPointeau
 * @authors Letessier Yoann
 * @date 25/05/2021
 */

#include "modifpointeau.h"
#include "ui_modifpointeau.h"

/**
 * @brief ModifPointeau::ModifPointeau
 * @param parent
 */
ModifPointeau::ModifPointeau(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModifPointeau)
{
    ui->setupUi(this);
    InitialiserTableaux();
    ActualiserListeDesLieux();
}

ModifPointeau::~ModifPointeau()
{
    delete ui;
}

/**
 * @brief ModifPointeau::InitialiserTableaux
 */
void ModifPointeau::InitialiserTableaux()
{
    //Mode de sélection des tableaux
    ///Sélection par ligne
    ui->tableWidgetLieux->setSelectionBehavior(QAbstractItemView::SelectRows);
    ///Sélection d'une seul ligne à la fois
    ui->tableWidgetLieux->setSelectionMode(QAbstractItemView::SingleSelection);
    ///Largeur des colonnes tableau
    ui->tableWidgetLieux->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
    ui->tableWidgetLieux->setColumnWidth(0,100);
    ui->tableWidgetLieux->setColumnWidth(1,100);
    ui->tableWidgetLieux->setColumnWidth(3,100);
    //ui->tableWidgetLieux->setColumnWidth(4,100);
    //QPushButton  *QPushbuttonModifier = new QPushButton("Modifier", this);
    //ui->tableWidgetLieux->setCellWidget(0,4, QPushbuttonModifier);
}

/**
 * @brief ModifPointeau::ActualiserListeDesLieux
 */
void ModifPointeau::ActualiserListeDesLieux()
{
    listeLieux.clear();
    ui->tableWidgetLieux->setRowCount(0);
    listeLieux = bdd.ObtenirLieux();

    if(listeLieux.size() > 0){
        for(int i =0; i<listeLieux.size(); i++){

            ui->tableWidgetLieux->setRowCount(ui->tableWidgetLieux->rowCount() + 1);
            QTableWidgetItem *batiment = new QTableWidgetItem(listeLieux.at(i)->ObtenirBatiment());
            QTableWidgetItem *etage = new QTableWidgetItem(listeLieux.at(i)->ObtenirEtage());
            QTableWidgetItem *emplacement = new QTableWidgetItem(listeLieux.at(i)->ObtenirEmplacement());

            batiment->setFlags(batiment->flags() ^ Qt::ItemIsEditable);
            etage->setFlags(etage->flags() ^ Qt::ItemIsEditable);
            emplacement->setFlags(emplacement->flags() ^ Qt::ItemIsEditable);

            ui->tableWidgetLieux->setItem(ui->tableWidgetLieux->rowCount() - 1, 0, emplacement);
            ui->tableWidgetLieux->setItem(ui->tableWidgetLieux->rowCount() - 1, 1, batiment);
            ui->tableWidgetLieux->setItem(ui->tableWidgetLieux->rowCount() - 1, 2, etage);
            //QCheckBox  *checkBoxModifier = new QCheckBox("choisir", this);
            // ui->tableWidgetLieux->setCellWidget(ui->tableWidgetLieux->rowCount() -1, 3,
            //                                     QPushbuttonModifier);
            // connect(QPushbuttonModifier, &QPushButton::clicked, this, &IhmLieux::onpushButtonModifier_clicked);
        }
    }
}

/**
 * @brief ModifPointeau::on_pushButtonAnnuler_clicked
 */
void ModifPointeau::on_pushButtonAnnuler_clicked()
{
    close();
}
