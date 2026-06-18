#ifndef CRYPTO_HPP
#define CRYPTO_HPP

#include <string>
#include <vector>
#include <cstdint>

namespace TapNovaPay {

class CryptoUtils {
public:
    static std::vector<uint8_t> sha256(const std::vector<uint8_t>& data);
    static std::string sha256Hex(const std::string& data);
    static std::vector<uint8_t> ripemd160(const std::vector<uint8_t>& data);
    static std::string base58Encode(const std::vector<uint8_t>& data);
};

class Secp256k1 {
public:
    static std::vector<uint8_t> derivePublicKey(const std::vector<uint8_t>& private_key);
};

} // namespace TapNovaPay

#endif
