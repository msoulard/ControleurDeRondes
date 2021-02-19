#include "pointeau.h"

Pointeau::Pointeau(QObject *parent) : QObject(parent)
{

}

Pointeau::Pointeau(const QString &lieu, const QString &etat, QObject *parent) :
    QObject(parent),
    m_lieu(lieu),
    m_etat(etat)
{

}

QString Pointeau::changerCouleur(int i)
{
    QString couleur;
    switch (i) {
    case 1 :
        couleur = "#00FF00"; //vert
        break;
    case 2 :
        couleur = "#ffa500"; //orange
        break;
    case 3 :
        couleur = "#0000FF"; //bleu
        break;
    case 4 :
        couleur = "#FF0000"; //rouge
        break;
    default:
        couleur = "black";
        break;
    }
    return couleur;
}

void Pointeau::horodater()
{
    horodatage = QDateTime::currentDateTime();
    qDebug() << horodatage;
}

QString Pointeau::lieu() const
{
    return m_lieu;
}

void Pointeau::setLieu(const QString &lieu)
{
    if(lieu != m_lieu){
        m_lieu = lieu;
        emit lieuChanged();
    }
}

QString Pointeau::etat() const
{
    return m_etat;
}

void Pointeau::setEtat(const QString &etat)
{
    if(etat != m_etat){
        m_etat = etat;
        emit etatChanged();
    }
}
