#ifndef FLAPPYBIRD_STARTMENU_H
#define FLAPPYBIRD_STARTMENU_H

#include <QPushButton>
#include <QIcon>
#include <QButtonGroup>
#include <QPalette>

class StartMenu : public QButtonGroup{
    int width_;
    int height_;
    QPushButton *settingsBtn;
    QPushButton *startBtn;
    QPushButton *scoresBtn;

    QIcon *settingsImg = new QIcon("../sprites/Menu/Settings.png");
    QIcon *startImg = new QIcon("../sprites/Menu/StartButton.png");
    QIcon *scoresImg = new QIcon("../sprites/Menu/Scores.png");

public:
    explicit StartMenu(QWidget *parent);

    void show();

    void hide();

    ~StartMenu() override;
};


#endif //FLAPPYBIRD_STARTMENU_H
