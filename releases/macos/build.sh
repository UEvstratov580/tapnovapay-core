#!/bin/bash
echo "🔧 Збірка TapNovaPay Core для macOS"

# Встановлення залежностей
brew install cmake qt6 openssl curl sqlite3 nlohmann-json

# Створюємо папку для збірки
mkdir -p build && cd build

# Налаштовуємо CMake
cmake .. -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_PREFIX_PATH=$(brew --prefix qt6)

# Збираємо
make -j$(sysctl -n hw.ncpu)

# Створюємо .app
macdeployqt tapnovapay-gui.app -dmg

echo "✅ macOS збірка готова!"
