/**
   @file modifagent.h
 * @brief The ModifAgent class
 * @details Déclaration de la classe ModifAgent héritant de la classe QWidget
 * @authors Letessier Yoann
 * @date 25/05/2021
 */

#ifndef MODIFAGENT_H
#define MODIFAGENT_H

#include <QWidget>
#include "accesmysql.h"
#include "agents.h"

namespace Ui {
class ModifAgent;
}
class ModifAgent : public QWidget
{
    Q_OBJECT

public:
    explicit ModifAgent(QString _prenom, QString _nom, QString _badge, int _statut, int _id, QWidget *parent = nullptr);
    ~ModifAgent();

private slots:
    void on_pushButton_3_clicked();
    void AfficherAgent();
    void on_pushButton_4_clicked();
    bool on_radioButtonActif_clicked();
    bool on_radioButtonInactif_clicked();

private:
    Ui::ModifAgent *ui;
    AccesMySQL bdd;
    int selectionAgent;
    int idListeAgentActu;
    QList<Agents *> listeAgents;
    QList<QString> nomAgents;
    QList<QString> prenomAgents;
    QList<QString> badgeAgents;
    QList<bool> statutAgents;
    QString nom;
    QString prenom;
    QString badge;
    int statut;
    int id;

};

#endif // MODIFAGENT_H
