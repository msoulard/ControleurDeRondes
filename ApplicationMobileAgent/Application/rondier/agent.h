/**
 * @file agent.h
 * @brief The Agent class
 * @details Déclaration de la classe Agent
 * @author Maëva Soulard
 * @date 28/05/2021
 */

#ifndef AGENT_H
#define AGENT_H

#include <QObject>

class Agent : public QObject
{
    Q_OBJECT
public:
    explicit Agent(QObject *parent = nullptr);
    Q_INVOKABLE QString obtenirPrenomNom();

    QString getNom() const;
    void setNom(const QString &value);

    QString getPrenom() const;
    void setPrenom(const QString &value);

    int getId() const;
    void setId(int value);

    QString getNumBadge() const;
    void setNumBadge(const QString &value);

signals:
private:
    QString nom;
    QString prenom;
    int id;
    QString numBadge;
};

#endif // AGENT_H
