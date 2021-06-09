/********************************************************************************
** Form generated from reading UI file 'modiflieu.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFLIEU_H
#define UI_MODIFLIEU_H

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

class Ui_ModifLieu
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

    void setupUi(QWidget *ModifLieu)
    {
        if (ModifLieu->objectName().isEmpty())
            ModifLieu->setObjectName(QString::fromUtf8("ModifLieu"));
        ModifLieu->resize(502, 387);
        layoutWidget = new QWidget(ModifLieu);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(110, 80, 271, 191));
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

        label = new QLabel(ModifLieu);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(170, 40, 101, 16));
        layoutWidget_2 = new QWidget(ModifLieu);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(150, 300, 183, 26));
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


        retranslateUi(ModifLieu);

        QMetaObject::connectSlotsByName(ModifLieu);
    } // setupUi

    void retranslateUi(QWidget *ModifLieu)
    {
        ModifLieu->setWindowTitle(QCoreApplication::translate("ModifLieu", "Form", nullptr));
        label_3->setText(QCoreApplication::translate("ModifLieu", "B\303\242timent :", nullptr));
        label_4->setText(QCoreApplication::translate("ModifLieu", "\303\211tage :", nullptr));
        label_5->setText(QCoreApplication::translate("ModifLieu", "Emplacement :", nullptr));
        label->setText(QCoreApplication::translate("ModifLieu", "Modifier un lieu", nullptr));
        pushButtonEnregistrer->setText(QCoreApplication::translate("ModifLieu", "Enregistrer", nullptr));
        pushButtonAnnuler->setText(QCoreApplication::translate("ModifLieu", "Annuler", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModifLieu: public Ui_ModifLieu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFLIEU_H
