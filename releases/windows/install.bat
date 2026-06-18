@echo off
echo ============================================
echo   Встановлення TapNovaPay Core
echo ============================================
echo.
echo Копіюємо файли...
xcopy /E /I /Y TapNovaPay-Core "C:\Program Files\TapNovaPay Core"
echo.
echo Створюємо ярлик...
echo [InternetShortcut] > "%USERPROFILE%\Desktop\TapNovaPay Core.url"
echo URL=file:///C:/Program Files/TapNovaPay%20Core/tapnovapay-gui.exe >> "%USERPROFILE%\Desktop\TapNovaPay Core.url"
echo.
echo ✅ Встановлення завершено!
pause
