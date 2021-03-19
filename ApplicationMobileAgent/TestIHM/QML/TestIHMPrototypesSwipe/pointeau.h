#ifndef POINTEAU_H
#define POINTEAU_H

#include <QObject>
#include <QDateTime>
#include <QDebug>

class Pointeau : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString lieu READ lieu WRITE setLieu NOTIFY lieuChanged)
    Q_PROPERTY(QString etat READ etat WRITE setEtat NOTIFY etatChanged)

public:
    explicit Pointeau(QObject *parent = nullptr);
    Pointeau(const QString lieu, const QString etat, QObject *parent = 0);
    Q_INVOKABLE void horodater();

    QString lieu() const;
    void setLieu(const QString &lieu);

    QString etat() const;
    void setEtat(const QString &etat);

signals:
    void lieuChanged();
    void etatChanged();

private:
    QString m_lieu;
    QString m_etat;
    QDateTime horodatage;
};

#endif // POINTEAU_H
