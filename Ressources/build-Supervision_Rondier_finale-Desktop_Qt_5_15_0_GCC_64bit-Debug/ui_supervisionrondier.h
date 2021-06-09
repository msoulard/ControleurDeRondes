/********************************************************************************
** Form generated from reading UI file 'supervisionrondier.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPERVISIONRONDIER_H
#define UI_SUPERVISIONRONDIER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SuperVisionRondier
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SuperVisionRondier)
    {
        if (SuperVisionRondier->objectName().isEmpty())
            SuperVisionRondier->setObjectName(QString::fromUtf8("SuperVisionRondier"));
        SuperVisionRondier->resize(1303, 685);
        centralwidget = new QWidget(SuperVisionRondier);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 20, 1291, 621));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        SuperVisionRondier->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SuperVisionRondier);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1303, 21));
        SuperVisionRondier->setMenuBar(menubar);
        statusbar = new QStatusBar(SuperVisionRondier);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SuperVisionRondier->setStatusBar(statusbar);

        retranslateUi(SuperVisionRondier);

        QMetaObject::connectSlotsByName(SuperVisionRondier);
    } // setupUi

    void retranslateUi(QMainWindow *SuperVisionRondier)
    {
        SuperVisionRondier->setWindowTitle(QCoreApplication::translate("SuperVisionRondier", "SuperVisionRondier", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SuperVisionRondier: public Ui_SuperVisionRondier {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPERVISIONRONDIER_H
