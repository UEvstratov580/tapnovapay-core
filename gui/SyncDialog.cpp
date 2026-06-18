#include "SyncDialog.hpp"
#include <QMessageBox>

SyncDialog::SyncDialog(QWidget *parent)
    : QDialog(parent)
{
    setupUI();
    setWindowTitle("Вибір синхронізації");
    setModal(true);
    resize(450, 350);
}

void SyncDialog::setupUI() {
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    // Заголовок
    QLabel* titleLabel = new QLabel("<h2>⚙️ Налаштування синхронізації</h2>");
    titleLabel->setStyleSheet("color: #f7931a;");
    mainLayout->addWidget(titleLabel);

    QLabel* descLabel = new QLabel(
        "Виберіть режим синхронізації блокчейну для TapNovaPay Core.\n"
        "Це впливає на швидкість роботи та використання дискового простору."
    );
    descLabel->setWordWrap(true);
    descLabel->setStyleSheet("color: #8a8a8a; margin-bottom: 10px;");
    mainLayout->addWidget(descLabel);

    // Група вибору
    QGroupBox* syncGroup = new QGroupBox("Режим синхронізації");
    QVBoxLayout* groupLayout = new QVBoxLayout(syncGroup);

    m_buttonGroup = new QButtonGroup(this);

    // Повна синхронізація
    m_fullRadio = new QRadioButton(
        "📦 Повна синхронізація\n"
        "   • Завантажує повний блокчейн\n"
        "   • Найбільший об'єм даних\n"
        "   • Найвища швидкість роботи\n"
        "   • Рекомендується для повноцінних нод"
    );
    m_fullRadio->setStyleSheet("QLabel { color: #ffffff; }");
    m_fullRadio->setChecked(false);
    m_buttonGroup->addButton(m_fullRadio, FULL_SYNC);
    groupLayout->addWidget(m_fullRadio);

    // Легка синхронізація (за замовчуванням)
    m_lightRadio = new QRadioButton(
        "⚡ Легка синхронізація (рекомендовано)\n"
        "   • Завантажує тільки заголовки блоків\n"
        "   • Швидкий старт\n"
        "   • Мало дискового простору\n"
        "   • Підходить для більшості користувачів"
    );
    m_lightRadio->setStyleSheet("QLabel { color: #ffffff; }");
    m_lightRadio->setChecked(true);
    m_buttonGroup->addButton(m_lightRadio, LIGHT_SYNC);
    groupLayout->addWidget(m_lightRadio);

    // Без синхронізації
    m_noSyncRadio = new QRadioButton(
        "⏸️ Без синхронізації\n"
        "   • Не завантажує блокчейн\n"
        "   • Працює тільки з вашим гаманцем\n"
        "   • Миттєвий старт\n"
        "   • Для створення/імпорту гаманців"
    );
    m_noSyncRadio->setStyleSheet("QLabel { color: #ffffff; }");
    m_noSyncRadio->setChecked(false);
    m_buttonGroup->addButton(m_noSyncRadio, NO_SYNC);
    groupLayout->addWidget(m_noSyncRadio);

    connect(m_buttonGroup, QOverload<int>::of(&QButtonGroup::idClicked), this, &SyncDialog::onModeSelected);

    mainLayout->addWidget(syncGroup);

    // Кнопки
    QHBoxLayout* buttonLayout = new QHBoxLayout();

    m_confirmButton = new QPushButton("✅ Підтвердити");
    m_confirmButton->setStyleSheet("QPushButton { background-color: #f7931a; color: #1a1a1a; border: none; border-radius: 4px; padding: 10px 20px; font-weight: bold; } QPushButton:hover { background-color: #f8a43a; }");
    connect(m_confirmButton, &QPushButton::clicked, this, &SyncDialog::onConfirmClicked);

    m_cancelButton = new QPushButton("❌ Скасувати");
    m_cancelButton->setStyleSheet("QPushButton { background-color: #3a3a3a; color: #ffffff; border: none; border-radius: 4px; padding: 10px 20px; } QPushButton:hover { background-color: #4a4a4a; }");
    connect(m_cancelButton, &QPushButton::clicked, this, &QDialog::reject);

    buttonLayout->addStretch();
    buttonLayout->addWidget(m_confirmButton);
    buttonLayout->addWidget(m_cancelButton);

    mainLayout->addLayout(buttonLayout);
}

void SyncDialog::onModeSelected(int id) {
    switch (id) {
        case FULL_SYNC:
            m_selectedMode = FULL_SYNC;
            break;
        case LIGHT_SYNC:
            m_selectedMode = LIGHT_SYNC;
            break;
        case NO_SYNC:
            m_selectedMode = NO_SYNC;
            break;
    }
}

void SyncDialog::onConfirmClicked() {
    // Показуємо підтвердження вибору
    QString modeText;
    switch (m_selectedMode) {
        case FULL_SYNC: modeText = "Повна синхронізація"; break;
        case LIGHT_SYNC: modeText = "Легка синхронізація"; break;
        case NO_SYNC: modeText = "Без синхронізації"; break;
    }

    QMessageBox::information(this, "Вибір підтверджено",
        "✅ Вибрано режим: " + modeText + "\n\n"
        "TapNovaPay Core запускається з цими налаштуваннями.");
    accept();
}
