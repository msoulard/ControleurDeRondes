/**
   @file accesmysql.cpp
 * @brief The AccesMySQL class
 * @details Déclaration des méthodes de la classe AccesMySQL
 * @authors  Gabriel Lemée et Letessier Yoann
 * @date 25/03/2021
 */

#include "accesmysql.h"
#include "ihmagents.h"
#include "ui_ihmagents.h"

AccesMySQL::AccesMySQL()
{

}

/**
 * @brief AccesMySQL::Connexion
 * @param adresse
 * @param port
 * @param nomBDD
 * @param utilisateur
 * @param mdp
 * @return
 */
bool AccesMySQL::Connexion(QString adresse, int port, QString nomBDD, QString utilisateur, QString mdp)
{
    bool reussite = false;

    mySqlBdd = QSqlDatabase::addDatabase("QMYSQL");
    mySqlBdd.setPort(port);
    mySqlBdd.setHostName(adresse);
    mySqlBdd.setDatabaseName(nomBDD);

    if(mySqlBdd.open(utilisateur, mdp))
    {
        reussite = true;
    }
    return reussite;

    if(!mySqlBdd.open()){
        qDebug() << "pb acces bd" << mySqlBdd.lastError();
    }else{
        qDebug() << "acces bd ok";
        reussite = true;
    }
    return reussite;
}

/**
 * @brief AccesMySQL::VerifierConnexion
 * @return
 */
bool AccesMySQL::VerifierConnexion()
{
    bool valide = false;

    if(!mySqlBdd.isOpen())
    {
        qDebug() << "pb acces bdd" << mySqlBdd.lastError();
        valide = true;
    }
    return valide;
}

/**
 * @brief AccesMySQL::VerifierResponsable
 * @param identifiant
 * @param mdp
 * @return
 */
bool AccesMySQL::VerifierResponsable(QString identifiant, QString mdp)
{
    bool valide = false;

    if(VerifierConnexion() == true)
    {
        QSqlQuery requete(mySqlBdd);
        requete.prepare("SELECT mdp FROM responsables WHERE login=:identifiant");
        requete.bindValue(":identifiant", identifiant);
        if(requete.exec())
        {
            if(requete.next())
            {
                if(requete.value("mdp").toString() == mdp)
                {
                    valide = true;
                }
                else
                {
                    qDebug() << "pb mot de passe" << mySqlBdd.lastError();
                }
            }
            else
            {
                qDebug() << "pb login" << mySqlBdd.lastError();
            }
        }
        else
        {
            qDebug() << "Erreur lors de la requête \"SELECT mdp FROM responsable\" : "
                        + requete.lastError().text();
        }
    }
    return valide;
}

/**
 * @brief AccesMysql::RecupererAgents
 * @details Cette méthode permet de recuperer le nom et le prenom des agents pour remplir la comboBox Agent
 * @param _ListeAgents
 * @return
 */
int AccesMySQL::RecupererAgents(QList<Agent> &_ListeAgents)
{
    int cpt = 0;
    Agent agentCourant;
    if(VerifierConnexion())
    {
        QSqlQuery requete(mySqlBdd);


        if(requete.exec("SELECT nom,prenom, id_agent FROM agents  ;"))
        {
            QString agent;

            while (requete.next())
            {
                agent = requete.value("nom").toString() + " " + requete.value("prenom").toString();
                agentCourant.nom=agent;
                agentCourant.id=requete.value("id_agent").toInt();
                _ListeAgents.append(agentCourant);
                cpt++;
            }
        }else{
            qDebug() <<
                        "Erreur lors de la requête  "
                        + requete.lastError().text();
        }
    }
    return cpt;
}
/**
 * @brief AccesMysql::RecupererRonde
 * @details Permet de recuperer le nom de la ronde effectuée par l'agent pour remplir la comboBox de la ronde
 * @param _ListeRonde
 * @param idAgent
 * @return
 */

int AccesMySQL::RecupererRonde(QList<Ronde> &_ListeRonde,int idAgent)
{
    int cpt = 0;
    Ronde rondeCourante;
    if(VerifierConnexion())
    {
        QSqlQuery requete(mySqlBdd);

        if(requete.prepare("SELECT rondes.nom,rondes.id_ronde from rondes,agents,aEteEffectueePar "
                           "where agents.id_agent=aEteEffectueePar.id_agent and aEteEffectueePar.id_ronde = rondes.id_ronde  and agents.id_agent=:ida;"))
        {
            requete.bindValue(":ida",idAgent);
            if(requete.exec())
            {
                while (requete.next())
                {
                    rondeCourante.nom = requete.value("nom").toString();
                    rondeCourante.id=requete.value("id_ronde").toInt();
                    _ListeRonde.append(rondeCourante);
                    cpt++;
                }
            }else{
                qDebug() <<
                            "Erreur lors exec  de la requête  "
                            + requete.lastError().text();
            }
        }
    }else{
        qDebug() <<
                    "Erreur connexion bdd lost  ";
    }
    return cpt;
}

/**
 * @brief AccesMysql::RecupererDescription
 * @details Cette méthode permet de récupérer la description de l'anomalie pour remplir le qTextBrowser qui est dans l'interface chronologieAnomalie
 * @param idAnomalie
 * @param _ListeChronologieAnomalie
 * @return
 */

QString AccesMySQL::RecupererDescription(int idAnomalie)
{
    QString anomalie;
    if(VerifierConnexion())
    {
        QSqlQuery requete(mySqlBdd);

        if(requete.prepare("SELECT description from anomalies,aEteScannePar where anomalies.id_anomalie=aEteScannePar.id_anomalie and aEteScannePar.id_anomalie=:idA;"))
        {
            requete.bindValue(":idA",idAnomalie);

            if(requete.exec())
            {
                while (requete.next())
                {
                    anomalie =requete.value("description").toString();
                }
            }else{

                qDebug() <<
                            "Erreur lors exec  de la requête  "
                            + requete.lastError().text();
            }
        }
    }else{
        qDebug() <<
                    "Erreur connexion bdd lost  ";
    }
    return anomalie;
}

/**
 * @brief AccesMysql::RecupererCheminImage
 * @details Cette méthode permet de récupérer le chemin de l'image de l'anomalie pour remplir les labels qui sont dans l'interface chronologieAnomalie
 * @param idAnomalie
 * @param _ListeChronologieAnomalie
 * @return
 */

QStringList AccesMySQL::RecupererCheminsImages(int idAnomalie)
{
    QStringList anomalies;
    if(VerifierConnexion())
    {
        QSqlQuery requete(mySqlBdd);

        if(requete.prepare("SELECT chemin from photos,anomalies where photos.id_anomalie=anomalies.id_anomalie and anomalies.id_anomalie=:idA ;"))
        {
            requete.bindValue(":idA",idAnomalie);

            if(requete.exec())
            {
                while (requete.next())
                {
                    anomalies.append(requete.value("chemin").toString());

                }
            }else{

                qDebug() <<
                            "Erreur lors exec  de la requête  "
                            + requete.lastError().text();
            }
        }
    }else{
        qDebug() <<
                    "Erreur connexion bdd lost  ";
    }
    return anomalies;

}


/**
 * @brief AccesMysql::RecupererTableauNiveauDeux
 * @details Cette méthode permet de remplir le tableau des l'historique du pointeaux
 * @param _ListeChronologieAnomalie
 * @param idHistoriqueRonde
 * @param _historiqueAnomalie
 */

void AccesMySQL::RecupererTableauNiveauDeux(QList<DonneesChronologieAnomalie> &_ListeChronologieAnomalie, int idHistoriqueRonde,QList<Anomalie> &_historiqueAnomalie)
{
    if(VerifierConnexion())
    {
        QSqlQuery requete(mySqlBdd);
        DonneesChronologieAnomalie donneesChronoAno;

        if(requete.prepare("select id_anomalie,ordre,designation,batiment,etage,emplacement,aEteScannePar.date_heure from aEteScannePar,pointeaux,lieux "
                           "where pointeaux.id_pointeau=aEteScannePar.id_pointeau and pointeaux.id_pointeau=lieux.id_pointeau and "
                           "aEteScannePar.id_historiqueRonde=:idR order by ordre ASC "))
        {
            requete.bindValue(":idR",idHistoriqueRonde);

            if(requete.exec())
            {
                while (requete.next())
                {
                    donneesChronoAno.ordre=requete.value("ordre").toInt();
                    donneesChronoAno.lieuRonde.designation=requete.value("designation").toString();
                    donneesChronoAno.lieuRonde.etage=requete.value("etage").toString();
                    donneesChronoAno.lieuRonde.emplacement=requete.value("emplacement").toString();
                    donneesChronoAno.lieuRonde.batiment=requete.value("batiment").toString();
                    donneesChronoAno.dateHeure=requete.value("date_heure").toDateTime();
                    donneesChronoAno.idAnomalie=requete.value("id_anomalie").toInt();
                    /*donneesChronoAno.cheminImage=requete.value("chemin").toString();
                    donneesChronoAno.description=requete.value("description").toString();*/
                    _ListeChronologieAnomalie.append(donneesChronoAno);
                }
            }else{

                qDebug() <<
                            "Erreur lors exec  de la requête  "
                            + requete.lastError().text();
            }
        }
    }else{
        qDebug() <<
                    "Erreur connexion bdd lost  ";
    }

}

/**
 * @brief AccesMysql::RecupererTabAnomalie
 * @details Cette méthode permet de remplir le tableau des anomalies (IMAGES ET DESCRIPTIONS) du PDF
 * @param _ListeChronologieAnomalie
 * @param idHistoriqueRonde
 */

void AccesMySQL::RecupererTabAnomalie(QList<DonneesChronologieAnomalie> &_ListeChronologieAnomalie, int idHistoriqueRonde)
{
    if(VerifierConnexion() == true)
    {
        QSqlQuery requete(mySqlBdd);
        DonneesChronologieAnomalie donneesChronoAno;

        if(requete.prepare("select aEteScannePar.id_anomalie,designation,batiment,etage,emplacement,description,chemin "
                           "from aEteScannePar,pointeaux,lieux,anomalies,photos where pointeaux.id_pointeau=aEteScannePar.id_pointeau and aEteScannePar.id_anomalie=anomalies.id_anomalie "
                           "and anomalies.id_anomalie=photos.id_anomalie and pointeaux.id_pointeau=lieux.id_pointeau and aEteScannePar.id_historiqueRonde=:idR order by ordre ASC;"))
        {
            requete.bindValue(":idR",idHistoriqueRonde);

            if(requete.exec())
            {
                while (requete.next())
                {
                    donneesChronoAno.lieuRonde.designation=requete.value("designation").toString();
                    donneesChronoAno.lieuRonde.etage=requete.value("etage").toString();
                    donneesChronoAno.lieuRonde.emplacement=requete.value("emplacement").toString();
                    donneesChronoAno.lieuRonde.batiment=requete.value("batiment").toString();

                    donneesChronoAno.idAnomalie=requete.value("id_anomalie").toInt();
                    donneesChronoAno.description=requete.value("description").toString();
                    donneesChronoAno.cheminImage=requete.value("chemin").toString();
                    _ListeChronologieAnomalie.append(donneesChronoAno);
                }
            }else{

                qDebug() <<
                            "Erreur lors exec  de la requête  "
                            + requete.lastError().text();
            }
        }
    }else{
        qDebug() <<
                    "Erreur connexion bdd lost  ";
    }
}

/**
 * @brief AccesMysql::RecupererDonneeTableauHistoriqueNiveau1
 * @details Cette méthode permet de récupérer le nom de la ronde, la date de debut et de fin et aussi le nbAnomalie en fonction des idAgent et idRonde pour remplir le tableau de l'historique des rondes
 * @param idAgent
 * @param idRonde
 * @param dateDebut
 * @param dateFin
 * @param _ListeHistorique
 */


void AccesMySQL::RecupererDonneeTableauHistoriqueNiveau1(int idAgent, int idRonde, QDateTime dateDebut, QDateTime dateFin, QList<DonneesHistorique> &_ListeHistorique)
{

    if(VerifierConnexion())
    {
        QSqlQuery requete(mySqlBdd);
        DonneesHistorique rondeCourante;
        int idHisto;
        // idAgent !=-1 idRonde!=-1 -> agent et ronde selectionne
        if(idAgent!=-1 && idRonde!=-1)
        {
            if(requete.prepare("select rondes.id_ronde,id_historiqueRonde,date_heure, nom from aEteEffectueePar,rondes "
                               "where id_agent=:idA and aEteEffectueePar.id_ronde=:idR and date_heure between :dateD and :dateF "
                               "and aEteEffectueePar.id_ronde=rondes.id_ronde;"))
            {
                requete.bindValue(":idA",idAgent);
                requete.bindValue(":idR",idRonde);
                requete.bindValue(":dateD",dateDebut);
                requete.bindValue(":dateF",dateFin);
                if(requete.exec())
                {
                    while (requete.next())
                    {
                        idHisto=requete.value("id_historiqueRonde").toInt();

                        QSqlQuery requeteAnomalie(mySqlBdd);
                        if(requeteAnomalie.prepare("select count(id_anomalie) AS nbAnomalie from aEteScannePar where id_historiqueRonde=:idHisto;"))
                        {
                            requeteAnomalie.bindValue(":idHisto",idHisto);
                            if (requeteAnomalie.exec())
                            {
                                while(requeteAnomalie.next())
                                {
                                    rondeCourante.nomRonde=requete.value("nom").toString();
                                    rondeCourante.dateHeure=requete.value("date_heure").toDateTime();
                                    rondeCourante.nbAnomalie =requeteAnomalie.value("nbAnomalie").toInt();
                                    rondeCourante.idRonde =requete.value("id_ronde").toInt();
                                    _ListeHistorique.append(rondeCourante);
                                }
                            }
                        }
                    }
                }

            }else{

                qDebug() <<
                            "Erreur lors exec  de la requête  "
                            + requete.lastError().text();
            }
        }
        // idAgent !=-1 idRonde=-1 -> agent selectionne et toutes les rondes sont sélectionnées
        if(idAgent!=-1 && idRonde==-1)
        {

            if(requete.prepare("select rondes.id_ronde,id_historiqueRonde,date_heure, nom from aEteEffectueePar,rondes"
                               " where id_agent=:idA and date_heure between :dateD and :dateF and aEteEffectueePar.id_ronde=rondes.id_ronde ;"))
            {
                requete.bindValue(":idA",idAgent);
                requete.bindValue(":dateD",dateDebut);
                requete.bindValue(":dateF",dateFin);
                if(requete.exec())
                {
                    while (requete.next())
                    {
                        idHisto=requete.value("id_historiqueRonde").toInt();

                        QSqlQuery requeteAnomalie(mySqlBdd);
                        if(requeteAnomalie.prepare("select count(id_anomalie) AS nbAnomalie from aEteScannePar where id_historiqueRonde=:idHisto;"))
                        {
                            requeteAnomalie.bindValue(":idHisto",idHisto);
                            if (requeteAnomalie.exec())
                            {
                                while(requeteAnomalie.next())
                                {
                                    rondeCourante.nomRonde=requete.value("nom").toString();
                                    rondeCourante.dateHeure=requete.value("date_heure").toDateTime();
                                    rondeCourante.nbAnomalie =requeteAnomalie.value("nbAnomalie").toInt();
                                    rondeCourante.idRonde =requete.value("id_ronde").toInt();
                                    _ListeHistorique.append(rondeCourante);
                                }
                            }
                        }
                    }
                }
            }else{

                qDebug() <<
                            "Erreur lors exec  de la requête  "
                            + requete.lastError().text();
            }
        }
        // idAgent =-1 idRonde=-1 -> tous les agents sont selectionnées et toutes les rondes sont sélectionnées
        if(idAgent ==-1 && idRonde ==-1)
        {
            if(requete.prepare("select agents.nom,agents.prenom,rondes.id_ronde,id_historiqueRonde,date_heure,rondes.nom from aEteEffectueePar,rondes,agents "
                               "where date_heure between :dateD and :dateF and aEteEffectueePar.id_ronde=rondes.id_ronde and agents.id_agent=aEteEffectueePar.id_agent;"))
            {

                requete.bindValue(":dateD",dateDebut);
                requete.bindValue(":dateF",dateFin);
                if(requete.exec())
                {
                    while (requete.next())
                    {
                        idHisto=requete.value("id_historiqueRonde").toInt();

                        QSqlQuery requeteAnomalie(mySqlBdd);
                        if(requeteAnomalie.prepare("select count(id_anomalie) AS nbAnomalie from aEteScannePar where id_historiqueRonde=:idHisto;"))
                        {
                            requeteAnomalie.bindValue(":idHisto",idHisto);
                            if (requeteAnomalie.exec())
                            {
                                while(requeteAnomalie.next())
                                {
                                    rondeCourante.nomRonde=requete.value("rondes.nom").toString();
                                    rondeCourante.dateHeure=requete.value("date_heure").toDateTime();
                                    rondeCourante.nbAnomalie =requeteAnomalie.value("nbAnomalie").toInt();
                                    rondeCourante.idRonde =requete.value("id_ronde").toInt();
                                    rondeCourante.NomPrenomAgent.nom=requete.value("agents.nom").toString()+" "+ requete.value("agents.prenom").toString();
                                    _ListeHistorique.append(rondeCourante);
                                }
                            }
                        }
                    }
                }
            }else{

                qDebug() <<
                            "Erreur lors exec  de la requête  "
                            + requete.lastError().text();
            }
        }
    }else{
        qDebug() <<
                    "Erreur connexion bdd lost  ";
    }
}

/**
 * @brief AccesMySQL::AjouterTag
 * @param numBadge
 * @return
 */
int AccesMySQL::AjouterTag(QString numBadge)
{
    /*int retour = 0;
    if(VerifierConnexion())
    {
        QSqlQuery requete(mySqlBdd);

        requete.prepare("SELECT numbadge FROM agents WHERE idTag=:idTag");
        requete.bindValue(":idTag", numBadge);

        if(requete.exec())
        {
            if(requete.size() > 0)
            {
                retour = 1;
            }
            else
            {
                requete.clear();

                requete.prepare("INSERT INTO tags VALUE (:tag)");
                requete.bindValue(":tag", tag);
                if(requete.exec())
                {
                    retour = 2;
                }
                else
                {
                    qDebug() << "Erreur lors de la requête \"INSERT INTO tags\" : " + requete.lastError().text();
                }
            }
        }
        else
        {
            qDebug() << "Erreur lors de la requête \"SELECT * FROM tags\" : " + requete.lastError().text();
        }
    }
    return retour;*/
}

/**
 * @brief AccesMySQL::ObtenirAgents
 * @return
 */
QList<Agents *> AccesMySQL::ObtenirAgents()
{
    Agents *unAgent;
    QList<Agents *> listeAgents;
    QSqlQuery requete(mySqlBdd);

    if(VerifierConnexion() == true)
    {
        if(requete.exec("SELECT * FROM agents ORDER BY nom, prenom"))
        {
            while(requete.next())
            {
                unAgent = new Agents(
                            requete.value("id_agent").toString(),
                            requete.value("nom").toString(),
                            requete.value("prenom").toString(),
                            requete.value("numbadge").toString(),
                            requete.value("statut").toBool());

                listeAgents.append(unAgent);
            }
        }
        else
        {
            qDebug() << "Erreur lors de la requête \"SELECT * FROM agents\" : " + requete.lastError().text();
        }
    }
    return listeAgents;
}

/**
 * @brief AccesMySQL::AjouterAgent
 * @param nom
 * @param prenom
 * @param badge
 * @param statut
 * @return
 */
bool AccesMySQL::AjouterAgent(QString nom, QString prenom, QString badge, bool statut)
{
    bool valide = false;
    if(VerifierConnexion() == true)
    {
        QSqlQuery requete(mySqlBdd);

        requete.prepare("INSERT INTO agents (nom, prenom, numbadge, statut)"
                        "VALUES (:nom, :prenom, :numbadge, :statut)");
        requete.bindValue(":nom", nom);
        requete.bindValue(":prenom", prenom);
        requete.bindValue(":numbadge", badge);
        requete.bindValue(":statut", statut);
        if(requete.exec())
        {
            valide = true;
        }
        else
        {
            qDebug() << "Erreur lors de la requête \"INSERT INTO agents\" : " + requete.lastError().text();
        }
        return valide;
    }
}

/**
 * @brief AccesMySQL::ModifierAgent
 * @param nom
 * @param prenom
 * @param badge
 * @param statut
 * @param id
 * @return
 */
bool AccesMySQL::ModifierAgent(QString nom, QString prenom, QString badge, int statut, int id)
{
    bool valide = false;
    if(VerifierConnexion() == true){
        QSqlQuery requete(mySqlBdd);
        requete.prepare("UPDATE agents SET nom = ':nom', prenom = ':prenom', numbadge = ':badge', statut = ':statut' WHERE id_agent = :id");
        requete.bindValue(":nom", nom);
        requete.bindValue(":prenom", prenom);
        requete.bindValue(":numbadge", badge);
        requete.bindValue(":statut", statut);
        requete.bindValue(":id_agent", id);
        if(requete.exec())
        {
            valide = true;
        }else{
            qDebug() << "Erreur lors de la requête \"UPDATE agents\" : " + requete.lastError().text();
        }
    }
    return valide;
}

/**
 * @brief AccesMySQL::ObtenitIdAgent
 * @param nom
 * @param prenom
 * @param badge
 * @param statut
 * @return
 */
int AccesMySQL::ObtenirIdAgent(QString nom, QString prenom, QString badge, bool statut)
{
    int id = 1;
    QSqlQuery requete(mySqlBdd);
    if(VerifierConnexion() == true)
    {
        requete.prepare("SELECT id_agent FROM agents WHERE agents.nom = :nom AND agents.prenom = :prenom AND agents.numbadge = :badge AND agents.statut = :statut;");
        requete.bindValue(":nom",nom);
        requete.bindValue(":prenom",prenom);
        requete.bindValue(":numbadge",badge);
        requete.bindValue(":statut",statut);
        //requete.bindValue(":id_agent",id);
        if(requete.exec()){
            while(requete.next()){
                id = requete.value("id_agent").toInt();
                //requete.value(id).toInt();
            }
            qDebug() << id;
        }else{
            qDebug() << "Erreur lors de la requête \"SELECT id_agent FROM agents\" : " + requete.lastError().text();
        }
    }else{
        qDebug() << "Erreur lors de la vérification de la connexion : "
                    "" + requete.lastError().text();
    }
    qDebug() << id;
    return id;
}

/**
 * @brief AccesMySQL::ObtenirNomAgents
 * @return
 */
QList<QString> AccesMySQL::ObtenirNomAgents()
{
    QList<QString> listeNomAgents;
    QString nom;

    if(VerifierConnexion() == true){
        QSqlQuery requete(mySqlBdd);

        if(requete.exec("select nom from agents")){
            while(requete.next()){
                nom = requete.value("nom").toString();
            }
        }else{
            qDebug() << "Erreur lors de la requere \"SELECT nom FROM agents\" : " + requete.lastError().text();
        }
    }
    return listeNomAgents;
}

/**
 * @brief AccesMySQL::ObtenirPointeaux
 * @return
 */
QList<Pointeaux *> AccesMySQL::ObtenirPointeaux()
{
    Pointeaux *unPointeau;
    QList<Pointeaux *> listePointeaux;
    QSqlQuery requetePointeaux(mySqlBdd);
    QList<Lieu *> listeLieux;

    if(VerifierConnexion() == true){
        if(requetePointeaux.exec("SELECT pointeaux.*, lieux.emplacement, comporte.ordre FROM pointeaux,lieux, comporte WHERE pointeaux.id_pointeau=lieux.id_pointeau AND pointeaux.id_pointeau = comporte.id_pointeau ORDER BY designation;")){
            while(requetePointeaux.next()){
                unPointeau = new Pointeaux(requetePointeaux.value("ordre").toInt(),
                                           requetePointeaux.value("designation").toString(),
                                           requetePointeaux.value("statut").toBool(),
                                           requetePointeaux.value("tag_mifare").toString(),
                                           requetePointeaux.value("emplacement").toString(),
                                           requetePointeaux.value("id_pointeau").toInt());
                listePointeaux.append(unPointeau);
            }
        }else{
            qDebug() << "Erreur lors de la requete \"SELECT tout FROM pointeaux,lieux\" : " + requetePointeaux.lastError().text();
        }
    }
    return  listePointeaux;
}

/**
 * @brief AccesMySQL::ObtenirRondes
 * @return
 */
QList<Rondes *> AccesMySQL::ObtenirRondes()
{
    Rondes *uneRonde;
    Pointeaux *unPointeau;
    TempsPointage *unTemps;
    QList<Rondes *> listeRondes;
    QList <Pointeaux *> listePointeaux;
    QList<TempsPointage *> listeTemps;
    QSqlQuery requeteRonde(mySqlBdd), requetePointeau(mySqlBdd);

    if(VerifierConnexion() == true){
//        if(requeteRonde.exec("SELECT rondes.*, comporte.*, peutFaire.id_agent, pointeaux.* FROM rondes,comporte,pointeaux,peutFaire WHERE rondes.id_ronde = comporte.id_ronde AND comporte.id_pointeau = pointeaux.id_pointeau AND rondes.id_ronde = peutFaire.id_agent;")){
//            while(requeteRonde.next()){
        if(requeteRonde.exec("SELECT * FROM rondes")){
            while(requeteRonde.next()){

                listePointeaux.clear();
                listeTemps.clear();

                requetePointeau.prepare("SELECT pointeaux.*, lieux.emplacement, comporte.ordre FROM pointeaux,lieux, comporte WHERE pointeaux.id_pointeau=lieux.id_pointeau AND pointeaux.id_pointeau = comporte.id_pointeau ORDER BY designation;");

                requetePointeau.bindValue(":id_ronde",requeteRonde.value("id_ronde"));
                if(requetePointeau.exec()){
                    unPointeau = new Pointeaux(requetePointeau.value("ordre").toInt(),
                                               requetePointeau.value("designation").toString(),
                                               requetePointeau.value("statut").toBool(),
                                               requetePointeau.value("tag_mifare").toString(),
                                               requetePointeau.value("emplacement").toString(),
                                               requetePointeau.value("id_pointeau").toInt());
                    listePointeaux.append(unPointeau);

                    unTemps = new TempsPointage(requetePointeau.value("tempsMin").toInt(), requetePointeau.value("tempsMax").toInt());
                    listeTemps.append(unTemps);
                }
                uneRonde = new Rondes(requeteRonde.value("nom").toString(),listePointeaux,
                                      listeTemps,requeteRonde.value("statut").toBool(),
                                      requeteRonde.value("id_ronde").toInt());
                listeRondes.append(uneRonde);
            }
        }else{
            qDebug() << "Erreur lors de la requete \"SELECT * FROM ronde\" : " +requetePointeau.lastError().text();
        }
    }
    return  listeRondes;
}

/**
 * @brief AccesMySQL::ObtenirLieux
 * @return
 */
QList<Lieu *> AccesMySQL::ObtenirLieux()
{
    Lieu *unLieu;
    QList<Lieu *> listeLieux;
    QSqlQuery requete(mySqlBdd);

    if(VerifierConnexion() == true){
        if(requete.exec("SELECT * FROM lieux ORDER BY id_lieu")){
            while(requete.next()){
                unLieu = new Lieu(
                            requete.value("batiment").toString(),
                            requete.value("etage").toString(),
                            requete.value("emplacement").toString(),
                            requete.value("id_lieu").toInt(),
                            requete.value("id_pointeau").toInt());
                listeLieux.append(unLieu);
            }
        }else{
            qDebug() << "Erreur lors de la requête \"SELECT * FROM lieux\" : " + requete.lastError().text();
        }
    }
    return listeLieux;
}

/**
 * @brief AccesMySQL::AjouterLieux
 * @param batiment
 * @param etage
 * @param emplacement
 * @return
 */
bool AccesMySQL::AjouterLieux(QString batiment, QString etage, QString emplacement)
{
    bool valide = false;

    if(VerifierConnexion() == true){
        QSqlQuery requete(mySqlBdd);
        requete.prepare("INSERT INTO lieux (batiment, etage, emplacement) VALUES (:batiment, :etage, :emplacement)");
        requete.bindValue(":batiment",batiment);
        requete.bindValue(":etage",etage);
        requete.bindValue(":emplacement",emplacement);

        if(requete.exec())
        {
            valide = true;
        }
        else
        {
            qDebug() << "Erreur lors de la requête \"INSERT INTO lieux\" : " + requete.lastError().text();
        }
    }
}

/**
 * @brief AccesMySQL::ModifierLieu
 * @param batiment
 * @param etage
 * @param emplacement
 * @return
 */
int AccesMySQL::ModifierLieu(QString batiment, QString etage, QString emplacement)
{
    bool valide = false;

    if(VerifierConnexion() == true){
        QSqlQuery requete(mySqlBdd);
        requete.prepare("UPDATE lieux SET batiment=:batiment, etage=:etage, emplacement=:emplacement");
        requete.bindValue(":batiment",batiment);
        requete.bindValue(":etage",etage);
        requete.bindValue(":emplacement",emplacement);

        if(requete.exec())
        {
            valide = true;
        }
        else
        {
            qDebug() << "Erreur lors de la requête \"INSERT INTO lieux\" : " + requete.lastError().text();
        }
    }
}

int AccesMySQL::ObtenirNumeroMaxRondeHP()
{

}

/**
 * @brief AccesMySQL::RequeteFiltresAgents
 * @return
 */
bool AccesMySQL::RequeteFiltresAgents()
{
    Agents *unAgent;
    bool valide = false;
    QList<Agents *> listeAgents;
    QSqlQuery requete(mySqlBdd);

    if(requete.exec()){
        while(requete.next()){
            unAgent = new Agents(requete.value("idAgent").toString(),
                                 requete.value("nom").toString(),
                                 requete.value("prenom").toString(),
                                 requete.value("numbadge").toString(),
                                 requete.value("statut").toBool());
            listeAgents.append(unAgent);
        }
        valide = true;
    }else{
        qDebug() << " Erreur lors de la requête filtres";
    }
    return valide;
}

/**
 * @brief AccesMySQL::AppliquerFiltresAgents
 * @param nom
 * @param statut
 * @param numbadge
 * @return
 */
bool AccesMySQL::AppliquerFiltresAgents(QString nom, bool statut, QString numbadge,                                                                                                                                                                                                                                               QList<Agents *> & listeAgents)
{
    //Agents *unAgent;
    //bool valide = false;

    if(VerifierConnexion() == true){

        QSqlQuery requete(mySqlBdd);

        requete.prepare("SELECT * FROM agents WHERE nom = :nom AND statut = :statut AND numbadge = :numbadge");
        requete.bindValue(":nom",nom);
        requete.bindValue(":statut",statut);
        requete.bindValue(":numbadge",numbadge);

        RequeteFiltresAgents();
        //if(requete.exec()){
        //            while(requete.next()){
        //                unAgent = new Agents(requete.value("idAgent").toInt(),
        //                                     requete.value("nom").toString(),
        //                                     requete.value("prenom").toString(),
        //                                     requete.value("numbadge").toString(),
        //                                     requete.value("statut").toBool()
        //                                     );
        //                listeAgents.append(unAgent);
        //            }
        //            valide = true;
        //        }else{
        //           qDebug() << " Erreur lors de la requête ";
    }
    //    }
    //   return  valide;
}

/**
 * @brief AccesMySQL::AppliquerFiltresStatutAgents
 * @param statut
 * @param listeAgents
 * @return
 */
bool AccesMySQL::AppliquerFiltresStatutAgents(bool statut, QList<Agents *> &listeAgents)
{
    Agents *unAgent;
    bool valide = false;

    if(VerifierConnexion() == true){

        QSqlQuery requete(mySqlBdd);

        requete.prepare("SELECT * FROM agents WHERE statut = :statut");
        requete.bindValue(":statut",statut);

        //RequeteFiltresAgents();
        if(requete.exec()){
            while(requete.next()){
                unAgent = new Agents(requete.value("idAgent").toString(),
                                     requete.value("nom").toString(),
                                     requete.value("prenom").toString(),
                                     requete.value("numbadge").toString(),
                                     requete.value("statut").toBool()
                                     );
                listeAgents.append(unAgent);
            }
            valide = true;
        }else{
            qDebug() << " Erreur lors de la requête filtre statuts";
        }
    }
    return  valide;
}

/**
 * @brief AccesMySQL::AppliquerFiltresNomAgents
 * @param nom
 * @param listeAgents
 * @return
 */
bool AccesMySQL::AppliquerFiltresNomAgents(QString nom, QList<Agents *> &listeAgents)
{
    Agents *unAgent;
    bool valide = false;

    if(VerifierConnexion() == true){

        QSqlQuery requete(mySqlBdd);

        requete.prepare("SELECT * FROM agents WHERE nom = :nom");
        requete.bindValue(":nom",nom);

        if(requete.exec()){
            while(requete.next()){
                unAgent = new Agents(requete.value("idAgent").toString(),
                                     requete.value("nom").toString(),
                                     requete.value("prenom").toString(),
                                     requete.value("numbadge").toString(),
                                     requete.value("statut").toBool()
                                     );
                listeAgents.append(unAgent);
            }
            valide = true;
        }else{
            qDebug() << " Erreur lors de la requête filtre nom ";
        }
    }
    return  valide;
}

/**
 * @brief AccesMySQL::AppliquerFiltresBadgeAgents
 * @param badge
 * @param listeAgents
 * @return
 */
bool AccesMySQL::AppliquerFiltresBadgeAgents(QString badge, QList<Agents *> &listeAgents)
{
    Agents *unAgent;
    bool valide = false;

    if(VerifierConnexion() == true){

        QSqlQuery requete(mySqlBdd);

        requete.prepare("SELECT * FROM agents WHERE badge = :badge");
        requete.bindValue(":badge",badge);

        if(requete.exec()){
            while(requete.next()){
                unAgent = new Agents(requete.value("idAgent").toString(),
                                     requete.value("nom").toString(),
                                     requete.value("prenom").toString(),
                                     requete.value("numbadge").toString(),
                                     requete.value("statut").toBool()
                                     );
                listeAgents.append(unAgent);
            }
            valide = true;
        }else{
            qDebug() << " Erreur lors de la requête filtre badge";
        }
    }
    return  valide;
}

/**
 * @brief AccesMySQL::AppliquerFiltresStatutBadgeAgents
 * @param statut
 * @param numbadge
 * @param listeAgents
 * @return
 */
bool AccesMySQL::AppliquerFiltresStatutBadgeAgents(bool statut, QString numbadge, QList<Agents *> &listeAgents)
{
    Agents *unAgent;
    bool valide = false;

    if(VerifierConnexion() == true){

        QSqlQuery requete(mySqlBdd);

        requete.prepare("SELECT * FROM agents WHERE statut = :statut AND numbadge = :numbadge");
        requete.bindValue(":statut",statut);
        requete.bindValue(":numbadge",numbadge);

        if(requete.exec()){
            while(requete.next()){
                unAgent = new Agents(requete.value("idAgent").toString(),
                                     requete.value("nom").toString(),
                                     requete.value("prenom").toString(),
                                     requete.value("numbadge").toString(),
                                     requete.value("statut").toBool()
                                     );
                listeAgents.append(unAgent);
            }
            valide = true;
        }else{
            qDebug() << " Erreur lors de la requête ";
        }
    }
    return  valide;
}

void AccesMySQL::TransfererRondes(int idRonde, int idAgent, QString dateHeure)
{
    QSqlQuery requete(mySqlBdd);
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
    QSqlQuery requete(mySqlBdd);
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
    QSqlQuery requete(mySqlBdd);
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
    QSqlQuery requete(mySqlBdd);
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
    QSqlQuery requete(mySqlBdd);
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

    QSqlQuery requete(mySqlBdd);
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

    QSqlQuery requete(mySqlBdd);
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
    QSqlQuery requete(mySqlBdd);

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

    QSqlQuery requete(mySqlBdd);
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

    QSqlQuery requete(mySqlBdd);
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

    QSqlQuery requete(mySqlBdd);
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
    QSqlQuery requete(mySqlBdd);
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

    QSqlQuery requete(mySqlBdd);
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
    mySqlBdd.close();
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
    QSqlQuery requete(mySqlBdd);
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
