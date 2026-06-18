#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QTimer>
#include <QTranslator>
#include <memory>
#include "../include/Wallet.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(std::shared_ptr<TapNovaPay::Wallet> wallet, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void changeLanguage(int index);
    void autoConnect();
    void onConnectClicked();
    void onSendConfirmed();
    void onCopyAddress();
    void onNewAddress();
    void onCreateWallet();  // Додаємо цей метод
    void updateUI();

    // Навігація
    void showOverview();
    void showSend();
    void showReceive();
    void showHistory();
    void showSettings();

private:
    void log(const QString& message);
    void loadData();
    void updateBalance();
    void updateAddress();
    void updateStatus();
    void updateHistory();
    void retranslateUI();

    Ui::MainWindow *ui;
    std::shared_ptr<TapNovaPay::Wallet> m_wallet;
    QTimer* m_timer;
    QTranslator m_translator;
    QString m_currentLang;
};

#endif
