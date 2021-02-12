#include "couleurs.h"

Couleurs::Couleurs(QObject *parent) : QObject(parent)
{

}

QString Couleurs::changerCouleur(int i)
{
    QString couleur;
    switch (i) {
    case 1 :
        couleur = "green";
        break;
    case 2 :
        couleur = "orange";
        break;
    case 3 :
        couleur = "blue";
        break;
    case 4 :
        couleur = "red";
        break;
    default:
        couleur = "black";
        break;
    }
     return couleur;
}
