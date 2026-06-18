QT += core widgets network gui
CONFIG += c++17
TARGET = tapnovapay-gui
TEMPLATE = app

# Мови
TRANSLATIONS = translations/tapnovapay_uk.ts \
               translations/tapnovapay_en.ts

SOURCES = \
    src/main.cpp \
    src/MainWindow.cpp \
    src/Wallet.cpp \
    src/RPCClient.cpp \
    src/Crypto.cpp \
    src/Config.cpp

HEADERS = \
    src/MainWindow.hpp \
    include/Wallet.hpp \
    include/RPCClient.hpp \
    include/Crypto.hpp \
    include/Config.hpp \
    include/config.h

FORMS = src/MainWindow.ui

INCLUDEPATH += include src

# Бібліотеки
LIBS += -lssl -lcrypto -lcurl -lsqlite3 -lws2_32 -lcrypt32

# Прибираємо попередження
QMAKE_CXXFLAGS += -w
QMAKE_CFLAGS += -w

# Синхронізація
SOURCES += gui/SyncDialog.cpp
HEADERS += gui/SyncDialog.hpp

# Ресурси

# Безпека
SOURCES += src/Security.cpp
HEADERS += include/Security.hpp

# Security Monitor
SOURCES += src/SecurityMonitor.cpp
HEADERS += include/SecurityMonitor.hpp

# Транзакції та підписи
SOURCES += src/TransactionSigner.cpp
SOURCES += src/DeveloperSignature.cpp
HEADERS += include/DeveloperSignature.hpp
