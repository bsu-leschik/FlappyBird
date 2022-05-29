#ifndef FLAPPYBIRD_SETTINGSWINDOW_H
#define FLAPPYBIRD_SETTINGSWINDOW_H

#include <QWidget>
#include <QSlider>
#include <QPaintEvent>
#include <QLabel>
#include <QPalette>
#include <QCloseEvent>


class SettingsWindow : public QWidget{
    Q_OBJECT;
private:
    QSlider* birdVelocity;
    QSlider* tubeVelocity;
    QSlider* jumpHeight;

    QLabel* birdVelocityLabel;
    QLabel* tubeVelocityLabel;
    QLabel* jumpHeightLabel;

    QWidget* dropWidget;
    QLabel* dropLabel;

public:
    explicit SettingsWindow(QWidget* parent = nullptr);

    void closeEvent(QCloseEvent *event) override;

    int getJumpHeight();
    int getHorizontalVelocity();
    int getVerticalVelocity();

    ~SettingsWindow() override;
signals:
    void onCloseSignal();
};


#endif //FLAPPYBIRD_SETTINGSWINDOW_H
