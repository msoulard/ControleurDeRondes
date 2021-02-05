#ifndef UI_IHMLOCALISATION_H
#define UI_IHMLOCALISATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IHMLocalisation
{
public:
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QLabel *labelLocalisation;
    QComboBox *comboBoxLocalisation;
    QPushButton *pushButtonAjouter;
    QSpacerItem *horizontalSpacer_2;
    QFrame *line;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *labelEmplacement;
    QLineEdit *lineEditEmplacement;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelBatiment;
    QComboBox *comboBoxBatiment;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelEtage;
    QComboBox *comboBoxEtage;
    QSpacerItem *horizontalSpacer_4;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButtonEnregistrer;
    QPushButton *pushButtonSupprimer;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_2;


    void setupUi(QWidget *IHMLocalisation)
    {
        if (IHMLocalisation->objectName().isEmpty())
            IHMLocalisation->setObjectName(QStringLiteral("IHMLocalisation"));
        IHMLocalisation->resize(1043, 726);
        QFont font;
        font.setPointSize(12);
        IHMLocalisation->setFont(font);
        verticalLayout_2 = new QVBoxLayout(IHMLocalisation);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, -1, -1, 30);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        labelLocalisation = new QLabel(IHMLocalisation);
        labelLocalisation->setObjectName(QStringLiteral("labelLocalisation"));

        horizontalLayout_5->addWidget(labelLocalisation);

        comboBoxLocalisation = new QComboBox(IHMLocalisation);
        comboBoxLocalisation->setObjectName(QStringLiteral("comboBoxLocalisation"));
        comboBoxLocalisation->setMinimumSize(QSize(200, 0));
        comboBoxLocalisation->setEditable(true);

        horizontalLayout_5->addWidget(comboBoxLocalisation);

        pushButtonAjouter = new QPushButton(IHMLocalisation);
        pushButtonAjouter->setObjectName(QStringLiteral("pushButtonAjouter"));
        pushButtonAjouter->setEnabled(true);
        pushButtonAjouter->setMinimumSize(QSize(100, 27));
        pushButtonAjouter->setMaximumSize(QSize(100, 27));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/ajouterIcon.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButtonAjouter->setIcon(icon);
        pushButtonAjouter->setIconSize(QSize(20, 20));
        pushButtonAjouter->setAutoRepeat(false);

        horizontalLayout_5->addWidget(pushButtonAjouter);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_5);

        line = new QFrame(IHMLocalisation);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(-1, 0, -1, 0);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 70, -1, 70);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelEmplacement = new QLabel(IHMLocalisation);
        labelEmplacement->setObjectName(QStringLiteral("labelEmplacement"));
        labelEmplacement->setMinimumSize(QSize(108, 0));
        labelEmplacement->setMaximumSize(QSize(108, 16777215));

        horizontalLayout->addWidget(labelEmplacement);

        lineEditEmplacement = new QLineEdit(IHMLocalisation);
        lineEditEmplacement->setObjectName(QStringLiteral("lineEditEmplacement"));
        lineEditEmplacement->setMinimumSize(QSize(100, 0));
        lineEditEmplacement->setEnabled(false);

        horizontalLayout->addWidget(lineEditEmplacement);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        labelBatiment = new QLabel(IHMLocalisation);
        labelBatiment->setObjectName(QStringLiteral("labelBatiment"));
        labelBatiment->setMinimumSize(QSize(100, 0));
        labelBatiment->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_2->addWidget(labelBatiment);

        comboBoxBatiment = new QComboBox(IHMLocalisation);
        comboBoxBatiment->setObjectName(QStringLiteral("comboBoxBatiment"));
        comboBoxBatiment->setMinimumSize(QSize(200, 0));
        comboBoxBatiment->setEnabled(false);

        horizontalLayout_2->addWidget(comboBoxBatiment);

        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        labelEtage = new QLabel(IHMLocalisation);
        labelEtage->setObjectName(QStringLiteral("labelEtage"));
        labelEtage->setMinimumSize(QSize(100, 0));
        labelEtage->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_3->addWidget(labelEtage);

        comboBoxEtage = new QComboBox(IHMLocalisation);
        comboBoxEtage->setObjectName(QStringLiteral("comboBoxEtage"));
        comboBoxEtage->setMinimumSize(QSize(200, 0));
        comboBoxEtage->setEnabled(false);

        horizontalLayout_3->addWidget(comboBoxEtage);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout_6->addLayout(verticalLayout);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_6);

        line_2 = new QFrame(IHMLocalisation);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, 30, -1, -1);
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        pushButtonEnregistrer = new QPushButton(IHMLocalisation);
        pushButtonEnregistrer->setObjectName(QStringLiteral("pushButtonEnregistrer"));
        pushButtonEnregistrer->setEnabled(false);
        pushButtonEnregistrer->setMinimumSize(QSize(190, 70));
        pushButtonEnregistrer->setMaximumSize(QSize(16777215, 70));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/saveIcon.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButtonEnregistrer->setIcon(icon1);
        pushButtonEnregistrer->setIconSize(QSize(25, 25));

        horizontalLayout_4->addWidget(pushButtonEnregistrer);

        pushButtonSupprimer = new QPushButton(IHMLocalisation);
        pushButtonSupprimer->setObjectName(QStringLiteral("pushButtonSupprimer"));
        pushButtonSupprimer->setEnabled(false);
        pushButtonSupprimer->setMinimumSize(QSize(190, 70));
        pushButtonSupprimer->setMaximumSize(QSize(16777215, 70));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/supprIcon.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButtonSupprimer->setIcon(icon2);
        pushButtonSupprimer->setIconSize(QSize(25, 25));

        horizontalLayout_4->addWidget(pushButtonSupprimer);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);

        verticalLayout_2->addLayout(horizontalLayout_4);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        retranslateUi(IHMLocalisation);

        QMetaObject::connectSlotsByName(IHMLocalisation);
    } // setupUi

    void retranslateUi(QWidget *IHMLocalisation)
    {
        IHMLocalisation->setWindowTitle(QApplication::translate("IHMLocalisation", "IHMLocalisation", 0));
        pushButtonAjouter->setText(QApplication::translate("IHMLocalisation", " Nouveau", 0));
        labelLocalisation->setText(QApplication::translate("IHMLocalisation", "Localisation :", 0));
        labelEmplacement->setText(QApplication::translate("IHMLocalisation", "Emplacement :", 0));
        labelBatiment->setText(QApplication::translate("IHMLocalisation", "Batiment :", 0));
        labelEtage->setText(QApplication::translate("IHMLocalisation", "Etage :", 0));
        pushButtonEnregistrer->setText(QApplication::translate("IHMLocalisation", "   Enregistrer", 0));
        pushButtonSupprimer->setText(QApplication::translate("IHMLocalisation", "   Supprimer", 0));
    } // retranslateUi

};

namespace Ui {
class IHMLocalisation: public Ui_IHMLocalisation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IHMLOCALISATION_H
