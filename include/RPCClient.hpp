#ifndef RPC_CLIENT_HPP
#define RPC_CLIENT_HPP

#include <string>
#include <vector>
#include <optional>
#include <nlohmann/json.hpp>
#include <curl/curl.h>

using json = nlohmann::json;

namespace TapNovaPay {

struct BalanceInfo { uint64_t confirmed = 0; uint64_t unconfirmed = 0; uint64_t total = 0; };
struct UTXOInfo { std::string txid; uint32_t vout; uint64_t amount; std::string address; std::string script_pubkey; int confirmations; bool spendable; };

class RPCClient {
public:
    RPCClient(const std::string& host, uint16_t port, const std::string& user, const std::string& password);
    ~RPCClient();
    bool connect();
    bool isConnected() const { return m_connected; }
    void disconnect();
    std::optional<BalanceInfo> getBalance(const std::string& address = "");
    std::vector<UTXOInfo> listUnspent(const std::vector<std::string>& addresses = {});
    std::string sendRawTransaction(const std::string& tx_hex);
    std::optional<json> getBlockchainInfo();
    uint32_t getBlockCount();
private:
    json sendRequest(const std::string& method, const json& params = json::array());
    static size_t writeCallback(void* contents, size_t size, size_t nmemb, std::string* response);
    std::string m_host, m_port_str, m_user, m_password, m_url;
    uint16_t m_port;
    bool m_connected = false;
    CURL* m_curl = nullptr;
    long m_request_id = 0;
};

} // namespace TapNovaPay

#endif
