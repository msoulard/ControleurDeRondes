#ifndef RONDIER_H
#define RONDIER_H

#include <QObject>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QList>
#include <QDebug>

#include "accesbdd.h"
#include "agent.h"
#include "ronde.h"

class Rondier : public QObject
{
    Q_OBJECT
public:
    explicit Rondier(QQmlApplicationEngine &_engine, QObject *parent = nullptr);
    Q_INVOKABLE void mettreAJourAgent(QString _numBadge);
    Q_INVOKABLE QStringList obtenirRondes();
    Q_INVOKABLE QString obtenirNomRondeCourante(int _index);

signals:
private:
    QQmlApplicationEngine &engine;
    AccesBdd bdd;
    Agent agent;
    QList<Ronde*> listeRondes;
    QList<Pointeau*> listePointeaux;
    Ronde *rondeCourante;
};

#endif // RONDIER_H
