#include "pointeau.h"

Pointeau::Pointeau(QObject *parent) : QObject(parent)
{

}

Pointeau::Pointeau(const QString lieu, const QString etat, QObject *parent) :
    QObject(parent),
    m_lieu(lieu),
    m_etat(etat)
{

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
