/**
   @file agents.h
 * @brief The Agents class
 * @version 1.0
 * @details Déclaration de la classe Agents
 * @authors  Gabriel Lemée et Letessier Yoann
 * @date 25/03/2021
 */

#ifndef AGENTS_H
#define AGENTS_H

#include <QString>

class Agents
{
public:
    Agents(QString _idAgent, QString _nom, QString _prenom, QString _badge, bool _statut);

    QString ObtenirNom();
    void DefinirNom(QString _nom);
    QString ObtenirPrenom();
    void DefinirPrenom(QString _prenom);
    QString ObtenirBadge();
    void DefinirBadge(QString _badge);
    QString ObtenirStatut();
    void DefinirStatut(bool _statut);
    QString ObtenirIdAgent();
    void DefinirIdAgent(int _idAgent);


private:

    //Attributs
    QString nom;        /*!< Nom de l'agent. */
    QString prenom;     /*!< Prénom de l'agent. */
    QString badge;      /*!< Badge de l'agent. */
    bool statut;        /*!< status de l'agents. */
    QString idAgent;    /*!< Id de l'agent dans la base de données. */
};

#endif // AGENTS_H
