@echo off
chcp 65001 > nul
title TapNovaPay Core
color 0A
echo ============================================================
echo    TapNovaPay Core Wallet v1.0.0
echo ============================================================
echo.
echo  📌 Підключення до блокчейну...
echo.
tapnovapay-gui.exe
pause
