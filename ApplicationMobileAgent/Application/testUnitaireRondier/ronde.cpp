#include "ronde.h"

Ronde::Ronde(const QString _nom, const int _idRonde, QObject *parent) :
    QObject(parent),
    nom(_nom),
    idRonde(_idRonde)
{

}
