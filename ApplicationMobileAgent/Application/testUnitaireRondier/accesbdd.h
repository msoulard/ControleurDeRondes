#ifndef ACCESBDD_H
#define ACCESBDD_H

#include <QObject>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <pointeau.h>
#include <ronde.h>

using namespace std;

class AccesBdd : public QObject
{
    Q_OBJECT
public:
    explicit AccesBdd(QObject *parent = nullptr);
    Q_INVOKABLE QString obtenirAgent(QString _numBadge);
    Q_INVOKABLE QString obtenirPointeaux(int _id_ronde);
    Q_INVOKABLE void obtenirRondes(QList<Ronde*> &_listeRondes);
    Q_INVOKABLE void RecupererLePointeau(QString _tag_mifare);
    Q_INVOKABLE void MettreAJourBdd();
    Q_INVOKABLE void EnregistrerAnomalie(int _id_pointeau);

    ///Rondes
    //QList<Rondes> listeRondes;

signals:

private :
    QSqlDatabase db;
    ///Agents
    QString nomAgent;
    QString prenomAgent;
    int idAgent;
    ///Rondes
    //QList<QString> nomRondes;
    //QList<int> idRondes;
    QString nomRondeCourante;
    int idRondeCourante;


};


#endif // ACCESBDD_H
