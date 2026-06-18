#ifndef SECURITY_MONITOR_HPP
#define SECURITY_MONITOR_HPP

#include <string>
#include <vector>
#include <map>
#include <chrono>

namespace TapNovaPay {

struct SecurityAlert {
    std::string address;
    std::string reason;
    uint64_t timestamp;
    int severity; // 1-10
    bool is_banned;
};

class SecurityMonitor {
public:
    SecurityMonitor();
    ~SecurityMonitor();

    // Перевірка безпеки гаманця
    bool checkWalletSecurity(const std::string& address);
    bool isWalletBanned(const std::string& address);
    
    // Додати інцидент безпеки
    void reportSecurityIncident(const std::string& address, const std::string& reason, int severity);
    
    // Бан гаманця
    void banWallet(const std::string& address, const std::string& reason);
    void unbanWallet(const std::string& address);
    
    // Отримання статусу
    std::vector<SecurityAlert> getAlerts() const;
    std::vector<std::string> getBannedWallets() const;
    
    // Перевірка підозрілих дій
    bool isSuspiciousActivity(const std::string& address, const std::string& action);
    
private:
    void saveSecurityData();
    void loadSecurityData();
    bool checkSignatureValidity(const std::string& address);
    bool checkBehaviorAnomalies(const std::string& address);
    
    std::map<std::string, SecurityAlert> m_alerts;
    std::vector<std::string> m_banned_wallets;
    std::map<std::string, int> m_failed_attempts;
    std::map<std::string, std::chrono::system_clock::time_point> m_last_activity;
};

} // namespace TapNovaPay

#endif
