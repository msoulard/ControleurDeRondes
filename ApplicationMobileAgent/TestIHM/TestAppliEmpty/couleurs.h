#ifndef COULEURS_H
#define COULEURS_H

#include <QObject>
#include <QString>

using namespace std;

class Couleurs : public QObject
{
    Q_OBJECT
public:
    explicit Couleurs(QObject *parent = nullptr);    
    Q_INVOKABLE QString changerCouleur(int i);

signals:

};

#endif // COULEURS_H
