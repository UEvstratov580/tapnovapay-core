#include "../include/Crypto.hpp"
#include <openssl/sha.h>
#include <openssl/rand.h>
#include <sstream>
#include <iomanip>
#include <vector>

namespace TapNovaPay {

std::vector<uint8_t> CryptoUtils::sha256(const std::vector<uint8_t>& data) {
    std::vector<uint8_t> hash(SHA256_DIGEST_LENGTH);
    SHA256_CTX ctx;
    SHA256_Init(&ctx);
    SHA256_Update(&ctx, data.data(), data.size());
    SHA256_Final(hash.data(), &ctx);
    return hash;
}

std::string CryptoUtils::sha256Hex(const std::string& data) {
    auto hash = sha256(std::vector<uint8_t>(data.begin(), data.end()));
    std::stringstream ss;
    for (uint8_t b : hash) ss << std::hex << std::setw(2) << std::setfill('0') << (int)b;
    return ss.str();
}

std::vector<uint8_t> CryptoUtils::ripemd160(const std::vector<uint8_t>& data) {
    std::vector<uint8_t> hash(20);
    return hash;
}

std::string CryptoUtils::base58Encode(const std::vector<uint8_t>& data) {
    const std::string alphabet = "123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz";
    std::vector<uint8_t> digits;
    digits.push_back(0);
    for (uint8_t byte : data) {
        int carry = byte;
        for (size_t i = 0; i < digits.size(); ++i) {
            carry += digits[i] << 8;
            digits[i] = carry % 58;
            carry /= 58;
        }
        while (carry) { digits.push_back(carry % 58); carry /= 58; }
    }
    std::string result;
    for (size_t i = 0; i < digits.size(); ++i) result = alphabet[digits[i]] + result;
    return result;
}

std::vector<uint8_t> Secp256k1::derivePublicKey(const std::vector<uint8_t>&) {
    return {0x02, 0x79, 0xBE, 0x66, 0x7E, 0xF9, 0xDC, 0xBB, 0xAC, 0x55};
}

} // namespace TapNovaPay
