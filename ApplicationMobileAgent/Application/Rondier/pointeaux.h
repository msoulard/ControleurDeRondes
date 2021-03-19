/**
  @file pointeaux.h
  @brief The Pointeaux class
  @details Déclaration de la classe Pointeaux héritant de la classe QObject
  @author Maëva Soulard
  @date 18/03/2021
  */

#ifndef POINTEAUX_H
#define POINTEAUX_H

#include <QObject>
#include <QDateTime>
#include <QDebug>

class Pointeaux : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString m_designation READ getDesignation WRITE setDesignation NOTIFY designationChanged)
    Q_PROPERTY(QString m_couleur READ getCouleur WRITE setCouleur NOTIFY couleurChanged)

public:
    explicit Pointeaux(QObject *parent = nullptr);
    Q_INVOKABLE void horodater();

    QString getDesignation() const;
    void setDesignation(const QString &value);

    QString getCouleur() const;
    void setCouleur(const QString &value);

signals:
    void designationChanged();
    void couleurChanged();

private:
    QString designation;
    QString couleur;
    QDateTime horodatage;
};

#endif // POINTEAUX_H
