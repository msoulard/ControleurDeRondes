/********************************************************************************
** Form generated from reading UI file 'widget_deroulementronde.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_DEROULEMENTRONDE_H
#define UI_WIDGET_DEROULEMENTRONDE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget_DeroulementRonde
{
public:
    QListView *listView_listePointeau;
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QWidget *Widget_DeroulementRonde)
    {
        if (Widget_DeroulementRonde->objectName().isEmpty())
            Widget_DeroulementRonde->setObjectName(QString::fromUtf8("Widget_DeroulementRonde"));
        Widget_DeroulementRonde->resize(800, 600);
        listView_listePointeau = new QListView(Widget_DeroulementRonde);
        listView_listePointeau->setObjectName(QString::fromUtf8("listView_listePointeau"));
        listView_listePointeau->setGeometry(QRect(90, 190, 256, 192));
        pushButton = new QPushButton(Widget_DeroulementRonde);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(350, 480, 80, 24));
        label = new QLabel(Widget_DeroulementRonde);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(260, 30, 58, 16));

        retranslateUi(Widget_DeroulementRonde);

        QMetaObject::connectSlotsByName(Widget_DeroulementRonde);
    } // setupUi

    void retranslateUi(QWidget *Widget_DeroulementRonde)
    {
        Widget_DeroulementRonde->setWindowTitle(QCoreApplication::translate("Widget_DeroulementRonde", "Widget_DeroulementRonde", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget_DeroulementRonde", "PushButton", nullptr));
        label->setText(QCoreApplication::translate("Widget_DeroulementRonde", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget_DeroulementRonde: public Ui_Widget_DeroulementRonde {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_DEROULEMENTRONDE_H
