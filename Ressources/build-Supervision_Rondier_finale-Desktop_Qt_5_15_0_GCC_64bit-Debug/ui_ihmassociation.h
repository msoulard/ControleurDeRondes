/********************************************************************************
** Form generated from reading UI file 'ihmassociation.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IHMASSOCIATION_H
#define UI_IHMASSOCIATION_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IHMAssociation
{
public:
    QListView *listViewRondes;
    QLabel *label_2;
    QLabel *label_3;
    QListView *listViewRondesAssociees;
    QPushButton *pushButton_4;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBoxNomAgents;
    QPushButton *pushButton;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QPushButton *pushButton_2;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_5;
    QPushButton *pushButton_3;

    void setupUi(QWidget *IHMAssociation)
    {
        if (IHMAssociation->objectName().isEmpty())
            IHMAssociation->setObjectName(QString::fromUtf8("IHMAssociation"));
        IHMAssociation->resize(1223, 588);
        listViewRondes = new QListView(IHMAssociation);
        listViewRondes->setObjectName(QString::fromUtf8("listViewRondes"));
        listViewRondes->setGeometry(QRect(20, 150, 391, 281));
        label_2 = new QLabel(IHMAssociation);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(130, 120, 101, 16));
        label_3 = new QLabel(IHMAssociation);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(610, 110, 171, 16));
        listViewRondesAssociees = new QListView(IHMAssociation);
        listViewRondesAssociees->setObjectName(QString::fromUtf8("listViewRondesAssociees"));
        listViewRondesAssociees->setGeometry(QRect(590, 140, 461, 291));
        pushButton_4 = new QPushButton(IHMAssociation);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(420, 450, 121, 51));
        layoutWidget = new QWidget(IHMAssociation);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(360, 30, 275, 26));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        comboBoxNomAgents = new QComboBox(layoutWidget);
        comboBoxNomAgents->setObjectName(QString::fromUtf8("comboBoxNomAgents"));

        horizontalLayout->addWidget(comboBoxNomAgents);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        layoutWidget1 = new QWidget(IHMAssociation);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(430, 180, 131, 48));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        pushButton_2 = new QPushButton(layoutWidget1);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/images/droiteIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon);

        verticalLayout->addWidget(pushButton_2);

        layoutWidget2 = new QWidget(IHMAssociation);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(433, 310, 131, 51));
        verticalLayout_2 = new QVBoxLayout(layoutWidget2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_2->addWidget(label_5);

        pushButton_3 = new QPushButton(layoutWidget2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/images/gaucheIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon1);

        verticalLayout_2->addWidget(pushButton_3);


        retranslateUi(IHMAssociation);

        QMetaObject::connectSlotsByName(IHMAssociation);
    } // setupUi

    void retranslateUi(QWidget *IHMAssociation)
    {
        IHMAssociation->setWindowTitle(QCoreApplication::translate("IHMAssociation", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("IHMAssociation", "Liste des rondes :", nullptr));
        label_3->setText(QCoreApplication::translate("IHMAssociation", "Liste des rondes de l'agent :", nullptr));
        pushButton_4->setText(QCoreApplication::translate("IHMAssociation", "Enregistrer", nullptr));
        label->setText(QCoreApplication::translate("IHMAssociation", "Choix de l'agent :", nullptr));
        pushButton->setText(QCoreApplication::translate("IHMAssociation", "Appliquer", nullptr));
        label_4->setText(QCoreApplication::translate("IHMAssociation", "Affecter la ronde", nullptr));
        pushButton_2->setText(QString());
        label_5->setText(QCoreApplication::translate("IHMAssociation", "D\303\251saffecter la ronde", nullptr));
        pushButton_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class IHMAssociation: public Ui_IHMAssociation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IHMASSOCIATION_H
