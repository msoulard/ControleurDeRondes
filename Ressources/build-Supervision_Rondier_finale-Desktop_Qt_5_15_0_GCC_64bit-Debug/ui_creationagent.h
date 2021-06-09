/********************************************************************************
** Form generated from reading UI file 'creationagent.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATIONAGENT_H
#define UI_CREATIONAGENT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreationAgent
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEditNom;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *lineEditPrenom;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *lineEditBadge;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QRadioButton *radioButtonActif;
    QRadioButton *radioButtonInactif;
    QLabel *label;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButtonEnregistrer;
    QPushButton *pushButtonAnnuler;

    void setupUi(QWidget *CreationAgent)
    {
        if (CreationAgent->objectName().isEmpty())
            CreationAgent->setObjectName(QString::fromUtf8("CreationAgent"));
        CreationAgent->resize(636, 406);
        layoutWidget = new QWidget(CreationAgent);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(140, 50, 291, 271));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_4->addWidget(label_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        lineEditNom = new QLineEdit(layoutWidget);
        lineEditNom->setObjectName(QString::fromUtf8("lineEditNom"));

        horizontalLayout_4->addWidget(lineEditNom);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        lineEditPrenom = new QLineEdit(layoutWidget);
        lineEditPrenom->setObjectName(QString::fromUtf8("lineEditPrenom"));

        horizontalLayout_3->addWidget(lineEditPrenom);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        lineEditBadge = new QLineEdit(layoutWidget);
        lineEditBadge->setObjectName(QString::fromUtf8("lineEditBadge"));

        horizontalLayout_2->addWidget(lineEditBadge);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout->addWidget(label_5);

        radioButtonActif = new QRadioButton(layoutWidget);
        radioButtonActif->setObjectName(QString::fromUtf8("radioButtonActif"));
        radioButtonActif->setChecked(true);

        horizontalLayout->addWidget(radioButtonActif);

        radioButtonInactif = new QRadioButton(layoutWidget);
        radioButtonInactif->setObjectName(QString::fromUtf8("radioButtonInactif"));

        horizontalLayout->addWidget(radioButtonInactif);


        verticalLayout->addLayout(horizontalLayout);

        label = new QLabel(CreationAgent);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(230, 10, 131, 16));
        layoutWidget_2 = new QWidget(CreationAgent);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(140, 340, 291, 26));
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


        retranslateUi(CreationAgent);

        QMetaObject::connectSlotsByName(CreationAgent);
    } // setupUi

    void retranslateUi(QWidget *CreationAgent)
    {
        CreationAgent->setWindowTitle(QCoreApplication::translate("CreationAgent", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("CreationAgent", "Nom :", nullptr));
        label_3->setText(QCoreApplication::translate("CreationAgent", "Pr\303\251nom :", nullptr));
        label_4->setText(QCoreApplication::translate("CreationAgent", "Num\303\251ro de badge :", nullptr));
        label_5->setText(QCoreApplication::translate("CreationAgent", "Statut  :", nullptr));
        radioButtonActif->setText(QCoreApplication::translate("CreationAgent", "Actif", nullptr));
        radioButtonInactif->setText(QCoreApplication::translate("CreationAgent", "Inactif", nullptr));
        label->setText(QCoreApplication::translate("CreationAgent", "Cr\303\251ation d'un agent", nullptr));
        pushButtonEnregistrer->setText(QCoreApplication::translate("CreationAgent", "Enregistrer", nullptr));
        pushButtonAnnuler->setText(QCoreApplication::translate("CreationAgent", "Annuler", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreationAgent: public Ui_CreationAgent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATIONAGENT_H
