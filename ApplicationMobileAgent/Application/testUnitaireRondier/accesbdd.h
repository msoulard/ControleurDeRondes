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
    QList<Ronde*> obtenirListeRondes(QString _numBadge);
    QList<Pointeau*> obtenirListePointeaux(int _idRonde);
    Q_INVOKABLE QList<QObject*> obtenirListeDesignationsPointeaux();
    Q_INVOKABLE QList<QString> obtenirListeNomsRondes(QString _numBadge);

    QList<Ronde *> getListeRondes() const;
    void setListeRondes(const QList<Ronde *> &value);

signals:
private :
    QSqlDatabase db;
    QList<Ronde*> listeRondes;
};

#endif // ACCESBDD_H
