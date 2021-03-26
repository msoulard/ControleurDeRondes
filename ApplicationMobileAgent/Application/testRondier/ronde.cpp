#include "ronde.h"

Ronde::Ronde(QObject *parent) : QObject(parent)
{

}

QList<Ronde *> Ronde::obtenirListeRondes(int _idAgent)
{
    AccesBdd bdd;
    QList<Ronde*> listeRondes;
    listeRondes = bdd.obtenirRondes(_idAgent);
    return listeRondes;
}

QString Ronde::getNom() const
{
    return nom;
}

void Ronde::setNom(const QString &value)
{
    nom = value;
}

int Ronde::getId() const
{
    return id;
}

void Ronde::setId(int value)
{
    id = value;
}
