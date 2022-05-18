#include "StartMenu.h"

StartMenu::StartMenu(QWidget *parent) : QButtonGroup(parent) {
    width_ = parent->width();
    height_ = parent->height();

    settingsBtn = new QPushButton(parent);
    startBtn = new QPushButton(parent);
    scoresBtn = new QPushButton(parent);

    startBtn->setGeometry(width_ / 2 - 110, height_ / 2, 104, 58);
    scoresBtn->setGeometry(width_ / 2 + 10, height_ / 2, 104, 58);
    settingsBtn->setGeometry(width_ / 2 - 40, height_ / 2 + 70, 80, 28);

    startBtn->setIcon(*startImg);
    scoresBtn->setIcon(*scoresImg);
    settingsBtn->setIcon(*settingsImg);

    startBtn->setPalette(QPalette(Qt::TransparentMode));
    scoresBtn->setPalette(QPalette(Qt::TransparentMode));

    startBtn->setIconSize(startBtn->size());
    scoresBtn->setIconSize(scoresBtn->size());
    settingsBtn->setIconSize(settingsBtn->size());



    addButton(startBtn, 1);
    addButton(scoresBtn, 2);
    addButton(settingsBtn, 3);
}

void StartMenu::show() {
    settingsBtn->show();
    startBtn->show();
    scoresBtn->show();
}

void StartMenu::hide() {
    scoresBtn->hide();
    startBtn->hide();
    settingsBtn->hide();
}

StartMenu::~StartMenu() {
    delete settingsBtn;
    delete settingsImg;
    delete startBtn;
    delete startImg;
    delete scoresBtn;
    delete scoresImg;
}





