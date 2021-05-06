#ifndef RONDE_H
#define RONDE_H

#include <QObject>
#include <QDebug>

#include "accesbdd.h"

//struct S_Ronde{
//    QString nom;
//    int id;
//};

class Ronde : public QObject
{
    Q_OBJECT
public:
    explicit Ronde(QObject *parent = nullptr);
    Q_INVOKABLE void mettreAJourIndexCourant(int _indexRonde);
    Q_INVOKABLE QString obtenirNomRondeCourante();
    Q_INVOKABLE int obtenirIdRondeCourante();

    QString getNom() const;
    void setNom(const QString &value);

    int getId() const;
    void setId(int value);

signals:

private :
    QString nom;
    int id;
    int indexRondeCourante;
};

#endif // RONDE_H
