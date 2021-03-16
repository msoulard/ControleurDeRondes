#ifndef POINTEAUX_H
#define POINTEAUX_H

#include <QObject>
#include <QDateTime>
#include <QDebug>

class Pointeaux : public QObject
{
    Q_PROPERTY(QString designation READ designation WRITE setDesignation NOTIFY designationChanged)
    Q_PROPERTY(QString couleur READ couleur WRITE setCouleur NOTIFY couleurChanged)

public:
    explicit Pointeaux(QObject *parent = nullptr);
    Pointeaux(const QString &_designation, const QString &_couleur, QObject *parent = 0);
    Q_INVOKABLE QString changerCouleur(int i);
    Q_INVOKABLE void horodater();

    QString designation() const;
    void setDesignation(const QString &_designation);

    QString couleur() const;
    void setCouleur(const QString &_couleur);

signals:
    void designationChanged();
    void couleurChanged();

private:
    QString m_designation;
    QString m_couleur;
    QDateTime horodatage;
};

#endif // POINTEAUX_H
