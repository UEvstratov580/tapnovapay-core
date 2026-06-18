#include "../include/SecurityMonitor.hpp"
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <chrono>

using json = nlohmann::json;

namespace TapNovaPay {

SecurityMonitor::SecurityMonitor() {
    loadSecurityData();
}

SecurityMonitor::~SecurityMonitor() {
    saveSecurityData();
}

bool SecurityMonitor::checkWalletSecurity(const std::string& address) {
    // Перевіряємо чи гаманець забанений
    if (isWalletBanned(address)) {
        std::cout << "❌ Wallet " << address << " is BANNED!" << std::endl;
        return false;
    }
    
    // Перевіряємо підозрілі дії
    if (checkBehaviorAnomalies(address)) {
        reportSecurityIncident(address, "Suspicious behavior detected", 7);
        return false;
    }
    
    // Перевіряємо валідність підпису
    if (!checkSignatureValidity(address)) {
        reportSecurityIncident(address, "Invalid signature", 9);
        banWallet(address, "Invalid signature detected");
        return false;
    }
    
    return true;
}

bool SecurityMonitor::isWalletBanned(const std::string& address) {
    for (const auto& banned : m_banned_wallets) {
        if (banned == address) {
            return true;
        }
    }
    return false;
}

void SecurityMonitor::banWallet(const std::string& address, const std::string& reason) {
    if (!isWalletBanned(address)) {
        m_banned_wallets.push_back(address);
        reportSecurityIncident(address, "BANNED: " + reason, 10);
        std::cout << "🚫 Wallet " << address << " has been BANNED!" << std::endl;
        std::cout << "   Reason: " << reason << std::endl;
        saveSecurityData();
    }
}

void SecurityMonitor::unbanWallet(const std::string& address) {
    auto it = std::find(m_banned_wallets.begin(), m_banned_wallets.end(), address);
    if (it != m_banned_wallets.end()) {
        m_banned_wallets.erase(it);
        std::cout << "✅ Wallet " << address << " has been UNBANNED" << std::endl;
        saveSecurityData();
    }
}

void SecurityMonitor::reportSecurityIncident(const std::string& address, const std::string& reason, int severity) {
    SecurityAlert alert;
    alert.address = address;
    alert.reason = reason;
    alert.timestamp = std::chrono::duration_cast<std::chrono::seconds>(
        std::chrono::system_clock::now().time_since_epoch()
    ).count();
    alert.severity = severity;
    alert.is_banned = isWalletBanned(address);
    
    m_alerts[address + "_" + std::to_string(alert.timestamp)] = alert;
    saveSecurityData();
}

bool SecurityMonitor::checkBehaviorAnomalies(const std::string& address) {
    auto now = std::chrono::system_clock::now();
    
    // Перевіряємо частоту запитів
    if (m_last_activity.find(address) != m_last_activity.end()) {
        auto diff = std::chrono::duration_cast<std::chrono::seconds>(now - m_last_activity[address]);
        if (diff.count() < 1) { // Більше 1 запиту в секунду
            m_failed_attempts[address]++;
            if (m_failed_attempts[address] > 10) {
                return true; // Підозріла активність
            }
        } else {
            m_failed_attempts[address] = 0;
        }
    }
    
    m_last_activity[address] = now;
    return false;
}

bool SecurityMonitor::checkSignatureValidity(const std::string& address) {
    // Перевірка валідності підпису транзакцій
    // Якщо підпис не валідний - бан
    return true; // Тимчасово повертаємо true
}

bool SecurityMonitor::isSuspiciousActivity(const std::string& address, const std::string& action) {
    // Перевірка підозрілих дій
    if (action == "multiple_failed_transactions") {
        reportSecurityIncident(address, "Multiple failed transactions", 5);
        return true;
    }
    if (action == "unusual_amount") {
        reportSecurityIncident(address, "Unusual transaction amount", 4);
        return true;
    }
    return false;
}

std::vector<SecurityAlert> SecurityMonitor::getAlerts() const {
    std::vector<SecurityAlert> alerts;
    for (const auto& pair : m_alerts) {
        alerts.push_back(pair.second);
    }
    return alerts;
}

std::vector<std::string> SecurityMonitor::getBannedWallets() const {
    return m_banned_wallets;
}

void SecurityMonitor::saveSecurityData() {
    json data;
    data["banned_wallets"] = m_banned_wallets;
    
    json alerts_json;
    for (const auto& pair : m_alerts) {
        json alert_json;
        alert_json["address"] = pair.second.address;
        alert_json["reason"] = pair.second.reason;
        alert_json["timestamp"] = pair.second.timestamp;
        alert_json["severity"] = pair.second.severity;
        alert_json["is_banned"] = pair.second.is_banned;
        alerts_json[pair.first] = alert_json;
    }
    data["alerts"] = alerts_json;
    
    std::ofstream file("security_data.json");
    if (file.is_open()) {
        file << data.dump(4);
        file.close();
    }
}

void SecurityMonitor::loadSecurityData() {
    std::ifstream file("security_data.json");
    if (!file.is_open()) return;
    
    try {
        json data = json::parse(file);
        if (data.contains("banned_wallets")) {
            m_banned_wallets = data["banned_wallets"].get<std::vector<std::string>>();
        }
    } catch (...) {
        // Файл пошкоджений - створюємо новий
    }
}

} // namespace TapNovaPay
