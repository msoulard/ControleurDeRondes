#include "pointeaux.h"

Pointeaux::Pointeaux(QObject *parent) : QObject(parent)
{

}

Pointeaux::Pointeaux(const QString &_designation, const QString &_couleur, QObject *parent) :
    QObject(parent),
    m_designation(_designation),
    m_couleur(_couleur)
{

}

QString Pointeaux::changerCouleur(int i)
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

void Pointeaux::horodater()
{
    horodatage = QDateTime::currentDateTime();
    qDebug() << horodatage;
}

QString Pointeaux::designation() const
{
    return m_designation;
}

void Pointeaux::setDesignation(const QString &_designation)
{
    if(_designation != m_designation){
        m_designation = _designation;
        emit designationChanged();
    }
}

QString Pointeaux::couleur() const
{
    return m_couleur;
}

void Pointeaux::setCouleur(const QString &_couleur)
{
    if(_couleur != m_couleur){
        m_couleur = _couleur;
        emit couleurChanged();
    }
}
