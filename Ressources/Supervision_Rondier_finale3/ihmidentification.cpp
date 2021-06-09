/**
   @file ihmidentification.cpp
 * @brief The IHMIdentification class
 * @details Déclaration des méthodes et des slots de la classe IHMIdentification
 * @authors Letessier Yoann
 * @date 25/05/2021
 */

#include "ihmidentification.h"
#include "ui_ihmidentification.h"

IHMIdentification::IHMIdentification(AccesMySQL &mySqlBdd, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IHMIdentification)
{
    ui->setupUi(this);
    AfficherImageClient();
}

/**
 * @brief IHMIdentification::~IHMIdentification
 */
IHMIdentification::~IHMIdentification()
{
    delete ui;
}

/**
 * @brief IHMIdentification::AfficherImageClient
 * @param cheminImage
 */
void IHMIdentification::AfficherImageClient()
{
    ui->labelImageClient->setPixmap(QPixmap(":/img/images/BarbeDevauxLogo.png"));
    ui->labelImageClient->setAlignment(Qt::AlignCenter);
}

/**
 * @brief IHMIdentification::on_pushButtonConnexion_clicked
 */
void IHMIdentification::on_pushButtonConnexion_clicked()
{
    if(ui->lineEditIdentifiant->text().simplified().isEmpty() == true || ui->lineEditMDP->text().simplified().isEmpty() == true)
    {
        qDebug() << "L'un des champs est vide !";
    }
    else
    {
        if(bdd.VerifierResponsable(ui->lineEditIdentifiant->text(), ui->lineEditMDP->text()))
        {
            responsableConnecteBool = true;
            emit responsableConnecte();
        }
    }
}
