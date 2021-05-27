/**
   @file AccesSqlite.cpp
 * @brief Implémentation de la classe AccesSqlite
 * @details Classe permettant l'acces à la base de données SQLite
 * @version 1.0
 * @author Damien CABARET
 * @date 03/04/2021
 */

#include "accessqlite.h"

/**
 * @brief AccesSqlite::AccesSqlite
 */
AccesSqlite::AccesSqlite()
{

}

/**
 * @brief AccesSqlite::ConnexionBddSqlite
 * @return
 */
bool AccesSqlite::ConnexionBddSqlite()
{
    bool reussite = false;

    bddSqlite = QSqlDatabase::addDatabase("QSQLITE");
    bddSqlite.setDatabaseName(QDir::currentPath().toLatin1() + "/BDD/RondierBDDVide.db");

    if(!bddSqlite.open())
    {
        qDebug()<<"Probleme d'accès à la base de données SQLite"<<bddSqlite.lastError();
    }
    else{
        reussite = true;
        qDebug()<<"Accès à la base de données SQLite ok";
    }

    return reussite;

}

/**
 * @brief AccesSqlite::RecupererAnomalies
 * @param _ListeAnomalie
 */
void AccesSqlite::RecupererAnomalies(QList<Anomalie> &_ListeAnomalie)
{
    Anomalie anomalieScannee;

    QSqlQuery requete(bddSqlite);
    if(requete.exec("SELECT id_anomalie, description FROM anomalies;"))
    {
        while (requete.next())
        {
            anomalieScannee.idAnomalie = requete.value("id_anomalie").toInt();
            anomalieScannee.description = requete.value("description").toString();
            _ListeAnomalie.append(anomalieScannee);
        }
    }
    else
    {
        qDebug() <<
                    "Erreur lors de la requête  "
                    + requete.lastError().text();
    }
}

/**
 * @brief AccesSqlite::RecupererAEteEffectuePar
 * @param _ListeaEteEffectueePar
 */
void AccesSqlite::RecupererAEteEffectuePar(QList<aEteEffectueePar> &_ListeaEteEffectueePar)
{
    aEteEffectueePar rondeEffectuee;

    QSqlQuery requete(bddSqlite);
    if(requete.exec("SELECT id_historiqueRonde, id_ronde, id_agent, date_heure FROM aEteEffectueePar;"))
    {
        while (requete.next())
        {
            rondeEffectuee.idHistoriqueRonde = requete.value("id_historiqueRonde").toInt();
            rondeEffectuee.idRonde = requete.value("id_ronde").toInt();
            rondeEffectuee.idAgent = requete.value("id_agent").toInt();
            rondeEffectuee.dateHeure = requete.value("date_heure").toString();
            _ListeaEteEffectueePar.append(rondeEffectuee);
        }
    }
    else
    {
        qDebug() <<
                    "Erreur lors de la requête  "
                    + requete.lastError().text();
    }
}

/**
 * @brief AccesSqlite::RecupererAEteScannePar
 * @param _ListeaEteScannePar
 */
void AccesSqlite::RecupererAEteScannePar(QList<aEteScannePar> &_ListeaEteScannePar)
{
    aEteScannePar pointeauScanne;

    QSqlQuery requete(bddSqlite);
    if(requete.exec("SELECT id, id_pointeau, id_anomalie, ordre, date_heure, id_historiqueRonde "
                    "FROM aEteScannePar;"))
    {
        while (requete.next())
        {
            pointeauScanne.idScanne = requete.value("id").toInt();
            pointeauScanne.idPointeau = requete.value("id_pointeau").toInt();
            pointeauScanne.idAnomalie = requete.value("id_anomalie").toInt();
            pointeauScanne.ordre = requete.value("ordre").toInt();
            pointeauScanne.dateHeure = requete.value("date_heure").toString();
            pointeauScanne.idHistoriqueRonde = requete.value("id_historiqueRonde").toInt();
            _ListeaEteScannePar.append(pointeauScanne);
        }
    }
    else
    {
        qDebug() <<
                    "Erreur lors de la requête "
                    + requete.lastError().text();
    }
}

/**
 * @brief AccesSqlite::RecupererPhoto
 * @param _ListePhoto
 */
void AccesSqlite::RecupererPhoto(QList<Photo> &_ListePhoto)
{
    Photo photoAnomalie;

    QSqlQuery requete(bddSqlite);
    if(requete.exec("SELECT id_photo, chemin, id_anomalie FROM photos;"))
    {
        while (requete.next())
        {
            photoAnomalie.idPhoto  = requete.value("id_photo").toInt();
            photoAnomalie.chemin  = requete.value("chemin").toString();
            photoAnomalie.idAnomalieFK  = requete.value("id_anomalie").toInt();
            _ListePhoto.append(photoAnomalie);
        }
    }
    else
    {
        qDebug() <<
                    "Erreur lors de la requête  "
                    + requete.lastError().text();
    }
}

/**
 * @brief AccesSqlite::TransfererRonde
 * @param laRonde
 */
void AccesSqlite::TransfererRonde(Ronde laRonde)
{   
    QSqlQuery requete(bddSqlite);
    requete.prepare("insert into rondes (id_ronde, nom) values (:idronde, :nomRonde);");
    requete.bindValue(":idronde", laRonde.idRonde);
    requete.bindValue(":nomRonde", laRonde.NomRonde);
    if (!requete.exec()){
        qDebug()<<"pb ajout ronde : "<<requete.lastError();
    }
}

/**
 * @brief AccesSqlite::TransfererPointeau
 * @param lePointeau
 * @param unLieu
 */
void AccesSqlite::TransfererPointeau(Pointeau lePointeau, Lieux unLieu)
{
    QSqlQuery requete(bddSqlite);
    requete.prepare("insert into pointeaux (id_pointeau, designation, tag_mifare, batiment, etage, emplacement) values (:idpointeau, :designation, :tagmifare, :batiment, :etage, :emplacement);");
    requete.bindValue(":idpointeau", lePointeau.idPointeau);
    requete.bindValue(":designation", lePointeau.designation);
    requete.bindValue(":tagmifare", lePointeau.tagMifare);
    requete.bindValue(":batiment", unLieu.batiment);
    requete.bindValue(":etage", unLieu.etage);
    requete.bindValue(":emplacement", unLieu.emplacement);
    if (!requete.exec()){
        qDebug()<<"pb ajout pointeau : "<<requete.lastError();
    }
}

/**
 * @brief AccesSqlite::TransfererAgent
 * @param unAgent
 */
void AccesSqlite::TransfererAgent(Agent unAgent)
{
    QSqlQuery requete(bddSqlite);
    requete.prepare("insert into agents (id_agent, nom, prenom, numbadge) values (:idagent, :nom, :prenom, :numbadge);");
    requete.bindValue(":idagent", unAgent.idAgent);
    requete.bindValue(":nom", unAgent.nomAgent);
    requete.bindValue(":prenom", unAgent.prenomAgent);
    requete.bindValue(":numbadge", unAgent.numBadgeAgent);
    if (!requete.exec()){
        qDebug()<<"pb ajout agent : "<<requete.lastError();
    }
}

/**
 * @brief AccesSqlite::TransfererLieu
 * @param unLieu
 */
void AccesSqlite::TransfererLieu(Lieux unLieu)
{
    QSqlQuery requete(bddSqlite);
    requete.prepare("insert into pointeaux (batiment, etage, emplacement) values (:batiment, :etage, :emplacement);");
    requete.bindValue(":batiment", unLieu.batiment);
    requete.bindValue(":etage", unLieu.etage);
    requete.bindValue(":emplacement", unLieu.emplacement);
    if (!requete.exec()){
        qDebug()<<"pb ajout lieu : "<<requete.lastError();
    }
}

/**
 * @brief AccesSqlite::TransfererAnomalie1
 * @param IdAnomalie
 * @param descriptionAnomalie
 */
void AccesSqlite::TransfererAnomalie1(int IdAnomalie, QString descriptionAnomalie)
{
    QSqlQuery requete(bddSqlite);
    requete.prepare("insert into anomalies (id_anomalie, description) values (:idanomalie, :description);");
    requete.bindValue(":idanomalie", IdAnomalie);
    requete.bindValue(":description", descriptionAnomalie);
    if (!requete.exec()){
        qDebug()<<"pb ajout anomalie ordre : "<<requete.lastError();
    }
}

/**
 * @brief AccesSqlite::TransfererPeutFaire
 * @param unPeutFaire
 */
void AccesSqlite::TransfererPeutFaire(peutFaire unPeutFaire)
{
    QSqlQuery requete(bddSqlite);
    requete.prepare("insert into peutFaire (id, id_agent, id_ronde) values (:id, :idagent, :idronde);");
    requete.bindValue(":id", unPeutFaire.idPeutFaire);
    requete.bindValue(":idagent", unPeutFaire.idAgent);
    requete.bindValue(":idronde", unPeutFaire.idRonde);
    if (!requete.exec()){
        qDebug()<<"pb ajout peutFaire : "<<requete.lastError();
    }
}

/**
 * @brief AccesSqlite::TransfererComporte
 * @param unComporte
 */
void AccesSqlite::TransfererComporte(Comporte unComporte)
{
    QSqlQuery requete(bddSqlite);
    requete.prepare("insert into comporte (id_ronde, id_pointeau, ordre, tempsmini, tempsmaxi) values (:idronde, :idpointeau, :ordre, :tempsmini, :tempsmaxi);");
    requete.bindValue(":idronde", unComporte.idRonde);
    requete.bindValue(":idpointeau", unComporte.idPointeau);
    requete.bindValue(":ordre", unComporte.ordre);
    requete.bindValue(":tempsmini", unComporte.tempsMini);
    requete.bindValue(":tempsmaxi", unComporte.tempsMaxi);
    if (!requete.exec()){
        qDebug()<<"pb ajout comporte : "<<requete.lastError();
    }
}

/**
 * @brief AccesSqlite::TransfereraEteEffectueePar
 * @param unaEteEffectueePar
 */
void AccesSqlite::TransfereraEteEffectueePar(aEteEffectueePar unaEteEffectueePar)
{
    QSqlQuery requete(bddSqlite);
    requete.prepare("insert into aEteEffectueePar (id_historiqueRonde, id_ronde, id_agent, date_heure) values (:id_historiqueRonde, :idronde, :idagent, :dateHeure);");
    requete.bindValue(":id_historiqueRonde", unaEteEffectueePar.idHistoriqueRonde);
    requete.bindValue(":idronde", unaEteEffectueePar.idRonde);
    requete.bindValue(":idagent", unaEteEffectueePar.idAgent);
    requete.bindValue(":dateHeure", unaEteEffectueePar.dateHeure);
    if (!requete.exec()){
        qDebug()<<"pb ajout comporte : "<<requete.lastError();
    }
}

void AccesSqlite::FermerBDD()
{
    bddSqlite.close();
}
