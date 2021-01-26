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
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SupervisionRondier
{
public:
    QAction *actionCheminPhotos;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QMenuBar *menuBar;
    QMenu *menuOptions;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SupervisionRondier)
    {
        if (SupervisionRondier->objectName().isEmpty())
            SupervisionRondier->setObjectName(QString::fromUtf8("SupervisionRondier"));
        SupervisionRondier->resize(1111, 624);
        QFont font;
        font.setPointSize(12);
        SupervisionRondier->setFont(font);
        actionCheminPhotos = new QAction(SupervisionRondier);
        actionCheminPhotos->setObjectName(QString::fromUtf8("actionCheminPhotos"));
        centralWidget = new QWidget(SupervisionRondier);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(-1, -1, -1, 9);
        SupervisionRondier->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SupervisionRondier);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1111, 20));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QString::fromUtf8("menuOptions"));
        menuOptions->setToolTipsVisible(false);
        SupervisionRondier->setMenuBar(menuBar);
        statusBar = new QStatusBar(SupervisionRondier);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        SupervisionRondier->setStatusBar(statusBar);

        menuBar->addAction(menuOptions->menuAction());

        retranslateUi(SupervisionRondier);

        QMetaObject::connectSlotsByName(SupervisionRondier);
    } // setupUi

    void retranslateUi(QMainWindow *SupervisionRondier)
    {
        SupervisionRondier->setWindowTitle(QCoreApplication::translate("SupervisionRondier", "SupervisionRondier", nullptr));
        actionCheminPhotos->setText(QCoreApplication::translate("SupervisionRondier", "Chemin des photos", nullptr));
        menuOptions->setTitle(QCoreApplication::translate("SupervisionRondier", "Options", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SupervisionRondier: public Ui_SupervisionRondier {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPERVISIONRONDIER_H
