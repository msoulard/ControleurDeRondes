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
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_10;
    QComboBox *comboBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_11;
    QPushButton *pushButton_Detecter;
    QPushButton *pushButton_EnvoyerOrdinateur;
    QPushButton *pushButton_EnvoyerSmartphone;

    void setupUi(QWidget *ihmSynchronisation)
    {
        if (ihmSynchronisation->objectName().isEmpty())
            ihmSynchronisation->setObjectName(QString::fromUtf8("ihmSynchronisation"));
        ihmSynchronisation->resize(800, 600);
        verticalLayoutWidget = new QWidget(ihmSynchronisation);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(60, 80, 204, 51));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(verticalLayoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout->addWidget(label_10);

        comboBox = new QComboBox(verticalLayoutWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        verticalLayout->addWidget(comboBox);

        layoutWidget = new QWidget(ihmSynchronisation);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(450, 80, 278, 48));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout_2->addWidget(label_11);

        pushButton_Detecter = new QPushButton(layoutWidget);
        pushButton_Detecter->setObjectName(QString::fromUtf8("pushButton_Detecter"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/images/smartphoneAddIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Detecter->setIcon(icon);

        verticalLayout_2->addWidget(pushButton_Detecter);

        pushButton_EnvoyerOrdinateur = new QPushButton(ihmSynchronisation);
        pushButton_EnvoyerOrdinateur->setObjectName(QString::fromUtf8("pushButton_EnvoyerOrdinateur"));
        pushButton_EnvoyerOrdinateur->setGeometry(QRect(380, 270, 161, 51));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/images/synchroIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_EnvoyerOrdinateur->setIcon(icon1);
        pushButton_EnvoyerSmartphone = new QPushButton(ihmSynchronisation);
        pushButton_EnvoyerSmartphone->setObjectName(QString::fromUtf8("pushButton_EnvoyerSmartphone"));
        pushButton_EnvoyerSmartphone->setGeometry(QRect(200, 270, 161, 51));

        retranslateUi(ihmSynchronisation);

        QMetaObject::connectSlotsByName(ihmSynchronisation);
    } // setupUi

    void retranslateUi(QWidget *ihmSynchronisation)
    {
        ihmSynchronisation->setWindowTitle(QCoreApplication::translate("ihmSynchronisation", "ihmSynchronisation", nullptr));
        label_10->setText(QCoreApplication::translate("ihmSynchronisation", "Liste des smartphones connect\303\251s :", nullptr));
        label_11->setText(QCoreApplication::translate("ihmSynchronisation", "Rechercher un nouveau smartphone connect\303\251 :", nullptr));
        pushButton_Detecter->setText(QCoreApplication::translate("ihmSynchronisation", "D\303\251tecter", nullptr));
        pushButton_EnvoyerOrdinateur->setText(QCoreApplication::translate("ihmSynchronisation", "Envoyer \303\240 la station d'accueil", nullptr));
        pushButton_EnvoyerSmartphone->setText(QCoreApplication::translate("ihmSynchronisation", "Envoyer au smartphone", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ihmSynchronisation: public Ui_ihmSynchronisation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IHMSYNCHRONISATION_H
