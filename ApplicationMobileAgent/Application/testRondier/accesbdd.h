#ifndef ACCESBDD_H
#define ACCESBDD_H

#include <QObject>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>

struct S_Agent;
class Ronde;
class Pointeau;

class AccesBdd : public QObject
{
    Q_OBJECT
public:
    explicit AccesBdd(QObject *parent = nullptr);
    ~AccesBdd();
    S_Agent obtenirAgent(QString _numBadge);
    QList<Ronde*> obtenirRondes(QString _numBadge);
    QList<Pointeau*> obtenirPointeau(int _idRonde);

signals:
private :
    QSqlDatabase db;
};

#endif // ACCESBDD_H
