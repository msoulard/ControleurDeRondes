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
    Q_INVOKABLE QList<QString> obtenirListeRondes(QString _numBadge);

    QString getNom() const;
    void setNom(const QString &value);

    int getId() const;
    void setId(int value);

signals:

private :
    QString nom;
    int id;
    QList<Ronde*> listeRondes;
};

#endif // RONDE_H
