#ifndef FLAPPYBIRD_SETTINGSWINDOW_H
#define FLAPPYBIRD_SETTINGSWINDOW_H

#include <QWidget>

class SettingsWindow : public QWidget{
public:
    explicit SettingsWindow(QWidget* parent = nullptr);
    ~SettingsWindow() override;
};


#endif //FLAPPYBIRD_SETTINGSWINDOW_H
