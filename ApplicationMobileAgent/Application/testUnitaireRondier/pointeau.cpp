#include "pointeau.h"


Pointeau::Pointeau(QObject *parent) : QObject(parent)
{

}

int Pointeau::horodater()
{

    horodatage = QDateTime::currentDateTime();
    qDebug() << horodatage;
    return 45;
}
//void Pointeaux::horodater()
//{
//    horodatage = QDateTime::currentDateTime();
//    qDebug() << horodatage;
//}
QString Pointeau::getDesignation() const
{
    return designation;
}

void Pointeau::setDesignation(const QString &value)
{
    designation = value;
}

QString Pointeau::getCouleur() const
{
    return couleur;
}

void Pointeau::setCouleur(const QString &value)
{
    couleur = value;
}

int Pointeau::getNum() const
{
    return num;
}

void Pointeau::setNum(int value)
{
    num = value;
}
