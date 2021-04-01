#include "pointeau.h"

Pointeau::Pointeau(QObject *parent) : QObject(parent)
{

}

void Pointeau::horodater()
{
    horodatage = QDateTime::currentDateTime();
    qDebug() << horodatage;
}

QList<QString> Pointeau::obtenirListeDesignationsPointeaux(int _idRonde)
{
    //Accès à la base de données
    AccesBdd bdd;
    //Liste des désignations des pointeaux
    QList<QString> listeDesignations;
    //Intance d'une ronde permettant de récupérer le pointeau courant dans la boucle for
    Pointeau *pointeau;
    //Récupérer la liste des pointeaux correspondantes à la ronde choisie
    listePointeaux = bdd.obtenirPointeau(_idRonde);
    //Boucle qui permet de récupérer que les désignations des pointeaux
    for(int i = 0 ; i < listePointeaux.size() ; i ++){
        //Intanciation du pointeau
        pointeau = new Pointeau();
        //Mise à jour du pointeau avec les données du pointeau courant de la liste
        pointeau->setDesignation(listePointeaux.at(i)->getDesignation());
        //Ajouter les désignations des pointeaux dans la liste des désignations des pointeaux
        listeDesignations.append(pointeau->getDesignation());
    }
    //Afficher la liste des désignation dans la console
    qDebug() << "liste des désignations des pointeaux : " << listeDesignations;
    //Retourner la liste des désignations des pointeaux
    return listeDesignations;
}

QList<QString> Pointeau::obtenirListeCouleursPointeaux()
{
    QList<QString> listeCouleur;
    for(int i = 0 ; i < listePointeaux.size() ; i++){
        //Mettre à jour la couleur
        if (i==0){   // premier pointeau en bleu
            listeCouleur.append("#0000FF");
        }
        else{ //les suivant en noir
            listeCouleur.append("#000000");
        }
    }

    return listeCouleur;
}

QString Pointeau::getDesignation() const
{
    return designation;
}

void Pointeau::setDesignation(const QString &value)
{
    designation = value;
}

QString Pointeau::getCouleur() const
{
    return couleur;
}

void Pointeau::setCouleur(const QString &value)
{
    couleur = value;
}

int Pointeau::getIdPointeau() const
{
    return idPointeau;
}

void Pointeau::setIdPointeau(int value)
{
    idPointeau = value;
}

QString Pointeau::getTagMifare() const
{
    return tagMifare;
}

void Pointeau::setTagMifare(const QString &value)
{
    tagMifare = value;
}

QString Pointeau::getBatiment() const
{
    return batiment;
}

void Pointeau::setBatiment(const QString &value)
{
    batiment = value;
}

QString Pointeau::getEtage() const
{
    return etage;
}

void Pointeau::setEtage(const QString &value)
{
    etage = value;
}

QString Pointeau::getEmplacement() const
{
    return emplacement;
}

void Pointeau::setEmplacement(const QString &value)
{
    emplacement = value;
}

int Pointeau::getOrdre() const
{
    return ordre;
}

void Pointeau::setOrdre(int value)
{
    ordre = value;
}

QString Pointeau::getTempsMini() const
{
    return tempsMini;
}

void Pointeau::setTempsMini(const QString &value)
{
    tempsMini = value;
}

QString Pointeau::getTempsMaxi() const
{
    return tempsMaxi;
}

void Pointeau::setTempsMaxi(const QString &value)
{
    tempsMaxi = value;
}

