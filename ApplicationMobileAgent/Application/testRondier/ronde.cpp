#include "ronde.h"

Ronde::Ronde(QObject *parent) : QObject(parent)
{

}

/**
 * @brief Ronde::obtenirListeRondes
 * @param _numBadge
 * @return
 */
QList<QString> Ronde::obtenirListeRondes(QString _numBadge)
{
    ///Accès à la base de données
    AccesBdd bdd;
    ///Liste des noms des rondes
    QList<QString> listeNoms;
    ///Intance d'une ronde permettant de récupérer la ronde courante dans la boucle for
    Ronde *ronde;
    ///Récupérer la liste des rondes correspondantes à l'agent
    listeRondes = bdd.obtenirRondes(_numBadge);
    ///Boucle qui permet de récupérer que les noms des rondes
    for(int i = 0 ; i < listeRondes.size() ; i ++){
        ///Intanciation de la ronde
        ronde = new Ronde();
        ///Mise à jour de la ronde avec les données de la ronde courante de la liste
        ronde = listeRondes.at(i);
        ///Ajouter les noms des rondes dans la liste des noms des rondes
        listeNoms.append(ronde->getNom());
    }
    ///Afficher la liste des noms dans la console
    qDebug() << listeNoms;
    ///Retourner la liste des noms des rondes
    return listeNoms;
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
