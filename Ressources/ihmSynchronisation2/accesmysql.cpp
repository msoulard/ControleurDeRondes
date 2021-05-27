/**
   @file AccesMySQL.cpp
 * @brief Implémentation de la classe AccesMySQL
 * @details Classe permettant l'acces à la base de données MySQL
 * @version 1.0
 * @author Damien CABARET
 * @date 03/04/2021
 */

#include "accesmysql.h"

/**
 * @brief AccesMySQL::AccesMySQL
 */
AccesMySQL::AccesMySQL()
{

}

bool AccesMySQL::ConnexionMysql()
{
    bool reussite = false;

    bddMysql = QSqlDatabase::addDatabase("QMYSQL");
    bddMysql.setHostName("172.18.58.7");
    bddMysql.setDatabaseName("StationAccueilOuijdane");
    bddMysql.setUserName("snir");
    bddMysql.setPassword("snir");

    if(!bddMysql.open())
    {

        qDebug()<<"pb acces bdd"<<bddMysql.lastError();
    }
    else{
        reussite = true;
        qDebug()<<"Acces BDD MYSQL ok";
    }

    return reussite;
}


/**
 * @brief AccesMySQL::TransfererRondes
 * @param idRonde
 * @param idAgent
 * @param dateHeure
 */
void AccesMySQL::TransfererRondes(int idRonde, int idAgent, QString dateHeure)
{
    QSqlQuery requete(bddMysql);
    requete.prepare("insert into aEteEffectueePar_2 (id_ronde, id_agent, date_heure) values (:idronde, :idagent, :dateHeure);");
    requete.bindValue(":idronde", idRonde);
    requete.bindValue(":idagent", idAgent);
    requete.bindValue(":dateHeure", dateHeure);
    if (!requete.exec()){
        qDebug()<<"pb ajout Rondes : "<<requete.lastError();
    }
}

/**
 * @brief AccesMySQL::TransfererAnomalie
 * @param anomalieScannee
 */
void AccesMySQL::TransfererAnomalie(Anomalie anomalieScannee)
{
    QSqlQuery requete(bddMysql);
    requete.prepare("insert into anomalies (id_anomalie, description) values (:idanomalie, :description);");
    requete.bindValue(":idanomalie", anomalieScannee.idAnomalie);
    requete.bindValue(":description", anomalieScannee.description);
    if (!requete.exec()){
        qDebug()<<"pb ajout Anomalie : "<<requete.lastError();
    }
}

/**
 * @brief AccesMySQL::TransfererPhoto
 * @param photoAnomalie
 */
void AccesMySQL::TransfererPhoto(Photo photoAnomalie)
{
    QSqlQuery requete(bddMysql);
    requete.prepare("insert into photos (id_photo, chemin, id_anomalie) values (:idphoto, :chemin, :idanomalie);");
    requete.bindValue(":idphoto", photoAnomalie.idPhoto);
    requete.bindValue(":chemin", photoAnomalie.chemin);
    requete.bindValue(":idanomalie", photoAnomalie.idAnomalieFK);
    if (!requete.exec()){
        qDebug()<<"pb ajout Photo : "<<requete.lastError();
    }
}

/**
 * @brief AccesMySQL::TransfereraEteEffectueePar
 * @param rondeEffectuee
 */
void AccesMySQL::TransfereraEteEffectueePar(aEteEffectueePar rondeEffectuee)
{
    QSqlQuery requete(bddMysql);
    requete.prepare("insert into aEteEffectueePar (id_ronde, id_agent, date_heure) values (:idronde, :idagent, :dateHeure);");
    //requete.bindValue(":idhistorique", rondeEffectuee.idHistoriqueRonde);
    requete.bindValue(":idronde", rondeEffectuee.idRonde);
    requete.bindValue(":idagent", rondeEffectuee.idAgent);
    requete.bindValue(":dateHeure", rondeEffectuee.dateHeure);
    if (!requete.exec()){
        qDebug()<<"pb ajout aEteEffectueePar : "<<requete.lastError();
    }
}

/**
 * @brief AccesMySQL::TransfereraEteScannePar
 * @param pointeauScanne
 */
void AccesMySQL::TransfereraEteScannePar(aEteScannePar pointeauScanne)
{
    QSqlQuery requete(bddMysql);
    requete.prepare("insert into aEteScannePar (id_pointeau, id_anomalie, ordre, date_heure, id_historiqueRonde) values (:id_pointeau, :id_anomalie, :ordre, :date_heure, :id_historiqueRonde);");
    //requete.bindValue(":id", pointeauScanne.idPointeau);
    requete.bindValue(":id_pointeau", pointeauScanne.idPointeau);
    requete.bindValue(":id_anomalie", pointeauScanne.idAnomalie);
    requete.bindValue(":ordre", pointeauScanne.ordre);
    requete.bindValue(":date_heure", pointeauScanne.dateHeure);
    requete.bindValue(":id_historiqueRonde", pointeauScanne.idHistoriqueRonde);
    if (!requete.exec()){
        qDebug()<<"pb ajout aEteScannePar : "<<requete.lastError();
    }
}

/**
 * @brief AccesMySQL::RecupererRonde
 * @param _ListeRonde
 */
void AccesMySQL::RecupererRonde(QList<Ronde> &_ListeRonde)
{
    Ronde rondeCourante;

    QSqlQuery requete(bddMysql);
    if(requete.exec("SELECT id_ronde, nom FROM rondes WHERE statut = 0;"))
    {
        while (requete.next())
        {
            rondeCourante.idRonde = requete.value("id_ronde").toInt();
            rondeCourante.NomRonde = requete.value("nom").toString();
            _ListeRonde.append(rondeCourante);
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
 * @brief AccesMySQL::RecupererAgent
 * @param _ListeAgent
 */
void AccesMySQL::RecupererAgent(QList<Agent> &_ListeAgent)
{
    Agent AgentCourant;

    QSqlQuery requete(bddMysql);
    if(requete.exec("SELECT id_agent, nom, prenom, numbadge FROM agents WHERE statut = 0;"))
    {
        while (requete.next())
        {
            AgentCourant.idAgent = requete.value("id_agent").toInt();
            AgentCourant.nomAgent = requete.value("nom").toString();
            AgentCourant.prenomAgent = requete.value("prenom").toString();
            AgentCourant.numBadgeAgent = requete.value("numbadge").toString();
            _ListeAgent.append(AgentCourant);
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
 * @brief AccesMySQL::RecupererPointeaux
 * @param _ListePointeau
 */
void AccesMySQL::RecupererPointeaux(QList<Pointeau> &_ListePointeau)
{
    Pointeau pointeauCourant;
    QSqlQuery requete(bddMysql);

    if(requete.exec("SELECT id_pointeau, designation, tag_mifare FROM pointeaux WHERE statut = 0;"))
    {
        while (requete.next())
        {
            pointeauCourant.idPointeau = requete.value("id_pointeau").toInt();
            pointeauCourant.designation = requete.value("designation").toString();
            pointeauCourant.tagMifare = requete.value("tag_mifare").toString();
            _ListePointeau.append(pointeauCourant);
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
 * @brief AccesMySQL::RecupererPeutFaire
 * @param _ListePeutFaire
 */
void AccesMySQL::RecupererPeutFaire(QList<peutFaire> &_ListePeutFaire)
{
    peutFaire peutFaireCourant;

    QSqlQuery requete(bddMysql);
    if(requete.exec("SELECT id, peutFaire.id_agent, peutFaire.id_ronde FROM peutFaire INNER JOIN rondes ON peutFaire.id_ronde = rondes.id_ronde INNER JOIN agents ON peutFaire.id_agent = agents.id_agent WHERE rondes.statut = 0 AND agents.statut = 0;"))
    {
        while (requete.next())
        {
            peutFaireCourant.idPeutFaire = requete.value("id").toInt();
            peutFaireCourant.idAgent = requete.value("id_agent").toInt();
            peutFaireCourant.idRonde = requete.value("id_ronde").toInt();
            _ListePeutFaire.append(peutFaireCourant);
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
 * @brief AccesMySQL::RecupererLieux
 * @param _ListeLieu
 */
void AccesMySQL::RecupererLieux(QList<Lieux> &_ListeLieu)
{
    Lieux lieuCourant;

    QSqlQuery requete(bddMysql);
    if(requete.exec("SELECT id_lieu, batiment, etage, emplacement, pointeaux.id_pointeau FROM lieux INNER JOIN pointeaux ON lieux.id_pointeau = pointeaux.id_pointeau WHERE pointeaux.statut = 0 ORDER BY pointeaux.id_pointeau ASC;"))
    {
        while (requete.next())
        {
            lieuCourant.idLieu = requete.value("id_lieu").toInt();
            lieuCourant.batiment = requete.value("batiment").toString();
            lieuCourant.etage = requete.value("etage").toString();
            lieuCourant.emplacement = requete.value("emplacement").toString();
            lieuCourant.idPointeauLieu = requete.value("id_pointeau").toInt();
            _ListeLieu.append(lieuCourant);
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
 * @brief AccesMySQL::RecupererComporte
 * @param _ListeComporte
 */
void AccesMySQL::RecupererComporte(QList<Comporte> &_ListeComporte)
{
    Comporte comporteCourant;

    QSqlQuery requete(bddMysql);
    if(requete.exec("SELECT id, comporte.id_ronde, id_pointeau, ordre, tempsmini, tempsmaxi FROM comporte INNER JOIN rondes ON comporte.id_ronde = rondes.id_ronde WHERE rondes.statut = 0 ;"))
    {
        while (requete.next())
        {
            comporteCourant.idComporte = requete.value("id").toInt();
            comporteCourant.idRonde = requete.value("id_ronde").toInt();
            comporteCourant.idPointeau = requete.value("id_pointeau").toInt();
            comporteCourant.ordre = requete.value("ordre").toInt();
            comporteCourant.tempsMini = requete.value("tempsmini").toString();
            comporteCourant.tempsMaxi = requete.value("tempsmaxi").toString();
            _ListeComporte.append(comporteCourant);
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
 * @brief AccesMySQL::RecupererAnomalie1
 * @param _description
 */
void AccesMySQL::RecupererAnomalie1(QString &_description)
{
    QSqlQuery requete(bddMysql);
    if(requete.exec("SELECT description FROM anomalies WHERE id_anomalie = 1;"))
    {
        while (requete.next())
        {
            _description.append(requete.value("description").toString());
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
 * @brief AccesMySQL::RecupereraEteEffectueePar
 * @param _ListeaEteEffectueePar
 */
void AccesMySQL::RecupereraEteEffectueePar(QList<aEteEffectueePar> &_ListeaEteEffectueePar)
{
    aEteEffectueePar aEteEffectueeParCourant;

    QSqlQuery requete(bddMysql);
    if(requete.exec("SELECT id_historiqueRonde, aEteEffectueePar.id_ronde, aEteEffectueePar.id_agent, date_heure FROM aEteEffectueePar INNER JOIN rondes ON aEteEffectueePar.id_ronde = rondes.id_ronde INNER JOIN agents ON aEteEffectueePar.id_agent = agents.id_agent ;"))
    {
        while (requete.next())
        {
            aEteEffectueeParCourant.idHistoriqueRonde = requete.value("id_historiqueRonde").toInt();
            aEteEffectueeParCourant.idRonde = requete.value("id_ronde").toInt();
            aEteEffectueeParCourant.idAgent = requete.value("id_agent").toInt();
            aEteEffectueeParCourant.dateHeure = requete.value("date_heure").toString();
            _ListeaEteEffectueePar.append(aEteEffectueeParCourant);
        }
    }
    else
    {
        qDebug() <<
                    "Erreur lors de la requête SELECT aEteEffectueePar "
                    + requete.lastError().text();
    }
}

void AccesMySQL::FermerBDD()
{
    bddMysql.close();
}

/**
 * @brief AccesMySQL::TransfererPointeaux
 * @param idPointeau
 * @param idAgent
 * @param idRonde
 * @param idAnomalie
 * @param ordre
 * @param temps
 */
void AccesMySQL::TransfererPointeaux(int idPointeau, int idAgent, int idRonde, int idAnomalie, int ordre, QString temps)
{
    QSqlQuery requete(bddMysql);
    requete.prepare("insert into aEteScannePar (id_pointeau, id_agent, id_ronde, id_anomalie, ordre, temps) values (:idpointeau, :idagent, :idronde, :idanomalie, :ordre, :temps);");
    requete.bindValue(":idpointeau", idPointeau);
    requete.bindValue(":idagent", idAgent);
    requete.bindValue(":idronde", idRonde);
    requete.bindValue(":idanomalie", idAnomalie);
    requete.bindValue(":ordre", ordre);
    requete.bindValue(":temps", temps);
    if (!requete.exec()){
        qDebug()<<"pb ajout ronde : "<<requete.lastError();
    }
}
