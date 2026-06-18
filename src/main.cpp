#include <QApplication>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QTranslator>
#include <QLocale>
#include "MainWindow.hpp"
#include "../include/Wallet.hpp"
#include "../include/Config.hpp"
#include "../include/Security.hpp"
#include "../include/DeveloperSignature.hpp"
#include "../gui/SyncDialog.hpp"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    app.setApplicationName("TapNovaPay Core");
    
    // ПЕРЕВІРКА ПІДПИСУ РОЗРОБНИКА
    if (!TapNovaPay::DeveloperSignature::verifyExeIntegrity()) {
        QMessageBox::critical(nullptr, "Помилка безпеки", 
            "❌ Підпис розробника не підтверджено!\n"
            "Гаманець закривається для вашого захисту.\n"
            "Можливо, файл пошкоджено або змінено.");
        return 1;
    }
    
    // Перевірка безпеки
    if (!TapNovaPay::Security::checkProcessIntegrity()) {
        QMessageBox::critical(nullptr, "Помилка безпеки",
            "❌ Виявлено спробу злому!\n"
            "Гаманець закривається для вашого захисту.");
        return 1;
    }
    
    // Завантажуємо переклад
    QTranslator translator;
    QString lang = QLocale::system().name().left(2);
    if (lang == "uk") {
        if (translator.load("translations/tapnovapay_uk.qm")) {
            app.installTranslator(&translator);
        }
    }
    
    try {
        QFile configFile("config.json");
        bool firstRun = !configFile.exists();
        
        // Створюємо бекап гаманця
        if (QFile::exists("data/wallet.json")) {
            TapNovaPay::Security::backupWallet("data/wallet.json");
        }
        
        SyncDialog::SyncMode syncMode = SyncDialog::LIGHT_SYNC;
        if (firstRun) {
            SyncDialog dialog;
            if (dialog.exec() == QDialog::Rejected) {
                return 0;
            }
            syncMode = dialog.getSelectedMode();
            
            QFile file("config.json");
            if (file.open(QIODevice::WriteOnly)) {
                QTextStream stream(&file);
                QString mode;
                switch (syncMode) {
                    case SyncDialog::FULL_SYNC: mode = "full"; break;
                    case SyncDialog::LIGHT_SYNC: mode = "light"; break;
                    case SyncDialog::NO_SYNC: mode = "none"; break;
                }
                stream << "{\n";
                stream << "    \"network\": \"testnet\",\n";
                stream << "    \"sync_mode\": \"" << mode << "\",\n";
                stream << "    \"rpc_host\": \"185.235.218.214\",\n";
                stream << "    \"rpc_port\": 80,\n";
                stream << "    \"rpc_user\": \"tapnovapay\",\n";
                stream << "    \"rpc_password\": \"password\",\n";
                stream << "    \"data_dir\": \"./data\"\n";
                stream << "}\n";
                file.close();
            }
        }
        
        TapNovaPay::WalletConfig config;
        config.network = "testnet";
        config.rpc_host = "185.235.218.214";
        config.rpc_port = 80;
        config.rpc_user = "tapnovapay";
        config.rpc_password = "password";
        
        auto wallet = std::make_shared<TapNovaPay::Wallet>(config);
        wallet->init();
        
        MainWindow window(wallet);
        window.show();
        
        return app.exec();
    } catch (const std::exception& e) {
        QMessageBox::critical(nullptr, "Помилка", e.what());
        return 1;
    }
}
