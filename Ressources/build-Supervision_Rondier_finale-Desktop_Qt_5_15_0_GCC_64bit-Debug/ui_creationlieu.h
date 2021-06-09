/********************************************************************************
** Form generated from reading UI file 'creationlieu.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATIONLIEU_H
#define UI_CREATIONLIEU_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreationLieu
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *lineEditBatiment;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *lineEditEtage;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *lineEditEmplacement;
    QLabel *label;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButtonEnregistrer;
    QPushButton *pushButtonAnnuler;

    void setupUi(QWidget *CreationLieu)
    {
        if (CreationLieu->objectName().isEmpty())
            CreationLieu->setObjectName(QString::fromUtf8("CreationLieu"));
        CreationLieu->resize(486, 364);
        layoutWidget = new QWidget(CreationLieu);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(100, 70, 271, 191));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        lineEditBatiment = new QLineEdit(layoutWidget);
        lineEditBatiment->setObjectName(QString::fromUtf8("lineEditBatiment"));

        horizontalLayout_3->addWidget(lineEditBatiment);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        lineEditEtage = new QLineEdit(layoutWidget);
        lineEditEtage->setObjectName(QString::fromUtf8("lineEditEtage"));

        horizontalLayout_2->addWidget(lineEditEtage);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout->addWidget(label_5);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        lineEditEmplacement = new QLineEdit(layoutWidget);
        lineEditEmplacement->setObjectName(QString::fromUtf8("lineEditEmplacement"));

        horizontalLayout->addWidget(lineEditEmplacement);


        verticalLayout->addLayout(horizontalLayout);

        label = new QLabel(CreationLieu);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(180, 30, 101, 16));
        layoutWidget_2 = new QWidget(CreationLieu);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(140, 290, 183, 26));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        pushButtonEnregistrer = new QPushButton(layoutWidget_2);
        pushButtonEnregistrer->setObjectName(QString::fromUtf8("pushButtonEnregistrer"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/images/saveIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonEnregistrer->setIcon(icon);

        horizontalLayout_5->addWidget(pushButtonEnregistrer);

        pushButtonAnnuler = new QPushButton(layoutWidget_2);
        pushButtonAnnuler->setObjectName(QString::fromUtf8("pushButtonAnnuler"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/images/supprIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonAnnuler->setIcon(icon1);

        horizontalLayout_5->addWidget(pushButtonAnnuler);


        retranslateUi(CreationLieu);

        QMetaObject::connectSlotsByName(CreationLieu);
    } // setupUi

    void retranslateUi(QWidget *CreationLieu)
    {
        CreationLieu->setWindowTitle(QCoreApplication::translate("CreationLieu", "Form", nullptr));
        label_3->setText(QCoreApplication::translate("CreationLieu", "B\303\242timent :", nullptr));
        label_4->setText(QCoreApplication::translate("CreationLieu", "\303\211tage :", nullptr));
        label_5->setText(QCoreApplication::translate("CreationLieu", "Emplacement :", nullptr));
        label->setText(QCoreApplication::translate("CreationLieu", "Modifier un lieu", nullptr));
        pushButtonEnregistrer->setText(QCoreApplication::translate("CreationLieu", "Enregistrer", nullptr));
        pushButtonAnnuler->setText(QCoreApplication::translate("CreationLieu", "Annuler", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreationLieu: public Ui_CreationLieu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATIONLIEU_H
