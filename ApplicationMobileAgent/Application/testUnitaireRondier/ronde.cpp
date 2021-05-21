#include "ronde.h"

/**
 * @brief Ronde::Ronde
 * @param parent
 */
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
    AccesBdd bdd;
    qDebug() << "index courant : " << indexRondeCourante ;
    qDebug() << "nom de la ronde courante (MAJ index) : " << bdd.getListeRondes().at(indexRondeCourante)->getNom();
}

/**
 * @brief Ronde::obtenirNomRonde
 * @return
 */
QString Ronde::obtenirNomRondeCourante()
{
    mettreAJourIndexCourant(1);
    AccesBdd bdd;
    QString nomRonde = "";
    if(indexRondeCourante != -1){
        qDebug() << bdd.getListeRondes().at(indexRondeCourante)->getNom();
        //nomRonde = bdd.getListeRondes().at(indexRondeCourante)->getNom();
    }
    qDebug() << "nom de la ronde courante : " << nomRonde;
    return nomRonde;
}

/**
 * @brief Ronde::obtenirIdRondeCourante
 * @return
 */
int Ronde::obtenirIdRondeCourante()
{
    int idRonde = 0;
    AccesBdd bdd;
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
