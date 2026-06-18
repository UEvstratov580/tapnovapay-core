#include "../include/Security.hpp"
#include "../include/DeveloperSignature.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <openssl/sha.h>

#ifdef _WIN32
#include <windows.h>
#endif

namespace TapNovaPay {

std::string Security::calculateSHA256(const std::vector<uint8_t>& data) {
    std::vector<uint8_t> hash(SHA256_DIGEST_LENGTH);
    SHA256_CTX ctx;
    SHA256_Init(&ctx);
    SHA256_Update(&ctx, data.data(), data.size());
    SHA256_Final(hash.data(), &ctx);
    
    std::stringstream ss;
    for (uint8_t b : hash) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)b;
    }
    return ss.str();
}

std::string Security::calculateFileHash(const std::string& filepath) {
    std::ifstream file(filepath, std::ios::binary);
    if (!file.is_open()) return "";
    
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
    
    std::stringstream ss;
    for (uint8_t b : hash) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)b;
    }
    return ss.str();
}

bool Security::verifyFileIntegrity(const std::string& filepath, const std::string& expected_hash) {
    std::string actual_hash = calculateFileHash(filepath);
    return actual_hash == expected_hash;
}

bool Security::checkDebugger() {
#ifdef _WIN32
    if (IsDebuggerPresent()) {
        return true;
    }
#endif
    return false;
}

bool Security::checkMemoryTampering() {
    return false;
}

bool Security::checkProcessIntegrity() {
    // Перевіряємо підпис розробника
    if (!DeveloperSignature::verifyDeveloperSignature("TapNovaPay Core v1.0")) {
        std::cout << "❌ Developer signature verification failed!" << std::endl;
        return false;
    }
    
    if (checkDebugger()) {
        std::cout << "⚠️ Debugger detected!" << std::endl;
        return false;
    }
    return true;
}

bool Security::backupWallet(const std::string& wallet_path) {
    std::string backup_path = wallet_path + ".backup." + 
        std::to_string(std::time(nullptr));
    
    std::ifstream src(wallet_path, std::ios::binary);
    if (!src.is_open()) return false;
    
    std::ofstream dst(backup_path, std::ios::binary);
    if (!dst.is_open()) return false;
    
    dst << src.rdbuf();
    std::cout << "✅ Wallet backup created: " << backup_path << std::endl;
    return true;
}

bool Security::restoreWallet(const std::string& backup_path) {
    std::string wallet_path = backup_path;
    size_t pos = wallet_path.find(".backup.");
    if (pos != std::string::npos) {
        wallet_path = wallet_path.substr(0, pos);
    }
    
    std::ifstream src(backup_path, std::ios::binary);
    if (!src.is_open()) return false;
    
    std::ofstream dst(wallet_path, std::ios::binary);
    if (!dst.is_open()) return false;
    
    dst << src.rdbuf();
    std::cout << "✅ Wallet restored from: " << backup_path << std::endl;
    return true;
}

std::string Security::encryptData(const std::string& data, const std::string& key) {
    std::string result = data;
    for (size_t i = 0; i < data.size(); ++i) {
        result[i] = data[i] ^ key[i % key.size()];
    }
    return result;
}

std::string Security::decryptData(const std::string& data, const std::string& key) {
    return encryptData(data, key);
}

std::string Security::signData(const std::string& data, const std::string& private_key) {
    return calculateSHA256(std::vector<uint8_t>(data.begin(), data.end()));
}

bool Security::verifySignature(const std::string& data, const std::string& signature, const std::string& public_key) {
    std::string calculated = signData(data, "");
    return calculated == signature;
}

} // namespace TapNovaPay
