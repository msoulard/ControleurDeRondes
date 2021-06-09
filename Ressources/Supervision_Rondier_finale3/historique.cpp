/**
  @file historique.h
  @brief Implémentation de la classe Historique
  @version 1.0
  @author Ouijdane IMER
  @date   3/05/2021
  */


#include "historique.h"
#include "ui_historique.h"

/**
 * @brief Historique::Historique
 * @param parent
 * @details le constructeur de la classe Historique
 */
Historique::Historique(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Historique)
{


    ui->setupUi(this);
    typeConfigurationBDD *configBDD = new typeConfigurationBDD;
    Bdd = new AccesMySQL();

    if (Bdd->VerifierConnexion())
    {

        ui->tableWidget->setColumnWidth(0,200);
        ui->tableWidget->setColumnWidth(1,200);
        ui->tableWidget->setColumnWidth(2,200);
        ui->tableWidget->setColumnWidth(3,300);
        remplirComboBoxAgents();
        ui->comboBoxRonde->setItemData(0,-1); // mettre la valeur -1 pour le 1er element de la liste des rondes
    }
    else
    {
        // pas acces a la bdd
    }
    QDateTime dateTimeFin = QDateTime::currentDateTime();
    dateTimeFin.currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    ui->dateTimeFin->setDateTime(dateTimeFin);





}
Historique::~Historique()
{
    delete ui;
}


/**
 * @brief Historique::RemplirTableauHistorique
 * @details Cette méthode permet de remplir le tableau de l'historique des rondes
 * (Nom de la ronde,la date de début de passage,l'heure de de début de passage et le nombre d'anomalie pour chaque ronde)
 */

void Historique::RemplirTableauHistorique()
{
    int idAgent = ui->comboBoxAgents->itemData(ui->comboBoxAgents->currentIndex()).toInt();
    int idRonde=ui->comboBoxRonde->itemData(ui->comboBoxRonde->currentIndex()).toInt();

    QDateTime dateHeureDebut=ui->dateTimeDebut->dateTime();
    QDateTime dateHeureFin=ui->dateTimeFin->dateTime();

    QList<DonneesHistorique> listeHistorique;
    //Bdd->RecupererDonneeTableau1();

    ui->tableWidget->setColumnCount(6);
    QStringList labels;
    labels <<"Agents"<<"Ronde" <<"Heure de début de la ronde"<<"Date de début de la ronde"<<"Nombre d'anomalie"<<"idRonde";
    ui->tableWidget->setHorizontalHeaderLabels(labels);
    int rowCount=0;

    QHeaderView * headerView = ui->tableWidget->horizontalHeader();
    headerView->setSectionResizeMode(QHeaderView::ResizeToContents);
    Bdd->RecupererDonneeTableauHistoriqueNiveau1(idAgent,idRonde,dateHeureDebut,dateHeureFin,listeHistorique);
    ui->tableWidget->hideColumn(COLONNE_ID_RONDE);
    ui->tableWidget->showColumn(COLONNE_AGENTS);
    foreach (DonneesHistorique d, listeHistorique)
    {

        QTableWidgetItem *Ronde=new QTableWidgetItem(d.nomRonde);
        QTableWidgetItem *Heure=new QTableWidgetItem(d.dateHeure.time().toString());
        QTableWidgetItem *date=new QTableWidgetItem(d.dateHeure.date().toString("yyyy-MM-dd"));
        QTableWidgetItem *NbAnomalie=new QTableWidgetItem(QString::number(d.nbAnomalie));
        QTableWidgetItem *idRondeCourante=new QTableWidgetItem(QString::number(d.idRonde));

        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(rowCount,COLONNE_RONDE,Ronde);
        ui->tableWidget->setItem(rowCount,COLONNE_HEURE_HISTORIQUE,Heure);
        ui->tableWidget->setItem(rowCount,COLONNE_DATE,date);
        ui->tableWidget->setItem(rowCount,COLONNE_NB_ANOMALIE,NbAnomalie);
        ui->tableWidget->setItem(rowCount,COLONNE_ID_RONDE,idRondeCourante);
        if(idAgent ==-1 ) // pas d'agent selectionné
        {
            QTableWidgetItem *agents=new QTableWidgetItem(d.NomPrenomAgent.nom);
            ui->tableWidget->setItem(rowCount,COLONNE_AGENTS,agents);
        }


        rowCount++;

    }
    if (idAgent!=-1)    // si un agent sélectionné, cacher la colonne agent
    {

        ui->tableWidget->hideColumn(COLONNE_AGENTS);
    }
    ui->tableWidget->setRowCount(rowCount);
}

void Historique::on_tableWidget_itemSelectionChanged()
{
    // int idRonde=ui->comboBoxRonde->itemData(ui->comboBoxRonde->currentIndex()).toInt();
}
/**
 * @brief Historique::remplirComboBoxAgents
 * @details Cette Méthode permet de remplir la comboBoxAgents avec les noms et les prénoms des agents
 */

void Historique::remplirComboBoxAgents()
{

    QList<Agent> listeAgents;
    int nbAnomalie;
    int idAgent;
    int idRonde;
    qDebug() << " RecupererListeNomAgent";

    ui->comboBoxAgents->disconnect();
    ui->comboBoxAgents->clear();
    ui->comboBoxAgents->addItem("Tous les agents",-1);

    /*  QStringList listeNomAgent;
    QList<int> listeIdAgents;*/

    int nbAgents = Bdd->RecupererAgents(listeAgents);
    for(int i = 0; i< nbAgents; i++)
    {
        ui->comboBoxAgents->addItem(listeAgents.at(i).nom,listeAgents.at(i).id);
    }

    // ui->comboBoxAgents->setCurrentIndex(-1);
    connect(ui->comboBoxAgents,SIGNAL(currentIndexChanged(int)),this,SLOT(on_comboBoxAgents_currentIndexChanged(int)));

}
/**
 * @brief Historique::remplirComboBoxRonde
 * @details Cette méthode permet de récupérer la liste des rondes
 */

void Historique::remplirComboBoxRonde()
{
    QList<Ronde> listeRondes;

    int idRonde;
    qDebug() << " RecupererListeNomRonde";

    ui->comboBoxAgents->disconnect();
    ui->comboBoxAgents->clear();
    ui->comboBoxAgents->addItem("Toutes les rondes",-1);
    int nbRonde = Bdd->RecupererRonde(listeRondes,idRonde);
    for(int i = 0; i< nbRonde; i++)
    {
        ui->comboBoxRonde->addItem(listeRondes.at(i).nom,listeRondes.at(i).id);
    }

    /*   // ui->comboBoxAgents->setCurrentIndex(-1);
    connect(ui->comboBoxRonde,SIGNAL(currentIndexChanged(int)),this,SLOT(on_comboBoxRonde_currentIndexChanged(int)));*/
}

/**
 * @brief Historique::on_comboBoxAgents_currentIndexChanged
 * @details Ce slot permet de faire une relation entre la comboBoxAgents et la comboBoxRonde
 * @param index
 */
void Historique::on_comboBoxAgents_currentIndexChanged(int index)
{
    /* if(index >0)
        qDebug() << "Agent sélectionné : " << idAgents.at(index-1);*/


    QList<Ronde> listeRonde;
    int idAgent=ui->comboBoxAgents->itemData(index).toInt();

    ui->comboBoxRonde->clear();
    ui->comboBoxRonde->addItem("Toutes les rondes",-1);
    int nbRonde = Bdd->RecupererRonde(listeRonde,idAgent);
    for(int i = 0; i< nbRonde; i++)
    {
        ui->comboBoxRonde->addItem(listeRonde.at(i).nom,listeRonde.at(i).id);
    }
}


/**
 * @brief Historique::on_pushButtonAppliquer_clicked
 * @details Cette méthode permet d'appliquer les filtres et générer le tableau de l'historique des rondes
 */

void Historique::on_pushButtonAppliquer_clicked()
{
    RemplirTableauHistorique();

}



void Historique::on_comboBoxRonde_currentIndexChanged(int index)
{

}

/**
 * @brief Historique::on_tableWidget_itemClicked
 * @param item
 * @brief ce slot permet d'afficher la page ChronologieAnomalie en appuyant sur une ligne de premier Tableau
 */
void Historique::on_tableWidget_itemClicked(QTableWidgetItem *item)
{
    int idRonde=ui->tableWidget->item(ui->tableWidget->currentRow(),COLONNE_ID_RONDE)->text().toInt();
    int idAgent= ui->comboBoxAgents->currentText().toInt();

    QString Agent;
    QString NomRonde;

    Agent = ui->tableWidget->item(ui->tableWidget->currentRow(),COLONNE_AGENTS)->text();
    NomRonde = ui->tableWidget->item(ui->tableWidget->currentRow(),COLONNE_RONDE)->text();

    qDebug() << ui->tableWidget->currentRow();
    ChronologieAnomalie * Fenetre = new ChronologieAnomalie(*Bdd,Agent,NomRonde,idRonde);
    Fenetre->show();

}

/*void Historique::on_dateTimeFin_dateChanged(const QDateTime &date)
{

}
*/
