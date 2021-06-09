/**
   @file ihmsynchronisation.cpp
 * @brief Implémentation de la classe ihmSynchronisation
 * @details Classe permettant la gestion de l'IHM Synchronisation
 * @version 1.0
 * @author Damien CABARET
 * @date 03/04/2021
 */

#include "ihmsynchronisation.h"
#include "ui_ihmsynchronisation.h"

ihmSynchronisation::ihmSynchronisation(QWidget *parent):
    QWidget(parent),
    ui(new  Ui::ihmSynchronisation)
{
    ui->setupUi(this);

    //BDD
    bddSqlite = new AccesSqlite();
    bddMysql = new AccesMySQL();

    //Detecter l'OS
    OS = QSysInfo::kernelType();

    qDebug() << OS;
}

ihmSynchronisation::~ihmSynchronisation()
{
    delete ui;
}

void ihmSynchronisation::AfficherMessageTransfert()
{

}

void ihmSynchronisation::on_pushButton_EnvoyerOrdinateur_clicked()
{
    //Transferer la BDD SQLite dans l'ordinateur avec ADB
    if(OS == "linux"){
        //Si l'OS est linux :
        arguments << "-s" << ui->comboBox_2->currentText() << "shell" ;
        commandeSynchronisation2 = new QProcess();
        commandeSynchronisation2->start(programmeLinux, arguments);
        commandeSynchronisation2->write("run-as org.qtproject.rondier\n");
        commandeSynchronisation2->waitForBytesWritten();
        commandeSynchronisation2->write("cp /data/data/org.qtproject.rondier/db/Rondier_BDDRemplie.db /sdcard/Download/\n");

        commandeSynchronisation3 = new QProcess();
        commandeSynchronisation3->start("adb pull /sdcard/Download/Rondier_BDDRemplie.db " + QDir::currentPath().toLatin1() + "/BDD");
    }
    else{
        //Si l'OS est Windows :
        commandeSynchronisation2 = new QProcess();
        commandeSynchronisation2->start("cmd.exe");
        commandeSynchronisation2->write("cd " + QDir::currentPath().toLatin1() + "/ADB\n");
        commandeSynchronisation2->waitForBytesWritten();
        commandeSynchronisation2->write("adb shell\n");
        commandeSynchronisation2->waitForBytesWritten();
        commandeSynchronisation2->write("run-as org.qtproject.androidsynchronisation\n");
        commandeSynchronisation2->waitForBytesWritten();
        commandeSynchronisation2->write("cp /data/data/org.qtproject.androidsynchronisation/db/RondierBDDVide.db /sdcard/Download/\n");

        commandeSynchronisation3 = new QProcess();
        commandeSynchronisation3->start("cmd.exe");
        commandeSynchronisation3->write("cd " + QDir::currentPath().toLatin1() + "/ADB\n");
        commandeSynchronisation3->write("adb pull /sdcard/Download/RondierBDDVide.db " + QDir::currentPath().toLatin1() + "/BDD\n");
        commandeSynchronisation3->waitForBytesWritten();
    }

    if(bddSqlite->ConnexionBddSqlite())
    {

        //Recuperer aEteEffectueePar
        QList<aEteEffectueePar> listeaEteEffectueePar;
        bddSqlite->RecupererAEteEffectuePar(listeaEteEffectueePar);

        //Recuperer aEteScannePar
        QList<aEteScannePar> listeaEteScannePar;
        bddSqlite->RecupererAEteScannePar(listeaEteScannePar);

        //Récuperer Anomalies
        QList<Anomalie> listeAnomalie;
        bddSqlite->RecupererAnomalies(listeAnomalie);

        //Récuperer Photos
        QList<Photo> listePhoto;
        bddSqlite->RecupererPhoto(listePhoto);

        if(!dir.exists(QDir::currentPath().toLatin1() + "/images")){
            QDir().mkdir(QDir::currentPath().toLatin1() + "/images");
        }

        //Transfert des photo du smartphone vers l'ordinateur
        commandeTransfertPhoto = new QProcess();
        commandeTransfertPhoto->start("cmd.exe");
        commandeTransfertPhoto->write("cd " + QDir::currentPath().toLatin1() + "/ADB\n");
        commandeTransfertPhoto->waitForBytesWritten();
        commandeTransfertPhoto->write("adb shell\n");
        commandeTransfertPhoto->waitForBytesWritten();
        commandeTransfertPhoto->write("run-as org.qtproject.rondier\n");
        commandeTransfertPhoto->waitForBytesWritten();
        commandeTransfertPhoto->write("cp /data/data/org.qtproject.rondier/images/* /sdcard/BDD/images/\n");

        commandeTransfertPhotoPull = new QProcess();
        commandeTransfertPhotoPull->start("cmd.exe");
        commandeTransfertPhotoPull->write("cd " + QDir::currentPath().toLatin1() + "/ADB\n");
        commandeTransfertPhotoPull->write("adb pull /sdcard/BDD/images/ " + QDir::currentPath().toLatin1() + "/images\n");

        //Copie des données de la BDD SQLite dans la MySQL
        if(bddMysql->VerifierConnexion())
        {
            for(int i = 0; i < listeaEteEffectueePar.length(); i++)
            {
                bddMysql->TransfereraEteEffectueePar(listeaEteEffectueePar.at(i));
            }
            for(int i = 0; i < listeaEteScannePar.length(); i++)
            {
                bddMysql->TransfereraEteScannePar(listeaEteScannePar.at(i));
            }
            for(int i = 0; i < listeAnomalie.length(); i++)
            {
                bddMysql->TransfererAnomalie(listeAnomalie.at(i));
            }
            for(int i = 0; i < listePhoto.length(); i++)
            {
                bddMysql->TransfererPhoto(listePhoto.at(i));
            }
            /*
                for(int i = 0; i < listePhoto.length(); i++)
                {
                    bddMysql->TransfererPhoto(listePhoto.at(i));
                }*/
        }
    }
    else
    {
        qDebug() << "pas d'accès à la BDD";
    }
}

/**
     * @brief ihmSynchronisation::on_pushButton_EnvoyerSmartphone_clicked
     */
void ihmSynchronisation::on_pushButton_EnvoyerSmartphone_clicked()
{
    if(bddMysql->VerifierConnexion())
    {
        //Recuperer les agents
        QList<Agent> listeAgent;
        bddMysql->RecupererAgent(listeAgent);

        //Recuperer les rondes
        QList<Ronde> listeRonde;
        bddMysql->RecupererRonde(listeRonde);

        //Recuperer les pointeaux
        QList<Pointeau> listePointeau;
        bddMysql->RecupererPointeaux(listePointeau);

        //Recuperer les lieux
        QList<Lieux> listeLieu;
        bddMysql->RecupererLieux(listeLieu);

        //Recuperer table comporte
        QList<Comporte> listeComporte;
        bddMysql->RecupererComporte(listeComporte);

        //Recuperer table peutFaire
        QList<peutFaire> listePeutFaire;
        bddMysql->RecupererPeutFaire(listePeutFaire);

        //Recuperer l'anomalie de defaut d'ordre
        int IdAnomalie1 = 1;
        QString descriptionAnomalie;
        bddMysql->RecupererAnomalie1(descriptionAnomalie);

        //Recuperer aEteEffectueePar
        QList<aEteEffectueePar> listeaEteEffectueePar;
        bddMysql->RecupereraEteEffectueePar(listeaEteEffectueePar);

        //Copie des données de la BDD MySQL dans la SQLite
        if(bddSqlite->ConnexionBddSqlite())
        {
            for(int i = 0; i < listeRonde.length(); i++)
            {
                bddSqlite->TransfererRonde(listeRonde.at(i));
            }
            for(int i = 0; i < listePointeau.length(); i++)
            {
                bddSqlite->TransfererPointeau(listePointeau.at(i), listeLieu.at(i));
            }
            for(int i = 0; i < listeAgent.length(); i++)
            {
                bddSqlite->TransfererAgent(listeAgent.at(i));
            }
            /*for(int i = 0; i < listePointeau.length() ; i++)
                {
                    bddSqlite->TransfererLieu(listeLieu.at(i));
                }*/
            for(int i = 0; i < IdAnomalie1; i++)
            {
                bddSqlite->TransfererAnomalie1(IdAnomalie1, descriptionAnomalie);
            }
            for(int i = 0; i < listePeutFaire.length(); i++)
            {
                bddSqlite->TransfererPeutFaire(listePeutFaire.at(i));
            }
            for(int i = 0; i < listeComporte.length(); i++)
            {
                bddSqlite->TransfererComporte(listeComporte.at(i));
            }
            /*for(int i = 0; i < listeaEteEffectueePar.length(); i++)
                {
                    bddSqlite->TransfereraEteEffectueePar(listeaEteEffectueePar.at(i));
                }*/

        }

    }

    //Récuperer la BDD SQLite dans le smartphone
    if(OS == "linux"){
        //Si l'OS est linux :
        commandeSupprimer = new QProcess();
        commandeSupprimer->start(programmeLinux, arguments);
        commandeSupprimer->write("rm /sdcard/Download/Rondier_BDDRemplie.db\n");
        commandeSupprimer->write("run-as org.qtproject.rondier\n");
        commandeSupprimer->write("rm db/Rondier_BDDRemplie.db\n");

        commandeSynchronisation4 = new QProcess();
        commandeSynchronisation4->start("adb push " + QDir::currentPath().toLatin1() + "/BDD/Rondier_BDDRemplie.db /sdcard/Download/");

        commandeSynchronisation = new QProcess();
        arguments << "-s" << ui->comboBox_2->currentText() << "shell" ;
        commandeSynchronisation->start(programmeLinux, arguments);
        commandeSynchronisation->write("run-as org.qtproject.rondier\n");
        commandeSynchronisation->waitForBytesWritten();
        commandeSynchronisation->write("mkdir db\n");
        commandeSynchronisation->waitForBytesWritten();
        commandeSynchronisation->write("cp /sdcard/Download/Rondier_BDDRemplie.db /data/data/org.qtproject.rondier/db/\n");
    }
    else{
        //Si l'OS est Windows :
        commandeSynchronisation = new QProcess();
        commandeSynchronisation->start("cmd.exe");
        commandeSynchronisation->write("cd " + QDir::currentPath().toLatin1() + "/ADB\n");
        commandeSynchronisation->waitForBytesWritten();
        commandeSynchronisation->write("adb push " + QDir::currentPath().toLatin1() + "/BDD/RondierBDDVide.db /sdcard/Download/\n");
        commandeSynchronisation->waitForBytesWritten();
        commandeSynchronisation->write("adb shell\n");
        commandeSynchronisation->waitForBytesWritten();
        commandeSynchronisation->write("run-as org.qtproject.androidsynchronisation\n");
        commandeSynchronisation->waitForBytesWritten();
        commandeSynchronisation->write("mkdir db\n");
        commandeSynchronisation->waitForBytesWritten();
        commandeSynchronisation->write("cp /sdcard/Download/RondierBDDVide.db /data/data/org.qtproject.androidsynchronisation/db/\n");
    }
}

void ihmSynchronisation::on_pushButton_Detecter_clicked()
{
    //Detecter les smartphone
    commandeListerSmartphone = new QProcess();
    connect(commandeListerSmartphone, &QProcess::readyReadStandardOutput, this, &ihmSynchronisation::onQProcess_readyReadStandardOutput);
    //connect(commandeListerSmartphone, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(onQProcess_listerSmartphonesFinished()));

    if(OS == "linux"){
        //Si l'OS est linux :
        commandeListerSmartphone->start("adb devices");
    }
    else{
        //Si l'OS est Windows :
        commandeListerSmartphone->start("cmd.exe");
        commandeListerSmartphone->write("cd " + QDir::currentPath().toLatin1() + "/ADB\n");
        commandeListerSmartphone->waitForBytesWritten();
        commandeListerSmartphone->write("adb devices\n");
    }

    //AfficherMessageTransfert();
}

void ihmSynchronisation::onQProcess_readyReadStandardOutput()
{
    QRegularExpression regle("\\n(.*?)\\t");
    QRegularExpressionMatchIterator iterator = regle.globalMatch(commandeListerSmartphone->readAll());

    smartphone.clear();

    while(iterator.hasNext())
    {
        QRegularExpressionMatch match = iterator.next();
        smartphone.append(match.captured(1));
        ui->comboBox_2->addItems(smartphone);
    }
}
