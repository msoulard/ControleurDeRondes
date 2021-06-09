/********************************************************************************
** Form generated from reading UI file 'ihmrondes.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IHMRONDES_H
#define UI_IHMRONDES_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IhmRondes
{
public:
    QLabel *label_2;
    QTableWidget *tableWidgetPointeaux;
    QTableWidget *tableWidgetRondes;
    QLabel *label_3;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBoxNom;
    QPushButton *pushButton;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QPushButton *pushButton_2;

    void setupUi(QWidget *IhmRondes)
    {
        if (IhmRondes->objectName().isEmpty())
            IhmRondes->setObjectName(QString::fromUtf8("IhmRondes"));
        IhmRondes->resize(1206, 536);
        label_2 = new QLabel(IhmRondes);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(120, 110, 121, 16));
        tableWidgetPointeaux = new QTableWidget(IhmRondes);
        if (tableWidgetPointeaux->columnCount() < 2)
            tableWidgetPointeaux->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetPointeaux->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetPointeaux->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidgetPointeaux->setObjectName(QString::fromUtf8("tableWidgetPointeaux"));
        tableWidgetPointeaux->setGeometry(QRect(10, 160, 256, 192));
        tableWidgetRondes = new QTableWidget(IhmRondes);
        if (tableWidgetRondes->columnCount() < 7)
            tableWidgetRondes->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetRondes->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetRondes->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidgetRondes->setHorizontalHeaderItem(2, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidgetRondes->setHorizontalHeaderItem(3, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidgetRondes->setHorizontalHeaderItem(4, __qtablewidgetitem6);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/images/basIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setIcon(icon);
        tableWidgetRondes->setHorizontalHeaderItem(5, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidgetRondes->setHorizontalHeaderItem(6, __qtablewidgetitem8);
        tableWidgetRondes->setObjectName(QString::fromUtf8("tableWidgetRondes"));
        tableWidgetRondes->setGeometry(QRect(460, 160, 701, 192));
        label_3 = new QLabel(IhmRondes);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(480, 120, 161, 16));
        layoutWidget = new QWidget(IhmRondes);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(320, 30, 261, 26));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        comboBoxNom = new QComboBox(layoutWidget);
        comboBoxNom->setObjectName(QString::fromUtf8("comboBoxNom"));

        horizontalLayout->addWidget(comboBoxNom);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        layoutWidget1 = new QWidget(IhmRondes);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(360, 390, 193, 51));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_3 = new QPushButton(layoutWidget1);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/images/saveIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon1);

        horizontalLayout_2->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(layoutWidget1);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/images/supprIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon2);

        horizontalLayout_2->addWidget(pushButton_4);

        layoutWidget2 = new QWidget(IhmRondes);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(299, 210, 123, 48));
        verticalLayout = new QVBoxLayout(layoutWidget2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        pushButton_2 = new QPushButton(layoutWidget2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/img/images/droiteIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon3);

        verticalLayout->addWidget(pushButton_2);


        retranslateUi(IhmRondes);

        QMetaObject::connectSlotsByName(IhmRondes);
    } // setupUi

    void retranslateUi(QWidget *IhmRondes)
    {
        IhmRondes->setWindowTitle(QCoreApplication::translate("IhmRondes", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("IhmRondes", "Liste des pointeaux :", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetPointeaux->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("IhmRondes", "D\303\251signation", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetPointeaux->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("IhmRondes", "Lieu", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetRondes->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("IhmRondes", "Position", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetRondes->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("IhmRondes", "D\303\251signation", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidgetRondes->horizontalHeaderItem(2);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("IhmRondes", "Lieu", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidgetRondes->horizontalHeaderItem(3);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("IhmRondes", "Temps min", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidgetRondes->horizontalHeaderItem(4);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("IhmRondes", "Temps max", nullptr));
        label_3->setText(QCoreApplication::translate("IhmRondes", "D\303\251roulement de la ronde :", nullptr));
        label->setText(QCoreApplication::translate("IhmRondes", "Ronde :", nullptr));
        pushButton->setText(QCoreApplication::translate("IhmRondes", "Appliquer", nullptr));
        pushButton_3->setText(QCoreApplication::translate("IhmRondes", "Enregistrer", nullptr));
        pushButton_4->setText(QCoreApplication::translate("IhmRondes", "Supprimer", nullptr));
        label_4->setText(QCoreApplication::translate("IhmRondes", "Ajouter le pointeau :", nullptr));
        pushButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class IhmRondes: public Ui_IhmRondes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IHMRONDES_H
