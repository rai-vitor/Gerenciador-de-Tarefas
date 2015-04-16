/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDial>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTableView *tableView;
    QWidget *tab_2;
    QGroupBox *groupBox_5;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QLabel *label_4;
    QLineEdit *lineEdit_2;
    QLabel *label_5;
    QLineEdit *lineEdit_3;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QFormLayout *formLayout_9;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QProgressBar *progressBar_1;
    QGroupBox *groupBox_2;
    QFormLayout *formLayout_2;
    QProgressBar *progressBar_2;
    QFormLayout *formLayout_8;
    QGroupBox *groupBox_6;
    QFormLayout *formLayout_4;
    QProgressBar *progressBar_3;
    QGroupBox *groupBox_7;
    QFormLayout *formLayout_3;
    QProgressBar *progressBar_4;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_3;
    QFormLayout *formLayout_6;
    QProgressBar *progressBar_5;
    QGroupBox *groupBox_4;
    QFormLayout *formLayout_5;
    QProgressBar *progressBar_6;
    QWidget *tab_3;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QPushButton *pushButton;
    QDial *dial;
    QLabel *label_2;
    QWidget *layoutWidget1;
    QFormLayout *formLayout_11;
    QLCDNumber *lcdNumber;
    QLabel *label;
    QWidget *layoutWidget2;
    QFormLayout *formLayout_10;
    QLCDNumber *lcdNumber_2;
    QLabel *label_10;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(848, 504);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(20, 30, 811, 271));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tableView = new QTableView(tab);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(20, 20, 771, 211));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        groupBox_5 = new QGroupBox(tab_2);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(580, 20, 211, 171));
        label_3 = new QLabel(groupBox_5);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 20, 171, 16));
        lineEdit = new QLineEdit(groupBox_5);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 40, 113, 20));
        label_4 = new QLabel(groupBox_5);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 70, 111, 16));
        lineEdit_2 = new QLineEdit(groupBox_5);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(10, 90, 113, 20));
        label_5 = new QLabel(groupBox_5);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 120, 141, 16));
        lineEdit_3 = new QLineEdit(groupBox_5);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(10, 140, 113, 20));
        layoutWidget = new QWidget(tab_2);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 11, 413, 132));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        formLayout_9 = new QFormLayout();
        formLayout_9->setSpacing(6);
        formLayout_9->setObjectName(QStringLiteral("formLayout_9"));
        groupBox = new QGroupBox(layoutWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        formLayout = new QFormLayout(groupBox);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        progressBar_1 = new QProgressBar(groupBox);
        progressBar_1->setObjectName(QStringLiteral("progressBar_1"));
        progressBar_1->setValue(0);

        formLayout->setWidget(0, QFormLayout::LabelRole, progressBar_1);


        formLayout_9->setWidget(0, QFormLayout::LabelRole, groupBox);

        groupBox_2 = new QGroupBox(layoutWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        formLayout_2 = new QFormLayout(groupBox_2);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        progressBar_2 = new QProgressBar(groupBox_2);
        progressBar_2->setObjectName(QStringLiteral("progressBar_2"));
        progressBar_2->setValue(0);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, progressBar_2);


        formLayout_9->setWidget(1, QFormLayout::LabelRole, groupBox_2);


        gridLayout->addLayout(formLayout_9, 0, 0, 1, 1);

        formLayout_8 = new QFormLayout();
        formLayout_8->setSpacing(6);
        formLayout_8->setObjectName(QStringLiteral("formLayout_8"));
        groupBox_6 = new QGroupBox(layoutWidget);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        formLayout_4 = new QFormLayout(groupBox_6);
        formLayout_4->setSpacing(6);
        formLayout_4->setContentsMargins(11, 11, 11, 11);
        formLayout_4->setObjectName(QStringLiteral("formLayout_4"));
        progressBar_3 = new QProgressBar(groupBox_6);
        progressBar_3->setObjectName(QStringLiteral("progressBar_3"));
        progressBar_3->setValue(0);

        formLayout_4->setWidget(0, QFormLayout::LabelRole, progressBar_3);


        formLayout_8->setWidget(0, QFormLayout::LabelRole, groupBox_6);

        groupBox_7 = new QGroupBox(layoutWidget);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        formLayout_3 = new QFormLayout(groupBox_7);
        formLayout_3->setSpacing(6);
        formLayout_3->setContentsMargins(11, 11, 11, 11);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        progressBar_4 = new QProgressBar(groupBox_7);
        progressBar_4->setObjectName(QStringLiteral("progressBar_4"));
        progressBar_4->setValue(0);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, progressBar_4);


        formLayout_8->setWidget(1, QFormLayout::LabelRole, groupBox_7);


        gridLayout->addLayout(formLayout_8, 0, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox_3 = new QGroupBox(layoutWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        formLayout_6 = new QFormLayout(groupBox_3);
        formLayout_6->setSpacing(6);
        formLayout_6->setContentsMargins(11, 11, 11, 11);
        formLayout_6->setObjectName(QStringLiteral("formLayout_6"));
        progressBar_5 = new QProgressBar(groupBox_3);
        progressBar_5->setObjectName(QStringLiteral("progressBar_5"));
        progressBar_5->setValue(0);

        formLayout_6->setWidget(0, QFormLayout::LabelRole, progressBar_5);


        verticalLayout->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(layoutWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        formLayout_5 = new QFormLayout(groupBox_4);
        formLayout_5->setSpacing(6);
        formLayout_5->setContentsMargins(11, 11, 11, 11);
        formLayout_5->setObjectName(QStringLiteral("formLayout_5"));
        progressBar_6 = new QProgressBar(groupBox_4);
        progressBar_6->setObjectName(QStringLiteral("progressBar_6"));
        progressBar_6->setValue(0);

        formLayout_5->setWidget(0, QFormLayout::LabelRole, progressBar_6);


        verticalLayout->addWidget(groupBox_4);


        gridLayout->addLayout(verticalLayout, 0, 2, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        label_6 = new QLabel(tab_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(-2, 60, 131, 51));
        label_6->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(tab_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(140, 30, 341, 16));
        label_8 = new QLabel(tab_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(140, 50, 301, 31));
        label_9 = new QLabel(tab_3);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(140, 110, 631, 16));
        label_11 = new QLabel(tab_3);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(140, 70, 211, 31));
        label_12 = new QLabel(tab_3);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(140, 130, 661, 51));
        label_13 = new QLabel(tab_3);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(140, 190, 651, 16));
        tabWidget->addTab(tab_3, QString());
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(680, 310, 151, 23));
        dial = new QDial(centralWidget);
        dial->setObjectName(QStringLiteral("dial"));
        dial->setGeometry(QRect(780, -10, 50, 64));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(680, 10, 91, 20));
        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 303, 220, 25));
        formLayout_11 = new QFormLayout(layoutWidget1);
        formLayout_11->setSpacing(6);
        formLayout_11->setContentsMargins(11, 11, 11, 11);
        formLayout_11->setObjectName(QStringLiteral("formLayout_11"));
        formLayout_11->setContentsMargins(0, 0, 0, 0);
        lcdNumber = new QLCDNumber(layoutWidget1);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setProperty("intValue", QVariant(2));

        formLayout_11->setWidget(0, QFormLayout::LabelRole, lcdNumber);

        label = new QLabel(layoutWidget1);
        label->setObjectName(QStringLiteral("label"));

        formLayout_11->setWidget(0, QFormLayout::FieldRole, label);

        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(20, 330, 204, 25));
        formLayout_10 = new QFormLayout(layoutWidget2);
        formLayout_10->setSpacing(6);
        formLayout_10->setContentsMargins(11, 11, 11, 11);
        formLayout_10->setObjectName(QStringLiteral("formLayout_10"));
        formLayout_10->setContentsMargins(0, 0, 0, 0);
        lcdNumber_2 = new QLCDNumber(layoutWidget2);
        lcdNumber_2->setObjectName(QStringLiteral("lcdNumber_2"));

        formLayout_10->setWidget(0, QFormLayout::LabelRole, lcdNumber_2);

        label_10 = new QLabel(layoutWidget2);
        label_10->setObjectName(QStringLiteral("label_10"));

        formLayout_10->setWidget(0, QFormLayout::FieldRole, label_10);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 848, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Lista de Processos", 0));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "CPU Info", 0));
        label_3->setText(QApplication::translate("MainWindow", "Tempo de Uso de CPU", 0));
        label_4->setText(QApplication::translate("MainWindow", "Tempo Ocioso", 0));
        label_5->setText(QApplication::translate("MainWindow", "Uptime", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "CPU 1", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "CPU 2", 0));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "CPU 3", 0));
        groupBox_7->setTitle(QApplication::translate("MainWindow", "CPU 4", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Mem\303\263ria", 0));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Swap", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Desempenho", 0));
        label_6->setText(QApplication::translate("MainWindow", "Icone do Sistema", 0));
        label_7->setText(QApplication::translate("MainWindow", "Nome do Computador", 0));
        label_8->setText(QApplication::translate("MainWindow", "Nome do SO", 0));
        label_9->setText(QApplication::translate("MainWindow", "Hardware", 0));
        label_11->setText(QApplication::translate("MainWindow", "Kernel do SO", 0));
        label_12->setText(QApplication::translate("MainWindow", "Informa\303\247\303\265es de Hardware (CPU, mem\303\263ria principal, mem\303\263ria secund\303\241ria dispon\303\255vel)", 0));
        label_13->setText(QApplication::translate("MainWindow", "Informa\303\247\303\265es de Hardware (CPU, mem\303\263ria principal, mem\303\263ria secund\303\241ria dispon\303\255vel)", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Sistema", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Finalizar Processo", 0));
        label_2->setText(QApplication::translate("MainWindow", "Atualiza\303\247\303\243o", 0));
        label->setText(QApplication::translate("MainWindow", "N\303\272mero de processos", 0));
        label_10->setText(QApplication::translate("MainWindow", "N\303\272mero de threads", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
