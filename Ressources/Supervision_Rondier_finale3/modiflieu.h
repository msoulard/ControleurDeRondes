/**
   @file modiflieu.h
 * @brief The ModifLieu class
 * @details Déclaration de la classe ModifLieu héritant de la classe QWidget
 * @authors Letessier Yoann
 * @date 25/05/2021
 */

#ifndef MODIFLIEU_H
#define MODIFLIEU_H

#include <QWidget>

namespace Ui {
class ModifLieu;
}

class ModifLieu : public QWidget
{
    Q_OBJECT

public:
    explicit ModifLieu(QString _batiment, QString _etage, QString _emplacement, QWidget *parent = nullptr);
    ~ModifLieu();
    void AfficherLieu();

private slots:
    void on_pushButtonAnnuler_clicked();
    void on_pushButtonEnregistrer_clicked();

private:
    Ui::ModifLieu *ui;
    QString batiment;
    QString etage;
    QString emplacement;
};

#endif // MODIFLIEU_H
