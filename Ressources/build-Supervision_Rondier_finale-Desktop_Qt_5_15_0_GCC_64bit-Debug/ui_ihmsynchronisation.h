/********************************************************************************
** Form generated from reading UI file 'ihmsynchronisation.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IHMSYNCHRONISATION_H
#define UI_IHMSYNCHRONISATION_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ihmSynchronisation
{
public:
    QPushButton *pushButton_EnvoyerSmartphone;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_12;
    QPushButton *pushButton_Detecter;
    QPushButton *pushButton_EnvoyerOrdinateur;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_13;
    QComboBox *comboBox_2;

    void setupUi(QWidget *ihmSynchronisation)
    {
        if (ihmSynchronisation->objectName().isEmpty())
            ihmSynchronisation->setObjectName(QString::fromUtf8("ihmSynchronisation"));
        ihmSynchronisation->resize(723, 426);
        pushButton_EnvoyerSmartphone = new QPushButton(ihmSynchronisation);
        pushButton_EnvoyerSmartphone->setObjectName(QString::fromUtf8("pushButton_EnvoyerSmartphone"));
        pushButton_EnvoyerSmartphone->setGeometry(QRect(150, 210, 161, 51));
        layoutWidget = new QWidget(ihmSynchronisation);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(400, 20, 278, 48));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout_3->addWidget(label_12);

        pushButton_Detecter = new QPushButton(layoutWidget);
        pushButton_Detecter->setObjectName(QString::fromUtf8("pushButton_Detecter"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/images/smartphoneAddIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Detecter->setIcon(icon);

        verticalLayout_3->addWidget(pushButton_Detecter);

        pushButton_EnvoyerOrdinateur = new QPushButton(ihmSynchronisation);
        pushButton_EnvoyerOrdinateur->setObjectName(QString::fromUtf8("pushButton_EnvoyerOrdinateur"));
        pushButton_EnvoyerOrdinateur->setGeometry(QRect(330, 210, 161, 51));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/images/synchroIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_EnvoyerOrdinateur->setIcon(icon1);
        verticalLayoutWidget = new QWidget(ihmSynchronisation);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 20, 204, 51));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_13 = new QLabel(verticalLayoutWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        verticalLayout_4->addWidget(label_13);

        comboBox_2 = new QComboBox(verticalLayoutWidget);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        verticalLayout_4->addWidget(comboBox_2);


        retranslateUi(ihmSynchronisation);

        QMetaObject::connectSlotsByName(ihmSynchronisation);
    } // setupUi

    void retranslateUi(QWidget *ihmSynchronisation)
    {
        ihmSynchronisation->setWindowTitle(QCoreApplication::translate("ihmSynchronisation", "Form", nullptr));
        pushButton_EnvoyerSmartphone->setText(QCoreApplication::translate("ihmSynchronisation", "Envoyer au smartphone", nullptr));
        label_12->setText(QCoreApplication::translate("ihmSynchronisation", "Rechercher un nouveau smartphone connect\303\251 :", nullptr));
        pushButton_Detecter->setText(QCoreApplication::translate("ihmSynchronisation", "D\303\251tecter", nullptr));
        pushButton_EnvoyerOrdinateur->setText(QCoreApplication::translate("ihmSynchronisation", "Envoyer \303\240 la station d'accueil", nullptr));
        label_13->setText(QCoreApplication::translate("ihmSynchronisation", "Liste des smartphones connect\303\251s :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ihmSynchronisation: public Ui_ihmSynchronisation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IHMSYNCHRONISATION_H
