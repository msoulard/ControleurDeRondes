/**
   @file creationpointeau.cpp
 * @brief The CreationPointeau class
 * @details Déclaration des méthodes de la classe CreationPointeau
 * @authors Letessier Yoann
 * @date 25/05/2021
 */

#include "creationpointeau.h"
#include "ui_creationpointeau.h"

CreationPointeau::CreationPointeau(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreationPointeau)
{
    ui->setupUi(this);
}

CreationPointeau::~CreationPointeau()
{
    delete ui;
}
