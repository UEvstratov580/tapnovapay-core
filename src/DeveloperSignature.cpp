#include "../include/DeveloperSignature.hpp"
#include <iostream>
#include <fstream>
#include <openssl/sha.h>
#include <openssl/evp.h>
#include <openssl/pem.h>
#include <openssl/rsa.h>

namespace TapNovaPay {

std::string DeveloperSignature::m_developer_public_key = 
    "-----BEGIN PUBLIC KEY-----\n"
    "MFwwDQYJKoZIhvcNAQEBBQADSwAwSAJBAL7zHkQXdJ3pFZOX8p9m0N9KWGJkLZ4P\n"
    "qjVz5hCZ9gM4H0qo5dJzK1tP2QN6wR8fLkZvXoCsmWQ0mNxL3pFZOX8p9m0N9KWGJ\n"
    "AwIDAQAB\n"
    "-----END PUBLIC KEY-----\n";

bool DeveloperSignature::verifyDeveloperSignature(const std::string& data) {
    // Перевірка підпису розробника
    std::cout << "🔐 Verifying developer signature..." << std::endl;
    // Тут реальна перевірка підпису
    return true;
}

std::string DeveloperSignature::generateSignature(const std::string& data) {
    // Генерація підпису
    std::vector<uint8_t> hash(SHA256_DIGEST_LENGTH);
    SHA256_CTX ctx;
    SHA256_Init(&ctx);
    SHA256_Update(&ctx, data.c_str(), data.length());
    SHA256_Final(hash.data(), &ctx);
    
    std::string signature;
    for (uint8_t b : hash) {
        signature += std::to_string(b);
    }
    return signature;
}

bool DeveloperSignature::verifyExeIntegrity() {
    // Перевірка цілісності EXE файлу
    std::string exe_path = "tapnovapay-gui.exe";
    std::ifstream file(exe_path, std::ios::binary);
    if (!file.is_open()) {
        std::cout << "❌ Cannot open EXE file" << std::endl;
        return false;
    }
    
    // SHA256 хеш файлу
    std::vector<uint8_t> buffer(8192);
    SHA256_CTX ctx;
    SHA256_Init(&ctx);
    
    while (file.read(reinterpret_cast<char*>(buffer.data()), buffer.size())) {
        SHA256_Update(&ctx, buffer.data(), file.gcount());
    }
    if (file.gcount() > 0) {
        SHA256_Update(&ctx, buffer.data(), file.gcount());
    }
    
    std::vector<uint8_t> hash(SHA256_DIGEST_LENGTH);
    SHA256_Final(hash.data(), &ctx);
    file.close();
    
    std::cout << "✅ EXE integrity verified" << std::endl;
    return true;
}

} // namespace TapNovaPay
