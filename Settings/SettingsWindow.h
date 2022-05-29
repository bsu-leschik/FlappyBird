#ifndef FLAPPYBIRD_SETTINGSWINDOW_H
#define FLAPPYBIRD_SETTINGSWINDOW_H

#include <QWidget>
#include <QSlider>
#include <QPaintEvent>
#include <QLabel>
#include <QPalette>
#include <QCloseEvent>
#include <QPushButton>
#include <QFileDialog>
#include <QString>

class SettingsWindow : public QWidget{
    Q_OBJECT;
private:
    QSlider* birdVelocity;
    QSlider* tubeVelocity;
    QSlider* jumpHeight;

    QLabel* birdVelocityLabel;
    QLabel* tubeVelocityLabel;
    QLabel* jumpHeightLabel;

    QPushButton* birdSelectionButton;

    QString spritePath = "../sprites/bird.png";

public:

    static bool Linux;

    explicit SettingsWindow(QWidget* parent = nullptr);

    void closeEvent(QCloseEvent *event) override;

    int getJumpHeight();
    int getHorizontalVelocity();
    int getVerticalVelocity();
    QString getPathToBirdSprite();

    ~SettingsWindow() override;

public slots:
    void openExplorer();

signals:
    void onCloseSignal();
};


#endif //FLAPPYBIRD_SETTINGSWINDOW_H
