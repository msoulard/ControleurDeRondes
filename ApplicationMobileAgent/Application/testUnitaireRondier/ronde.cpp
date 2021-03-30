#include "ronde.h"

Ronde::Ronde(const QString _nom, const int _idRonde, QObject *parent) :
    QObject(parent),
    nom(_nom),
    idRonde(_idRonde)
{

}

QString Ronde::getNom() const
{
    return nom;
}

void Ronde::setNom(const QString &value)
{
    nom = value;
}
