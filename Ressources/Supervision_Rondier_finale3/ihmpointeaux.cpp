/**
   @file ihmpointeaux.h
 * @brief The IHMPointeaux class
 * @details Déclaration des méthodes et des slots de la classe IHMLieu
 * @authors  Gabriel Lemée et Letessier Yoann
 * @date 25/05/2021
 */

#include "ihmpointeaux.h"
#include "ui_ihmpointeaux.h"

IhmPointeaux::IhmPointeaux(QList<Pointeaux *> &_listePointeaux, AccesMySQL & mySqlBdd, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IhmPointeaux)
{
    ui->setupUi(this);
    ActualiserListeDesPointeaux();
    ActualiserDesignation();
    InitialiserTableaux();
}

IhmPointeaux::~IhmPointeaux()
{
    delete ui;
}


/**
 * @brief IhmPointeaux::ActualiserListeDesPointeaux
 */
void IhmPointeaux::ActualiserListeDesPointeaux()
{
    listePointeaux.clear();
    designation.clear();
    statut.clear();
    tag.clear();

    ui->tableWidgetPointeaux->setRowCount(0);
    listePointeaux = bdd.ObtenirPointeaux();
    listeLieux = bdd.ObtenirLieux();

    if(listePointeaux.size() > 0){
        for(int i = 0; i < listePointeaux.size(); i++){
            ui->tableWidgetPointeaux->setRowCount(ui->tableWidgetPointeaux->rowCount() + 1);
            QTableWidgetItem *designation = new QTableWidgetItem(listePointeaux.at(i)->ObtenirDesignation());            
            QTableWidgetItem *emplacement = new QTableWidgetItem(listePointeaux.at(i)->ObtenirEmplacement());
            QTableWidgetItem *statut = new QTableWidgetItem(listePointeaux.at(i)->ObtenirStatut());
            //QTableWidgetItem *emplacement = new QTableWidgetItem(listeLieux.at(i)->ObtenirEmplacement());

            designation->setFlags(designation->flags() ^ Qt::ItemIsEditable);
            statut->setFlags(statut->flags() ^ Qt::ItemIsEditable);
            emplacement->setFlags(emplacement->flags() ^ Qt::ItemIsEditable);

            ui->tableWidgetPointeaux->setItem(ui->tableWidgetPointeaux->rowCount() -1, 0, designation);
            ui->tableWidgetPointeaux->setItem(ui->tableWidgetPointeaux->rowCount() -1, 1, emplacement);
            ui->tableWidgetPointeaux->setItem(ui->tableWidgetPointeaux->rowCount() -1, 2, statut);
            QPushButton  *QPushbuttonModifier = new QPushButton("Modifier", this);
            ui->tableWidgetPointeaux->setCellWidget(ui->tableWidgetPointeaux->rowCount() -1, 3,
                                                 QPushbuttonModifier);
            connect(QPushbuttonModifier, &QPushButton::clicked, this, &IhmPointeaux::onpushButtonModifier_clicked);
        }
    }
}

/**
 * @brief IhmPointeaux::InitialiserTableaux
 */
void IhmPointeaux::InitialiserTableaux()
{
    //Mode de sélection des tableaux
    ///Sélection par ligne
    ui->tableWidgetPointeaux->setSelectionBehavior(QAbstractItemView::SelectRows);
    ///Sélection d'une seul ligne à la fois
    ui->tableWidgetPointeaux->setSelectionMode(QAbstractItemView::SingleSelection);
    ///Largeur des colonnes tableau
    ui->tableWidgetPointeaux->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
    ui->tableWidgetPointeaux->setColumnWidth(0,100);
    ui->tableWidgetPointeaux->setColumnWidth(1,100);
}

/**
 * @brief IhmPointeaux::ActualiserDesignation
 */
void IhmPointeaux::ActualiserDesignation()
{
    listePointeaux = bdd.ObtenirPointeaux();
    ui->comboBoxDesignation->clear();
    ui->comboBoxDesignation->addItem("Choisissez pointeau",-1);
    for(int i = 1 ; i<listePointeaux.size() ; i++)
    {
        ui->comboBoxDesignation->addItem(listePointeaux.at(i)->ObtenirDesignation() + " ",listePointeaux.at(i)->ObtenirIdPointeau());
    }
    ui->comboBoxDesignation->setCurrentIndex(0);
}

/**
 * @brief IhmPointeaux::onpushButtonModifier_clicked
 */
void IhmPointeaux::onpushButtonModifier_clicked()
{
    ModifPointeau *pointeau = new ModifPointeau;
    pointeau->show();
}

/**
 * @brief IhmPointeaux::on_pushButton_2_clicked
 */
void IhmPointeaux::on_pushButton_2_clicked()
{
    CreationPointeau *pointeau = new CreationPointeau;
    pointeau->show();
}
