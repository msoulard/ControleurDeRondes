#include "basebdd.h"
#include "QDebug"
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QMessageBox>
BaseBDD::BaseBDD()
{

}

QString BaseBDD::connexion()
{
    DB = QSqlDatabase::addDatabase("QSQLITE");
           DB.setHostName("localhost");
           DB.setDatabaseName("/home/bmezerette/ControleurDeRonde2020");
           DB.setUserName("root");
           DB.setPassword("totototo");

           DB.open();

              qDebug() << DB.connectionName();
              qDebug() << DB.isOpen();
              qDebug() << DB.contains();

           if(!DB.isOpen())           // Si l'ouverture as eu un problème ou non, afficher le message correspondant
                     {
                         qDebug("Erreur Ouverture");
                     }
                     else
                     {
                         qDebug("Ouverture reussie");
          }

          QSqlQuery prepare("select alias from pointeaux");
          if(!prepare.exec()){
              qDebug() << "probleme requete constructeur" << prepare.lastError();
          }
          else {
              QString BDD;
              while(prepare.next()){
                  BDD = prepare.value("alias").toString();
// dire de mettre sa dans le combobox page 3 pour afficher les pointeaux. Et mettre en relation avec QML -> problème
              }
          }
}
