/**
   @file ihmrondes.cpp
 * @brief The IHMRondes class
 * @details Déclaration des méthodes et des slots de la classe IHMRondes
 * @authors Letessier Yoann
 * @date 25/05/2021
 */

#include "ihmrondes.h"
#include "ui_ihmrondes.h"

/**
 * @brief IhmRondes::IhmRondes
 * @param _listeRonde
 * @param _listePointeaux
 * @param mySqlBdd
 * @param parent
 */
IhmRondes::IhmRondes(QList<Rondes *> &_listeRonde, QList<Pointeaux *> &_listePointeaux, AccesMySQL & mySqlBdd, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IhmRondes)
{
    ui->setupUi(this);
    ActualiserListePointeaux();
    AfficherNomRondes();
    ActualiserListeRondes();
}

/**
 * @brief IhmRondes::~IhmRondes
 */
IhmRondes::~IhmRondes()
{
    delete ui;
}

void IhmRondes::ActualiserListePointeaux()
{
    listePointeaux.clear();
    ui->tableWidgetPointeaux->setRowCount(0);
    listePointeaux = bdd.ObtenirPointeaux();

    if(listePointeaux.size() > 0){
        for(int i = 0; i < listePointeaux.size(); i++){
            ui->tableWidgetPointeaux->setRowCount(ui->tableWidgetPointeaux->rowCount() + 1);
            QTableWidgetItem *designation = new QTableWidgetItem(listePointeaux.at(i)->ObtenirDesignation());
            QTableWidgetItem *emplacement = new QTableWidgetItem(listePointeaux.at(i)->ObtenirEmplacement());

            designation->setFlags(designation->flags() ^ Qt::ItemIsEditable);
            emplacement->setFlags(emplacement->flags() ^ Qt::ItemIsEditable);

            ui->tableWidgetPointeaux->setItem(ui->tableWidgetPointeaux->rowCount() -1, 0, designation);
            ui->tableWidgetPointeaux->setItem(ui->tableWidgetPointeaux->rowCount() -1, 1, emplacement);
        }
    }
}

void IhmRondes::AfficherNomRondes()
{
    listeRondes = bdd.ObtenirRondes();
    ui->comboBoxNom->clear();
    ui->comboBoxNom->addItem("Choisir une ronde",-1);

    for(int i = 1 ; i<listeRondes.size() ; i++)
    {
        ui->comboBoxNom->addItem(listeRondes.at(i)->ObtenirNom() + " ", listeRondes.at(i)->ObtenirIdRonde());
    }
    ui->comboBoxNom->setCurrentIndex(0);
}

void IhmRondes::ActualiserListeRondes()
{
    Rondes *laRonde;
    listeRondes.clear();
    listePointeaux.clear();

    ui->tableWidgetRondes->setRowCount(0);
    listeRondes = bdd.ObtenirRondes();
    listePointeaux = bdd.ObtenirPointeaux();

    ui->tableWidgetRondes->setRowCount(laRonde->ObtenirListePointeaux().size());

    for(int i = 0 ; i<laRonde->ObtenirListePointeaux().count() ; i++){

        QTableWidgetItem *ordrePointeau = new QTableWidgetItem(QString::number(i + 1));
        ui->tableWidgetRondes->setItem(i,1,ordrePointeau);
        QTableWidgetItem *numeroPointeau = new QTableWidgetItem(QString::number(laRonde->ObtenirListePointeaux().at(i)->ObtenirOdre()));
        QTableWidgetItem *lieuPointeau = new QTableWidgetItem(laRonde->ObtenirListePointeaux().at(i)->ObtenirEmplacement());
        ui->tableWidgetRondes->setItem(i, 2, lieuPointeau);

        if(i < laRonde->ObtenirListePointeaux().size() - 1)
        {
            QSpinBox *spinBoxMin = new QSpinBox();
            grilleSpinBox[spinBoxMin] = QPoint(i, 3);
            spinBoxMin->setMaximum(719);
            spinBoxMin->setMinimum(1);
            QSpinBox *spinBoxMax = new QSpinBox();
            grilleSpinBox[spinBoxMax] = QPoint(i, 4);
            spinBoxMax->setMaximum(720);
            spinBoxMax->setMinimum(2);
            spinBoxMin->setValue(laRonde->ObtenirListeTempsPointage().at(i)->ObtenirTempsMin());
            ui->tableWidgetRondes->setCellWidget(i, 3, spinBoxMin);
            if(!connect(spinBoxMin, SIGNAL(valueChanged(int)), this, SLOT(onSpinBoxTempsMinChange(int))))
            {
                qDebug() << "Erreur lors de la connextion du signal spinBoxMin";
            }
            spinBoxMax->setValue(laRonde->ObtenirListeTempsPointage().at(i)->ObtenirTempsMax());
            ui->tableWidgetRondes->setCellWidget(i, 4, spinBoxMax);
            if(!connect(spinBoxMax, SIGNAL(valueChanged(int)), this, SLOT(onSpinBoxTempsMaxChange(int))))
            {
                qDebug() << "Erreur lors de la connextion du signal spinBoxMax";
            }
        }
        if(i > 0)
        {
            QWidget* wdg = new QWidget;
            QLabel *label = new QLabel();
            label->setPixmap(iconeHaut);
            QHBoxLayout* layout = new QHBoxLayout(wdg);
            layout->addWidget(label);
            layout->setAlignment( Qt::AlignCenter );
            layout->setMargin(0);
            wdg->setLayout(layout);
            ui->tableWidgetRondes->setCellWidget(i, 5, wdg);
        }
        if(i < laRonde->ObtenirListePointeaux().size() -1)
        {
            QWidget* wdg = new QWidget;
            QLabel *label = new QLabel();
            label->setPixmap(iconeBas);
            QHBoxLayout* layout = new QHBoxLayout(wdg);
            layout->addWidget(label);
            layout->setAlignment( Qt::AlignCenter );
            layout->setMargin(0);
            wdg->setLayout(layout);
            ui->tableWidgetRondes->setCellWidget(i, 6, wdg);
        }
        QWidget* wdg = new QWidget;
        QLabel *label = new QLabel();
        label->setPixmap(iconeSuppr);
        QHBoxLayout* layout = new QHBoxLayout(wdg);
        layout->addWidget(label);
        layout->setAlignment( Qt::AlignCenter );
        layout->setMargin(0);
        wdg->setLayout(layout);
        ui->tableWidgetRondes->setCellWidget(i, 7, wdg);
    }
    ui->tableWidgetRondes->model()->blockSignals(false);
    ui->tableWidgetRondes->model()->layoutChanged();
}
