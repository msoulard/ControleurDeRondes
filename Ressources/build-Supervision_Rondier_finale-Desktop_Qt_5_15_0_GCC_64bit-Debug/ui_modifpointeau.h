/********************************************************************************
** Form generated from reading UI file 'modifpointeau.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFPOINTEAU_H
#define UI_MODIFPOINTEAU_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModifPointeau
{
public:
    QTableWidget *tableWidgetLieux;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *pushButtonEnregistrer;
    QPushButton *pushButtonAnnuler;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *lineEdit_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *lineEdit_4;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QLineEdit *lineEdit_5;

    void setupUi(QWidget *ModifPointeau)
    {
        if (ModifPointeau->objectName().isEmpty())
            ModifPointeau->setObjectName(QString::fromUtf8("ModifPointeau"));
        ModifPointeau->resize(790, 473);
        tableWidgetLieux = new QTableWidget(ModifPointeau);
        if (tableWidgetLieux->columnCount() < 4)
            tableWidgetLieux->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetLieux->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetLieux->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetLieux->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetLieux->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidgetLieux->setObjectName(QString::fromUtf8("tableWidgetLieux"));
        tableWidgetLieux->setGeometry(QRect(170, 210, 401, 192));
        layoutWidget = new QWidget(ModifPointeau);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(290, 420, 183, 26));
        horizontalLayout_9 = new QHBoxLayout(layoutWidget);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        pushButtonEnregistrer = new QPushButton(layoutWidget);
        pushButtonEnregistrer->setObjectName(QString::fromUtf8("pushButtonEnregistrer"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/images/saveIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonEnregistrer->setIcon(icon);

        horizontalLayout_9->addWidget(pushButtonEnregistrer);

        pushButtonAnnuler = new QPushButton(layoutWidget);
        pushButtonAnnuler->setObjectName(QString::fromUtf8("pushButtonAnnuler"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/images/supprIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonAnnuler->setIcon(icon1);

        horizontalLayout_9->addWidget(pushButtonAnnuler);

        layoutWidget_2 = new QWidget(ModifPointeau);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(270, 70, 193, 60));
        verticalLayout = new QVBoxLayout(layoutWidget_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit = new QLineEdit(layoutWidget_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(layoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        lineEdit_2 = new QLineEdit(layoutWidget_2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout->addWidget(lineEdit_2);


        verticalLayout->addLayout(horizontalLayout);

        label = new QLabel(ModifPointeau);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(290, 20, 131, 16));
        layoutWidget_3 = new QWidget(ModifPointeau);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(50, 160, 651, 32));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        pushButton = new QPushButton(layoutWidget_3);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_4->addWidget(pushButton);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(layoutWidget_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        lineEdit_3 = new QLineEdit(layoutWidget_3);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        horizontalLayout_3->addWidget(lineEdit_3);


        horizontalLayout_4->addLayout(horizontalLayout_3);


        horizontalLayout_6->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(layoutWidget_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_5->addWidget(label_5);

        lineEdit_4 = new QLineEdit(layoutWidget_3);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        horizontalLayout_5->addWidget(lineEdit_4);


        horizontalLayout_6->addLayout(horizontalLayout_5);


        horizontalLayout_8->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_6 = new QLabel(layoutWidget_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_7->addWidget(label_6);

        lineEdit_5 = new QLineEdit(layoutWidget_3);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        horizontalLayout_7->addWidget(lineEdit_5);


        horizontalLayout_8->addLayout(horizontalLayout_7);


        retranslateUi(ModifPointeau);

        QMetaObject::connectSlotsByName(ModifPointeau);
    } // setupUi

    void retranslateUi(QWidget *ModifPointeau)
    {
        ModifPointeau->setWindowTitle(QCoreApplication::translate("ModifPointeau", "Form", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetLieux->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ModifPointeau", "Emplacement", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetLieux->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("ModifPointeau", "B\303\242timent", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetLieux->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("ModifPointeau", "\303\211tage", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetLieux->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("ModifPointeau", "S\303\251lection", nullptr));
        pushButtonEnregistrer->setText(QCoreApplication::translate("ModifPointeau", "Enregistrer", nullptr));
        pushButtonAnnuler->setText(QCoreApplication::translate("ModifPointeau", "Annuler", nullptr));
        label_2->setText(QCoreApplication::translate("ModifPointeau", "Nom :", nullptr));
        label_3->setText(QCoreApplication::translate("ModifPointeau", "Tag :", nullptr));
        label->setText(QCoreApplication::translate("ModifPointeau", "Modifier un pointeau", nullptr));
        pushButton->setText(QCoreApplication::translate("ModifPointeau", "Filtrer lieux :", nullptr));
        label_4->setText(QCoreApplication::translate("ModifPointeau", "B\303\242timent :", nullptr));
        label_5->setText(QCoreApplication::translate("ModifPointeau", "\303\211tage :", nullptr));
        label_6->setText(QCoreApplication::translate("ModifPointeau", "Emplacement :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModifPointeau: public Ui_ModifPointeau {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFPOINTEAU_H
