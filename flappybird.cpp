#include "flappybird.h"
#include "./ui_flappybird.h"
#include <iostream>

FlappyBird::FlappyBird(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FlappyBird)
    {
    ui->setupUi(this);

    auto* wait = new QTimer(this);
    wait->setSingleShot(true);

    connect(wait, SIGNAL(timeout()), SLOT(start()));
    connect(refreshTimer, SIGNAL(timeout()), SLOT(refreshController()));
    wait->start(500);
}

void FlappyBird::start() {
    QPixmap background("/home/skalem/FlappyBird/sprites/back.png");
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, background);
    this->setPalette(palette);

    bird = new Bird(100, this->height()/2);
    birdController = new BirdController(bird, this->height());
    tubeController = new TubeController(this->width(), this->height());
    intersectionController = new IntersectionController(birdController, tubeController);

    refreshTimer->start(refreshTime);
}

void FlappyBird::refreshController() {
    tubeController->refresh();
    birdController->refresh();
    if (intersectionController->isIntersection()){
        this->stop();
        return;
    }
    this->update();
}

void FlappyBird::paintEvent(QPaintEvent *e) {
    if (tubeController == nullptr) {return;}
    auto* painter = new QPainter(this);
    tubeController->paint(painter);

    painter->drawImage(bird->getRect() ,bird->getSprite());
    delete painter;
}

void FlappyBird::keyPressEvent(QKeyEvent *e) {
    if(Qt::Key_Space == e->key()) {
        if (birdController != nullptr) {
            birdController->jump();
        } else {
            start();
        }
    }
}

void FlappyBird::stop() {
    refreshTimer->stop();
    delete tubeController;
    tubeController = nullptr;
    delete birdController;
    birdController = nullptr;
    delete intersectionController;
}

FlappyBird::~FlappyBird(){
    delete ui;
    delete backPNG_;
    stop();
}
