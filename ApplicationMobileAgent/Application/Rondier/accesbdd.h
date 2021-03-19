/**
  @file accesbdd.h
  @brief The AccesBDD class
  @details Déclaration de la classe AccesBDD héritant de la classe QObject
  @author Maëva Soulard
  @date 19/03/2021
  */

#ifndef ACCESBDD_H
#define ACCESBDD_H

#include <QObject>
#include <QSqlDatabase>
#include <QDebug>

class AccesBDD : public QObject
{
    Q_OBJECT
public:
    explicit AccesBDD(QObject *parent = nullptr);

signals:

private :
    QSqlDatabase db;

};

#endif // ACCESBDD_H
