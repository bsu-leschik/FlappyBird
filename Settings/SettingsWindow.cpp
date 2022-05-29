#include "SettingsWindow.h"
#include <iostream>



#ifdef Q_OS_LINUX
    bool SettingsWindow::Linux = true;
#elif defined(Q_OS_WINDOWS)
    SettingsWindow::Linux = false
#else
#error "Not supported OS"
#endif

SettingsWindow::SettingsWindow(QWidget *parent) : QWidget(parent) {
    birdVelocity = new QSlider(Qt::Horizontal, this);
    birdVelocity->setGeometry(100, 0, this->width() - 200, this->height() / 5);
    birdVelocityLabel = new QLabel(birdVelocity);
    birdVelocityLabel->setAlignment(Qt::AlignTop);
    birdVelocityLabel->setText("Fall velocity:");
    birdVelocity->setMaximum(10);
    birdVelocity->setMinimum(1);
    birdVelocity->setSliderPosition(1);
    birdVelocity->setTickInterval(3);
    birdVelocity->setTickPosition(QSlider::TicksBelow);
    birdVelocity->setTracking(true);


    tubeVelocity = new QSlider(Qt::Horizontal, this);
    tubeVelocity->setGeometry(100, this->height() / 5, this->width() - 200, this->height() / 5);
    tubeVelocityLabel = new QLabel(tubeVelocity);
    tubeVelocityLabel->setText("Horizontal velocity:");
    tubeVelocity->setMaximum(10);
    tubeVelocity->setMinimum(1);
    tubeVelocity->setSliderPosition(2);
    tubeVelocity->setTracking(true);

    jumpHeight = new QSlider(Qt::Horizontal, this);
    jumpHeight->setGeometry(100, 2 * this->height() / 5, this->width() - 200, this->height() / 5);
    jumpHeightLabel = new QLabel(jumpHeight);
    jumpHeightLabel->setText("Jump height: ");
    jumpHeight->setMaximum(30);
    jumpHeight->setMinimum(1);
    jumpHeight->setSliderPosition(5);
    jumpHeight->setTracking(true);

    spriteButtons = new QButtonGroup(this);

    birdSelectionButton0 = new QPushButton(this);
    birdSelectionButton0->setText("Find bird(wings down)");
    birdSelectionButton1 = new QPushButton(this);
    birdSelectionButton1->setText("Find bird(wings in middle)");
    birdSelectionButton2 = new QPushButton(this);
    birdSelectionButton2->setText("Find bird(wings up)");



    spriteButtons->addButton(birdSelectionButton0);
    spriteButtons->setId(birdSelectionButton0, 0);
    spriteButtons->addButton(birdSelectionButton1);
    spriteButtons->setId(birdSelectionButton1, 1);
    spriteButtons->addButton(birdSelectionButton2);
    spriteButtons->setId(birdSelectionButton2, 2);

    birdSelectionButton0->setGeometry(100, 3* this->height() / 5, this->width()/5, 30);
    birdSelectionButton1->setGeometry(150 + this->width() / 5, 3* this->height() / 5, this->width()/5, 30);
    birdSelectionButton2->setGeometry(200 + 2*this->width() / 5, 3* this->height() / 5, this->width()/5, 30);

    connect(spriteButtons, SIGNAL(idClicked(int)), this, SLOT(openExplorer(int)));

    birdVelocity->show();
    tubeVelocity->show();
    jumpHeight->show();
}

SettingsWindow::~SettingsWindow() {
    delete birdVelocity;
    delete tubeVelocity;
    delete jumpHeight;
}

void SettingsWindow::closeEvent(QCloseEvent *event) {
    QWidget::closeEvent(event);
    tubeVelocity->setSliderPosition(tubeVelocity->value());
    emit onCloseSignal();
}

int SettingsWindow::getJumpHeight() {
    return jumpHeight->value();
}

int SettingsWindow::getHorizontalVelocity() {
    return tubeVelocity->value();
}

int SettingsWindow::getVerticalVelocity() {
    return birdVelocity->value();
}

void SettingsWindow::openExplorer(int id) {
    QString path;
    if (Linux) {
        path = "/home";
    } else {
        path = "";
    }
    QString tempPath;
    tempPath = QFileDialog::getOpenFileName(this, tr("Open File"), path, tr("Images (*.png *.xpm *.jpg)"));
    if (tempPath != nullptr){
        spritePaths[id] = tempPath;
    }
}

QVector<QString> SettingsWindow::getPathToBirdSprite() {
    return spritePaths;
}
