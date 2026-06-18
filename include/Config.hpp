#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <string>
#include <cstdint>

namespace TapNovaPay {

struct Config {
    std::string network = "mainnet";
    std::string data_dir = "./data";
    std::string rpc_host = "127.0.0.1";
    uint16_t rpc_port = 9333;
    std::string rpc_user;
    std::string rpc_password;
    std::string sync_mode = "light";
    bool use_password = false;
};

Config loadConfig(const std::string& config_file = "config.json");

} // namespace TapNovaPay

#endif
