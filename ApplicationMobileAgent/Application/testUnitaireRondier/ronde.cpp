#include "ronde.h"

Ronde::Ronde(QObject *parent) : QObject(parent)
{
    indexRondeCourante = -1;
}

/**
 * @brief Ronde::mettreAJourIndexCourant
 * @param _indexRonde
 */
void Ronde::mettreAJourIndexCourant(int _indexRonde)
{
    indexRondeCourante = _indexRonde;
    qDebug() << "index courant : " << indexRondeCourante ;
    qDebug() << "nom de la ronde courante (MAJ index) : " << bdd.getListeRondes().at(indexRondeCourante)->getNom();
}

/**
 * @brief Ronde::obtenirNomRonde
 * @return
 */
QString Ronde::obtenirNomRondeCourante()
{
    //mettreAJourIndexCourant(0);
    indexRondeCourante = 1;
    QString nomRonde = "";
    if(indexRondeCourante != -1){
        nomRonde = bdd.getListeRondes().at(indexRondeCourante)->getNom();
    }
    qDebug() << "nom de la ronde courante : " << nomRonde;
    return nomRonde;
}

int Ronde::obtenirIdRondeCourante()
{
    int idRonde = 0;
    if(indexRondeCourante != -1){
      idRonde = bdd.getListeRondes().at(indexRondeCourante)->getId();
    }
    return idRonde;
}

/**
 * @brief Ronde::getNom
 * @return
 */
QString Ronde::getNom() const
{
    return nom;
}

/**
 * @brief Ronde::setNom
 * @param value
 */
void Ronde::setNom(const QString &value)
{
    nom = value;
}

/**
 * @brief Ronde::getId
 * @return
 */
int Ronde::getId() const
{
    return id;
}

/**
 * @brief Ronde::setId
 * @param value
 */
void Ronde::setId(int value)
{
    id = value;
}
