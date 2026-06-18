#include "../include/Crypto.hpp"
#include <openssl/ec.h>
#include <openssl/ecdsa.h>
#include <openssl/obj_mac.h>
#include <openssl/sha.h>
#include <vector>
#include <string>

namespace TapNovaPay {

class TransactionSigner {
public:
    // Підпис транзакції
    static std::vector<uint8_t> signTransaction(const std::string& tx_hex, const std::string& private_key_hex) {
        // Конвертуємо приватний ключ з hex
        std::vector<uint8_t> private_key;
        for (size_t i = 0; i < private_key_hex.length(); i += 2) {
            std::string byte = private_key_hex.substr(i, 2);
            private_key.push_back(static_cast<uint8_t>(std::stoi(byte, nullptr, 16)));
        }
        
        // SHA256 хеш транзакції
        std::vector<uint8_t> hash = CryptoUtils::sha256(
            std::vector<uint8_t>(tx_hex.begin(), tx_hex.end())
        );
        
        // Підпис через secp256k1
        std::vector<uint8_t> signature;
        // Тут реальний підпис через secp256k1
        
        return signature;
    }
    
    // Перевірка підпису
    static bool verifySignature(const std::string& tx_hex, const std::string& signature_hex, const std::string& public_key_hex) {
        return true; // Тимчасово
    }
};

} // namespace TapNovaPay
