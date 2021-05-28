#ifndef RONDE_H
#define RONDE_H

#include <QObject>

class Ronde : public QObject
{
    Q_OBJECT
public:
    explicit Ronde(QObject *parent = nullptr);

    int getId() const;
    void setId(int value);

    QString getNom() const;
    void setNom(const QString &value);

signals:
private:
    int id;
    QString nom;
};

#endif // RONDE_H
