#ifndef SYNCDIALOG_HPP
#define SYNCDIALOG_HPP

#include <QDialog>
#include <QLabel>
#include <QRadioButton>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QButtonGroup>

class SyncDialog : public QDialog {
    Q_OBJECT

public:
    enum SyncMode {
        FULL_SYNC,
        LIGHT_SYNC,
        NO_SYNC
    };

    explicit SyncDialog(QWidget *parent = nullptr);

    SyncMode getSelectedMode() const { return m_selectedMode; }

private slots:
    void onModeSelected(int id);
    void onConfirmClicked();

private:
    void setupUI();

    QButtonGroup* m_buttonGroup;
    QRadioButton* m_fullRadio;
    QRadioButton* m_lightRadio;
    QRadioButton* m_noSyncRadio;
    QPushButton* m_confirmButton;
    QPushButton* m_cancelButton;
    SyncMode m_selectedMode = LIGHT_SYNC;
};

#endif
