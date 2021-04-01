#ifndef POINTEAU_H
#define POINTEAU_H

#include <QObject>
#include <QDateTime>
#include <QDebug>

#include "accesbdd.h"

class Pointeau : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString m_designation READ getDesignation WRITE setDesignation NOTIFY designationChanged)
    Q_PROPERTY(QString m_couleur READ getCouleur WRITE setCouleur NOTIFY couleurChanged)

public:
    explicit Pointeau(QObject *parent = nullptr);
    Q_INVOKABLE void horodater();
    Q_INVOKABLE QList<QString> obtenirListeDesignationsPointeaux(int _idRonde);
    Q_INVOKABLE QList<QString> obtenirListeCouleursPointeaux();

    QString getCouleur() const;
    void setCouleur(const QString &value);

    int getIdPointeau() const;
    void setIdPointeau(int value);

    QString getDesignation() const;
    void setDesignation(const QString &value);

    QString getTagMifare() const;
    void setTagMifare(const QString &value);

    QString getBatiment() const;
    void setBatiment(const QString &value);

    QString getEtage() const;
    void setEtage(const QString &value);

    QString getEmplacement() const;
    void setEmplacement(const QString &value);

    int getOrdre() const;
    void setOrdre(int value);

    QString getTempsMini() const;
    void setTempsMini(const QString &value);

    QString getTempsMaxi() const;
    void setTempsMaxi(const QString &value);

signals:
    void designationChanged();
    void couleurChanged();

private:
    QString couleur;
    QDateTime horodatage;
    QList<Pointeau*> listePointeaux;
    ///Attributs du pointeau
    int idPointeau;
    QString designation;
    QString tagMifare;
    QString batiment;
    QString etage;
    QString emplacement;
    int ordre;
    QString tempsMini;
    QString tempsMaxi;

};

#endif // POINTEAU_H
