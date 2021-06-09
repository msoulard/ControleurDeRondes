/**
   @file supervisionrondier.h
 * @brief The SuperVisionRondier class
 * @details Déclaration de la classe SuperVisionRondier
 * @authors Letessier Yoann
 * @date 25/05/2021
 */
#ifndef SUPERVISIONRONDIER_H
#define SUPERVISIONRONDIER_H

#include <QMainWindow>
#include <QTabWidget>
#include <QWidget>

#include "gestionsmartphones.h"
#include "communicationadb.h"
#include "accesmysql.h"
#include "accesxml.h"
#include "ihmidentification.h"
#include "ihmagents.h"
#include "agents.h"
#include "ihmpointeaux.h"
#include "pointeaux.h"
#include "ihmlieux.h"
#include "lieu.h"
#include "ihmrondes.h"
#include "rondes.h"
#include "ihmassociation.h"
#include "ihmsynchronisation.h"
#include "historique.h"


QT_BEGIN_NAMESPACE
namespace Ui { class SuperVisionRondier; }
QT_END_NAMESPACE
/**
 * @brief The SuperVisionRondier class
 */
class SuperVisionRondier : public QMainWindow
{
    Q_OBJECT

public:
    SuperVisionRondier(QWidget *parent = nullptr);
    ~SuperVisionRondier();

private slots:
    //Slots Qt
    void onTabWidgetChange(int onglet);
    //Slots custom
    void onResponsableConnecte();

private:
    //Constantes
    const QString CHEMINXML = "configurations.xml";
    bool scannerActif;
    bool erreurScannerAffiche;
    ///Accès aux composants de l'IHM
    Ui::SuperVisionRondier *ui;
    ///Accès, connexion, vérification et modification de la base de données
    AccesMySQL *mySqlBdd;
    ///IHM identifiaction du responsable.
    IHMIdentification *widgetIdentification;
    ///Onglet de gestion des agents.
    IhmAgents *tabAgent;
    IhmPointeaux *tabPointeau;
    IhmLieux *tabLieu;
    IhmRondes *tabRonde;
    ihmSynchronisation *tabSynchronisation;
    QTabWidget *widgetTab;
    ///Liste des agents de la base de données.
    QList<Agents*> listeAgents;
    ///Liste des pointeaux de la base de données.
    QList<Pointeaux*> listePointeaux;
    ///Liste des rondes de la base de données.
    QList<Rondes *> listeRonde;
    IHMAssociation * tabAssociation;
    AccesXML *xmlConfig;
    Message boiteMessage;
    Historique *tabHistorique;

};
#endif // SUPERVISIONRONDIER_H
