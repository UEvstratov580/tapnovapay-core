#!/bin/bash
echo "🔧 Збірка TapNovaPay Core для Linux"

# Встановлення залежностей
sudo apt update
sudo apt install -y g++ cmake qt6-base-dev qt6-tools-dev \
    libssl-dev libcurl4-openssl-dev libsqlite3-dev nlohmann-json3-dev

# Створюємо папку для збірки
mkdir -p build && cd build

# Налаштовуємо CMake
cmake .. -DCMAKE_BUILD_TYPE=Release

# Збираємо
make -j$(nproc)

# Копіюємо готовий бінарник
cp tapnovapay-gui ../releases/linux/TapNovaPay-Core/

echo "✅ Linux збірка готова!"
