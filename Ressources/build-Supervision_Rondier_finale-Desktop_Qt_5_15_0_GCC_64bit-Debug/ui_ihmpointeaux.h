/********************************************************************************
** Form generated from reading UI file 'ihmpointeaux.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IHMPOINTEAUX_H
#define UI_IHMPOINTEAUX_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IhmPointeaux
{
public:
    QTableWidget *tableWidgetPointeaux;
    QPushButton *pushButton_2;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBoxDesignation;
    QPushButton *pushButton;

    void setupUi(QWidget *IhmPointeaux)
    {
        if (IhmPointeaux->objectName().isEmpty())
            IhmPointeaux->setObjectName(QString::fromUtf8("IhmPointeaux"));
        IhmPointeaux->resize(1070, 498);
        tableWidgetPointeaux = new QTableWidget(IhmPointeaux);
        if (tableWidgetPointeaux->columnCount() < 4)
            tableWidgetPointeaux->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetPointeaux->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetPointeaux->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetPointeaux->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetPointeaux->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidgetPointeaux->setObjectName(QString::fromUtf8("tableWidgetPointeaux"));
        tableWidgetPointeaux->setGeometry(QRect(60, 80, 921, 271));
        pushButton_2 = new QPushButton(IhmPointeaux);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(430, 370, 131, 31));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/images/ajouterIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon);
        layoutWidget = new QWidget(IhmPointeaux);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(330, 40, 324, 26));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        comboBoxDesignation = new QComboBox(layoutWidget);
        comboBoxDesignation->setObjectName(QString::fromUtf8("comboBoxDesignation"));

        horizontalLayout->addWidget(comboBoxDesignation);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);


        retranslateUi(IhmPointeaux);

        QMetaObject::connectSlotsByName(IhmPointeaux);
    } // setupUi

    void retranslateUi(QWidget *IhmPointeaux)
    {
        IhmPointeaux->setWindowTitle(QCoreApplication::translate("IhmPointeaux", "Form", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetPointeaux->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("IhmPointeaux", "D\303\251signation", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetPointeaux->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("IhmPointeaux", "Lieu", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetPointeaux->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("IhmPointeaux", "Statut", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetPointeaux->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("IhmPointeaux", "modification", nullptr));
        pushButton_2->setText(QCoreApplication::translate("IhmPointeaux", "Nouveau", nullptr));
        label->setText(QCoreApplication::translate("IhmPointeaux", "D\303\251signation du pointeau :", nullptr));
        pushButton->setText(QCoreApplication::translate("IhmPointeaux", "Appliquer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IhmPointeaux: public Ui_IhmPointeaux {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IHMPOINTEAUX_H
