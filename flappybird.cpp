#include "flappybird.h"
#include "./ui_flappybird.h"

FlappyBird::FlappyBird(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FlappyBird)
    {
    ui->setupUi(this);

    auto* wait = new QTimer(this);
    wait->setSingleShot(true);

    connect(wait, SIGNAL(timeout()), SLOT(start()));
    wait->start(500);
}

void FlappyBird::start() {
    QPixmap background("/home/skalem/FlappyBird/sprites/back.png");
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, background);
    this->setPalette(palette);

    bird = new Bird(100, this->height()/2);
    birdController = new BirdController(bird);

    tubeController = new TubeController(this->width(), this->height());
    connect(refreshTimer, SIGNAL(timeout()), SLOT(refreshController()));
    refreshTimer->start(refreshTime);
}

void FlappyBird::refreshController() {
    tubeController->refresh();
    birdController->refresh();
    this->update();
}

void FlappyBird::paintEvent(QPaintEvent *e) {
    if (tubeController == nullptr) {return;}
    QPainter* painter = new QPainter(this);
    tubeController->paint(painter);

    painter->drawImage(bird->getRect() ,bird->getSprite());
    delete painter;
}

void FlappyBird::keyPressEvent(QKeyEvent *e) {
    if(Qt::Key_Space == e->key()) {
        birdController->jump();
    }
}

FlappyBird::~FlappyBird(){
    delete ui;
    delete backPNG_;
    delete bird;
    delete birdController;
    delete tubeController;

}


