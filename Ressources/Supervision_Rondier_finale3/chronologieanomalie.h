/**
  @file chronologieanomalie.h
  @brief Déclaration de la classe ChronologieAnomalie
  @version 1.0
  @author Ouijdane IMER
  @date   3/05/2021
  */

#ifndef CHRONOLOGIEANOMALIE_H
#define CHRONOLOGIEANOMALIE_H
#include <QWidget>
#include <QBrush>
#include <QVariant>
#include <QColor>
#include <QDebug>
#include <QPdfWriter>
#include <QFont>
#include <QFileDialog>
#include <QPrinter>
#include <QTextDocument>
#include <QPainter>
#include <QtGlobal>
#include <QLabel>
#include <QPixmap>
#include "historique.h"
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include "accesmysql.h"
#include "QImageReader"
#include "historique.h"
#define COLONNE_ORDRE 0
#define COLONNE_DESIGNATION 1
#define COLONNE_LIEU 2
#define COLONNE_DATE 3
#define COLONNE_HEURE_CHRONOLOGIE 4
#define COLONNE_ID_ANOMALIE 5
#define COLONNE_DESCRIPTION 6
#define HAUTEUR_CELLULE_ANOMALIE_PDF 160
#define HAUTEUR_CELLULE_DEFAUT_PDF 60
#define HAUTEUR_CELLULE_ENTETE_ANOMALIE_PDF 50
#define CENTRE_IMAGE_ANOMALIE_PDF 20
namespace Ui {
class ChronologieAnomalie;
}



class ChronologieAnomalie : public QWidget
{
    Q_OBJECT

public:
    explicit ChronologieAnomalie(AccesMySQL &_database, QString _NomAgent, QString _NomRonde, const int _idHistoriqueRonde, QWidget *parent = nullptr);
    ~ChronologieAnomalie();
       void RemplirTableChronologie();
private slots:

    void on_tableWidgetChronologie_cellClicked(int row, int column);

    void on_pushButtonpdf_clicked();

    void on_PushButtonAnnuler_clicked();

    void on_tableWidgetChronologie_itemClicked(QTableWidgetItem *item);



    void on_checkBox1_clicked();

    void on_checkBox_2_clicked();

    void on_checkBox_3_clicked();

private:
       void ExporterPdf();
    Ui::ChronologieAnomalie *ui;
    QPixmap * pixH; QLabel * header;
    AccesMySQL &database;
    int idHistoriqueRonde;
    QString NomAgent;
    QString NomRonde;
    QStringList listeCheminSelectionImagesDuPdf;







};

#endif // CHRONOLOGIEANOMALIE_H
