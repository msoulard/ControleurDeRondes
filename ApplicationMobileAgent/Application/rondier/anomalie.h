#ifndef ANOMALIE_H
#define ANOMALIE_H

#include <QObject>

class Anomalie : public QObject
{
    Q_OBJECT
public:
    explicit Anomalie(QObject *parent = nullptr);

    int getId() const;
    void setId(int value);

    QString getDescription() const;
    void setDescription(const QString &value);

signals:
private:
    int id;
    QString description;

};

#endif // ANOMALIE_H
