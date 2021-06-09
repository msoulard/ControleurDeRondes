/********************************************************************************
** Form generated from reading UI file 'ihmagents.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IHMAGENTS_H
#define UI_IHMAGENTS_H

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

class Ui_IhmAgents
{
public:
    QTableWidget *tableWidgetAgents;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_2;
    QComboBox *comboBoxNom;
    QLabel *label_3;
    QComboBox *comboBoxStatut;
    QLabel *label_4;
    QComboBox *comboBoxBadge;
    QPushButton *pushButtonAppliquer;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButtonActualiser;
    QPushButton *pushButtonNouveau;

    void setupUi(QWidget *IhmAgents)
    {
        if (IhmAgents->objectName().isEmpty())
            IhmAgents->setObjectName(QString::fromUtf8("IhmAgents"));
        IhmAgents->resize(1075, 521);
        tableWidgetAgents = new QTableWidget(IhmAgents);
        if (tableWidgetAgents->columnCount() < 6)
            tableWidgetAgents->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetAgents->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetAgents->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetAgents->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetAgents->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidgetAgents->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidgetAgents->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableWidgetAgents->setObjectName(QString::fromUtf8("tableWidgetAgents"));
        tableWidgetAgents->setGeometry(QRect(100, 90, 891, 301));
        layoutWidget = new QWidget(IhmAgents);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(168, 20, 591, 28));
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

        comboBoxNom = new QComboBox(layoutWidget);
        comboBoxNom->setObjectName(QString::fromUtf8("comboBoxNom"));
        comboBoxNom->setEditable(true);

        horizontalLayout->addWidget(comboBoxNom);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        comboBoxStatut = new QComboBox(layoutWidget);
        comboBoxStatut->setObjectName(QString::fromUtf8("comboBoxStatut"));
        comboBoxStatut->setEditable(true);

        horizontalLayout->addWidget(comboBoxStatut);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        comboBoxBadge = new QComboBox(layoutWidget);
        comboBoxBadge->setObjectName(QString::fromUtf8("comboBoxBadge"));
        comboBoxBadge->setEditable(true);

        horizontalLayout->addWidget(comboBoxBadge);

        pushButtonAppliquer = new QPushButton(layoutWidget);
        pushButtonAppliquer->setObjectName(QString::fromUtf8("pushButtonAppliquer"));

        horizontalLayout->addWidget(pushButtonAppliquer);


        horizontalLayout_2->addLayout(horizontalLayout);

        widget = new QWidget(IhmAgents);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(280, 400, 261, 81));
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


        retranslateUi(IhmAgents);

        QMetaObject::connectSlotsByName(IhmAgents);
    } // setupUi

    void retranslateUi(QWidget *IhmAgents)
    {
        IhmAgents->setWindowTitle(QCoreApplication::translate("IhmAgents", "Form", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetAgents->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("IhmAgents", "Pr\303\251nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetAgents->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("IhmAgents", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetAgents->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("IhmAgents", "N\302\260 de badge", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetAgents->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("IhmAgents", "Statut", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidgetAgents->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("IhmAgents", "Id", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidgetAgents->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("IhmAgents", "Modification", nullptr));
        label->setText(QCoreApplication::translate("IhmAgents", "Filtres : ", nullptr));
        label_2->setText(QCoreApplication::translate("IhmAgents", "nom :", nullptr));
        label_3->setText(QCoreApplication::translate("IhmAgents", "statut :", nullptr));
        label_4->setText(QCoreApplication::translate("IhmAgents", "badge :", nullptr));
        pushButtonAppliquer->setText(QCoreApplication::translate("IhmAgents", "Appliquer", nullptr));
        pushButtonActualiser->setText(QCoreApplication::translate("IhmAgents", "Actualiser", nullptr));
        pushButtonNouveau->setText(QCoreApplication::translate("IhmAgents", "Nouveau", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IhmAgents: public Ui_IhmAgents {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IHMAGENTS_H
