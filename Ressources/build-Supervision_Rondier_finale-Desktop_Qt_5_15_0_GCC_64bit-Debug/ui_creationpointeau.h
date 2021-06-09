/********************************************************************************
** Form generated from reading UI file 'creationpointeau.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATIONPOINTEAU_H
#define UI_CREATIONPOINTEAU_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreationPointeau
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushButtonEnregistrer;
    QPushButton *pushButtonAnnuler;
    QLabel *label;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *lineEdit_7;
    QTableWidget *tableWidgetLieux;

    void setupUi(QWidget *CreationPointeau)
    {
        if (CreationPointeau->objectName().isEmpty())
            CreationPointeau->setObjectName(QString::fromUtf8("CreationPointeau"));
        CreationPointeau->resize(722, 517);
        layoutWidget = new QWidget(CreationPointeau);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(180, 470, 183, 26));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        pushButtonEnregistrer = new QPushButton(layoutWidget);
        pushButtonEnregistrer->setObjectName(QString::fromUtf8("pushButtonEnregistrer"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/images/saveIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonEnregistrer->setIcon(icon);

        horizontalLayout_7->addWidget(pushButtonEnregistrer);

        pushButtonAnnuler = new QPushButton(layoutWidget);
        pushButtonAnnuler->setObjectName(QString::fromUtf8("pushButtonAnnuler"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/images/supprIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonAnnuler->setIcon(icon1);

        horizontalLayout_7->addWidget(pushButtonAnnuler);

        label = new QLabel(CreationPointeau);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(240, 20, 111, 16));
        layoutWidget_2 = new QWidget(CreationPointeau);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(170, 70, 282, 151));
        verticalLayout_2 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_2 = new QLabel(layoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_6->addWidget(label_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        lineEdit = new QLineEdit(layoutWidget_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_6->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_3 = new QLabel(layoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_5->addWidget(label_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        lineEdit_2 = new QLineEdit(layoutWidget_2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_5->addWidget(lineEdit_2);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(layoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        lineEdit_7 = new QLineEdit(layoutWidget_2);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));

        horizontalLayout_4->addWidget(lineEdit_7);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_2->addLayout(verticalLayout);

        tableWidgetLieux = new QTableWidget(CreationPointeau);
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
        tableWidgetLieux->setGeometry(QRect(80, 240, 471, 221));

        retranslateUi(CreationPointeau);

        QMetaObject::connectSlotsByName(CreationPointeau);
    } // setupUi

    void retranslateUi(QWidget *CreationPointeau)
    {
        CreationPointeau->setWindowTitle(QCoreApplication::translate("CreationPointeau", "Form", nullptr));
        pushButtonEnregistrer->setText(QCoreApplication::translate("CreationPointeau", "Enregistrer", nullptr));
        pushButtonAnnuler->setText(QCoreApplication::translate("CreationPointeau", "Annuler", nullptr));
        label->setText(QCoreApplication::translate("CreationPointeau", "Cr\303\251er un pointeau", nullptr));
        label_2->setText(QCoreApplication::translate("CreationPointeau", "Nom :", nullptr));
        label_3->setText(QCoreApplication::translate("CreationPointeau", "Tag :", nullptr));
        label_4->setText(QCoreApplication::translate("CreationPointeau", "Emplacement :", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetLieux->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("CreationPointeau", "Emplacement", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetLieux->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("CreationPointeau", "B\303\242timent", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetLieux->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("CreationPointeau", "\303\211tage", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetLieux->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("CreationPointeau", "S\303\251lection", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreationPointeau: public Ui_CreationPointeau {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATIONPOINTEAU_H
