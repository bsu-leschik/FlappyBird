#include "flappybird.h"
#include "./ui_flappybird.h"

FlappyBird::FlappyBird(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::FlappyBird) {
    ui->setupUi(this);

    setFocusPolicy(Qt::StrongFocus);

    auto *wait = new QTimer(this);
    wait->setSingleShot(true);


    connect(wait, SIGNAL(timeout()), SLOT(init()));
    connect(refreshTimer, SIGNAL(timeout()), SLOT(refreshController()));
    wait->start(500);
}

void FlappyBird::init() {
    QPixmap background("/home/skalem/FlappyBird/sprites/back.png");
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, background);
    this->setPalette(palette);

    menu = new StartMenu(this);
    connect(menu, SIGNAL(idClicked(int)), SLOT(startMenuController(int)));
    menu->show();
}

void FlappyBird::start() {
    bird = new Bird(100, this->height() / 2);
    birdController = new BirdController(bird, this->height());
    tubeController = new TubeController(this->width(), this->height());
    intersectionController = new IntersectionController(birdController, tubeController);
    scoreController = new ScoreController(this->width() / 2, this->height() / 10);

    menu->hide();

    inGame = true;

    refreshTimer->start(this->refreshTime);
}

void FlappyBird::refreshController() {
    tubeController->refresh();
    birdController->refresh();


    if (intersectionController->isIntersection()) {
        this->stop();
        return;
    }
    if (intersectionController->passed()) {
        scoreController->add();
    }
    this->update();
}

void FlappyBird::paintEvent(QPaintEvent *e) {
    if (tubeController == nullptr) { return; }
    auto *painter = new QPainter(this);
    tubeController->paint(painter);
    scoreController->paint(painter);


    painter->drawImage(bird->getRect(), bird->getSprite());
    delete painter;
}

void FlappyBird::keyPressEvent(QKeyEvent *e) {
    if (!inGame){
        return;
    }
    if (Qt::Key_Space == e->key()) {
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
    delete scoreController;
    inGame = false;
    menu->show();
}

void FlappyBird::startMenuController(int id) {
    //1 - start 2 - scores 3 - settings
    if (id == 1) {
        this->start();
        return;
    }

    if (id == 2) { return; }

    if (id == 3) {
        this->openSettings();
    }
}

void FlappyBird::openSettings() {
    settings = new SettingsWindow();
    settings->show();
}

FlappyBird::~FlappyBird() {
    delete ui;
    delete backPNG_;
    delete menu;
    delete settings;
    stop();
}




