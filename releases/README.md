# TapNovaPay Core Wallet

Децентралізований гаманець для блокчейну TapNovaPay

## 📥 Завантаження

### 🪟 Windows
- **Версія:** TapNovaPay-Core-Windows.zip
- **Встановлення:** Розпакуйте та запустіть `run.bat`

### 🐧 Linux (Debian/Ubuntu)
- **Версія:** TapNovaPay-Core-Linux.tar.gz
- **Встановлення:**
  ```bash
  tar -xzf TapNovaPay-Core-Linux.tar.gz
  cd TapNovaPay-Core
  ./run.sh

cd ~/TapNovaPay

# Показуємо всі готові файли
echo "=========================================="
echo "📦 ГОТОВІ ЗБІРКИ"
echo "=========================================="
echo ""

# 1. Готова програма
echo "🪟 Windows (портативна версія):"
ls -la TapNovaPay-Core/tapnovapay-gui.exe
du -sh TapNovaPay-Core/
echo "   📁 Папка: ~/TapNovaPay/TapNovaPay-Core/"
echo ""

# 2. Архіви
echo "📦 Архіви:"
ls -la releases/*.zip 2>/dev/null
echo ""

# 3. Копіюємо все в одну папку для зручності
mkdir -p TapNovaPay-Releases
cp -r TapNovaPay-Core TapNovaPay-Releases/
cp releases/TapNovaPay-Core-Windows.zip TapNovaPay-Releases/ 2>/dev/null
cp releases/README.md TapNovaPay-Releases/ 2>/dev/null

# Створюємо інструкцію
cat > TapNovaPay-Releases/INSTALL.txt << 'EOF'
===========================================
   TapNovaPay Core - Встановлення
===========================================

🪟 Windows:
   1. Розпакуйте TapNovaPay-Core-Windows.zip
   2. Запустіть run.bat або tapnovapay-gui.exe

📁 Або просто запустіть готову програму:
   TapNovaPay-Core/tapnovapay-gui.exe

🔐 Безпека:
   - Програма має підпис розробника
   - Автоматичний бекап гаманця
   - Захист від злому

📞 Підтримка:
   Telegram: https://t.me/tapnovapay
   Email: info@tapnovapay.org
