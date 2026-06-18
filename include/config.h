#ifndef CONFIG_H
#define CONFIG_H

namespace TapNovaPay {
    struct BuiltinConfig {
        static constexpr const char* NETWORK = "testnet";
        static constexpr const char* RPC_HOST = "185.235.218.214";
        static constexpr int RPC_PORT = 80;
        static constexpr const char* RPC_USER = "";
        static constexpr const char* RPC_PASSWORD = "";
        static constexpr const char* DATA_DIR = "./data";
    };
}

#endif
