/********************************************************************************
** Form generated from reading UI file 'ihmrapport.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IHMRAPPORT_H
#define UI_IHMRAPPORT_H

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
#include <QGraphicsView>

QT_BEGIN_NAMESPACE

class Ui_IHMRapport
{
public:
    QVBoxLayout *verticalLayout_7;
    //Modifications 2020
    QGroupBox *groupBoxFiltre;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBoxFiltreNomRonde;
    QComboBox *comboBoxFiltreNomRonde;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *checkBox;
    QComboBox *comboBoxFiltreAgent;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkBoxFiltreDate;
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
    QFrame *line;
    QHBoxLayout *horizontalLayout_9;
    QTableWidget *tableWidgetRondes;
    QHBoxLayout *horizontalLayout_8;
    QTableWidget *tableWidget_Pointeaux;
    QHBoxLayout *horizontalLayout_7;
    QTableWidget *tableWidgetPhotos;
    QGraphicsView *graphicViewPhotos;
    QHBoxLayout *horizontalLayout_11;
    QVBoxLayout *verticalLayout_11;
    QLabel *labelCommentaire;
    QTextEdit *textEditCommentaire;
    QSpacerItem *horizontalSpacer_8;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButtonPDF;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer;
    //Fin

    void setupUi(QWidget *IHMRapport)
    {
        if (IHMRapport->objectName().isEmpty())
            IHMRapport->setObjectName(QStringLiteral("IHMRapport"));
        IHMRapport->resize(1234, 951);
        QFont font;
        font.setPointSize(12);
        IHMRapport->setFont(font);
        verticalLayout_7 = new QVBoxLayout(IHMRapport);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        groupBoxFiltre = new QGroupBox(IHMRapport);
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

        //horizontalLayout_5->addItem(horizontalSpacer_6);

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
        checkBoxFiltreNomRonde = new QCheckBox(groupBoxFiltre);
        checkBoxFiltreNomRonde->setObjectName(QStringLiteral("checkBoxFiltreNomRonde"));

        verticalLayout->addWidget(checkBoxFiltreNomRonde);

        comboBoxFiltreNomRonde = new QComboBox(groupBoxFiltre);
        comboBoxFiltreNomRonde->setObjectName(QStringLiteral("comboBoxFiltreNomRonde"));
        comboBoxFiltreNomRonde->setEnabled(false);
        comboBoxFiltreNomRonde->setMinimumSize(QSize(250, 0));
        comboBoxFiltreNomRonde->setEditable(true);

        verticalLayout->addWidget(comboBoxFiltreNomRonde);

        horizontalLayout_4->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(40, -1, -1, -1);
        checkBox = new QCheckBox(groupBoxFiltre);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        verticalLayout_2->addWidget(checkBox);

        comboBoxFiltreAgent = new QComboBox(groupBoxFiltre);
        comboBoxFiltreAgent->setObjectName(QStringLiteral("comboBoxFiltreAgent"));
        comboBoxFiltreAgent->setEnabled(false);
        comboBoxFiltreAgent->setMinimumSize(QSize(250, 0));
        comboBoxFiltreAgent->setEditable(true);

        verticalLayout_2->addWidget(comboBoxFiltreAgent);

        horizontalLayout_4->addLayout(verticalLayout_2);

        verticalLayout_4->addLayout(horizontalLayout_4);

        horizontalLayout_5->addLayout(verticalLayout_4);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        checkBoxFiltreDate = new QCheckBox(groupBoxFiltre);
        checkBoxFiltreDate->setObjectName(QStringLiteral("checkBoxFiltreDate"));

        horizontalLayout_2->addWidget(checkBoxFiltreDate);

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

        line = new QFrame(IHMRapport);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_7->addWidget(line);

        verticalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
        verticalLayout_7->addItem(verticalSpacer_8);

        //Modifications 2020
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(50, 5, 50, 5);
        tableWidgetRondes = new QTableWidget(IHMRapport);
        if (tableWidgetRondes->columnCount() < 4)
            tableWidgetRondes->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetRondes->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetRondes->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetRondes->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetRondes->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidgetRondes->setObjectName(QStringLiteral("tableWidgetRondes"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidgetRondes->sizePolicy().hasHeightForWidth());
        tableWidgetRondes->setSizePolicy(sizePolicy);
        tableWidgetRondes->setMinimumSize(QSize(0, 120));
        tableWidgetRondes->setMaximumSize(QSize(16777215, 600));
        tableWidgetRondes->resizeColumnsToContents();
        tableWidgetRondes->horizontalHeader()->setStretchLastSection(true);
        QFont font2;
        font2.setKerning(true);
        font2.setStyleStrategy(QFont::PreferDefault);
        tableWidgetRondes->setFont(font2);
        tableWidgetRondes->setMouseTracking(false);
        tableWidgetRondes->setFocusPolicy(Qt::StrongFocus);
        tableWidgetRondes->setContextMenuPolicy(Qt::DefaultContextMenu);
        tableWidgetRondes->setAcceptDrops(false);
        tableWidgetRondes->setAutoFillBackground(false);
        tableWidgetRondes->setInputMethodHints(Qt::ImhNone);
        tableWidgetRondes->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidgetRondes->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        tableWidgetRondes->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidgetRondes->setTabKeyNavigation(true);
        tableWidgetRondes->setProperty("showDropIndicator", QVariant(true));
        tableWidgetRondes->setDragDropOverwriteMode(false);
        tableWidgetRondes->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidgetRondes->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidgetRondes->setTextElideMode(Qt::ElideMiddle);
        tableWidgetRondes->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
        tableWidgetRondes->setSortingEnabled(false);
        tableWidgetRondes->setWordWrap(false);
        tableWidgetRondes->setCornerButtonEnabled(true);
        tableWidgetRondes->verticalHeader()->setVisible(false);

        horizontalLayout_9->addWidget(tableWidgetRondes);

        verticalLayout_7->addLayout(horizontalLayout_9);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(50, 5, 50, 5);
        tableWidget_Pointeaux = new QTableWidget(IHMRapport);
        if (tableWidget_Pointeaux->columnCount() < 4)
            tableWidget_Pointeaux->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_Pointeaux->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_Pointeaux->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_Pointeaux->setHorizontalHeaderItem(2, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_Pointeaux->setHorizontalHeaderItem(3, __qtablewidgetitem11);
        tableWidget_Pointeaux->resizeColumnsToContents();
        tableWidget_Pointeaux->horizontalHeader()->setStretchLastSection(true);
        tableWidget_Pointeaux->setSizePolicy(sizePolicy);
        tableWidget_Pointeaux->setMinimumSize(QSize(0, 120));
        tableWidget_Pointeaux->setMaximumSize(QSize(750, 300));
        tableWidget_Pointeaux->setFont(font2);
        tableWidget_Pointeaux->setMouseTracking(false);
        tableWidget_Pointeaux->setFocusPolicy(Qt::StrongFocus);
        tableWidget_Pointeaux->setContextMenuPolicy(Qt::DefaultContextMenu);
        tableWidget_Pointeaux->setAcceptDrops(false);
        tableWidget_Pointeaux->setAutoFillBackground(false);
        tableWidget_Pointeaux->setInputMethodHints(Qt::ImhNone);
        tableWidget_Pointeaux->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidget_Pointeaux->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        tableWidget_Pointeaux->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_Pointeaux->setTabKeyNavigation(true);
        tableWidget_Pointeaux->setProperty("showDropIndicator", QVariant(true));
        tableWidget_Pointeaux->setDragDropOverwriteMode(false);
        tableWidget_Pointeaux->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget_Pointeaux->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget_Pointeaux->setTextElideMode(Qt::ElideMiddle);
        tableWidget_Pointeaux->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
        tableWidget_Pointeaux->setSortingEnabled(false);
        tableWidget_Pointeaux->setWordWrap(false);
        tableWidget_Pointeaux->setCornerButtonEnabled(true);
        tableWidget_Pointeaux->verticalHeader()->setVisible(false);

        horizontalLayout_8->addWidget(tableWidget_Pointeaux);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
        horizontalLayout_8->addItem(horizontalSpacer_7);

        verticalLayout_7->addLayout(horizontalLayout_8);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(50, 5, 50, 5);
        graphicViewPhotos = new QGraphicsView(IHMRapport);
//        if (tableWidgetPhotos->columnCount() < 3)
//            tableWidgetPhotos->setColumnCount(3);
//        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
//        tableWidgetPhotos->setHorizontalHeaderItem(0, __qtablewidgetitem12);
//        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
//        tableWidgetPhotos->setHorizontalHeaderItem(1, __qtablewidgetitem13);
//        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
//        tableWidgetPhotos->setHorizontalHeaderItem(2, __qtablewidgetitem14);
//        tableWidgetPhotos->setObjectName(QStringLiteral("tableWidgetPhotos"));
//        tableWidgetPhotos->setEnabled(true);
        graphicViewPhotos->setMinimumSize(QSize(400, 300));
        graphicViewPhotos->setMaximumSize(QSize(400, 500));
//        tableWidgetPhotos->setFrameShape(QFrame::StyledPanel);
//        tableWidgetPhotos->setFrameShadow(QFrame::Sunken);
//        tableWidgetPhotos->setLineWidth(0);
//        tableWidgetPhotos->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
//        tableWidgetPhotos->setAutoScroll(true);
//        tableWidgetPhotos->setAutoScrollMargin(16);
//        tableWidgetPhotos->setEditTriggers(QAbstractItemView::NoEditTriggers);
//        tableWidgetPhotos->setDragDropMode(QAbstractItemView::NoDragDrop);
//        tableWidgetPhotos->setTextElideMode(Qt::ElideNone);
//        tableWidgetPhotos->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
//        tableWidgetPhotos->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
//        tableWidgetPhotos->setShowGrid(true);
//        tableWidgetPhotos->setGridStyle(Qt::SolidLine);
//        tableWidgetPhotos->setSortingEnabled(false);
//        tableWidgetPhotos->setWordWrap(true);
//        tableWidgetPhotos->horizontalHeader()->setDefaultSectionSize(200);
//        tableWidgetPhotos->verticalHeader()->setVisible(false);

        horizontalLayout_7->addWidget(graphicViewPhotos);

        horizontalLayout_8->addLayout(horizontalLayout_7);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(50, 5, 50, 5);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));

        labelCommentaire = new QLabel(IHMRapport);
        verticalLayout_11->addWidget(labelCommentaire);

        textEditCommentaire = new QTextEdit(IHMRapport);
        textEditCommentaire->setMinimumSize(QSize(1000,0));
        textEditCommentaire->setMaximumSize(QSize(1000, 150));
        verticalLayout_11->addWidget(textEditCommentaire);

        horizontalLayout_11->addLayout(verticalLayout_11);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
        horizontalLayout_11->addSpacerItem(horizontalSpacer_8);

        verticalLayout_7->addLayout(horizontalLayout_11);

        //verticalLayout_7->addLayout(horizontalLayout_7);

        line_2 = new QFrame(IHMRapport);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_7->addWidget(line_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);

        pushButtonPDF = new QPushButton(IHMRapport);
        pushButtonPDF->setObjectName(QStringLiteral("pushButtonPDF"));
        pushButtonPDF->setMinimumSize(QSize(190, 70));
        pushButtonPDF->setMaximumSize(QSize(190, 70));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/pdfIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonPDF->setIcon(icon);
        pushButtonPDF->setIconSize(QSize(25, 25));

        horizontalLayout_6->addWidget(pushButtonPDF);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);

        verticalLayout_7->addLayout(horizontalLayout_6);

        retranslateUi(IHMRapport);

        QMetaObject::connectSlotsByName(IHMRapport);
    } // setupUi

    void retranslateUi(QWidget *IHMRapport)
    {
        IHMRapport->setWindowTitle(QApplication::translate("IHMRapport", "IHMRapport", 0));
        groupBoxFiltre->setTitle(QApplication::translate("IHMRapport", "Filtres :", 0));
        checkBoxFiltreNomRonde->setText(QApplication::translate("IHMRapport", "Nom de la ronde :", 0));
        checkBox->setText(QApplication::translate("IHMRapport", "Nom de l'agent :", 0));
        checkBoxFiltreDate->setText(QApplication::translate("IHMRapport", "Date :", 0));
        radioButton1FiltreDate->setText(QApplication::translate("IHMRapport", "Egale à", 0));
        radioButton2FiltreDate->setText(QApplication::translate("IHMRapport", "Après", 0));
        radioButton3FiltreDate->setText(QApplication::translate("IHMRapport", "Entre", 0));
        radioButton4FiltreDate->setText(QApplication::translate("IHMRapport", "Avant", 0));
        pushButtonDate1->setText(QApplication::translate("IHMRapport", "--/--/----", 0));
        pushButtonDate2->setText(QApplication::translate("IHMRapport", "--/--/----", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetRondes->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("IHMRapport", "Ronde", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetRondes->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("IHMRapport", "Agent", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetRondes->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("IHMRapport", "Date", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetRondes->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("IHMRapport", "Pointeaux tagu\303\251s", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_Pointeaux->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QApplication::translate("IHMRapport", "Ordre", 0));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_Pointeaux->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QApplication::translate("IHMRapport", "Alias", 0));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_Pointeaux->horizontalHeaderItem(2);
        ___qtablewidgetitem10->setText(QApplication::translate("IHMRapport", "Heure de pointage", 0));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_Pointeaux->horizontalHeaderItem(3);
        ___qtablewidgetitem11->setText(QApplication::translate("IHMRapport", "Anomalie(s)", 0));
        labelCommentaire->setText(QApplication::translate("IHMRapport", "Commentaire :", 0));
        pushButtonPDF->setText(QApplication::translate("IHMRapport", "   PDF", 0));
    } // retranslateUi

};

namespace Ui {
    class IHMRapport: public Ui_IHMRapport {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IHMRAPPORT_H
