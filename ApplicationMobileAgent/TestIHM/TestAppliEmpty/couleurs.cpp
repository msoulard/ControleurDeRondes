#include "couleurs.h"

Couleurs::Couleurs(QObject *parent) : QObject(parent)
{

}

Couleurs::Couleurs(const QString &name, const QString &color, QObject *parent) :
    QObject(parent),
    m_name(name),
    m_color(color)
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

QString Couleurs::lieu() const
{
    return m_name;
}

void Couleurs::setLieu(const QString &name)
{
    if(name != m_name){
        m_name = name;
        emit lieuChanged();
    }
}

QString Couleurs::etat() const
{
    return m_color;
}

void Couleurs::setEtat(const QString &color)
{
    if(m_color != color){
        m_color = color;
        emit etatChanged();
    }
}
