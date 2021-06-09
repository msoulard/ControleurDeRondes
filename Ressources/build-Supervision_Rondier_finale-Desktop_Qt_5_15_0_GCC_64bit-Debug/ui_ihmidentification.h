/********************************************************************************
** Form generated from reading UI file 'ihmidentification.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IHMIDENTIFICATION_H
#define UI_IHMIDENTIFICATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IHMIdentification
{
public:
    QPushButton *pushButtonConnexion;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelIdentifiant;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEditIdentifiant;
    QHBoxLayout *horizontalLayout;
    QLabel *labelMDP;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *lineEditMDP;
    QLabel *labelImageClient;

    void setupUi(QWidget *IHMIdentification)
    {
        if (IHMIdentification->objectName().isEmpty())
            IHMIdentification->setObjectName(QString::fromUtf8("IHMIdentification"));
        IHMIdentification->resize(604, 410);
        pushButtonConnexion = new QPushButton(IHMIdentification);
        pushButtonConnexion->setObjectName(QString::fromUtf8("pushButtonConnexion"));
        pushButtonConnexion->setGeometry(QRect(180, 190, 261, 41));
        layoutWidget = new QWidget(IHMIdentification);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(180, 40, 261, 131));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        labelIdentifiant = new QLabel(layoutWidget);
        labelIdentifiant->setObjectName(QString::fromUtf8("labelIdentifiant"));

        horizontalLayout_2->addWidget(labelIdentifiant);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        lineEditIdentifiant = new QLineEdit(layoutWidget);
        lineEditIdentifiant->setObjectName(QString::fromUtf8("lineEditIdentifiant"));

        horizontalLayout_2->addWidget(lineEditIdentifiant);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelMDP = new QLabel(layoutWidget);
        labelMDP->setObjectName(QString::fromUtf8("labelMDP"));

        horizontalLayout->addWidget(labelMDP);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        lineEditMDP = new QLineEdit(layoutWidget);
        lineEditMDP->setObjectName(QString::fromUtf8("lineEditMDP"));
        lineEditMDP->setEchoMode(QLineEdit::Password);
        lineEditMDP->setClearButtonEnabled(true);

        horizontalLayout->addWidget(lineEditMDP);


        verticalLayout->addLayout(horizontalLayout);

        labelImageClient = new QLabel(IHMIdentification);
        labelImageClient->setObjectName(QString::fromUtf8("labelImageClient"));
        labelImageClient->setGeometry(QRect(190, 250, 281, 91));
        labelImageClient->setTextFormat(Qt::AutoText);
        labelImageClient->setPixmap(QPixmap(QString::fromUtf8(":/img/images/BarbeDevauxLogo.png")));

        retranslateUi(IHMIdentification);

        QMetaObject::connectSlotsByName(IHMIdentification);
    } // setupUi

    void retranslateUi(QWidget *IHMIdentification)
    {
        IHMIdentification->setWindowTitle(QCoreApplication::translate("IHMIdentification", "Form", nullptr));
        pushButtonConnexion->setText(QCoreApplication::translate("IHMIdentification", "Connexion", nullptr));
        labelIdentifiant->setText(QCoreApplication::translate("IHMIdentification", "Identifiant :", nullptr));
        labelMDP->setText(QCoreApplication::translate("IHMIdentification", "Mot de passe :", nullptr));
        lineEditMDP->setText(QString());
        lineEditMDP->setPlaceholderText(QString());
        labelImageClient->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class IHMIdentification: public Ui_IHMIdentification {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IHMIDENTIFICATION_H
