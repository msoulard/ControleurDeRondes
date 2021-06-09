/**
  @file historique.h
  @brief Déclaration de la classe Historique
  @version 1.0
  @author Ouijdane IMER
  @date   3/05/2021
  */

#ifndef HISTORIQUE_H
#define HISTORIQUE_H
#include <QWidget>
#include <QTableWidgetItem>
#include <QFileDialog>
#include <QDebug>
#include "accesmysql.h"
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlError>
#include "chronologieanomalie.h"
#include "accesxml.h"
#define COLONNE_ID_RONDE 5
#define COLONNE_AGENTS 0
#define COLONNE_RONDE 1
#define COLONNE_HEURE_HISTORIQUE 2
#define COLONNE_DATE 3
#define COLONNE_NB_ANOMALIE 4

QT_BEGIN_NAMESPACE
namespace Ui { class Historique; }
QT_END_NAMESPACE

class Historique : public QWidget
{
    Q_OBJECT

public:
    Historique(QWidget *parent = nullptr);
    ~Historique();



    void AfficherPageChronologieAnomalie();
    void RemplirTableauHistorique();
    void remplirComboBoxAgents();
    void remplirComboBoxRonde();
    //void AfficherNbAnomalie();


private slots:
    void on_tableWidget_itemSelectionChanged();

    void on_comboBoxAgents_currentIndexChanged(int index);

    void on_pushButtonAppliquer_clicked();


    void on_comboBoxRonde_currentIndexChanged(int index);

    void on_tableWidget_itemClicked(QTableWidgetItem *item);

    //  void on_dateTimeFin_dateChanged(const QDateTime &date);

private:
    Ui::Historique *ui;
    AccesMySQL *Bdd;
    int id_agent;



};
#endif // HISTORIQUE_H
