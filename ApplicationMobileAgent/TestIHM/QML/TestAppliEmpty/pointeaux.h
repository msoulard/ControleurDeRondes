#ifndef COULEURS_H
#define COULEURS_H

#include <QObject>
#include <QString>

using namespace std;

class Couleurs : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString lieu READ lieu WRITE setLieu NOTIFY lieuChanged)
    Q_PROPERTY(QString etat READ etat WRITE setEtat NOTIFY etatChanged)

public:
    explicit Couleurs(QObject *parent = nullptr);    
    Couleurs(const QString &name, const QString &color, QObject *parent = 0);
    Q_INVOKABLE QString changerCouleur(int i);

    QString lieu() const;
    void setLieu(const QString &name);

    QString etat() const;
    void setEtat(const QString &color);

signals:
    void lieuChanged();
    void etatChanged();

private:
    QString m_name;
    QString m_color;

};

#endif // COULEURS_H
