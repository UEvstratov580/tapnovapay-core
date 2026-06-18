#include "../include/RPCClient.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <regex>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace TapNovaPay {

RPCClient::RPCClient(const std::string& host, uint16_t port, 
                     const std::string& user, const std::string& password)
    : m_host(host), m_port(port), m_user(user), m_password(password) {
    m_url = "http://" + m_host + ":" + std::to_string(port);
    m_curl = curl_easy_init();
    if (!m_curl) throw std::runtime_error("Failed to initialize CURL");
}

RPCClient::~RPCClient() {
    if (m_curl) curl_easy_cleanup(m_curl);
}

size_t RPCClient::writeCallback(void* contents, size_t size, size_t nmemb, std::string* response) {
    size_t total_size = size * nmemb;
    response->append(static_cast<char*>(contents), total_size);
    return total_size;
}

bool RPCClient::connect() {
    if (m_connected) return true;
    
    std::cout << "🔍 Connecting to node via Nginx..." << std::endl;
    
    try {
        // Перевіряємо висоту блокчейну
        std::string response;
        curl_easy_reset(m_curl);
        curl_easy_setopt(m_curl, CURLOPT_URL, (m_url + "/wallet-api/height").c_str());
        curl_easy_setopt(m_curl, CURLOPT_WRITEFUNCTION, writeCallback);
        curl_easy_setopt(m_curl, CURLOPT_WRITEDATA, &response);
        curl_easy_setopt(m_curl, CURLOPT_TIMEOUT, 10L);
        curl_easy_setopt(m_curl, CURLOPT_CONNECTTIMEOUT, 5L);
        
        CURLcode res = curl_easy_perform(m_curl);
        if (res == CURLE_OK) {
            auto data = json::parse(response);
            if (data.contains("height")) {
                m_connected = true;
                std::cout << "✅ Connected to node! Height: " << data["height"] << std::endl;
                return true;
            }
        } else {
            std::cout << "❌ CURL error: " << curl_easy_strerror(res) << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "❌ Connection error: " << e.what() << std::endl;
    }
    return false;
}

void RPCClient::disconnect() {
    m_connected = false;
}

std::optional<BalanceInfo> RPCClient::getBalance(const std::string& address) {
    if (!m_connected && !connect()) return std::nullopt;
    
    try {
        std::string response;
        curl_easy_reset(m_curl);
        curl_easy_setopt(m_curl, CURLOPT_URL, (m_url + "/wallet-api/balance").c_str());
        curl_easy_setopt(m_curl, CURLOPT_WRITEFUNCTION, writeCallback);
        curl_easy_setopt(m_curl, CURLOPT_WRITEDATA, &response);
        curl_easy_setopt(m_curl, CURLOPT_TIMEOUT, 10L);
        
        CURLcode res = curl_easy_perform(m_curl);
        if (res == CURLE_OK) {
            auto data = json::parse(response);
            BalanceInfo info;
            if (data.contains("balance")) {
                std::string bal = data["balance"];
                std::regex num_regex(R"(\d+\.?\d*)");
                std::smatch match;
                if (std::regex_search(bal, match, num_regex)) {
                    double amount = std::stod(match.str());
                    info.confirmed = static_cast<uint64_t>(amount * 100000000.0);
                    info.total = info.confirmed;
                }
            }
            return info;
        }
    } catch (...) {}
    return std::nullopt;
}

uint32_t RPCClient::getBlockCount() {
    if (!m_connected && !connect()) return 0;
    
    try {
        std::string response;
        curl_easy_reset(m_curl);
        curl_easy_setopt(m_curl, CURLOPT_URL, (m_url + "/wallet-api/height").c_str());
        curl_easy_setopt(m_curl, CURLOPT_WRITEFUNCTION, writeCallback);
        curl_easy_setopt(m_curl, CURLOPT_WRITEDATA, &response);
        curl_easy_setopt(m_curl, CURLOPT_TIMEOUT, 10L);
        
        CURLcode res = curl_easy_perform(m_curl);
        if (res == CURLE_OK) {
            auto data = json::parse(response);
            if (data.contains("height")) {
                std::string h = data["height"];
                std::regex num_regex(R"(\d+)");
                std::smatch match;
                if (std::regex_search(h, match, num_regex)) {
                    return std::stoi(match.str());
                }
            }
        }
    } catch (...) {}
    return 0;
}

std::vector<UTXOInfo> RPCClient::listUnspent(const std::vector<std::string>& addresses) {
    std::vector<UTXOInfo> utxos;
    if (!m_connected && !connect()) return utxos;
    
    try {
        std::string response;
        curl_easy_reset(m_curl);
        std::string url = m_url + "/wallet-api/utxos";
        curl_easy_setopt(m_curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(m_curl, CURLOPT_WRITEFUNCTION, writeCallback);
        curl_easy_setopt(m_curl, CURLOPT_WRITEDATA, &response);
        
        CURLcode res = curl_easy_perform(m_curl);
        if (res == CURLE_OK && !response.empty()) {
            auto data = json::parse(response);
            if (data.is_array()) {
                for (const auto& item : data) {
                    UTXOInfo utxo;
                    utxo.txid = item.value("txid", "");
                    utxo.vout = item.value("vout", 0);
                    utxo.amount = item.value("amount", 0.0);
                    utxo.address = item.value("address", "");
                    utxo.confirmations = item.value("confirmations", 0);
                    utxos.push_back(utxo);
                }
            }
        }
    } catch (...) {}
    return utxos;
}

std::string RPCClient::sendRawTransaction(const std::string& tx_hex) {
    if (!m_connected && !connect()) return "";
    
    try {
        json params = json::array({tx_hex});
        // Тут буде відправка транзакції
        return "txid_simulated";
    } catch (...) { return ""; }
}

std::optional<json> RPCClient::getBlockchainInfo() {
    if (!m_connected && !connect()) return std::nullopt;
    return json::object();
}

} // namespace TapNovaPay
