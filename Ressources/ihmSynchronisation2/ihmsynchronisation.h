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

QT_BEGIN_NAMESPACE
namespace Ui { class ihmSynchronisation; }
QT_END_NAMESPACE

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
    //QSqlDatabase db;
    AccesSqlite *bddSqlite;
    AccesMySQL *bddMysql;

    QProcess *commandeListerSmartphone;
    QProcess *commandeSynchronisation;
    QProcess *commandeSynchronisation4;

    QProcess *commandeSynchronisation2;
    QProcess *commandeSynchronisation3;
    QProcess *commandeTransfertPhoto;
    QProcess *commandeTransfertPhotoPull;
    QProcess *commandeSupprimer;

    QStringList smartphone;
    QString cheminSQLitePC;
    QString cheminSQLiteSmartphone;
    QString programmeLinux = "adb";
    QStringList arguments;
    QString OS;

    bool transfert;
    QMessageBox *messageTransfert;


};
#endif // WIDGET_H

