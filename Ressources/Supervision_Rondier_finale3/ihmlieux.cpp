/**
   @file ihmlieu.cpp
 * @brief The IHMLieu class
 * @details Déclaration des méthodes et des slots de la classe IHMLieu
 * @authors Letessier Yoann
 * @date 25/05/2021
 */

#include "ihmlieux.h"
#include "ui_ihmlieux.h"

IhmLieux::IhmLieux(/*QList<Lieu *> &_listeLieux, */AccesMySQL & mySqlBdd, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IhmLieux)
{
    ui->setupUi(this);
    ActualiserListeDesEmplacements();
    ActualiserListeDesEtage();
    ActualiserListeDesBatiment();
    InitialiserTableaux();
    ActualiserListeDesLieux();
}

/**
 * @brief IhmLieux::~IhmLieux
 */
IhmLieux::~IhmLieux()
{
    delete ui;
}

/**
 * @brief IhmLieux::InitialiserTableaux
 */
void IhmLieux::InitialiserTableaux()
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
    ui->tableWidgetLieux->setColumnWidth(4,100);
}

/**
 * @brief IhmLieux::ActualiserListeDesLieux
 */
void IhmLieux::ActualiserListeDesLieux()
{
    listeLieux.clear();
    ui->tableWidgetLieux->setRowCount(0);
    listeLieux = bdd.ObtenirLieux();
    ui->tableWidgetLieux->hideColumn(3);

    if(listeLieux.size() > 0){
        for(int i =0; i<listeLieux.size(); i++){

            ui->tableWidgetLieux->setRowCount(ui->tableWidgetLieux->rowCount() + 1);
            QTableWidgetItem *batiment = new QTableWidgetItem(listeLieux.at(i)->ObtenirBatiment());
            QTableWidgetItem *etage = new QTableWidgetItem(listeLieux.at(i)->ObtenirEtage());
            QTableWidgetItem *emplacement = new QTableWidgetItem(listeLieux.at(i)->ObtenirEmplacement());
            QTableWidgetItem *idLieu = new QTableWidgetItem(listeLieux.at(i)->ObtenirIdLieu());

            batiment->setFlags(batiment->flags() ^ Qt::ItemIsEditable);
            etage->setFlags(etage->flags() ^ Qt::ItemIsEditable);
            emplacement->setFlags(emplacement->flags() ^ Qt::ItemIsEditable);
            idLieu->setFlags(idLieu->flags() ^ Qt::ItemIsEditable);

            ui->tableWidgetLieux->setItem(ui->tableWidgetLieux->rowCount() - 1, 0, batiment);
            ui->tableWidgetLieux->setItem(ui->tableWidgetLieux->rowCount() - 1, 1, etage);
            ui->tableWidgetLieux->setItem(ui->tableWidgetLieux->rowCount() - 1, 2, emplacement);
            ui->tableWidgetLieux->setItem(ui->tableWidgetLieux->rowCount() - 1, 3, idLieu);
            QPushButton  *QPushbuttonModifier = new QPushButton("Modifier", this);
            ui->tableWidgetLieux->setCellWidget(ui->tableWidgetLieux->rowCount() -1, 4,
                                                QPushbuttonModifier);
            connect(QPushbuttonModifier, &QPushButton::clicked, this, &IhmLieux::onpushButtonModifier_clicked);
        }
    }
}

/**
 * @brief IhmLieux::ActualiserListeDesEmplacements
 */
void IhmLieux::ActualiserListeDesEmplacements()
{
    listeLieux = bdd.ObtenirLieux();
    ui->comboBoxEmplacement->clear();
    ui->comboBoxEmplacement->addItem("Choisissez un emplacement",-1);
    for(int i = 1 ; i<listeLieux.size() ; i++)
    {
        ui->comboBoxEmplacement->addItem(listeLieux.at(i)->ObtenirEmplacement() + " ", listeLieux.at(i)->ObtenirIdLieu());
    }
    ui->comboBoxEmplacement->setCurrentIndex(0);
}

/**
 * @brief IhmLieux::ActualiserListeDesEtage
 */
void IhmLieux::ActualiserListeDesEtage()
{
    listeLieux = bdd.ObtenirLieux();
    ui->comboBoxEtage->clear();
    ui->comboBoxEtage->addItem("Choisissez un étage",-1);
    for(int i = 1 ; i<listeLieux.size() ; i++)
    {
        ui->comboBoxEtage->addItem(listeLieux.at(i)->ObtenirEtage() + " ", listeLieux.at(i)->ObtenirIdLieu());
    }
    ui->comboBoxEtage->setCurrentIndex(0);
}

/**
 * @brief IhmLieux::ActualiserListeDesBatiment
 */
void IhmLieux::ActualiserListeDesBatiment()
{
    listeLieux = bdd.ObtenirLieux();
    ui->comboBoxBatiment->clear();
    ui->comboBoxBatiment->addItem("Choisissez un bâtiment",-1);
    for(int i = 1 ; i<listeLieux.size() ; i++)
    {
        ui->comboBoxBatiment->addItem(listeLieux.at(i)->ObtenirBatiment() + " ", listeLieux.at(i)->ObtenirIdLieu());
    }
    ui->comboBoxBatiment->setCurrentIndex(0);
}

/**
 * @brief IhmLieux::onpushButtonModifier_clicked
 */
void IhmLieux::onpushButtonModifier_clicked()
{
    int indexLigne=ui->tableWidgetLieux->currentRow();
    batiment2 = ui->tableWidgetLieux->item(indexLigne,0)->text();
    etage2=ui->tableWidgetLieux->item(indexLigne,1)->text();
    emplacement2=ui->tableWidgetLieux->item(indexLigne,2)->text();

    ModifLieu *lieu = new ModifLieu(batiment2,etage2,emplacement2);;
    lieu->show();
}

/**
 * @brief IhmLieux::on_pushButtonNouveau_clicked
 */
void IhmLieux::on_pushButtonNouveau_clicked()
{
    CreationLieu *lieu = new CreationLieu();
    lieu->show();
}

void IhmLieux::on_pushButtonActualiser_clicked()
{
    ActualiserListeDesLieux();
}
