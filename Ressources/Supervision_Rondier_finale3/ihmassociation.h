/**
   @file ihmassociation.h
 * @brief The IHMAssociation class
 * @version 1.0
 * @details Déclaration de la classe IhmAssociation héritant de la classe QWidget
 * @authors Letessier Yoann
 * @date 25/05/2021
 */
#ifndef IHMASSOCIATION_H
#define IHMASSOCIATION_H

#include <QWidget>
#include "rondes.h"
#include "agents.h"
#include "accesmysql.h"
#include "QList"

namespace Ui {
class IHMAssociation;
}

class IHMAssociation : public QWidget
{
    Q_OBJECT

public:
    explicit IHMAssociation(QList<Rondes *> &_listeRonde, QList<Agents *> &_listeAgent, AccesMySQL & mySqlBdd, QWidget *parent = nullptr);
    ~IHMAssociation();
    void ActualiserListeNomAgent();

private:
 Ui::IHMAssociation *ui;
    QList<Rondes *> listeRondes;
    QList<QString> nomRondes;
    QList<Agents *> listeAgents;
    QList<QString> nomAgents;
    AccesMySQL bdd;
};

#endif // IHMASSOCIATION_H
