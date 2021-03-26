#ifndef POINTEAUX_H
#define POINTEAUX_H

#include <QObject>
#include <QDateTime>
#include <QDebug>

class Pointeau : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString m_designation READ getDesignation WRITE setDesignation NOTIFY designationChanged)
    Q_PROPERTY(QString m_couleur READ getCouleur WRITE setCouleur NOTIFY couleurChanged)
    Q_PROPERTY(int m_num READ getNum WRITE setNum NOTIFY numChanged)

public:
    explicit Pointeau(QObject *parent = nullptr);
    Q_INVOKABLE int horodater();
    //Q_INVOKABLE void horodater();
    QString getDesignation() const;
    void setDesignation(const QString &value);

    QString getCouleur() const;
    void setCouleur(const QString &value);

    int getNum() const;
    void setNum(int value);

signals:
    void designationChanged();
    void couleurChanged();
    void numChanged();

private:
    ///Pointeaux
    QString couleur;
    QDateTime horodatage;    
    QString designation;
    int idPointeaux;
    QString tagPointeaux;
    ///Lieux
    QList<int> idLieux;
    QList<QString> batiment;
    QList<QString> etage;
    QList<QString> emplacement;
    QList<int> idPointeauLieux;
    //essais
    int num;
};

#endif // POINTEAUX_H
