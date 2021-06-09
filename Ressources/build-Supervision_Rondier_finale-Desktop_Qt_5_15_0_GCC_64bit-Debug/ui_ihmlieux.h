/********************************************************************************
** Form generated from reading UI file 'ihmlieux.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IHMLIEUX_H
#define UI_IHMLIEUX_H

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

class Ui_IhmLieux
{
public:
    QTableWidget *tableWidgetLieux;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_2;
    QComboBox *comboBoxBatiment;
    QLabel *label_3;
    QComboBox *comboBoxEtage;
    QLabel *label_4;
    QComboBox *comboBoxEmplacement;
    QPushButton *pushButton_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButtonActualiser;
    QPushButton *pushButtonNouveau;

    void setupUi(QWidget *IhmLieux)
    {
        if (IhmLieux->objectName().isEmpty())
            IhmLieux->setObjectName(QString::fromUtf8("IhmLieux"));
        IhmLieux->resize(982, 430);
        tableWidgetLieux = new QTableWidget(IhmLieux);
        if (tableWidgetLieux->columnCount() < 5)
            tableWidgetLieux->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetLieux->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetLieux->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetLieux->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetLieux->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidgetLieux->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidgetLieux->setObjectName(QString::fromUtf8("tableWidgetLieux"));
        tableWidgetLieux->setGeometry(QRect(70, 80, 891, 271));
        layoutWidget = new QWidget(IhmLieux);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(200, 30, 621, 28));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        comboBoxBatiment = new QComboBox(layoutWidget);
        comboBoxBatiment->setObjectName(QString::fromUtf8("comboBoxBatiment"));

        horizontalLayout->addWidget(comboBoxBatiment);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        comboBoxEtage = new QComboBox(layoutWidget);
        comboBoxEtage->setObjectName(QString::fromUtf8("comboBoxEtage"));

        horizontalLayout->addWidget(comboBoxEtage);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        comboBoxEmplacement = new QComboBox(layoutWidget);
        comboBoxEmplacement->setObjectName(QString::fromUtf8("comboBoxEmplacement"));

        horizontalLayout->addWidget(comboBoxEmplacement);


        horizontalLayout_2->addLayout(horizontalLayout);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);

        widget = new QWidget(IhmLieux);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(310, 360, 301, 51));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButtonActualiser = new QPushButton(widget);
        pushButtonActualiser->setObjectName(QString::fromUtf8("pushButtonActualiser"));

        horizontalLayout_3->addWidget(pushButtonActualiser);

        pushButtonNouveau = new QPushButton(widget);
        pushButtonNouveau->setObjectName(QString::fromUtf8("pushButtonNouveau"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/images/ajouterIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonNouveau->setIcon(icon);

        horizontalLayout_3->addWidget(pushButtonNouveau);


        retranslateUi(IhmLieux);

        QMetaObject::connectSlotsByName(IhmLieux);
    } // setupUi

    void retranslateUi(QWidget *IhmLieux)
    {
        IhmLieux->setWindowTitle(QCoreApplication::translate("IhmLieux", "Form", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetLieux->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("IhmLieux", "B\303\242timent", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetLieux->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("IhmLieux", "\303\211tage", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetLieux->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("IhmLieux", "Emplacement", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetLieux->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("IhmLieux", "Id", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidgetLieux->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("IhmLieux", "Modification", nullptr));
        label->setText(QCoreApplication::translate("IhmLieux", "Filtres :", nullptr));
        label_2->setText(QCoreApplication::translate("IhmLieux", "B\303\242timent : :", nullptr));
        label_3->setText(QCoreApplication::translate("IhmLieux", "\303\211tage :", nullptr));
        label_4->setText(QCoreApplication::translate("IhmLieux", "Emplacement :", nullptr));
        pushButton_2->setText(QCoreApplication::translate("IhmLieux", "Appliquer", nullptr));
        pushButtonActualiser->setText(QCoreApplication::translate("IhmLieux", "Actualiser", nullptr));
        pushButtonNouveau->setText(QCoreApplication::translate("IhmLieux", "Nouveau", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IhmLieux: public Ui_IhmLieux {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IHMLIEUX_H
