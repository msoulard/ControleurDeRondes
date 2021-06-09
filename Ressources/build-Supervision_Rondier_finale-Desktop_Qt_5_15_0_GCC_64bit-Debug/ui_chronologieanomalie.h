/********************************************************************************
** Form generated from reading UI file 'chronologieanomalie.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHRONOLOGIEANOMALIE_H
#define UI_CHRONOLOGIEANOMALIE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcheckboximage.h"

QT_BEGIN_NAMESPACE

class Ui_ChronologieAnomalie
{
public:
    QGridLayout *gridLayout;
    QLabel *labelChronologie;
    QLabel *labelAnomalie;
    QTableWidget *tableWidgetChronologie;
    QTextBrowser *textBrowser;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *labelImage1;
    QCheckBoxImage *checkBox1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelImage_2;
    QCheckBoxImage *checkBox_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelImage_3;
    QCheckBoxImage *checkBox_3;
    QPushButton *pushButtonpdf;
    QPushButton *PushButtonAnnuler;

    void setupUi(QWidget *ChronologieAnomalie)
    {
        if (ChronologieAnomalie->objectName().isEmpty())
            ChronologieAnomalie->setObjectName(QString::fromUtf8("ChronologieAnomalie"));
        ChronologieAnomalie->resize(1320, 702);
        gridLayout = new QGridLayout(ChronologieAnomalie);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        labelChronologie = new QLabel(ChronologieAnomalie);
        labelChronologie->setObjectName(QString::fromUtf8("labelChronologie"));
        QFont font;
        font.setPointSize(16);
        labelChronologie->setFont(font);
        labelChronologie->setStyleSheet(QString::fromUtf8("background-color: white;"));
        labelChronologie->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelChronologie, 0, 0, 1, 2);

        labelAnomalie = new QLabel(ChronologieAnomalie);
        labelAnomalie->setObjectName(QString::fromUtf8("labelAnomalie"));
        labelAnomalie->setFont(font);
        labelAnomalie->setStyleSheet(QString::fromUtf8("background-color: white;"));
        labelAnomalie->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout->addWidget(labelAnomalie, 2, 0, 1, 2);

        tableWidgetChronologie = new QTableWidget(ChronologieAnomalie);
        tableWidgetChronologie->setObjectName(QString::fromUtf8("tableWidgetChronologie"));
        tableWidgetChronologie->setMaximumSize(QSize(16777215, 16777215));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        tableWidgetChronologie->setFont(font1);
        tableWidgetChronologie->setTabletTracking(false);
        tableWidgetChronologie->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(238, 238, 236);\n"
"alternate-background-color:#606060;\n"
"selection-background-color:#282828;\n"
""));
        tableWidgetChronologie->setAutoScroll(true);
        tableWidgetChronologie->setAlternatingRowColors(false);
        tableWidgetChronologie->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidgetChronologie->setGridStyle(Qt::SolidLine);
        tableWidgetChronologie->setSortingEnabled(false);
        tableWidgetChronologie->setWordWrap(true);
        tableWidgetChronologie->setCornerButtonEnabled(true);
        tableWidgetChronologie->setColumnCount(0);
        tableWidgetChronologie->verticalHeader()->setMinimumSectionSize(20);
        tableWidgetChronologie->verticalHeader()->setProperty("showSortIndicator", QVariant(false));

        gridLayout->addWidget(tableWidgetChronologie, 1, 0, 1, 2);

        textBrowser = new QTextBrowser(ChronologieAnomalie);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setMaximumSize(QSize(500, 200));

        gridLayout->addWidget(textBrowser, 3, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelImage1 = new QLabel(ChronologieAnomalie);
        labelImage1->setObjectName(QString::fromUtf8("labelImage1"));

        horizontalLayout->addWidget(labelImage1);

        checkBox1 = new QCheckBoxImage(ChronologieAnomalie);
        checkBox1->setObjectName(QString::fromUtf8("checkBox1"));

        horizontalLayout->addWidget(checkBox1);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        labelImage_2 = new QLabel(ChronologieAnomalie);
        labelImage_2->setObjectName(QString::fromUtf8("labelImage_2"));

        horizontalLayout_2->addWidget(labelImage_2);

        checkBox_2 = new QCheckBoxImage(ChronologieAnomalie);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

        horizontalLayout_2->addWidget(checkBox_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        labelImage_3 = new QLabel(ChronologieAnomalie);
        labelImage_3->setObjectName(QString::fromUtf8("labelImage_3"));

        horizontalLayout_3->addWidget(labelImage_3);

        checkBox_3 = new QCheckBoxImage(ChronologieAnomalie);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));

        horizontalLayout_3->addWidget(checkBox_3);


        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout, 3, 0, 1, 1);

        pushButtonpdf = new QPushButton(ChronologieAnomalie);
        pushButtonpdf->setObjectName(QString::fromUtf8("pushButtonpdf"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/images/pdf-file.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonpdf->setIcon(icon);
        pushButtonpdf->setIconSize(QSize(71, 48));

        gridLayout->addWidget(pushButtonpdf, 5, 1, 1, 1);

        PushButtonAnnuler = new QPushButton(ChronologieAnomalie);
        PushButtonAnnuler->setObjectName(QString::fromUtf8("PushButtonAnnuler"));

        gridLayout->addWidget(PushButtonAnnuler, 4, 1, 1, 1);


        retranslateUi(ChronologieAnomalie);

        QMetaObject::connectSlotsByName(ChronologieAnomalie);
    } // setupUi

    void retranslateUi(QWidget *ChronologieAnomalie)
    {
        ChronologieAnomalie->setWindowTitle(QCoreApplication::translate("ChronologieAnomalie", "ChronologieAnomalie", nullptr));
        labelChronologie->setText(QCoreApplication::translate("ChronologieAnomalie", "Chronologie de l'inspection de ", nullptr));
        labelAnomalie->setText(QCoreApplication::translate("ChronologieAnomalie", "L'anomalie rencontr\303\251e", nullptr));
        labelImage1->setText(QCoreApplication::translate("ChronologieAnomalie", "Image1", nullptr));
        checkBox1->setText(QCoreApplication::translate("ChronologieAnomalie", "Aucune image s\303\251lectionn\303\251e", nullptr));
        labelImage_2->setText(QCoreApplication::translate("ChronologieAnomalie", "Image2", nullptr));
        checkBox_2->setText(QCoreApplication::translate("ChronologieAnomalie", "Aucune image s\303\251lectionn\303\251e", nullptr));
        labelImage_3->setText(QCoreApplication::translate("ChronologieAnomalie", "image3", nullptr));
        checkBox_3->setText(QCoreApplication::translate("ChronologieAnomalie", "Aucune image s\303\251lectionn\303\251e", nullptr));
        pushButtonpdf->setText(QString());
        PushButtonAnnuler->setText(QCoreApplication::translate("ChronologieAnomalie", "Annuler", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChronologieAnomalie: public Ui_ChronologieAnomalie {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHRONOLOGIEANOMALIE_H
