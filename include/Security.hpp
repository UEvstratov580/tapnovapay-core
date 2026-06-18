#ifndef SECURITY_HPP
#define SECURITY_HPP

#include <string>
#include <vector>
#include <cstdint>
#include <openssl/evp.h>
#include <openssl/pem.h>

namespace TapNovaPay {

class Security {
public:
    // Перевірка цілісності файлу
    static bool verifyFileIntegrity(const std::string& filepath, const std::string& expected_hash);
    static std::string calculateFileHash(const std::string& filepath);
    static std::string calculateSHA256(const std::vector<uint8_t>& data);
    
    // Цифровий підпис
    static bool verifySignature(const std::string& data, const std::string& signature, const std::string& public_key);
    static std::string signData(const std::string& data, const std::string& private_key);
    
    // Захист процесу
    static bool checkProcessIntegrity();
    static bool checkDebugger();
    static bool checkMemoryTampering();
    
    // Резервне копіювання
    static bool backupWallet(const std::string& wallet_path);
    static bool restoreWallet(const std::string& backup_path);
    
    // Шифрування
    static std::string encryptData(const std::string& data, const std::string& key);
    static std::string decryptData(const std::string& data, const std::string& key);
};

} // namespace TapNovaPay

#endif
