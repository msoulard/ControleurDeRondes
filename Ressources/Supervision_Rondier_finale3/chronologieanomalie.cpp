/**
  @file chronologieanomalie.h
  @brief Implémentation de la classe ChronologieAnomalie
  @version 1.0
  @author Ouijdane IMER
  @date   3/05/2021
  */

#include "chronologieanomalie.h"
#include "ui_chronologieanomalie.h"
#include "QBuffer"
/**
 * @brief ChronologieAnomalie::ChronologieAnomalie
 * @details le constructeur de la classe ChronologieAnomalie
 * @param _database
 * @param _NomAgent
 * @param _NomRonde
 * @param _idHistoriqueRonde
 * @param parent
 */

ChronologieAnomalie::ChronologieAnomalie(AccesMySQL &_database, QString _NomAgent, QString _NomRonde, const int _idHistoriqueRonde, QWidget *parent) :
    QWidget(parent),

    ui(new Ui::ChronologieAnomalie),
    database(_database),
    NomAgent(_NomAgent),
    NomRonde(_NomRonde),
    idHistoriqueRonde(_idHistoriqueRonde)
{
    ui->setupUi(this);
    ui->tableWidgetChronologie->setColumnWidth(0,20);
    ui->tableWidgetChronologie->setColumnWidth(1,350);
    ui->tableWidgetChronologie->setColumnWidth(2,350);
    ui->tableWidgetChronologie->setColumnWidth(3,350);
    ui->tableWidgetChronologie->setColumnWidth(4,350);
    ui->checkBox1->hide();
    ui->labelImage1->hide();
    ui->checkBox_2->hide();
    ui->labelImage_2->hide();
    ui->checkBox_3->hide();
    ui->labelImage_3->hide();
    ui->textBrowser->hide();
    QList<Lieux> lieu;
    QList <DonneesHistorique> nomRondeLabel;

    ui->labelChronologie->setText("Chronologie de l'inspection de "+_NomRonde);

    listeCheminSelectionImagesDuPdf.clear();
    RemplirTableChronologie();

}

ChronologieAnomalie::~ChronologieAnomalie()
{
    delete ui;
}

void ChronologieAnomalie::on_tableWidgetChronologie_cellClicked(int row, int column)
{

}

/**
 * @brief ChronologieAnomalie::on_pushButtonpdf_clicked
 * @details Ce slot permet de cliquer sur le bouton PDF pour enregistrer le PDF générée
 */
void ChronologieAnomalie::on_pushButtonpdf_clicked()
{
    ExporterPdf();
    close();
}
/**
 * @brief ChronologieAnomalie::RemplirTableChronologie
 * @details Cette méthode permet de remplir le tableau chronologie et de savoir l'anomalie trouvée par l'agent
 */

void ChronologieAnomalie::RemplirTableChronologie()
{
    QList<DonneesChronologieAnomalie> listeChronologieAnomalie;
    ui->tableWidgetChronologie->setColumnCount(7);
    QStringList labels;
    QList<Anomalie> listeAnomalies;
    labels <<"ordre"<< "Désignation" <<"Lieu"<<"Date de passage" << "Heure de passage"<<"idAnomalie"<<"description"<<"idPhotos";
    ui->tableWidgetChronologie->setHorizontalHeaderLabels(labels);
    int rowCount=0;
    QHeaderView * headerView = ui->tableWidgetChronologie->horizontalHeader();
    headerView->setSectionResizeMode(QHeaderView::ResizeToContents);
    database.RecupererTableauNiveauDeux(listeChronologieAnomalie,idHistoriqueRonde,listeAnomalies);
    int idAnomalie=-1;

    ui->tableWidgetChronologie->hideColumn(COLONNE_ID_ANOMALIE);
    ui->tableWidgetChronologie->hideColumn(COLONNE_DESCRIPTION);
    foreach (DonneesChronologieAnomalie h,listeChronologieAnomalie)
    {

        QTableWidgetItem *ordre=new QTableWidgetItem(QString::number(h.ordre));
        QTableWidgetItem *designation=new QTableWidgetItem(h.lieuRonde.designation);
        QTableWidgetItem *lieu=new QTableWidgetItem( h.lieuRonde.batiment +" "+ h.lieuRonde.etage +" "+ h.lieuRonde.emplacement );
        QTableWidgetItem *Date=new QTableWidgetItem(h.dateHeure.date().toString("yyyy-MM-dd"));
        QTableWidgetItem *heure=new QTableWidgetItem(h.dateHeure.time().toString());

        QTableWidgetItem *id_anomalie=new QTableWidgetItem(QString::number(h.idAnomalie));
        QTableWidgetItem *description=new QTableWidgetItem((h.description));

        ui->tableWidgetChronologie->insertRow(ui->tableWidgetChronologie->rowCount());
        ui->tableWidgetChronologie->setItem(rowCount,COLONNE_ORDRE,ordre);
        ui->tableWidgetChronologie->setItem(rowCount,COLONNE_DESIGNATION,designation);
        ui->tableWidgetChronologie->setItem(rowCount,COLONNE_LIEU,lieu);
        ui->tableWidgetChronologie->setItem(rowCount,COLONNE_DATE,Date);
        ui->tableWidgetChronologie->setItem(rowCount,COLONNE_HEURE_CHRONOLOGIE,heure);
        ui->tableWidgetChronologie->setItem(rowCount,COLONNE_ID_ANOMALIE,id_anomalie);
        ui->tableWidgetChronologie->setItem(rowCount,COLONNE_DESCRIPTION,description);

        // mettre des couleurs pour les anomalies
        idAnomalie=h.idAnomalie;
        //idPhotoA=h.idPhoto;

        // anomalie avec defaut d'ordre couleur en Orange
        if(idAnomalie==1)
        {
            QBrush brush{"orange"};
            ordre->setBackground(brush);
            designation->setBackground(brush);
            lieu->setBackground(brush);
            Date->setBackground(brush);
            heure->setBackground(brush);

        }

        //anomalie sans defaut d'ordre couleur en rouge
        if(idAnomalie>1){
            QBrush brush2{"red"};
            ordre->setBackground(brush2);
            designation->setBackground(brush2);
            lieu->setBackground(brush2);
            Date->setBackground(brush2);
            heure->setBackground(brush2);
        }
        //

        rowCount++;
    }

}
/**
 * @brief ChronologieAnomalie::ExporterPdf
 * @details Cette méthode permet de générer un Pdf
 */
void ChronologieAnomalie::ExporterPdf()
{QFileDialog fichierDlg(this);
    QString cheminDuFichier;
    fichierDlg.setAcceptMode(QFileDialog::AcceptSave);
    fichierDlg.setWindowTitle("Enregistrement du fichier PDF");
    fichierDlg.setOption(QFileDialog::DontResolveSymlinks);
    fichierDlg.setViewMode(QFileDialog::Detail);
    fichierDlg.setNameFilters(QStringList()<< "PDF File (*.pdf)");
    fichierDlg.setDefaultSuffix("pdf");
    if(fichierDlg.exec() && fichierDlg.selectedFiles().size()!=0)
    {
        cheminDuFichier = fichierDlg.selectedFiles() [0];
        //Création du PDF
        QPdfWriter rapport(cheminDuFichier);
        rapport.setPageSize(QPageSize(QPageSize::A4));
        rapport.setPageOrientation(QPageLayout::Portrait);
        rapport.setPageMargins(QMargins(10,10,10,10));
        rapport.setResolution(100);


        QPainter painter;

        painter.begin(&rapport);

        //Titre

        QRectF rectangleTitle(0,0 ,900, 750);

        QColor colorBlue(qRgb(135,206,250));
        QTextDocument title;
        title.setTextWidth(rectangleTitle.width());

        title.setHtml("<font  color='black' size='14'><p style='margin-left: 140%; font-family: Georgia, serif;font-weight:900;top: 4em;'>Rapport de ronde</p></font>");

        title.drawContents(&painter,rectangleTitle);

        QRectF target(550, 1, 200, 250);
        QRectF source(0.0, 0.0, 400, 450);
        QImage image(":/img/LogoTouchard.png");

        painter.drawImage(target, image, source);

        //dateHeure
        QDateTime dateTime;
        const QRect LabelDateHeure = QRect(100, 100, 100, 150);
        QPen framePen(Qt::black);
        framePen.setWidth(2);
        painter.setPen(framePen);
        QRectF rectangle(200, 100, 210, 18);
        painter.drawRoundedRect(rectangle,10,10);
        QRect boundingRect;
        painter.drawText(LabelDateHeure,0, tr("Date et heure"), &boundingRect);
        painter.drawText(rectangle,Qt::AlignHCenter|Qt::AlignCenter,dateTime.currentDateTime().toString("yyyy-MM-dd à hh:mm:ss"));

        //NomRonde
        const QRect LabelNomSite = QRect(100, 150, 100, 150);
        QRectF rectangle2(200, 150, 250, 18);
        painter.drawRoundedRect(rectangle2,10,10);
        QRect boundingRect2;
        painter.drawText(LabelNomSite, 1, tr("La ronde"), &boundingRect2);
        painter.drawText(rectangle2,Qt::AlignHCenter|Qt::AlignCenter,NomRonde);

        //Adresse
        const QRect LabelAdresse = QRect(100, 200, 100, 150);
        QRectF rectangle4(200, 200, 350, 18);

        painter.drawRoundedRect(rectangle4,10,10);
        QRect boundingRect3;
        painter.drawText(LabelAdresse, 1, tr("Adresse du site"), &boundingRect3);
        painter.drawText(rectangle4,Qt::AlignHCenter|Qt::AlignCenter,"8 Place George Washington, 72100 Le Mans");
        //NomAGENT
        const QRect LabelNomAgent = QRect(100, 250, 100, 150);
        QRectF rectangle5(200, 250, 230, 18);
        painter.drawRoundedRect(rectangle5,10,10);
        QRect boundingRect4;
        painter.drawText(LabelNomAgent, 1, tr("L'agent"), &boundingRect4);
        painter.drawText(rectangle5,Qt::AlignHCenter|Qt::AlignCenter,NomAgent);
        //LabelTitleChronologie
        QRectF rectangleTitleChronologie(50,300 ,700, 20);
        QFont fontTitre(QFont("Verdana",10,QFont::Bold));
        painter.fillRect(rectangleTitleChronologie,colorBlue);
        painter.drawRect(rectangleTitleChronologie);
        painter.drawText(rectangleTitleChronologie,Qt::AlignHCenter|Qt::AlignCenter,"Chronologie de l'inspection de la ronde");

        //tableauChronologie
        QRect cellule(-5,350,160,25);
        int largeurCellule = cellule.width();
        int hauteurCellule = cellule.height();

        QStringList enteteTableau;
        enteteTableau << QString("Ordre de passage") << QString("Désignation") << QString("Lieu")<<QString("Date de passage") << QString("Heure de passage");

        QFont fontTexte(QFont("Verdana",8,QFont::Normal));

        QList<DonneesChronologieAnomalie> listeChronologieAnomalie;
        QList<Anomalie> listeAnomalies;
        int idAnomalie=-1;
        database.RecupererTableauNiveauDeux(listeChronologieAnomalie,idHistoriqueRonde,listeAnomalies);
        int colonne=0;
        painter.setFont(fontTitre);
        for( colonne=0;colonne<5;colonne++)
        {
            painter.drawText(cellule,Qt::AlignCenter|Qt::AlignHCenter,enteteTableau.at(colonne));
            painter.drawRect(cellule);
            cellule.translate(largeurCellule,0);

        }
        cellule.translate(-5*largeurCellule,hauteurCellule);

        painter.setFont(fontTexte);
        QStringList ligneTexte;
        foreach (DonneesChronologieAnomalie A,listeChronologieAnomalie)
        {
            painter.setPen(QPen(Qt::black));
            painter.drawRect(cellule);
            ligneTexte.clear();
            ligneTexte <<  QString::number(A.ordre);
            ligneTexte << A.lieuRonde.designation;
            ligneTexte << A.lieuRonde.batiment +""+ A.lieuRonde.etage +""+A.lieuRonde.emplacement ;
            ligneTexte << A.dateHeure.date().toString("yyyy-MM-dd");
            ligneTexte << A.dateHeure.time().toString();

            idAnomalie=A.idAnomalie;

            QBrush brush("white");
            switch(idAnomalie)
            {
            case 1:
                brush.setColor("orange");
                break;
            case 0:
                brush.setColor("white");
                break;
            default:
                brush.setColor("red");

            }

            for( colonne=0;colonne<5;colonne++)
            {
                painter.fillRect(cellule,brush);
                painter.drawText(cellule,Qt::AlignCenter|Qt::AlignHCenter,ligneTexte.at(colonne));
                painter.drawRect(cellule);
                cellule.translate(largeurCellule,0);

            }

            cellule.translate(-5*largeurCellule,hauteurCellule);
        }

        //Mentionner La case de la date
        QRectF rectangleTitleDate(100,1020 ,100, 30);
        const QRect LabelDatee = QRect(100, 1000, 100, 150);
        painter.drawRect(rectangleTitleDate);
        QRect boundingRectDate;
        painter.drawText(LabelDatee, 1, tr("Date"), &boundingRectDate);

        //Mentionner la case de la signature
        QRectF rectangleSignature(550,1020 ,100, 30);
        const QRect LabelSignature = QRect(550, 1000, 200, 150);
        painter.drawRect(rectangleSignature);
        QRect boundingRectSignature;
        painter.drawText(LabelSignature, 1, tr("Signature du responsable"), &boundingRectSignature);

        //Nouvelle Page
        if(!rapport.newPage())
        {


        }
        //LabelAnomalie
        QRectF rectangleTitleAnomalie(50,50 ,700, 20);

        painter.fillRect(rectangleTitleAnomalie,colorBlue);
        painter.drawRect(rectangleTitleAnomalie);
        painter.drawText(rectangleTitleAnomalie,Qt::AlignHCenter|Qt::AlignCenter,"Les problèmes rencontrés et les images");

        int colonneAnomalie=0;
        //tableauAnomalie
        QRect CelluleAnomalieImage(10,-9,250,HAUTEUR_CELLULE_ANOMALIE_PDF);
        QRect CelluleEnteteTableau(10,100,250,HAUTEUR_CELLULE_ENTETE_ANOMALIE_PDF);
        int largeurCelluleA = CelluleAnomalieImage.width();
        int hauteurCelluleA = CelluleAnomalieImage.height();

        QStringList enteteTableauAnomalie;
        enteteTableauAnomalie << QString("Lieu") << QString("Images");
        enteteTableauAnomalie << QString("Description") ;
        QList<DonneesChronologieAnomalie> listeChronologieAnomalieTab;
        QList<Anomalie> listeAnomalies1;

        // generation en-tete tableau anomalies

        for(colonneAnomalie=0;colonneAnomalie<3;colonneAnomalie++)
        {
            painter.drawText(CelluleEnteteTableau,Qt::AlignCenter|Qt::AlignHCenter,enteteTableauAnomalie.at(colonneAnomalie));
            painter.drawRect(CelluleEnteteTableau);
            CelluleEnteteTableau.translate(largeurCelluleA,0);
            CelluleAnomalieImage.translate(largeurCelluleA,0);

        }
        CelluleEnteteTableau.translate(-3*largeurCelluleA,hauteurCellule);
        CelluleAnomalieImage.translate(-3*largeurCelluleA,hauteurCelluleA);

        painter.setFont(fontTexte);
        QStringList ligneTexteAnomalie;

        database.RecupererTabAnomalie(listeChronologieAnomalieTab,idHistoriqueRonde);

        //génération du contenu tableau des anomalies
        foreach (DonneesChronologieAnomalie anomalie,listeChronologieAnomalieTab)
        {
            painter.setPen(QPen(Qt::black));
            //painter.drawRect(CelluleAnomalie);
            ligneTexteAnomalie.clear();

            ligneTexteAnomalie <<  anomalie.lieuRonde.batiment +" " +anomalie.lieuRonde.etage+ " "+ anomalie.lieuRonde.emplacement;

            ligneTexteAnomalie <<" ";

            ligneTexteAnomalie <<  anomalie.description;

            QBrush brush("white");

            QPen penRed(QColor(Qt::red),2);
            QPen penBlack(QPen(Qt::black,2));
            QPen penOrange(QColor(255,69,0),2);

            qDebug()<<anomalie.idAnomalie;
            switch(anomalie.idAnomalie)
            {
            case 1:

                painter.setPen(penOrange);

                break;
            case 0:

                painter.setPen(penBlack);


                break;
            default:

                painter.setPen(penRed);

                painter.setBackgroundMode(Qt::BGMode(Qt::red));



            }



            CelluleAnomalieImage.setHeight(HAUTEUR_CELLULE_ANOMALIE_PDF);   // remettre hauteur pas defaut
            //painter.setPen(penOrange);
            for( colonneAnomalie=0;colonneAnomalie<3;colonneAnomalie++)
            {
                //if (anomalie.idAnomalie==1)
                if (anomalie.idAnomalie==1 || !listeCheminSelectionImagesDuPdf.contains(anomalie.cheminImage))
                {
                    CelluleAnomalieImage.setHeight(HAUTEUR_CELLULE_DEFAUT_PDF); // mettre hauteur plus petite


                }
                //if (listeCheminSelectionImagesDuPdf.contains(anomalie.cheminImage) || anomalie.idAnomalie==1)   // dessin si image ou defaut ordre
                // {


                //painter.fillRect(CelluleAnomalieImage,brush);
                QFont font=painter.font();
                font.setBold(true);

                painter.setFont(font);
                painter.drawText(CelluleAnomalieImage,Qt::AlignCenter,ligneTexteAnomalie.at(colonneAnomalie));
                font.setBold(false);
                painter.setFont(font);
                painter.setPen(penBlack);
                painter.drawRect(CelluleAnomalieImage);
                CelluleAnomalieImage.translate(largeurCelluleA,0);
                //}

            }
            // ajout image anomalie
            if (listeCheminSelectionImagesDuPdf.contains(anomalie.cheminImage)){
                QImage image(anomalie.cheminImage);

                painter.drawImage(largeurCelluleA+CENTRE_IMAGE_ANOMALIE_PDF,CelluleAnomalieImage.y(),image.scaledToHeight(HAUTEUR_CELLULE_ANOMALIE_PDF));

            }
            // passage a la ligne
            if (anomalie.idAnomalie==1 || !listeCheminSelectionImagesDuPdf.contains(anomalie.cheminImage))
            {
                CelluleAnomalieImage.translate(-3*largeurCelluleA,HAUTEUR_CELLULE_DEFAUT_PDF);

            }
            else
            {
                if ( listeCheminSelectionImagesDuPdf.contains(anomalie.cheminImage))
                {
                    CelluleAnomalieImage.translate(-3*largeurCelluleA,hauteurCelluleA);
                }


            }

        }
        if(!rapport.newPage())
        {


        }

        painter.end();



    }

}
/**
 * @brief ChronologieAnomalie::on_PushButtonAnnuler_clicked
 * @details ce slot permet de cliquer sur le bouton Annuler pour fermet la page Chronologie
 */

void ChronologieAnomalie::on_PushButtonAnnuler_clicked()
{
    close();
}

/**
 * @brief ChronologieAnomalie::on_tableWidgetChronologie_itemClicked
 * @param item
 * @details ce slot permet de récupérer l'image d'anamolie à partir d'une ligne d'un tableau
 */

void ChronologieAnomalie::on_tableWidgetChronologie_itemClicked(QTableWidgetItem *item)
{
    int idAnomalie=ui->tableWidgetChronologie->item(ui->tableWidgetChronologie->currentRow(),5)->text().toInt();// id de l'anomalie de la colonne cachée
        QString Description=ui->tableWidgetChronologie->item(ui->tableWidgetChronologie->currentRow(),6)->text();
        QList<DonneesChronologieAnomalie> anomalie;
        QList<Anomalie> listeAnomalies;
        ui->checkBox1->setChecked(false);
        ui->checkBox_2->setChecked(false);
        ui->checkBox_3->setChecked(false);
        if(idAnomalie>=1)
        {
            ui->labelAnomalie->setText("Anomalie Rencontrée dans le lieu "+ui->tableWidgetChronologie->item(ui->tableWidgetChronologie->currentRow(),COLONNE_LIEU)->text());
        }
        else {
            ui->labelAnomalie->setText("Aucune anomalie trouvée dans le lieu "+ui->tableWidgetChronologie->item(ui->tableWidgetChronologie->currentRow(),COLONNE_LIEU)->text());
        }

        database.RecupererTableauNiveauDeux(anomalie,idHistoriqueRonde,listeAnomalies);

        // TEST si je clique sur une ligne où il y a une anomalie
        // le programme affiche la partie des checkBoxs et les images
        // sinon les checksboxes et les images n'apparaissent pas s'il n' y a pas une anomalie
        if(idAnomalie>=1)
        {

            ui->checkBox1->show();
            ui->labelImage1->show();
            ui->checkBox_2->show();
            ui->labelImage_2->show();
            ui->checkBox_3->show();
            ui->labelImage_3->show();
            ui->textBrowser->show();
        }
        else
        {
            ui->checkBox1->hide();
            ui->labelImage1->hide();
            ui->checkBox_2->hide();
            ui->labelImage_2->hide();
            ui->checkBox_3->hide();
            ui->labelImage_3->hide();
            ui->textBrowser->hide();
        }

        // recuperer les chemins des images, en les mettant dans les labelsImages
        if(idAnomalie>=1)
        {
            QStringList chemins=database.RecupererCheminsImages(idAnomalie);
            Description=database.RecupererDescription(idAnomalie);
            ui->textBrowser->setText(Description);
            ui->labelImage1->clear();
            ui->labelImage_2->clear();
            ui->labelImage_3->clear();

            ui->labelImage1->show();
            ui->labelImage_2->show();
            ui->labelImage_3->show();

            switch (chemins.count())
            {
            case 1:
                ui->labelImage1->setPixmap(QPixmap(chemins[0]));
                ui->checkBox1->setCheminImage(chemins[0]);
                ui->labelImage_2->hide();
                ui->labelImage_3->hide();
                ui->checkBox_2->hide();
                ui->checkBox_3->hide();
                break;
            case 2:
                ui->labelImage1->setPixmap(QPixmap(chemins[0]));
                ui->labelImage_2->setPixmap(QPixmap(chemins[1]));

                ui->checkBox1->setCheminImage(chemins[0]);
                ui->checkBox_2->setCheminImage(chemins[1]);
                ui->labelImage_3->hide();
                ui->checkBox_3->hide();
                break;
            case 3:
                ui->labelImage1->setPixmap(QPixmap(chemins[0]));
                ui->labelImage_2->setPixmap(QPixmap(chemins[1]));
                ui->labelImage_3->setPixmap(QPixmap(chemins[2]));
                ui->checkBox1->setCheminImage(chemins[0]);
                ui->checkBox_2->setCheminImage(chemins[1]);
                break;

            }
            // cocher/decocher checked en fonction de la liste des images sélectionnée
            if (chemins.count()>=1 && listeCheminSelectionImagesDuPdf.contains(chemins[0]) )
            {
                ui->checkBox1->setChecked(true);
            }
            else
            {
                ui->checkBox1->setChecked(false);
                ui->checkBox1->setText("Aucune image sélectionnée");
            }

            if (chemins.count()>=2 && listeCheminSelectionImagesDuPdf.contains(chemins[1]))
            {
                ui->checkBox_2->setChecked(true);
            }
            else
            {
                ui->checkBox_2->setChecked(false);
                ui->checkBox_2->setText("Aucune image sélectionnée");
            }
            if (chemins.count()>=3 && listeCheminSelectionImagesDuPdf.contains(chemins[2]) )
            {
                ui->checkBox_3->setChecked(true);
            }
            else
            {
                ui->checkBox_3->setChecked(false);
                ui->checkBox_3->setText("Aucune image sélectionnée");
            }
        }
        else
        {
            ui->labelImage1->setText("Image Not found");
            ui->labelImage_2->setText("Image Not found");
            ui->labelImage_3->setText("Image Not found");
            ui->textBrowser->setText(Description);
        }



}



void ChronologieAnomalie::on_checkBox1_clicked()
{

    // tester si case est coche
    // si oui
    // ajouter dans liste des images selectionnees
    // chemin image courant

    if (ui->checkBox1->isChecked())
    {
        ui->checkBox1->setText("Image1 sélectionnée");
        qDebug()<<ui->checkBox1->getCheminImage();
        listeCheminSelectionImagesDuPdf.append(ui->checkBox1->getCheminImage());
    }
    else
    {
        ui->checkBox1->setText("Image1 non sélectionnée");
        listeCheminSelectionImagesDuPdf.removeOne(ui->checkBox1->getCheminImage());

    }
}

void ChronologieAnomalie::on_checkBox_2_clicked()
{
    if (ui->checkBox_2->isChecked())
    {
        ui->checkBox_2->setText("Image2 sélectionnée");
        qDebug()<<ui->checkBox_2->getCheminImage();
        listeCheminSelectionImagesDuPdf.append(ui->checkBox_2->getCheminImage());
    }
    else
    {
        ui->checkBox_2->setText("Image2 non sélectionnée");
        listeCheminSelectionImagesDuPdf.removeOne(ui->checkBox_2->getCheminImage());


    }

}

void ChronologieAnomalie::on_checkBox_3_clicked()
{

    if (ui->checkBox_3->isChecked())
    {
        ui->checkBox_3->setText("Image3 sélectionnée");
        qDebug()<<ui->checkBox_3->getCheminImage();
        listeCheminSelectionImagesDuPdf.append(ui->checkBox_3->getCheminImage());
    }
    else
    {
        ui->checkBox_3->setText("Image3  non sélectionnée");
        listeCheminSelectionImagesDuPdf.removeOne(ui->checkBox_3->getCheminImage());

    }

}
