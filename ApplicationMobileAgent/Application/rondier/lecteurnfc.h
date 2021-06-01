/**
   @file lecteurnfc.h
 * @brief Déclaration de la classe LecteurNFC
 * @version 1.0
 * @author Damien CABARET
 * @date 03/04/2021
 */

#ifndef LECTEURNFC_H
#define LECTEURNFC_H

#include <QObject>
#include <qqml.h>

QT_FORWARD_DECLARE_CLASS(QNearFieldManager)
QT_FORWARD_DECLARE_CLASS(QNearFieldTarget)

class LecteurNFC : public QObject
{
    Q_OBJECT

public:
    explicit LecteurNFC(QObject *parent = nullptr);
    ~LecteurNFC();

signals:
    void tagDetecte(QString tagNFC);

public slots:
    void targetDetected(QNearFieldTarget *target);
    void targetLost(QNearFieldTarget *target);

private:
    QNearFieldManager *manager;
    QString tag;


};

#endif // LECTEURNFC_H
