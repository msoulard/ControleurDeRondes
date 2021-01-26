#ifndef BASEBDD_H
#define BASEBDD_H
#include "QtSql/QSqlDatabase"
#include <QString>
#include <QObject>

class BaseBDD : public QObject
{
    Q_OBJECT
public:
    explicit BaseBDD();
    QString connexion();
    QSqlDatabase DB;

/*signals:

public slots:
    QString connexion();
    QSqlDatabase DB;
    QString Serveur, Nom, ID, Pass;*/
};

#endif // BASEBDD_H

