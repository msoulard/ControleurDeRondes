#include "ihmlocalisation.h"
#include "ui_ihmlocalisation.h"

IHMLocalisation::IHMLocalisation(AccesMySQL &mySqlBdd, QWidget *parent):
    QWidget(parent),
    ui(new Ui::IHMLocalisation),
    bdd(mySqlBdd)
{
    ui->setupUi(this);
}

IHMLocalisation::~IHMLocalisation()
{

}
