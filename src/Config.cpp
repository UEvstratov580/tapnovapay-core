#include "../include/Config.hpp"
#include "../include/config.h"
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace TapNovaPay {

Config loadConfig(const std::string& config_file) {
    Config config;
    config.network = BuiltinConfig::NETWORK;
    config.data_dir = BuiltinConfig::DATA_DIR;
    config.rpc_host = BuiltinConfig::RPC_HOST;
    config.rpc_port = BuiltinConfig::RPC_PORT;
    config.rpc_user = BuiltinConfig::RPC_USER;
    config.rpc_password = BuiltinConfig::RPC_PASSWORD;
    
    std::ifstream file(config_file);
    if (file.is_open()) {
        try {
            json data = json::parse(file);
            if (data.contains("network")) config.network = data["network"].get<std::string>();
            if (data.contains("rpc_host")) config.rpc_host = data["rpc_host"].get<std::string>();
            if (data.contains("rpc_port")) config.rpc_port = data["rpc_port"].get<uint16_t>();
            if (data.contains("rpc_user")) config.rpc_user = data["rpc_user"].get<std::string>();
            if (data.contains("rpc_password")) config.rpc_password = data["rpc_password"].get<std::string>();
            std::cout << "✅ Config loaded from file" << std::endl;
        } catch (...) { std::cout << "⚠️ Using built-in config" << std::endl; }
    } else {
        std::cout << "✅ Using built-in config" << std::endl;
    }
    return config;
}

} // namespace TapNovaPay
