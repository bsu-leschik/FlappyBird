#ifndef FLAPPYBIRD_SETTINGSWINDOW_H
#define FLAPPYBIRD_SETTINGSWINDOW_H

#include <QWidget>
#include <QSlider>
#include <QPaintEvent>
#include <QLabel>
#include <QPalette>


class SettingsWindow : public QWidget{
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

    ~SettingsWindow() override;
};


#endif //FLAPPYBIRD_SETTINGSWINDOW_H
