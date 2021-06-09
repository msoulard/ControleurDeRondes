/**
  @file accesmysql.h
  @brief implémentation de la classe QCheckBoxImage
  @version 1.0
  @author Ouijdane IMER
  @date   27/05/2021
  */
#include "qcheckboximage.h"

QCheckBoxImage::QCheckBoxImage(QWidget *parent):QCheckBox(parent)
{

}
/**
 * @brief QCheckBoxImage::getCheminImage
 * @details cette méthode permet de récupérer le contenu du chemin d'image
 * @return
 */

QString QCheckBoxImage::getCheminImage() const
{
    return cheminImage;
}
/**
 * @brief QCheckBoxImage::setCheminImage
 * @param value
 */

void QCheckBoxImage::setCheminImage(const QString &value)
{
    cheminImage = value;
}
