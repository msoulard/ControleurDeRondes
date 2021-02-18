#include "widget_deroulementronde.h"
#include "ui_widget_deroulementronde.h"

Widget_DeroulementRonde::Widget_DeroulementRonde(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget_DeroulementRonde)
{
    ui->setupUi(this);
}

Widget_DeroulementRonde::~Widget_DeroulementRonde()
{
    delete ui;
}

