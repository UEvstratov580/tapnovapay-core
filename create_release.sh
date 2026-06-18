#!/bin/bash

# Перевіряємо чи є токен в змінних оточення
if [ -z "$GITHUB_TOKEN" ]; then
    echo "❌ Помилка: GITHUB_TOKEN не встановлено"
    echo "Встановіть: export GITHUB_TOKEN=ваш_токен"
    exit 1
fi

REPO="UEvstratov580/tapnovapay-core"
VERSION=${1:-"v1.0.1"}

echo "🚀 Створюємо Release $VERSION..."

RESPONSE=$(curl -s -k -X POST \
  -H "Authorization: token $GITHUB_TOKEN" \
  -H "Accept: application/vnd.github.v3+json" \
  https://api.github.com/repos/$REPO/releases \
  -d "{
    \"tag_name\": \"$VERSION\",
    \"target_commitish\": \"main\",
    \"name\": \"TapNovaPay Core Wallet $VERSION\",
    \"body\": \"## TapNovaPay Core Wallet $VERSION\n\n### 🚀 Features\n- Automated build\n- Improved security\n- Bug fixes\n\n### 📦 Downloads\nSee assets below.\",
    \"draft\": false,
    \"prerelease\": false
  }")

RELEASE_ID=$(echo $RESPONSE | grep -o '"id":\s*[0-9]*' | head -1 | grep -o "[0-9]*")
echo "✅ Release ID: $RELEASE_ID"

if [ -f "releases/TapNovaPay-Core-Windows.zip" ]; then
  echo "📤 Завантажуємо Windows..."
  curl -s -k -X POST \
    -H "Authorization: token $GITHUB_TOKEN" \
    -H "Content-Type: application/zip" \
    https://uploads.github.com/repos/$REPO/releases/$RELEASE_ID/assets?name=TapNovaPay-Core-Windows.zip \
    --data-binary @releases/TapNovaPay-Core-Windows.zip
fi

echo "✅ Release $VERSION створено!"
echo "🔗 https://github.com/$REPO/releases/tag/$VERSION"
