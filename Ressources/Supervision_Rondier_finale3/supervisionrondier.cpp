/**
   @file supervisionrondier.cpp
 * @brief The SuperVisionRondier class
 * @details Déclaration des méthodes de la classe SuperVisionRondier
 * @authors Letessier Yoann
 * @date 25/05/2021
 */
#include "supervisionrondier.h"
#include "ui_supervisionrondier.h"

/**
 * @brief SuperVisionRondier::SuperVisionRondier
 * @param parent
 */
SuperVisionRondier::SuperVisionRondier(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SuperVisionRondier)
{
    ui->setupUi(this);
    scannerActif = false;
    erreurScannerAffiche = false;

    typeConfigurationBDD *configBDD = new typeConfigurationBDD;
    xmlConfig = new AccesXML();

    QFileInfo fichierVerif(CHEMINXML);
    if(fichierVerif.exists() && fichierVerif.isFile()){
        xmlConfig->LireConfiguration(CHEMINXML);
        configBDD = xmlConfig->ObtenirConfigurationBDD();
    }else{
        boiteMessage.AfficherAttention("Erreur lors de l'ouverture du fichier de configuration."
                                       "\nLe fichier \"configurations.xml\" n'existe pas.");
        exit(401);
    }
    QIcon iconeFenetre(":/images/agentIcon.png");

    QApplication::setWindowIcon(iconeFenetre);
    setWindowTitle("Supervision Rondier");
    QCoreApplication::setApplicationName("Supervision Rondier");

    mySqlBdd = new AccesMySQL();
    ///vérification connexion BDD
    if(mySqlBdd->Connexion(configBDD->ipServeurBDD, configBDD->portServeurBDD, configBDD->nomBDD, configBDD->utilisateurBDD, configBDD->motDePasseBDD)){
        widgetIdentification = new IHMIdentification(*mySqlBdd);
        widgetIdentification->AfficherImageClient(/*xmlConfig->ObtenirCheminImageClient()*/);

        if(!connect(widgetIdentification, SIGNAL(responsableConnecte()),SLOT(onResponsableConnecte())))
        {
            qDebug() << "Erreur lors de la connection du signal responsableConnecte";
        }
        ui->gridLayout->addWidget(widgetIdentification);
    }else{
        boiteMessage.AfficherAttention("Erreur lors de l'ouverture de la base de données.\nRelancez l'application et si le problème persiste, contacter un administrateur.");
        exit(401);
    }
}

/**
 * @brief SuperVisionRondier::~SuperVisionRondier
 */
SuperVisionRondier::~SuperVisionRondier()
{
    delete ui;
}

void SuperVisionRondier::onTabWidgetChange(int onglet)
{

}

/**
 * @brief SuperVisionRondier::onResponsableConnecte
 */
void SuperVisionRondier::onResponsableConnecte()
{
    listeAgents = mySqlBdd->ObtenirAgents();
    listePointeaux = mySqlBdd->ObtenirPointeaux();
    listeRonde = mySqlBdd->ObtenirRondes();

    widgetTab = new QTabWidget();
    QSize tailleIcone(50,50);
    QFont police;
    police.setPixelSize(11);
    widgetTab->setFont(police);

    tabAgent = new IhmAgents(listeAgents, *mySqlBdd);
    QIcon iconeAgent(":/img/images/agentIcon.png");
    tabPointeau = new IhmPointeaux(listePointeaux, *mySqlBdd);
    QIcon iconePointeau(":/img/images/pointeauIcon.png");
    tabLieu = new IhmLieux(*mySqlBdd);
    QIcon iconeLocalisation(":/img/images/emplacementIcon.png");
    tabRonde = new IhmRondes(listeRonde, listePointeaux, *mySqlBdd);
    QIcon iconeRonde(":/img/images/rondeIcon.png");
    tabSynchronisation = new ihmSynchronisation();
    QIcon iconeSynchronisation(":/img/images/synchroIcon.png");
    tabAssociation = new IHMAssociation(listeRonde, listeAgents, *mySqlBdd);
    QIcon iconeAssociation(":/img/images/associationIcon.png");
    tabHistorique = new Historique();
    QIcon iconeRapport(":/img/images/rapportIcon.png");
    //tabStatistiques = new IHMStatistiques(*mySqlBdd);
    //QIcon iconeStatistiques(":/images/statIcon.png");

    ui->gridLayout->addWidget(widgetTab);

    //    if(!connect(widgetTab, SIGNAL(currentChanged(int)), this, SLOT(onTabWidgetChange(int))))
    //    {
    //        qDebug() << "Erreur lors de la connection du signal onTabWidgetChange";
    //    }

    widgetTab->setIconSize(tailleIcone);
    widgetTab->addTab(tabAssociation, iconeAssociation, "Association Agents/Rondes");
    widgetTab->addTab(tabAgent, iconeAgent, "Gestion Agents");
    widgetTab->addTab(tabPointeau, iconePointeau, "Gestion Pointeaux");
    widgetTab->addTab(tabLieu, iconeLocalisation, "Gestion Emplacements");
    widgetTab->addTab(tabRonde, iconeRonde, "Gestion Rondes");
    widgetTab->addTab(tabSynchronisation, iconeSynchronisation, "Synchronisation");
    widgetTab->addTab(tabHistorique, iconeRapport, "Rapport");
    //widgetTab->addTab(tabStatistiques, iconeStatistiques, "Statistiques");
}

