/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *mainLayout;
    QFrame *headerFrame;
    QHBoxLayout *headerLayout;
    QLabel *logoLabel;
    QSpacerItem *spacerItem;
    QComboBox *langCombo;
    QLabel *statusLabel;
    QFrame *contentFrame;
    QHBoxLayout *contentLayout;
    QFrame *sidebarFrame;
    QVBoxLayout *sidebarLayout;
    QPushButton *overviewButton;
    QPushButton *sendButton;
    QPushButton *receiveButton;
    QPushButton *historyButton;
    QPushButton *settingsButton;
    QSpacerItem *spacerItem1;
    QPushButton *connectButton;
    QStackedWidget *stackedWidget;
    QWidget *overviewPage;
    QVBoxLayout *overviewLayout;
    QFrame *balanceFrame;
    QVBoxLayout *balanceFrameLayout;
    QLabel *balanceTitleLabel;
    QLabel *balanceLabel;
    QLabel *balanceSatLabel;
    QFrame *addressFrame;
    QVBoxLayout *addressFrameLayout;
    QLabel *addressTitleLabel;
    QLabel *addressLabel;
    QFrame *infoFrame;
    QHBoxLayout *infoFrameLayout;
    QLabel *heightLabel;
    QSpacerItem *spacerItem2;
    QLabel *networkLabel;
    QWidget *sendPage;
    QVBoxLayout *sendLayout;
    QLabel *sendTitleLabel;
    QFrame *sendFormFrame;
    QVBoxLayout *sendFormLayout;
    QLabel *sendToLabel;
    QLineEdit *sendAddressEdit;
    QLabel *sendAmountLabel;
    QDoubleSpinBox *sendAmountSpin;
    QHBoxLayout *sendFeeLayout;
    QLabel *sendFeeLabel;
    QLabel *sendFeeValueLabel;
    QSpacerItem *spacerItem3;
    QPushButton *sendConfirmButton;
    QWidget *receivePage;
    QVBoxLayout *receiveLayout;
    QLabel *receiveTitleLabel;
    QFrame *receiveFrame;
    QVBoxLayout *receiveFrameLayout;
    QLabel *receiveAddressLabel;
    QLineEdit *receiveAddressEdit;
    QHBoxLayout *receiveButtonsLayout;
    QPushButton *receiveCopyButton;
    QPushButton *receiveNewButton;
    QWidget *historyPage;
    QVBoxLayout *historyLayout;
    QLabel *historyTitleLabel;
    QTableWidget *historyTable;
    QWidget *settingsPage;
    QVBoxLayout *settingsLayout;
    QLabel *settingsTitleLabel;
    QFrame *settingsFrame;
    QVBoxLayout *settingsFrameLayout;
    QLabel *settingsNodeLabel;
    QLabel *settingsNodeInfoLabel;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(900, 650);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        mainLayout = new QVBoxLayout(centralwidget);
        mainLayout->setSpacing(0);
        mainLayout->setObjectName("mainLayout");
        mainLayout->setContentsMargins(0, 0, 0, 0);
        headerFrame = new QFrame(centralwidget);
        headerFrame->setObjectName("headerFrame");
        headerFrame->setMinimumSize(QSize(0, 60));
        headerLayout = new QHBoxLayout(headerFrame);
        headerLayout->setObjectName("headerLayout");
        headerLayout->setContentsMargins(20, -1, 20, -1);
        logoLabel = new QLabel(headerFrame);
        logoLabel->setObjectName("logoLabel");

        headerLayout->addWidget(logoLabel);

        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        headerLayout->addItem(spacerItem);

        langCombo = new QComboBox(headerFrame);
        langCombo->addItem(QString());
        langCombo->addItem(QString());
        langCombo->setObjectName("langCombo");

        headerLayout->addWidget(langCombo);

        statusLabel = new QLabel(headerFrame);
        statusLabel->setObjectName("statusLabel");

        headerLayout->addWidget(statusLabel);


        mainLayout->addWidget(headerFrame);

        contentFrame = new QFrame(centralwidget);
        contentFrame->setObjectName("contentFrame");
        contentLayout = new QHBoxLayout(contentFrame);
        contentLayout->setObjectName("contentLayout");
        contentLayout->setContentsMargins(0, 0, 0, 0);
        sidebarFrame = new QFrame(contentFrame);
        sidebarFrame->setObjectName("sidebarFrame");
        sidebarFrame->setMaximumSize(QSize(200, 16777215));
        sidebarLayout = new QVBoxLayout(sidebarFrame);
        sidebarLayout->setSpacing(2);
        sidebarLayout->setObjectName("sidebarLayout");
        sidebarLayout->setContentsMargins(0, 10, 0, 10);
        overviewButton = new QPushButton(sidebarFrame);
        overviewButton->setObjectName("overviewButton");
        overviewButton->setCheckable(true);
        overviewButton->setChecked(true);

        sidebarLayout->addWidget(overviewButton);

        sendButton = new QPushButton(sidebarFrame);
        sendButton->setObjectName("sendButton");
        sendButton->setCheckable(true);

        sidebarLayout->addWidget(sendButton);

        receiveButton = new QPushButton(sidebarFrame);
        receiveButton->setObjectName("receiveButton");
        receiveButton->setCheckable(true);

        sidebarLayout->addWidget(receiveButton);

        historyButton = new QPushButton(sidebarFrame);
        historyButton->setObjectName("historyButton");
        historyButton->setCheckable(true);

        sidebarLayout->addWidget(historyButton);

        settingsButton = new QPushButton(sidebarFrame);
        settingsButton->setObjectName("settingsButton");
        settingsButton->setCheckable(true);

        sidebarLayout->addWidget(settingsButton);

        spacerItem1 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        sidebarLayout->addItem(spacerItem1);

        connectButton = new QPushButton(sidebarFrame);
        connectButton->setObjectName("connectButton");

        sidebarLayout->addWidget(connectButton);


        contentLayout->addWidget(sidebarFrame);

        stackedWidget = new QStackedWidget(contentFrame);
        stackedWidget->setObjectName("stackedWidget");
        overviewPage = new QWidget();
        overviewPage->setObjectName("overviewPage");
        overviewLayout = new QVBoxLayout(overviewPage);
        overviewLayout->setSpacing(15);
        overviewLayout->setObjectName("overviewLayout");
        overviewLayout->setContentsMargins(30, 30, 30, 30);
        balanceFrame = new QFrame(overviewPage);
        balanceFrame->setObjectName("balanceFrame");
        balanceFrameLayout = new QVBoxLayout(balanceFrame);
        balanceFrameLayout->setSpacing(5);
        balanceFrameLayout->setObjectName("balanceFrameLayout");
        balanceFrameLayout->setContentsMargins(20, 20, 20, 20);
        balanceTitleLabel = new QLabel(balanceFrame);
        balanceTitleLabel->setObjectName("balanceTitleLabel");

        balanceFrameLayout->addWidget(balanceTitleLabel);

        balanceLabel = new QLabel(balanceFrame);
        balanceLabel->setObjectName("balanceLabel");

        balanceFrameLayout->addWidget(balanceLabel);

        balanceSatLabel = new QLabel(balanceFrame);
        balanceSatLabel->setObjectName("balanceSatLabel");

        balanceFrameLayout->addWidget(balanceSatLabel);


        overviewLayout->addWidget(balanceFrame);

        addressFrame = new QFrame(overviewPage);
        addressFrame->setObjectName("addressFrame");
        addressFrameLayout = new QVBoxLayout(addressFrame);
        addressFrameLayout->setSpacing(5);
        addressFrameLayout->setObjectName("addressFrameLayout");
        addressFrameLayout->setContentsMargins(20, 15, 20, 15);
        addressTitleLabel = new QLabel(addressFrame);
        addressTitleLabel->setObjectName("addressTitleLabel");

        addressFrameLayout->addWidget(addressTitleLabel);

        addressLabel = new QLabel(addressFrame);
        addressLabel->setObjectName("addressLabel");
        addressLabel->setWordWrap(true);

        addressFrameLayout->addWidget(addressLabel);


        overviewLayout->addWidget(addressFrame);

        infoFrame = new QFrame(overviewPage);
        infoFrame->setObjectName("infoFrame");
        infoFrameLayout = new QHBoxLayout(infoFrame);
        infoFrameLayout->setSpacing(10);
        infoFrameLayout->setObjectName("infoFrameLayout");
        infoFrameLayout->setContentsMargins(20, 10, 20, 10);
        heightLabel = new QLabel(infoFrame);
        heightLabel->setObjectName("heightLabel");

        infoFrameLayout->addWidget(heightLabel);

        spacerItem2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        infoFrameLayout->addItem(spacerItem2);

        networkLabel = new QLabel(infoFrame);
        networkLabel->setObjectName("networkLabel");

        infoFrameLayout->addWidget(networkLabel);


        overviewLayout->addWidget(infoFrame);

        stackedWidget->addWidget(overviewPage);
        sendPage = new QWidget();
        sendPage->setObjectName("sendPage");
        sendLayout = new QVBoxLayout(sendPage);
        sendLayout->setSpacing(15);
        sendLayout->setObjectName("sendLayout");
        sendLayout->setContentsMargins(30, 30, 30, 30);
        sendTitleLabel = new QLabel(sendPage);
        sendTitleLabel->setObjectName("sendTitleLabel");

        sendLayout->addWidget(sendTitleLabel);

        sendFormFrame = new QFrame(sendPage);
        sendFormFrame->setObjectName("sendFormFrame");
        sendFormLayout = new QVBoxLayout(sendFormFrame);
        sendFormLayout->setSpacing(15);
        sendFormLayout->setObjectName("sendFormLayout");
        sendFormLayout->setContentsMargins(20, 20, 20, 20);
        sendToLabel = new QLabel(sendFormFrame);
        sendToLabel->setObjectName("sendToLabel");

        sendFormLayout->addWidget(sendToLabel);

        sendAddressEdit = new QLineEdit(sendFormFrame);
        sendAddressEdit->setObjectName("sendAddressEdit");

        sendFormLayout->addWidget(sendAddressEdit);

        sendAmountLabel = new QLabel(sendFormFrame);
        sendAmountLabel->setObjectName("sendAmountLabel");

        sendFormLayout->addWidget(sendAmountLabel);

        sendAmountSpin = new QDoubleSpinBox(sendFormFrame);
        sendAmountSpin->setObjectName("sendAmountSpin");
        sendAmountSpin->setDecimals(8);
        sendAmountSpin->setMaximum(99999999.000000000000000);
        sendAmountSpin->setSingleStep(0.010000000000000);

        sendFormLayout->addWidget(sendAmountSpin);

        sendFeeLayout = new QHBoxLayout();
        sendFeeLayout->setObjectName("sendFeeLayout");
        sendFeeLabel = new QLabel(sendFormFrame);
        sendFeeLabel->setObjectName("sendFeeLabel");

        sendFeeLayout->addWidget(sendFeeLabel);

        sendFeeValueLabel = new QLabel(sendFormFrame);
        sendFeeValueLabel->setObjectName("sendFeeValueLabel");

        sendFeeLayout->addWidget(sendFeeValueLabel);

        spacerItem3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        sendFeeLayout->addItem(spacerItem3);


        sendFormLayout->addLayout(sendFeeLayout);

        sendConfirmButton = new QPushButton(sendFormFrame);
        sendConfirmButton->setObjectName("sendConfirmButton");

        sendFormLayout->addWidget(sendConfirmButton);


        sendLayout->addWidget(sendFormFrame);

        stackedWidget->addWidget(sendPage);
        receivePage = new QWidget();
        receivePage->setObjectName("receivePage");
        receiveLayout = new QVBoxLayout(receivePage);
        receiveLayout->setSpacing(15);
        receiveLayout->setObjectName("receiveLayout");
        receiveLayout->setContentsMargins(30, 30, 30, 30);
        receiveTitleLabel = new QLabel(receivePage);
        receiveTitleLabel->setObjectName("receiveTitleLabel");

        receiveLayout->addWidget(receiveTitleLabel);

        receiveFrame = new QFrame(receivePage);
        receiveFrame->setObjectName("receiveFrame");
        receiveFrameLayout = new QVBoxLayout(receiveFrame);
        receiveFrameLayout->setSpacing(15);
        receiveFrameLayout->setObjectName("receiveFrameLayout");
        receiveFrameLayout->setContentsMargins(20, 20, 20, 20);
        receiveAddressLabel = new QLabel(receiveFrame);
        receiveAddressLabel->setObjectName("receiveAddressLabel");

        receiveFrameLayout->addWidget(receiveAddressLabel);

        receiveAddressEdit = new QLineEdit(receiveFrame);
        receiveAddressEdit->setObjectName("receiveAddressEdit");
        receiveAddressEdit->setReadOnly(true);

        receiveFrameLayout->addWidget(receiveAddressEdit);

        receiveButtonsLayout = new QHBoxLayout();
        receiveButtonsLayout->setObjectName("receiveButtonsLayout");
        receiveCopyButton = new QPushButton(receiveFrame);
        receiveCopyButton->setObjectName("receiveCopyButton");

        receiveButtonsLayout->addWidget(receiveCopyButton);

        receiveNewButton = new QPushButton(receiveFrame);
        receiveNewButton->setObjectName("receiveNewButton");

        receiveButtonsLayout->addWidget(receiveNewButton);


        receiveFrameLayout->addLayout(receiveButtonsLayout);


        receiveLayout->addWidget(receiveFrame);

        stackedWidget->addWidget(receivePage);
        historyPage = new QWidget();
        historyPage->setObjectName("historyPage");
        historyLayout = new QVBoxLayout(historyPage);
        historyLayout->setSpacing(15);
        historyLayout->setObjectName("historyLayout");
        historyLayout->setContentsMargins(30, 30, 30, 30);
        historyTitleLabel = new QLabel(historyPage);
        historyTitleLabel->setObjectName("historyTitleLabel");

        historyLayout->addWidget(historyTitleLabel);

        historyTable = new QTableWidget(historyPage);
        if (historyTable->columnCount() < 5)
            historyTable->setColumnCount(5);
        historyTable->setObjectName("historyTable");
        historyTable->setColumnCount(5);

        historyLayout->addWidget(historyTable);

        stackedWidget->addWidget(historyPage);
        settingsPage = new QWidget();
        settingsPage->setObjectName("settingsPage");
        settingsLayout = new QVBoxLayout(settingsPage);
        settingsLayout->setSpacing(15);
        settingsLayout->setObjectName("settingsLayout");
        settingsLayout->setContentsMargins(30, 30, 30, 30);
        settingsTitleLabel = new QLabel(settingsPage);
        settingsTitleLabel->setObjectName("settingsTitleLabel");

        settingsLayout->addWidget(settingsTitleLabel);

        settingsFrame = new QFrame(settingsPage);
        settingsFrame->setObjectName("settingsFrame");
        settingsFrameLayout = new QVBoxLayout(settingsFrame);
        settingsFrameLayout->setSpacing(15);
        settingsFrameLayout->setObjectName("settingsFrameLayout");
        settingsFrameLayout->setContentsMargins(20, 20, 20, 20);
        settingsNodeLabel = new QLabel(settingsFrame);
        settingsNodeLabel->setObjectName("settingsNodeLabel");

        settingsFrameLayout->addWidget(settingsNodeLabel);

        settingsNodeInfoLabel = new QLabel(settingsFrame);
        settingsNodeInfoLabel->setObjectName("settingsNodeInfoLabel");

        settingsFrameLayout->addWidget(settingsNodeInfoLabel);


        settingsLayout->addWidget(settingsFrame);

        stackedWidget->addWidget(settingsPage);

        contentLayout->addWidget(stackedWidget);


        mainLayout->addWidget(contentFrame);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "TapNovaPay Core", nullptr));
        headerFrame->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: #1a1a1a; border-bottom: 1px solid #2a2a2a;", nullptr));
        logoLabel->setText(QCoreApplication::translate("MainWindow", "<h2>\360\237\222\260 TapNovaPay Core</h2>", nullptr));
        logoLabel->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #f7931a; font-weight: bold;", nullptr));
        langCombo->setItemText(0, QCoreApplication::translate("MainWindow", "\360\237\214\215 \320\243\320\272\321\200\320\260\321\227\320\275\321\201\321\214\320\272\320\260", nullptr));
        langCombo->setItemText(1, QCoreApplication::translate("MainWindow", "\360\237\214\215 English", nullptr));

        langCombo->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: #2a2a2a; color: #ffffff; border: 1px solid #3a3a3a; border-radius: 4px; padding: 5px;", nullptr));
        statusLabel->setText(QCoreApplication::translate("MainWindow", "\360\237\224\264 \320\222\321\226\320\264\320\272\320\273\321\216\321\207\320\265\320\275\320\276", nullptr));
        statusLabel->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #e74c3c; font-weight: bold; padding: 5px 15px; background-color: #2a2a2a; border-radius: 4px;", nullptr));
        contentFrame->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: #1e1e1e;", nullptr));
        sidebarFrame->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: #151515; border-right: 1px solid #2a2a2a;", nullptr));
        overviewButton->setText(QCoreApplication::translate("MainWindow", "\360\237\223\212 \320\236\320\263\320\273\321\217\320\264", nullptr));
        overviewButton->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color: transparent; color: #8a8a8a; border: none; padding: 12px 20px; text-align: left; font-size: 14px; border-left: 3px solid transparent; }\n"
"QPushButton:hover { background-color: #2a2a2a; color: #ffffff; }\n"
"QPushButton:checked { background-color: #2a2a2a; color: #f7931a; border-left: 3px solid #f7931a; }", nullptr));
        sendButton->setText(QCoreApplication::translate("MainWindow", "\360\237\223\244 \320\222\321\226\320\264\320\277\321\200\320\260\320\262\320\270\321\202\320\270", nullptr));
        sendButton->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color: transparent; color: #8a8a8a; border: none; padding: 12px 20px; text-align: left; font-size: 14px; border-left: 3px solid transparent; }\n"
"QPushButton:hover { background-color: #2a2a2a; color: #ffffff; }\n"
"QPushButton:checked { background-color: #2a2a2a; color: #f7931a; border-left: 3px solid #f7931a; }", nullptr));
        receiveButton->setText(QCoreApplication::translate("MainWindow", "\360\237\223\245 \320\236\321\202\321\200\320\270\320\274\320\260\321\202\320\270", nullptr));
        receiveButton->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color: transparent; color: #8a8a8a; border: none; padding: 12px 20px; text-align: left; font-size: 14px; border-left: 3px solid transparent; }\n"
"QPushButton:hover { background-color: #2a2a2a; color: #ffffff; }\n"
"QPushButton:checked { background-color: #2a2a2a; color: #f7931a; border-left: 3px solid #f7931a; }", nullptr));
        historyButton->setText(QCoreApplication::translate("MainWindow", "\360\237\223\234 \320\206\321\201\321\202\320\276\321\200\321\226\321\217", nullptr));
        historyButton->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color: transparent; color: #8a8a8a; border: none; padding: 12px 20px; text-align: left; font-size: 14px; border-left: 3px solid transparent; }\n"
"QPushButton:hover { background-color: #2a2a2a; color: #ffffff; }\n"
"QPushButton:checked { background-color: #2a2a2a; color: #f7931a; border-left: 3px solid #f7931a; }", nullptr));
        settingsButton->setText(QCoreApplication::translate("MainWindow", "\342\232\231\357\270\217 \320\235\320\260\320\273\320\260\321\210\321\202\321\203\320\262\320\260\320\275\320\275\321\217", nullptr));
        settingsButton->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color: transparent; color: #8a8a8a; border: none; padding: 12px 20px; text-align: left; font-size: 14px; border-left: 3px solid transparent; }\n"
"QPushButton:hover { background-color: #2a2a2a; color: #ffffff; }\n"
"QPushButton:checked { background-color: #2a2a2a; color: #f7931a; border-left: 3px solid #f7931a; }", nullptr));
        connectButton->setText(QCoreApplication::translate("MainWindow", "\360\237\214\220 \320\237\321\226\320\264\320\272\320\273\321\216\321\207\320\270\321\202\320\270", nullptr));
        connectButton->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color: #2a6a5a; color: #ffffff; border: none; border-radius: 4px; padding: 10px; margin: 0 10px; font-weight: bold; }\n"
"QPushButton:hover { background-color: #3a7a6a; }\n"
"QPushButton:pressed { background-color: #1a5a4a; }", nullptr));
        stackedWidget->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: #1e1e1e;", nullptr));
        balanceFrame->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: #2a2a2a; border-radius: 8px; border: 1px solid #3a3a3a;", nullptr));
        balanceTitleLabel->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\320\260\320\273\321\214\320\275\320\270\320\271 \320\261\320\260\320\273\320\260\320\275\321\201", nullptr));
        balanceTitleLabel->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #8a8a8a; font-size: 14px;", nullptr));
        balanceLabel->setText(QCoreApplication::translate("MainWindow", "0.00000000", nullptr));
        balanceLabel->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #f7931a; font-size: 36px; font-weight: bold;", nullptr));
        balanceSatLabel->setText(QCoreApplication::translate("MainWindow", "0 \321\201\320\260\321\202\320\276\321\210\321\226", nullptr));
        balanceSatLabel->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #6a6a6a; font-size: 12px;", nullptr));
        addressFrame->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: #2a2a2a; border-radius: 8px; border: 1px solid #3a3a3a;", nullptr));
        addressTitleLabel->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\321\202\320\276\321\207\320\275\320\260 \320\260\320\264\321\200\320\265\321\201\320\260", nullptr));
        addressTitleLabel->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #8a8a8a; font-size: 12px;", nullptr));
        addressLabel->setText(QCoreApplication::translate("MainWindow", "\320\220\320\264\321\200\320\265\321\201\321\203 \320\275\320\265 \321\201\321\202\320\262\320\276\321\200\320\265\320\275\320\276", nullptr));
        addressLabel->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #6a6a6a; font-family: Consolas; font-size: 12px;", nullptr));
        infoFrame->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: #2a2a2a; border-radius: 8px; border: 1px solid #3a3a3a;", nullptr));
        heightLabel->setText(QCoreApplication::translate("MainWindow", "\360\237\223\212 \320\222\320\270\321\201\320\276\321\202\320\260: 0", nullptr));
        heightLabel->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #8a8a8a; font-size: 12px;", nullptr));
        networkLabel->setText(QCoreApplication::translate("MainWindow", "\360\237\214\220 testnet", nullptr));
        networkLabel->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #8a8a8a; font-size: 12px;", nullptr));
        sendTitleLabel->setText(QCoreApplication::translate("MainWindow", "<h2>\360\237\223\244 \320\222\321\226\320\264\320\277\321\200\320\260\320\262\320\270\321\202\320\270 \320\272\320\276\321\210\321\202\320\270</h2>", nullptr));
        sendTitleLabel->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #f7931a;", nullptr));
        sendFormFrame->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: #2a2a2a; border-radius: 8px; border: 1px solid #3a3a3a;", nullptr));
        sendToLabel->setText(QCoreApplication::translate("MainWindow", "\320\220\320\264\321\200\320\265\321\201\320\260 \320\276\321\202\321\200\320\270\320\274\321\203\320\262\320\260\321\207\320\260", nullptr));
        sendToLabel->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #ffffff; font-weight: bold;", nullptr));
        sendAddressEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\321\226\321\202\321\214 \320\260\320\264\321\200\320\265\321\201\321\203...", nullptr));
        sendAddressEdit->setStyleSheet(QCoreApplication::translate("MainWindow", "QLineEdit { background-color: #1a1a1a; color: #ffffff; border: 1px solid #3a3a3a; border-radius: 4px; padding: 10px; }\n"
"QLineEdit:focus { border-color: #f7931a; }", nullptr));
        sendAmountLabel->setText(QCoreApplication::translate("MainWindow", "\320\241\321\203\320\274\320\260 (TNP)", nullptr));
        sendAmountLabel->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #ffffff; font-weight: bold;", nullptr));
        sendAmountSpin->setStyleSheet(QCoreApplication::translate("MainWindow", "QDoubleSpinBox { background-color: #1a1a1a; color: #ffffff; border: 1px solid #3a3a3a; border-radius: 4px; padding: 10px; }\n"
"QDoubleSpinBox:focus { border-color: #f7931a; }", nullptr));
        sendFeeLabel->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\274\321\226\321\201\321\226\321\217:", nullptr));
        sendFeeLabel->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #8a8a8a;", nullptr));
        sendFeeValueLabel->setText(QCoreApplication::translate("MainWindow", "0.001 TNP", nullptr));
        sendFeeValueLabel->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #8a8a8a;", nullptr));
        sendConfirmButton->setText(QCoreApplication::translate("MainWindow", "\342\234\205 \320\237\321\226\320\264\321\202\320\262\320\265\321\200\320\264\320\270\321\202\320\270 \320\262\321\226\320\264\320\277\321\200\320\260\320\262\320\272\321\203", nullptr));
        sendConfirmButton->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color: #f7931a; color: #1a1a1a; border: none; border-radius: 4px; padding: 12px; font-weight: bold; font-size: 14px; }\n"
"QPushButton:hover { background-color: #f8a43a; }\n"
"QPushButton:pressed { background-color: #e6830a; }", nullptr));
        receiveTitleLabel->setText(QCoreApplication::translate("MainWindow", "<h2>\360\237\223\245 \320\236\321\202\321\200\320\270\320\274\320\260\321\202\320\270 \320\272\320\276\321\210\321\202\320\270</h2>", nullptr));
        receiveTitleLabel->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #f7931a;", nullptr));
        receiveFrame->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: #2a2a2a; border-radius: 8px; border: 1px solid #3a3a3a;", nullptr));
        receiveAddressLabel->setText(QCoreApplication::translate("MainWindow", "\320\222\320\260\321\210\320\260 \320\260\320\264\321\200\320\265\321\201\320\260", nullptr));
        receiveAddressLabel->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #ffffff; font-weight: bold;", nullptr));
        receiveAddressEdit->setStyleSheet(QCoreApplication::translate("MainWindow", "QLineEdit { background-color: #1a1a1a; color: #8a8a8a; border: 1px solid #3a3a3a; border-radius: 4px; padding: 10px; font-family: Consolas; }\n"
"QLineEdit:focus { border-color: #f7931a; }", nullptr));
        receiveCopyButton->setText(QCoreApplication::translate("MainWindow", "\360\237\223\213 \320\232\320\276\320\277\321\226\321\216\320\262\320\260\321\202\320\270", nullptr));
        receiveCopyButton->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color: #3a3a3a; color: #ffffff; border: none; border-radius: 4px; padding: 8px 16px; }\n"
"QPushButton:hover { background-color: #4a4a4a; }", nullptr));
        receiveNewButton->setText(QCoreApplication::translate("MainWindow", "\360\237\224\204 \320\235\320\276\320\262\320\260 \320\260\320\264\321\200\320\265\321\201\320\260", nullptr));
        receiveNewButton->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color: #2a5a8a; color: #ffffff; border: none; border-radius: 4px; padding: 8px 16px; }\n"
"QPushButton:hover { background-color: #3a6a9a; }", nullptr));
        historyTitleLabel->setText(QCoreApplication::translate("MainWindow", "<h2>\360\237\223\234 \320\206\321\201\321\202\320\276\321\200\321\226\321\217 \321\202\321\200\320\260\320\275\320\267\320\260\320\272\321\206\321\226\320\271</h2>", nullptr));
        historyTitleLabel->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #f7931a;", nullptr));
        historyTable->setStyleSheet(QCoreApplication::translate("MainWindow", "QTableWidget { background-color: #2a2a2a; color: #ffffff; border: 1px solid #3a3a3a; border-radius: 8px; gridline-color: #3a3a3a; }\n"
"QTableWidget::item { padding: 8px; }\n"
"QHeaderView::section { background-color: #1a1a1a; color: #8a8a8a; padding: 8px; border: none; }\n"
"QTableWidget::item:selected { background-color: #3a3a3a; }", nullptr));
        settingsTitleLabel->setText(QCoreApplication::translate("MainWindow", "<h2>\342\232\231\357\270\217 \320\235\320\260\320\273\320\260\321\210\321\202\321\203\320\262\320\260\320\275\320\275\321\217</h2>", nullptr));
        settingsTitleLabel->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #f7931a;", nullptr));
        settingsFrame->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: #2a2a2a; border-radius: 8px; border: 1px solid #3a3a3a;", nullptr));
        settingsNodeLabel->setText(QCoreApplication::translate("MainWindow", "\360\237\214\220 \320\237\321\226\320\264\320\272\320\273\321\216\321\207\320\265\320\275\320\275\321\217 \320\264\320\276 \320\275\320\276\320\264\320\270", nullptr));
        settingsNodeLabel->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #ffffff; font-weight: bold;", nullptr));
        settingsNodeInfoLabel->setText(QCoreApplication::translate("MainWindow", "185.235.218.214:80 (\321\207\320\265\321\200\320\265\320\267 Nginx \320\277\321\200\320\276\320\272\321\201\321\226)", nullptr));
        settingsNodeInfoLabel->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #8a8a8a; font-size: 12px;", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
