#ifndef RONDIER_H
#define RONDIER_H

#include <QObject>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QList>
#include <QDebug>

#include "pointeau.h"
#include "accesbdd.h"
#include "agent.h"
#include "ronde.h"

class Rondier : public QObject
{
    Q_OBJECT
public:
    explicit Rondier(QObject *parent = nullptr);

signals:
private:
    QQmlApplicationEngine engine;
    AccesBdd bdd;
    QList<QObject*> listeDesignationPointeaux;
    QList<Pointeau*> listePointeaux;
};

#endif // RONDIER_H
