#ifndef IHMLOCALISATION_H
#define IHMLOCALISATION_H

#include <QObject>

// Qt
#include <QWidget>
#include <QTableWidgetItem>
#include <QSpinBox>
#include <QMessageBox>
#include <QComboBox>
#include <QMap>

#include "accesmysql.h"


namespace Ui {
class IHMLocalisation;
}

class IHMLocalisation : public QWidget
{
    Q_OBJECT

    ///------------------PUBLIC------------------///

public:
    explicit IHMLocalisation(AccesMySQL & mySqlBdd, QWidget *parent = 0);
    ~ IHMLocalisation();

    ///---------------PRIVATE-SLOTS--------------///

private slots:
    //Slots Qt

    ///------------------PRIVATE------------------///

private:

    //Ui
    Ui::IHMLocalisation *ui;
    AccesMySQL bdd;
};

#endif // IHMLOCALISATION_H
