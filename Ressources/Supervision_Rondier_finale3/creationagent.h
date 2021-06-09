/**
   @file creationagents.h
 * @brief The CreationAgents class
 * @version 1.0
 * @details Déclaration de la classe CreationAgents
 * @authors Letessier Yoann
 * @date 25/05/2021
 */
#ifndef CREATIONAGENT_H
#define CREATIONAGENT_H

#include <QWidget>
#include "agents.h"
#include "accesmysql.h"

namespace Ui {
class CreationAgent;
}

class CreationAgent : public QWidget
{
    Q_OBJECT

public:
    explicit CreationAgent(QWidget *parent = nullptr);
    ~CreationAgent();

private slots:
    void on_pushButtonEnregistrer_clicked();
    void on_pushButtonAnnuler_clicked();
    bool on_radioButtonActif_clicked();
    bool on_radioButtonInactif_clicked();

private:
    Ui::CreationAgent *ui;
    AccesMySQL bdd;
    QList<Agents *> listeAgents;
    bool statut;
};

#endif // CREATIONAGENT_H
