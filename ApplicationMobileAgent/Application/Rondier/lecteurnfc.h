#ifndef LECTEURNFC_H
#define LECTEURNFC_H

#include <QObject>
#include <QNearFieldManager>

class LecteurNFC : public QObject
{
    Q_OBJECT
public:
    explicit LecteurNFC(QObject *parent = nullptr);

signals:

};

#endif // LECTEURNFC_H
