#ifndef WALLET_HPP
#define WALLET_HPP

#include <string>
#include <vector>
#include <map>
#include <memory>
#include <cstdint>
#include "Crypto.hpp"
#include "RPCClient.hpp"
#include "SecurityMonitor.hpp"

namespace TapNovaPay {

struct WalletConfig {
    std::string network = "testnet";
    std::string data_dir = "./data";
    std::string rpc_host = "127.0.0.1";
    uint16_t rpc_port = 9333;
    std::string rpc_user;
    std::string rpc_password;
};

struct UTXO {
    std::string txid;
    uint32_t vout;
    uint64_t amount;
    std::string address;
    std::string script_pubkey;
    bool is_spent = false;
};

struct Transaction {
    std::string txid;
    int64_t amount;
    int64_t fee;
    uint64_t timestamp;
    std::vector<std::string> addresses;
    int confirmations;
    std::string status;
    std::string hex;
};

struct KeyPair {
    std::string private_key;
    std::string public_key;
    std::string address;
    std::string wif;
};

class Wallet {
public:
    Wallet(const WalletConfig& config);
    ~Wallet();

    bool init();
    bool connectToNode();
    bool isNodeConnected() const { return m_node_connected; }
    bool isLocked() const { return false; }
    bool isPasswordProtected() const { return false; }
    std::string getNetwork() const { return m_config.network; }
    uint64_t getLastBlockHeight();
    
    KeyPair generateKeyPair();
    std::vector<KeyPair> getAllKeys() const { return m_keys; }
    uint64_t getBalance(const std::string& address);
    bool sendToAddress(const std::string& from_addr, const std::string& to_addr, uint64_t amount);
    std::vector<Transaction> getHistory(const std::string& address, uint32_t limit = 20);
    
    // Безпека
    bool isWalletBanned(const std::string& address);
    void reportSecurityIncident(const std::string& address, const std::string& reason, int severity);
    
private:
    bool saveWallet();
    bool loadWallet();
    
    WalletConfig m_config;
    bool m_initialized = false;
    bool m_node_connected = false;
    std::vector<KeyPair> m_keys;
    std::map<std::string, std::string> m_address_to_key;
    std::unique_ptr<RPCClient> m_rpc_client;
    std::unique_ptr<SecurityMonitor> m_security_monitor;
};

} // namespace TapNovaPay

#endif
