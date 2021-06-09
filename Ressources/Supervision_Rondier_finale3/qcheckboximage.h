/**
  @file accesmysql.h
  @brief Déclaration de la classe QCheckBoxImage qui hérite de la classe QCheckBox
  @brief Cette classe permet d'avoir un chemin d'images dans la checkBox quand on sélectionne une image
  @version 1.0
  @author Ouijdane IMER
  @date   27/05/2021
  */
#ifndef QCHECKBOXIMAGE_H
#define QCHECKBOXIMAGE_H

#include <QObject>
#include <QCheckBox>

class QCheckBoxImage : public QCheckBox
{
    Q_OBJECT
public:
    QCheckBoxImage();
    QCheckBoxImage(QWidget *parent);
    QString getCheminImage() const;
    void setCheminImage(const QString &value);

private:
    QString cheminImage;
};

#endif // QCHECKBOXIMAGE_H
