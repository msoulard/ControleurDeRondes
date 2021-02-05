#ifndef IHMSTATISTIQUES_H
#define IHMSTATISTIQUES_H

#include <QWidget>
#include <QLabel>
#include <QTime>
#include <QMap>
#include <QPoint>
#include <QRect>
#include <QPen>
#include <QTextDocument>
#include <QPrinter>
#include <QFileDialog>
#include <QPainter>
#include <accesmysql.h>
#include <QDebug>

namespace Ui {
class IHMStatistiques;
}

class IHMStatistiques : public QWidget
{
    Q_OBJECT

public:
    explicit IHMStatistiques(AccesMySQL & mySqlBdd, QWidget *parent = 0);
    ~IHMStatistiques();

private:
    Ui::IHMStatistiques *ui;
    AccesMySQL bdd;

private slots:

    void on_pushButtonDate1_clicked();

    void on_pushButtonDate2_clicked();


};

#endif // IHMSTATISTIQUES_H
