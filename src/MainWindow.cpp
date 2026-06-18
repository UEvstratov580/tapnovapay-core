#include "MainWindow.hpp"
#include "ui_MainWindow.h"
#include <QMessageBox>
#include <QInputDialog>
#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include <QTimer>
#include <QApplication>
#include <QClipboard>
#include <QTableWidgetItem>
#include <QHeaderView>

MainWindow::MainWindow(std::shared_ptr<TapNovaPay::Wallet> wallet, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_wallet(wallet)
{
    ui->setupUi(this);
    
    setWindowTitle("TapNovaPay Core");
    // Просто встановлюємо іконку з файлу
    QIcon icon;
    icon.addFile("TNP-logo.png");
    setWindowIcon(icon);
    
    // Завантажуємо стиль
    QFile styleFile("style.qss");
    if (styleFile.open(QFile::ReadOnly)) {
        QTextStream stream(&styleFile);
        setStyleSheet(stream.readAll());
        styleFile.close();
    }
    
    // Налаштовуємо таблицю історії
    QStringList headers = {"Дата", "Тип", "Сума", "Адреса", "Статус"};
    ui->historyTable->setHorizontalHeaderLabels(headers);
    ui->historyTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->historyTable->setAlternatingRowColors(true);
    ui->historyTable->setShowGrid(false);
    
    // Підключення сигналів
    connect(ui->overviewButton, &QPushButton::clicked, this, &MainWindow::showOverview);
    connect(ui->sendButton, &QPushButton::clicked, this, &MainWindow::showSend);
    connect(ui->receiveButton, &QPushButton::clicked, this, &MainWindow::showReceive);
    connect(ui->historyButton, &QPushButton::clicked, this, &MainWindow::showHistory);
    connect(ui->settingsButton, &QPushButton::clicked, this, &MainWindow::showSettings);
    connect(ui->connectButton, &QPushButton::clicked, this, &MainWindow::onConnectClicked);
    connect(ui->sendConfirmButton, &QPushButton::clicked, this, &MainWindow::onSendConfirmed);
    connect(ui->receiveCopyButton, &QPushButton::clicked, this, &MainWindow::onCopyAddress);
    connect(ui->receiveNewButton, &QPushButton::clicked, this, &MainWindow::onNewAddress);
    connect(ui->langCombo, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::changeLanguage);
    
    // Таймер для оновлення
    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &MainWindow::updateUI);
    m_timer->start(5000);
    
    // Завантажуємо дані
    loadData();
    showOverview();
    
    // Автопідключення
    QTimer::singleShot(1000, this, &MainWindow::autoConnect);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::loadData() {
    auto keys = m_wallet->getAllKeys();
    if (!keys.empty()) {
        ui->addressLabel->setText(QString::fromStdString(keys[0].address));
        ui->receiveAddressEdit->setText(QString::fromStdString(keys[0].address));
    }
    updateBalance();
    updateHistory();
    updateStatus();
}

void MainWindow::updateBalance() {
    auto keys = m_wallet->getAllKeys();
    if (keys.empty()) {
        ui->balanceLabel->setText("0.00000000");
        ui->balanceSatLabel->setText("0 сатоші");
        return;
    }
    
    uint64_t balance = m_wallet->getBalance(keys[0].address);
    double tnp = balance / 100000000.0;
    ui->balanceLabel->setText(QString::number(tnp, 'f', 8));
    ui->balanceSatLabel->setText(QString::number(balance) + " сатоші");
}

void MainWindow::updateHistory() {
    ui->historyTable->setRowCount(0);
    auto keys = m_wallet->getAllKeys();
    if (keys.empty()) return;
    
    // Демо транзакції
    for (int i = 0; i < 5; i++) {
        int row = ui->historyTable->rowCount();
        ui->historyTable->insertRow(row);
        ui->historyTable->setItem(row, 0, new QTableWidgetItem(
            QDateTime::currentDateTime().addSecs(-i * 3600).toString("dd.MM.yyyy HH:mm")));
        ui->historyTable->setItem(row, 1, new QTableWidgetItem(i % 2 == 0 ? "📥 Отримано" : "📤 Відправлено"));
        ui->historyTable->setItem(row, 2, new QTableWidgetItem(QString::number((i + 1) * 0.5, 'f', 8) + " TNP"));
        ui->historyTable->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(keys[0].address)));
        ui->historyTable->setItem(row, 4, new QTableWidgetItem(i < 3 ? "✅ Підтверджено" : "⏳ Очікує"));
    }
}

void MainWindow::updateStatus() {
    if (m_wallet->isNodeConnected()) {
        ui->statusLabel->setText("🟢 Підключено");
        ui->statusLabel->setStyleSheet("color: #2ecc71; font-weight: bold; padding: 5px 15px; background-color: #2a2a2a; border-radius: 4px;");
        ui->connectButton->setText("✅ Підключено");
    } else {
        ui->statusLabel->setText("🔴 Відключено");
        ui->statusLabel->setStyleSheet("color: #e74c3c; font-weight: bold; padding: 5px 15px; background-color: #2a2a2a; border-radius: 4px;");
        ui->connectButton->setText("🌐 Підключити");
    }
    
    uint64_t height = m_wallet->getLastBlockHeight();
    ui->heightLabel->setText("📊 Висота: " + QString::number(height));
}

void MainWindow::updateUI() {
    updateStatus();
    updateBalance();
}

void MainWindow::showOverview() {
    ui->stackedWidget->setCurrentIndex(0);
    ui->overviewButton->setChecked(true);
    ui->sendButton->setChecked(false);
    ui->receiveButton->setChecked(false);
    ui->historyButton->setChecked(false);
    ui->settingsButton->setChecked(false);
}

void MainWindow::showSend() {
    ui->stackedWidget->setCurrentIndex(1);
    ui->sendButton->setChecked(true);
    ui->overviewButton->setChecked(false);
    ui->receiveButton->setChecked(false);
    ui->historyButton->setChecked(false);
    ui->settingsButton->setChecked(false);
}

void MainWindow::showReceive() {
    ui->stackedWidget->setCurrentIndex(2);
    ui->receiveButton->setChecked(true);
    ui->overviewButton->setChecked(false);
    ui->sendButton->setChecked(false);
    ui->historyButton->setChecked(false);
    ui->settingsButton->setChecked(false);
}

void MainWindow::showHistory() {
    ui->stackedWidget->setCurrentIndex(3);
    ui->historyButton->setChecked(true);
    ui->overviewButton->setChecked(false);
    ui->sendButton->setChecked(false);
    ui->receiveButton->setChecked(false);
    ui->settingsButton->setChecked(false);
    updateHistory();
}

void MainWindow::showSettings() {
    ui->stackedWidget->setCurrentIndex(4);
    ui->settingsButton->setChecked(true);
    ui->overviewButton->setChecked(false);
    ui->sendButton->setChecked(false);
    ui->receiveButton->setChecked(false);
    ui->historyButton->setChecked(false);
}

void MainWindow::onConnectClicked() {
    if (m_wallet->isNodeConnected()) {
        QMessageBox::information(this, "Підключення", "Вже підключено до ноди");
        return;
    }
    
    ui->statusLabel->setText("⏳ Підключення...");
    ui->statusLabel->setStyleSheet("color: #f7931a; font-weight: bold; padding: 5px 15px; background-color: #2a2a2a; border-radius: 4px;");
    
    if (m_wallet->connectToNode()) {
        updateStatus();
        updateBalance();
        updateHistory();
        QMessageBox::information(this, "Успішно", "Підключено до ноди!");
    } else {
        updateStatus();
        QMessageBox::warning(this, "Помилка", "Не вдалося підключитися до ноди");
    }
}

void MainWindow::onSendConfirmed() {
    if (!m_wallet->isNodeConnected()) {
        QMessageBox::warning(this, "Помилка", "Немає підключення до ноди");
        return;
    }
    
    QString address = ui->sendAddressEdit->text().trimmed();
    if (address.isEmpty()) {
        QMessageBox::warning(this, "Помилка", "Введіть адресу отримувача");
        return;
    }
    
    double amount = ui->sendAmountSpin->value();
    if (amount <= 0) {
        QMessageBox::warning(this, "Помилка", "Введіть суму");
        return;
    }
    
    auto keys = m_wallet->getAllKeys();
    if (keys.empty()) {
        QMessageBox::warning(this, "Помилка", "Створіть гаманець спочатку");
        return;
    }
    
    uint64_t sat = static_cast<uint64_t>(amount * 100000000.0);
    uint64_t balance = m_wallet->getBalance(keys[0].address);
    
    if (balance < sat) {
        QMessageBox::warning(this, "Помилка", "Недостатньо коштів");
        return;
    }
    
    if (QMessageBox::question(this, "Підтвердження", 
        "Відправити " + QString::number(amount, 'f', 8) + " TNP на адресу:\n" + address + "\n\nПідтвердити?") == QMessageBox::Yes) {
        
        if (m_wallet->sendToAddress(keys[0].address, address.toStdString(), sat)) {
            QMessageBox::information(this, "Успішно", "Транзакцію відправлено!");
            ui->sendAddressEdit->clear();
            ui->sendAmountSpin->setValue(0);
            updateBalance();
            updateHistory();
        } else {
            QMessageBox::warning(this, "Помилка", "Не вдалося відправити транзакцію");
        }
    }
}

void MainWindow::onCopyAddress() {
    QString address = ui->receiveAddressEdit->text();
    if (address.isEmpty()) {
        QMessageBox::warning(this, "Помилка", "Немає адреси для копіювання");
        return;
    }
    
    QClipboard* clipboard = QGuiApplication::clipboard();
    clipboard->setText(address);
    QMessageBox::information(this, "Готово", "Адресу скопійовано!");
}

void MainWindow::onNewAddress() {
    auto keys = m_wallet->generateKeyPair();
    ui->receiveAddressEdit->setText(QString::fromStdString(keys.address));
    ui->addressLabel->setText(QString::fromStdString(keys.address));
    QMessageBox::information(this, "Готово", "Нову адресу згенеровано!\n\n📍 " + QString::fromStdString(keys.address));
}

void MainWindow::changeLanguage(int index) {
    QString lang = index == 0 ? "uk" : "en";
    if (m_currentLang == lang) return;
    
    m_currentLang = lang;
    
    if (m_translator.load("translations/tapnovapay_" + lang + ".qm")) {
        qApp->installTranslator(&m_translator);
        ui->retranslateUi(this);
        retranslateUI();
        
        QString langName = (lang == "uk") ? "Українську" : "English";
        QMessageBox::information(this, "Мова", "Мову змінено на " + langName);
    }
}

void MainWindow::autoConnect() {
    if (!m_wallet->isNodeConnected()) {
        onConnectClicked();
    }
}

void MainWindow::log(const QString& message) {}
void MainWindow::updateAddress() {}
void MainWindow::retranslateUI() {}

void MainWindow::onCreateWallet() {
    auto keys = m_wallet->generateKeyPair();
    QMessageBox::information(this, "Гаманець створено",
        "✅ Гаманець успішно створено!\n\n"
        "📍 Адреса: " + QString::fromStdString(keys.address) + "\n"
        "🔑 Публічний ключ: " + QString::fromStdString(keys.public_key).left(30) + "...\n"
        "🔐 Приватний ключ збережено локально\n\n"
        "⚠️ Збережіть цю інформацію в надійному місці!");
    loadData();
}
