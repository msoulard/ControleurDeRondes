#include "anomalie.h"

Anomalie::Anomalie(QObject *parent) : QObject(parent)
{

}

int Anomalie::getId() const
{
    return id;
}

void Anomalie::setId(int value)
{
    id = value;
}

QString Anomalie::getDescription() const
{
    return description;
}

void Anomalie::setDescription(const QString &value)
{
    description = value;
}
