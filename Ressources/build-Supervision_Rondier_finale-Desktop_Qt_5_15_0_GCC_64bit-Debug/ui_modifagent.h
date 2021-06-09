/********************************************************************************
** Form generated from reading UI file 'modifagent.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFAGENT_H
#define UI_MODIFAGENT_H

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

class Ui_ModifAgent
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEditNom;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *lineEditPrenom;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *lineEditBadge;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_4;
    QRadioButton *radioButtonActif;
    QRadioButton *radioButtonInactif;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLabel *label;

    void setupUi(QWidget *ModifAgent)
    {
        if (ModifAgent->objectName().isEmpty())
            ModifAgent->setObjectName(QString::fromUtf8("ModifAgent"));
        ModifAgent->resize(639, 455);
        layoutWidget = new QWidget(ModifAgent);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(190, 100, 291, 201));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        lineEditNom = new QLineEdit(layoutWidget);
        lineEditNom->setObjectName(QString::fromUtf8("lineEditNom"));

        horizontalLayout->addWidget(lineEditNom);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        lineEditPrenom = new QLineEdit(layoutWidget);
        lineEditPrenom->setObjectName(QString::fromUtf8("lineEditPrenom"));

        horizontalLayout_2->addWidget(lineEditPrenom);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        lineEditBadge = new QLineEdit(layoutWidget);
        lineEditBadge->setObjectName(QString::fromUtf8("lineEditBadge"));

        horizontalLayout_3->addWidget(lineEditBadge);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_4->addWidget(label_5);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        radioButtonActif = new QRadioButton(layoutWidget);
        radioButtonActif->setObjectName(QString::fromUtf8("radioButtonActif"));
        radioButtonActif->setChecked(true);

        horizontalLayout_4->addWidget(radioButtonActif);

        radioButtonInactif = new QRadioButton(layoutWidget);
        radioButtonInactif->setObjectName(QString::fromUtf8("radioButtonInactif"));

        horizontalLayout_4->addWidget(radioButtonInactif);


        verticalLayout->addLayout(horizontalLayout_4);

        layoutWidget_2 = new QWidget(ModifAgent);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(240, 320, 189, 26));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        pushButton_3 = new QPushButton(layoutWidget_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/images/saveIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon);

        horizontalLayout_5->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(layoutWidget_2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/images/supprIcon2.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon1);

        horizontalLayout_5->addWidget(pushButton_4);

        label = new QLabel(ModifAgent);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(280, 40, 111, 16));

        retranslateUi(ModifAgent);

        QMetaObject::connectSlotsByName(ModifAgent);
    } // setupUi

    void retranslateUi(QWidget *ModifAgent)
    {
        ModifAgent->setWindowTitle(QCoreApplication::translate("ModifAgent", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("ModifAgent", "Nom :", nullptr));
        label_3->setText(QCoreApplication::translate("ModifAgent", "Pr\303\251nom :", nullptr));
        label_4->setText(QCoreApplication::translate("ModifAgent", "Num\303\251ro de badge :", nullptr));
        label_5->setText(QCoreApplication::translate("ModifAgent", "Agent :", nullptr));
        radioButtonActif->setText(QCoreApplication::translate("ModifAgent", "actif", nullptr));
        radioButtonInactif->setText(QCoreApplication::translate("ModifAgent", "inactif", nullptr));
        pushButton_3->setText(QCoreApplication::translate("ModifAgent", "Enregistrer", nullptr));
        pushButton_4->setText(QCoreApplication::translate("ModifAgent", "Annuler", nullptr));
        label->setText(QCoreApplication::translate("ModifAgent", "Modifier un agent", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModifAgent: public Ui_ModifAgent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFAGENT_H
