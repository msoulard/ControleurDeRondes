/**
   @file creationpointeau.h
 * @brief The CreationPointeau class
 * @version 1.0
 * @details Déclaration de la classe CreationPointeau
 * @authors Letessier Yoann
 * @date 25/05/2021
 */

#ifndef CREATIONPOINTEAU_H
#define CREATIONPOINTEAU_H

#include <QWidget>

namespace Ui {
class CreationPointeau;
}

class CreationPointeau : public QWidget
{
    Q_OBJECT

public:
    explicit CreationPointeau(QWidget *parent = nullptr);
    ~CreationPointeau();

private:
    Ui::CreationPointeau *ui;
};

#endif // CREATIONPOINTEAU_H
