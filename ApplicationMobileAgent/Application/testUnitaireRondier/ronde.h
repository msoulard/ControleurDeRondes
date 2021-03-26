#ifndef RONDES_H
#define RONDES_H

#include <QObject>

class Ronde : public QObject
{
    Q_OBJECT
public:
    explicit Ronde(const QString _nom, const int _idRonde, QObject *parent = nullptr);

signals:

private:
    QString nom;
    int idRonde;

};

#endif // RONDES_H
