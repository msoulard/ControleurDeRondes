#include "ihmstatistiques.h"
#include "ui_ihmstatistiques.h"

IHMStatistiques::IHMStatistiques(AccesMySQL &mySqlBdd, QWidget *parent):
  QWidget(parent),
  ui(new Ui::IHMStatistiques),
  bdd(mySqlBdd)
{
    ui->setupUi(this);

    ui->comboBoxFiltreAgent->setEnabled(true);
    ui->comboBoxFiltreNomRonde->setEnabled(true);
    ui->pushButtonDate1->setEnabled(true);
    ui->pushButtonDate2->setEnabled(true);
    ui->calendarWidgetFiltreDate1->hide();
    ui->calendarWidgetFiltreDate2->hide();
    ui->radioButton1FiltreDate->setEnabled(true);
    ui->radioButton2FiltreDate->setEnabled(true);
    ui->radioButton3FiltreDate->setEnabled(true);
    ui->radioButton4FiltreDate->setEnabled(true);
}

IHMStatistiques::~IHMStatistiques()
{

}

void IHMStatistiques::on_pushButtonDate1_clicked()
{
    if(ui->calendarWidgetFiltreDate1->isVisible())
    {
        ui->calendarWidgetFiltreDate1->hide();
    }
    else
    {
        ui->calendarWidgetFiltreDate1->show();
    }
    qDebug("Appuie detecte");
}

void IHMStatistiques::on_pushButtonDate2_clicked()
{
    if(ui->calendarWidgetFiltreDate2->isVisible())
    {
        ui->calendarWidgetFiltreDate2->hide();
    }
    else
    {
        ui->calendarWidgetFiltreDate2->show();
    }
}
