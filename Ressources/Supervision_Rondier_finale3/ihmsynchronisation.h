/**
   @file ihmsynchronisation.h
 * @brief Déclaration de la classe ihmSynchronisation
 * @version 1.0
 * @author Damien CABARET
 * @date 03/04/2021
 */

#ifndef IHMSYNCHRONISATION_H
#define IHMSYNCHRONISATION_H

#include <QWidget>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlError>
//#include <QSqlQuery>
#include <QProcess>
#include <QSysInfo>
#include <QCoreApplication>
#include <QStandardPaths>
#include <QDir>
#include <QFile>
#include "accesmysql.h"
#include "accessqlite.h"


namespace Ui {
class ihmSynchronisation;
}

class ihmSynchronisation : public QWidget
{
    Q_OBJECT

public:
    ihmSynchronisation(QWidget *parent = nullptr);
    ~ihmSynchronisation();
    void AfficherMessageTransfert();

private slots:
    void on_pushButton_EnvoyerOrdinateur_clicked();
    void on_pushButton_EnvoyerSmartphone_clicked();
    void on_pushButton_Detecter_clicked();
    void onQProcess_readyReadStandardOutput();

private:
    Ui::ihmSynchronisation *ui;

    //Accès aux BDD;
        AccesSqlite *bddSqlite;
        AccesMySQL *bddMysql;

        //Commande pour lister les smartphone
        QProcess *commandeListerSmartphone;
        //Commandes pour envoyer la BDD SQLite vers le smartphone
        QProcess *commandeSynchronisation;
        QProcess *commandeSynchronisation4;
        //Commandes pour récuperer dans la station d'accueil la BDD SQLite
        QProcess *commandeSynchronisation2;
        QProcess *commandeSynchronisation3;
        //Commandes pour récuperer les photos dans la station d'accueil
        QProcess *commandeTransfertPhoto;
        QProcess *commandeTransfertPhotoPull;
        //QProcess *commandeSupprimer;
        QProcess *commandeSupprimer;

        QStringList smartphone;
        QString programmeLinux = "adb";
        QStringList arguments;
        QString OS;
        QDir dir;

        bool transfert;
        QMessageBox *messageTransfert;
};

#endif // IHMSYNCHRONISATION_H
