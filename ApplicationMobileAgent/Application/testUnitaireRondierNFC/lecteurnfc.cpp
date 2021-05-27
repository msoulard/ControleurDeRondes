/**
   @file lecteurnfc.cpp
 * @brief Implémentation de la classe LecteurNFC
 * @details Classe permettant de détecter et lire l'iud d'un tag
 * @version 1.0
 * @author Damien CABARET
 * @date 03/04/2021
 */

#include "lecteurnfc.h"
#include <QNearFieldManager>
#include <QNearFieldTarget>
#include <QByteArray>
#include <QDebug>

/**
 * @brief LecteurNFC::LecteurNFC
 * @param parent
 */
LecteurNFC::LecteurNFC(QObject *parent) : QObject(parent)
{

    manager = new QNearFieldManager(this);
    if (!manager->isAvailable()) {
        qWarning() << "NFC non disponible";
        return;
    }


    while(!manager->startTargetDetection());
    connect(manager, &QNearFieldManager::targetDetected,
            this, &LecteurNFC::targetDetected);
    connect(manager, &QNearFieldManager::targetLost,
            this, &LecteurNFC::targetLost);
}

/**
 * @brief LecteurNFC::~LecteurNFC
 */
LecteurNFC::~LecteurNFC()
{
    manager->stopTargetDetection();
}

/**
 * @brief LecteurNFC::RecupererTag
 * @param tagNfc
 * @return
 */
QString LecteurNFC::recupererTag(const QString tagNfc)
{
    return tagNfc;
}

/**
 * @brief LecteurNFC::targetDetected
 * @param target
 */
void LecteurNFC::targetDetected(QNearFieldTarget *target)
{
    if (!target)
        return;

    QByteArray uid = target->uid();
    emit tagDetecte(uid.toHex(' ').toUpper());
}

/**
 * @brief LecteurNFC::targetLost
 * @param target
 */
void LecteurNFC::targetLost(QNearFieldTarget *target)
{
    if (target)
        target->deleteLater();
}
