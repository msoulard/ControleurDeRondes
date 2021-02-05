#ifndef UI_IHMSTATISTIQUES_H
#define UI_IHMSTATISTIQUES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_IHMStatistiques
{
public:
    QVBoxLayout *verticalLayout_7;
    QGroupBox *groupBoxFiltre;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QComboBox *comboBoxFiltreNomRonde;
    QVBoxLayout *verticalLayout_2;
    QComboBox *comboBoxFiltreAgent;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton1FiltreDate;
    QRadioButton *radioButton2FiltreDate;
    QRadioButton *radioButton3FiltreDate;
    QRadioButton *radioButton4FiltreDate;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButtonDate1;
    QCalendarWidget *calendarWidgetFiltreDate1;
    QVBoxLayout *verticalLayout_5;
    QPushButton *pushButtonDate2;
    QCalendarWidget *calendarWidgetFiltreDate2;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *verticalSpacer_8;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *pushButtonAppliquerFiltres;
    QSpacerItem *verticalSpacer2;
    QFrame *line;
    QHBoxLayout *horizontalLayout_9;
    QTableWidget *tableWidgetStats;
    QSpacerItem *verticalSpacer;
    QLabel *labelFiltreAgent;
    QLabel *labelFiltreRonde;
    QSpacerItem *verticalSpacer5;
    QSpacerItem *verticalSpacer6;

    void setupUi(QWidget *IHMStatistiques)
    {
        if (IHMStatistiques->objectName().isEmpty())
            IHMStatistiques->setObjectName(QStringLiteral("IHMStatistiques"));
        IHMStatistiques->resize(1234, 951);
        QFont font;
        font.setPointSize(12);
        IHMStatistiques->setFont(font);

        verticalLayout_7 = new QVBoxLayout(IHMStatistiques);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        groupBoxFiltre = new QGroupBox(IHMStatistiques);
        groupBoxFiltre->setObjectName(QStringLiteral("groupBoxFiltre"));
        groupBoxFiltre->setMinimumSize(QSize(0, 0));
        groupBoxFiltre->setMaximumSize(QSize(16777215, 16777215));
        QFont font1;
        font1.setPointSize(9);
        groupBoxFiltre->setFont(font1);
        horizontalLayout_5 = new QHBoxLayout(groupBoxFiltre);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(-1, -1, 35, -1);
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        pushButtonAppliquerFiltres = new QPushButton(groupBoxFiltre);
        pushButtonAppliquerFiltres->setText("Appliquer les filtres");
        pushButtonAppliquerFiltres->setObjectName(QStringLiteral("pushButtonAppliquerFiltre"));
        pushButtonAppliquerFiltres->setMinimumSize(QSize(261, 0));
        pushButtonAppliquerFiltres->setMaximumSize(QSize(261, 16777215));

        horizontalLayout_10->addWidget(pushButtonAppliquerFiltres);

        verticalLayout_8->addLayout(horizontalLayout_10);

        horizontalLayout_5->addLayout(verticalLayout_8);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(-1, -1, 60, -1);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));

        labelFiltreRonde = new QLabel(IHMStatistiques);
        labelFiltreRonde->setObjectName(QStringLiteral("labelFiltreRonde"));

        verticalLayout->addWidget(labelFiltreRonde);

        comboBoxFiltreNomRonde = new QComboBox(groupBoxFiltre);
        comboBoxFiltreNomRonde->setObjectName(QStringLiteral("comboBoxFiltreNomRonde"));
        comboBoxFiltreNomRonde->setEnabled(false);
        comboBoxFiltreNomRonde->setMinimumSize(QSize(250, 0));
        comboBoxFiltreNomRonde->setEditable(true);

        verticalLayout->addWidget(comboBoxFiltreNomRonde);

        horizontalLayout_4->addLayout(verticalLayout);

//        verticalSpacer5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
//        verticalLayout->addItem(verticalSpacer5);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(40, -1, -1, -1);

        labelFiltreAgent = new QLabel(IHMStatistiques);
        labelFiltreAgent->setObjectName(QStringLiteral("labelFiltreAgent"));

        verticalLayout_2->addWidget(labelFiltreAgent);

        comboBoxFiltreAgent = new QComboBox(groupBoxFiltre);
        comboBoxFiltreAgent->setObjectName(QStringLiteral("comboBoxFiltreAgent"));
        comboBoxFiltreAgent->setEnabled(false);
        comboBoxFiltreAgent->setMinimumSize(QSize(250,0));
        comboBoxFiltreAgent->setEditable(true);

        verticalLayout_2->addWidget(comboBoxFiltreAgent);

//        verticalSpacer6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
//        verticalLayout_2->addItem(verticalSpacer6);

        horizontalLayout_4->addLayout(verticalLayout_2);

        verticalLayout_4->addLayout(horizontalLayout_4);

        horizontalLayout_5->addLayout(verticalLayout_4);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        radioButton1FiltreDate = new QRadioButton(groupBoxFiltre);
        radioButton1FiltreDate->setObjectName(QStringLiteral("radioButton1FiltreDate"));
        radioButton1FiltreDate->setEnabled(false);
        radioButton1FiltreDate->setMinimumSize(QSize(45, 0));
        radioButton1FiltreDate->setChecked(true);

        horizontalLayout->addWidget(radioButton1FiltreDate);

        radioButton2FiltreDate = new QRadioButton(groupBoxFiltre);
        radioButton2FiltreDate->setObjectName(QStringLiteral("radioButton2FiltreDate"));
        radioButton2FiltreDate->setEnabled(false);
        radioButton2FiltreDate->setMinimumSize(QSize(45, 0));
        radioButton2FiltreDate->setChecked(false);

        horizontalLayout->addWidget(radioButton2FiltreDate);

        radioButton3FiltreDate = new QRadioButton(groupBoxFiltre);
        radioButton3FiltreDate->setObjectName(QStringLiteral("radioButton3FiltreDate"));
        radioButton3FiltreDate->setEnabled(false);
        radioButton3FiltreDate->setMinimumSize(QSize(45, 0));

        horizontalLayout->addWidget(radioButton3FiltreDate);

        radioButton4FiltreDate = new QRadioButton(groupBoxFiltre);
        radioButton4FiltreDate->setObjectName(QStringLiteral("radioButton4FiltreDate"));
        radioButton4FiltreDate->setEnabled(false);
        radioButton4FiltreDate->setMinimumSize(QSize(45, 0));

        horizontalLayout->addWidget(radioButton4FiltreDate);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        horizontalLayout_2->addLayout(horizontalLayout);

        verticalLayout_6->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        pushButtonDate1 = new QPushButton(groupBoxFiltre);
        pushButtonDate1->setObjectName(QStringLiteral("pushButtonDate1"));
        pushButtonDate1->setEnabled(false);
        pushButtonDate1->setMinimumSize(QSize(261, 0));
        pushButtonDate1->setMaximumSize(QSize(261, 16777215));

        verticalLayout_3->addWidget(pushButtonDate1);

        calendarWidgetFiltreDate1 = new QCalendarWidget(groupBoxFiltre);
        calendarWidgetFiltreDate1->setObjectName(QStringLiteral("calendarWidgetFiltreDate1"));
        calendarWidgetFiltreDate1->setMinimumSize(QSize(261, 191));
        calendarWidgetFiltreDate1->setMaximumSize(QSize(261, 191));
        calendarWidgetFiltreDate1->setGridVisible(true);
        calendarWidgetFiltreDate1->setHorizontalHeaderFormat(QCalendarWidget::ShortDayNames);
        calendarWidgetFiltreDate1->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
        calendarWidgetFiltreDate1->setNavigationBarVisible(true);
        calendarWidgetFiltreDate1->setDateEditEnabled(true);

        verticalLayout_3->addWidget(calendarWidgetFiltreDate1);

        horizontalLayout_3->addLayout(verticalLayout_3);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        pushButtonDate2 = new QPushButton(groupBoxFiltre);
        pushButtonDate2->setObjectName(QStringLiteral("pushButtonDate2"));
        pushButtonDate2->setEnabled(false);
        pushButtonDate2->setMinimumSize(QSize(261, 0));
        pushButtonDate2->setMaximumSize(QSize(261, 16777215));

        verticalLayout_5->addWidget(pushButtonDate2);

        calendarWidgetFiltreDate2 = new QCalendarWidget(groupBoxFiltre);
        calendarWidgetFiltreDate2->setObjectName(QStringLiteral("calendarWidgetFiltreDate2"));
        calendarWidgetFiltreDate2->setMinimumSize(QSize(261, 191));
        calendarWidgetFiltreDate2->setMaximumSize(QSize(261, 191));
        calendarWidgetFiltreDate2->setGridVisible(true);
        calendarWidgetFiltreDate2->setHorizontalHeaderFormat(QCalendarWidget::ShortDayNames);
        calendarWidgetFiltreDate2->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
        calendarWidgetFiltreDate2->setNavigationBarVisible(true);
        calendarWidgetFiltreDate2->setDateEditEnabled(true);

        verticalLayout_5->addWidget(calendarWidgetFiltreDate2);

        horizontalLayout_3->addLayout(verticalLayout_5);

        verticalLayout_6->addLayout(horizontalLayout_3);

        horizontalLayout_5->addLayout(verticalLayout_6);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
        horizontalLayout_5->addItem(horizontalSpacer_3);

        verticalLayout_7->addWidget(groupBoxFiltre);

        verticalSpacer2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
        verticalLayout_7->addItem(verticalSpacer2);

        line = new QFrame(IHMStatistiques);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_7->addWidget(line);

        verticalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
        verticalLayout_7->addItem(verticalSpacer_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(50, 5, 50, 5);
        tableWidgetStats = new QTableWidget(IHMStatistiques);
        if (tableWidgetStats->columnCount() < 6)
            tableWidgetStats->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetStats->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetStats->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetStats->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetStats->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidgetStats->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidgetStats->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableWidgetStats->setObjectName(QStringLiteral("tableWidgetStats"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidgetStats->sizePolicy().hasHeightForWidth());
        tableWidgetStats->setSizePolicy(sizePolicy);
        tableWidgetStats->setMinimumSize(QSize(0, 120));
        tableWidgetStats->setMaximumSize(QSize(16777215, 600));
        tableWidgetStats->resizeColumnsToContents();
        tableWidgetStats->horizontalHeader()->setStretchLastSection(true);
        QFont font2;
        font2.setKerning(true);
        font2.setStyleStrategy(QFont::PreferDefault);
        tableWidgetStats->setFont(font2);
        tableWidgetStats->setMouseTracking(false);
        tableWidgetStats->setFocusPolicy(Qt::StrongFocus);
        tableWidgetStats->setContextMenuPolicy(Qt::DefaultContextMenu);
        tableWidgetStats->setAcceptDrops(false);
        tableWidgetStats->setAutoFillBackground(false);
        tableWidgetStats->setInputMethodHints(Qt::ImhNone);
        tableWidgetStats->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidgetStats->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        tableWidgetStats->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidgetStats->setTabKeyNavigation(true);
        tableWidgetStats->setProperty("showDropIndicator", QVariant(true));
        tableWidgetStats->setDragDropOverwriteMode(false);
        tableWidgetStats->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidgetStats->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidgetStats->setTextElideMode(Qt::ElideMiddle);
        tableWidgetStats->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
        tableWidgetStats->setSortingEnabled(false);
        tableWidgetStats->setWordWrap(false);
        tableWidgetStats->setCornerButtonEnabled(true);
        tableWidgetStats->verticalHeader()->setVisible(false);
        tableWidgetStats->resizeColumnsToContents();

        horizontalLayout_9->addWidget(tableWidgetStats);
        verticalLayout_7->addLayout(horizontalLayout_9);

        verticalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
        verticalLayout_7->addItem(verticalSpacer);

        retranslateUi(IHMStatistiques);

    }

    void retranslateUi(QWidget *IHMStatistiques)
    {
        IHMStatistiques->setWindowTitle(QApplication::translate("IHMStatistiques", "IHMStatistiques", 0));
        groupBoxFiltre->setTitle(QApplication::translate("IHMStatistiques", "Filtres :", 0));
        labelFiltreRonde->setText(QApplication::translate("IHMStatistiques", "Nom de la ronde :", 0));
        labelFiltreAgent->setText(QApplication::translate("IHMStatistiques", "Nom de l'agent :", 0));
        radioButton1FiltreDate->setText(QApplication::translate("IHMStatistiques", "Egale à", 0));
        radioButton2FiltreDate->setText(QApplication::translate("IHMStatistiques", "Après", 0));
        radioButton3FiltreDate->setText(QApplication::translate("IHMStatistiques", "Entre", 0));
        radioButton4FiltreDate->setText(QApplication::translate("IHMStatistiques", "Avant", 0));
        pushButtonDate1->setText(QApplication::translate("IHMStatistiques", "--/--/----", 0));
        pushButtonDate2->setText(QApplication::translate("IHMStatistiques", "--/--/----", 0));
        QTableWidgetItem *__qtablewidgetitem = tableWidgetStats->horizontalHeaderItem(0);
        __qtablewidgetitem->setText(QApplication::translate("IHMStatistiques", "Agent", 0));
        QTableWidgetItem *__qtablewidgetitem1 = tableWidgetStats->horizontalHeaderItem(1);
        __qtablewidgetitem1->setText(QApplication::translate("IHMStatistiques", "Ronde", 0));
        QTableWidgetItem *__qtablewidgetitem2 = tableWidgetStats->horizontalHeaderItem(2);
        __qtablewidgetitem2->setText(QApplication::translate("IHMStatistiques", "Nb pointeaux scann\303\251s", 0));
        QTableWidgetItem *__qtablewidgetitem3 = tableWidgetStats->horizontalHeaderItem(3);
        __qtablewidgetitem3->setText(QApplication::translate("IHMStatistiques", "Défauts de parcours", 0));
        QTableWidgetItem *__qtablewidgetitem4 = tableWidgetStats->horizontalHeaderItem(4);
        __qtablewidgetitem4->setText(QApplication::translate("IHMStatistiques", "Nb anomalies", 0));
        QTableWidgetItem *__qtablewidgetitem5 = tableWidgetStats->horizontalHeaderItem(5);
        __qtablewidgetitem5->setText(QApplication::translate("IHMStatistiques", "Date", 0));
    }

};

namespace Ui {
class IHMStatistiques: public Ui_IHMStatistiques {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IHMSTATISTIQUES_H
