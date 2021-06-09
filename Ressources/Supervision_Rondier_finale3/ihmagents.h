/**
   @file ihmagents.h
 * @brief The IhmAgents class
 * @version 1.0
 * @details Déclaration de la classe IhmAgents héritant de la classe QWidget
 * @authors Letessier Yoann
 * @date 25/05/2021
 */
#ifndef IHMAGENTS_H
#define IHMAGENTS_H

#include <QWidget>
#include <QObject>
#include "QList"
#include "accesmysql.h"
#include "agents.h"
#include "message.h"
#include "modifagent.h"
#include "creationagent.h"

namespace Ui {
class IhmAgents;
}
class IhmAgents : public QWidget
{
    Q_OBJECT

public:
    explicit IhmAgents(QList<Agents *> &_listeAgents, AccesMySQL & mySqlBdd, QWidget *parent = nullptr);
    ~IhmAgents();

    void ActualiserListeDesAgents();
    void ActualiserListeNomAgent();
    void ActualiserListeBadgeAgent();
    void ActualiserStatutAgent();
    void InitialiserTableaux();
    void ActualiserTableauFiltres();
    bool DemanderEnregistrement();
    void ObtenirNomAgent(QList<Agents *> liste);

private slots:
    void on_pushButtonAppliquer_clicked();
    void onpushButtonModifier_clicked();
    void on_comboBoxStatut_currentIndexChanged(int index);
    //void on_comboBoxNom_currentIndexChanged(int index);
    void on_pushButtonNouveau_clicked();

    void on_pushButtonActualiser_clicked();

private:
    Ui::IhmAgents *ui;
    //QPushButton  *QPushbuttonModifier;
    QList<Agents *> listeAgents;
    QList<QString> nomAgents;
    QList<QString> prenomAgents;
    QList<QString> badgeAgents;
    int idAgent;
    QList<int> idAgents;
    QList<bool> statutAgents;
    AccesMySQL bdd;
    ModifAgent *widgetModifAgent;
    CreationAgent *widgetCretionAgent;
    ///0 : aucun agent selectionné,
    /// 1 : un agent existant est sélectionné,
    /// 2 : un nouvel agent est sélectionné.
    int selectionAgent;
    ///True l'agent actuel est enregistré, false il ne l'ai pas.
    bool agentActuEnregiste;
    ///Index de l'agent actuel dans la combobox.
    int indexComboboxAgentActu;
    ///Index de l'agent actuel dans la liste d'agents.
    int idListeAgentActu;
    ///Permet d'afficher des messages.
    Message boiteMessage;
    QString nom;
    QString prenom;
    QString badge;
    QString statutInitial;
    int id_Agent;
};
#endif // IHMAGENTS_H
