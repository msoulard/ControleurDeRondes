#ifndef RONDE_H
#define RONDE_H

#include <QObject>

#include "accesbdd.h"

struct S_Ronde{
    QString nom;
    int id;
};

class Ronde : public QObject
{
    Q_OBJECT
public:
    explicit Ronde(QObject *parent = nullptr);
    Q_INVOKABLE QList<Ronde*> obtenirListeRondes(int _idAgent);

    QString getNom() const;
    void setNom(const QString &value);

    int getId() const;
    void setId(int value);

signals:

private :
    QString nom;
    int id;
};

#endif // RONDE_H
