/********************************************************************************
** Form generated from reading UI file 'historique.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORIQUE_H
#define UI_HISTORIQUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Historique
{
public:
    QGroupBox *groupBoxFiltre;
    QPushButton *pushButtonAppliquer;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayoutHeureDate;
    QLabel *HeureDate;
    QLabel *labelDe;
    QDateTimeEdit *dateTimeDebut;
    QLabel *labelA;
    QDateTimeEdit *dateTimeFin;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayoutAgents;
    QLabel *Agents;
    QComboBox *comboBoxAgents;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayoutRonde;
    QLabel *Ronde;
    QComboBox *comboBoxRonde;
    QTableWidget *tableWidget;

    void setupUi(QWidget *Historique)
    {
        if (Historique->objectName().isEmpty())
            Historique->setObjectName(QString::fromUtf8("Historique"));
        Historique->resize(1251, 573);
        Historique->setStyleSheet(QString::fromUtf8("background-color: rgb(253, 245, 245);\n"
"color: rgb(0, 0, 0);"));
        groupBoxFiltre = new QGroupBox(Historique);
        groupBoxFiltre->setObjectName(QString::fromUtf8("groupBoxFiltre"));
        groupBoxFiltre->setGeometry(QRect(10, 20, 1221, 81));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush2(QColor(0, 0, 0, 128));
        brush2.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush3(QColor(0, 0, 0, 128));
        brush3.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush4(QColor(0, 0, 0, 128));
        brush4.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        groupBoxFiltre->setPalette(palette);
        groupBoxFiltre->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(255, 255, 255);"));
        pushButtonAppliquer = new QPushButton(groupBoxFiltre);
        pushButtonAppliquer->setObjectName(QString::fromUtf8("pushButtonAppliquer"));
        pushButtonAppliquer->setGeometry(QRect(1060, 30, 131, 24));
        layoutWidget = new QWidget(groupBoxFiltre);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(600, 30, 431, 27));
        horizontalLayoutHeureDate = new QHBoxLayout(layoutWidget);
        horizontalLayoutHeureDate->setObjectName(QString::fromUtf8("horizontalLayoutHeureDate"));
        horizontalLayoutHeureDate->setContentsMargins(0, 0, 0, 0);
        HeureDate = new QLabel(layoutWidget);
        HeureDate->setObjectName(QString::fromUtf8("HeureDate"));

        horizontalLayoutHeureDate->addWidget(HeureDate);

        labelDe = new QLabel(layoutWidget);
        labelDe->setObjectName(QString::fromUtf8("labelDe"));

        horizontalLayoutHeureDate->addWidget(labelDe);

        dateTimeDebut = new QDateTimeEdit(layoutWidget);
        dateTimeDebut->setObjectName(QString::fromUtf8("dateTimeDebut"));
        dateTimeDebut->setStyleSheet(QString::fromUtf8("background-color: rgb(253, 245, 245);\n"
"color: rgb(0, 0, 0);"));
        dateTimeDebut->setCalendarPopup(true);

        horizontalLayoutHeureDate->addWidget(dateTimeDebut);

        labelA = new QLabel(layoutWidget);
        labelA->setObjectName(QString::fromUtf8("labelA"));

        horizontalLayoutHeureDate->addWidget(labelA);

        dateTimeFin = new QDateTimeEdit(layoutWidget);
        dateTimeFin->setObjectName(QString::fromUtf8("dateTimeFin"));
        dateTimeFin->setStyleSheet(QString::fromUtf8("background-color: rgb(253, 245, 245);\n"
"color: rgb(0, 0, 0);"));
        dateTimeFin->setCorrectionMode(QAbstractSpinBox::CorrectToPreviousValue);
        dateTimeFin->setCalendarPopup(true);
        dateTimeFin->setTimeSpec(Qt::LocalTime);

        horizontalLayoutHeureDate->addWidget(dateTimeFin);

        layoutWidget1 = new QWidget(groupBoxFiltre);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 30, 241, 26));
        horizontalLayoutAgents = new QHBoxLayout(layoutWidget1);
        horizontalLayoutAgents->setObjectName(QString::fromUtf8("horizontalLayoutAgents"));
        horizontalLayoutAgents->setContentsMargins(0, 0, 0, 0);
        Agents = new QLabel(layoutWidget1);
        Agents->setObjectName(QString::fromUtf8("Agents"));

        horizontalLayoutAgents->addWidget(Agents);

        comboBoxAgents = new QComboBox(layoutWidget1);
        comboBoxAgents->addItem(QString());
        comboBoxAgents->setObjectName(QString::fromUtf8("comboBoxAgents"));
        comboBoxAgents->setLayoutDirection(Qt::LeftToRight);
        comboBoxAgents->setAutoFillBackground(false);
        comboBoxAgents->setStyleSheet(QString::fromUtf8(""));

        horizontalLayoutAgents->addWidget(comboBoxAgents);

        layoutWidget2 = new QWidget(groupBoxFiltre);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(280, 30, 241, 26));
        horizontalLayoutRonde = new QHBoxLayout(layoutWidget2);
        horizontalLayoutRonde->setObjectName(QString::fromUtf8("horizontalLayoutRonde"));
        horizontalLayoutRonde->setContentsMargins(0, 0, 0, 0);
        Ronde = new QLabel(layoutWidget2);
        Ronde->setObjectName(QString::fromUtf8("Ronde"));

        horizontalLayoutRonde->addWidget(Ronde);

        comboBoxRonde = new QComboBox(layoutWidget2);
        comboBoxRonde->addItem(QString());
        comboBoxRonde->setObjectName(QString::fromUtf8("comboBoxRonde"));
        comboBoxRonde->setStyleSheet(QString::fromUtf8("background-color: rgb(253, 245, 245);\n"
"color: rgb(0, 0, 0);"));

        horizontalLayoutRonde->addWidget(comboBoxRonde);

        tableWidget = new QTableWidget(Historique);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(230, 140, 731, 291));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        tableWidget->setFont(font);
        tableWidget->setTabletTracking(false);
        tableWidget->setStyleSheet(QString::fromUtf8(""));
        tableWidget->setAutoScroll(true);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setGridStyle(Qt::SolidLine);
        tableWidget->setSortingEnabled(false);
        tableWidget->setWordWrap(true);
        tableWidget->setCornerButtonEnabled(true);
        tableWidget->verticalHeader()->setMinimumSectionSize(20);
        tableWidget->verticalHeader()->setProperty("showSortIndicator", QVariant(false));

        retranslateUi(Historique);

        QMetaObject::connectSlotsByName(Historique);
    } // setupUi

    void retranslateUi(QWidget *Historique)
    {
        Historique->setWindowTitle(QCoreApplication::translate("Historique", "Historique", nullptr));
        groupBoxFiltre->setTitle(QCoreApplication::translate("Historique", "Filtres", nullptr));
        pushButtonAppliquer->setText(QCoreApplication::translate("Historique", "Appliquer", nullptr));
        HeureDate->setText(QCoreApplication::translate("Historique", "Heure et date", nullptr));
        labelDe->setText(QCoreApplication::translate("Historique", "De", nullptr));
        dateTimeDebut->setDisplayFormat(QCoreApplication::translate("Historique", "dd-MM-yyyy HH:mm", nullptr));
        labelA->setText(QCoreApplication::translate("Historique", "\303\240", nullptr));
        dateTimeFin->setDisplayFormat(QCoreApplication::translate("Historique", "dd-MM-yyyy HH:mm", nullptr));
        Agents->setText(QCoreApplication::translate("Historique", "Agents", nullptr));
        comboBoxAgents->setItemText(0, QCoreApplication::translate("Historique", "Tous les agents", nullptr));

        comboBoxAgents->setCurrentText(QCoreApplication::translate("Historique", "Tous les agents", nullptr));
        Ronde->setText(QCoreApplication::translate("Historique", "Ronde", nullptr));
        comboBoxRonde->setItemText(0, QCoreApplication::translate("Historique", "Toutes les rondes", nullptr));

    } // retranslateUi

};

namespace Ui {
    class Historique: public Ui_Historique {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORIQUE_H
