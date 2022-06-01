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
    QPixmap background(backPNG_);
    background = background.scaled(this->size(), Qt::KeepAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, background);
    this->setPalette(palette);

    bird = new Bird(100, this->height() / 2);
    ground = new Ground(this->width(), this->height()/10, 0, this->height() - this->height()/10);
    birdController = new BirdController(bird, this->height() - this->height()/10);
    tubeController = new TubeController(this->width(), this->height());
    groundController = new GroundController(ground);

    settings = new SettingsWindow();
    connect(settings, SIGNAL(onCloseSignal()), this, SLOT(settingsController()));

    menu = new StartMenu(this);
    connect(menu, SIGNAL(idClicked(int)), SLOT(startMenuController(int)));
    menu->show();
}

void FlappyBird::start() {

    QPixmap background(backPNG_);
    background = background.scaled(this->size(), Qt::KeepAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, background);
    this->setPalette(palette);
    birdController->restart();
    tubeController->restart();
    intersectionController = new IntersectionController(birdController, tubeController, groundController);
    scoreController = new ScoreController(this->width() / 2, this->height() / 10);

    menu->hide();

    inGame = true;

    refreshTimer->start(this->refreshTime);
}

void FlappyBird::refreshController() {
    tubeController->refresh();
    birdController->refresh();
    groundController->refresh();


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
    groundController->paint(painter);


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
    settings->show();
}

FlappyBird::~FlappyBird() {
    settings->close();
    stop();
    delete ui;
    delete menu;
    delete settings;
    delete bird;
    delete birdController;
    delete tubeController;
}

void FlappyBird::settingsController() {
    this->backPNG_ = settings->getBackground();
    tubeController->setTubeSprite(this->settings->getTube());
    tubeController->setVelocity(this->settings->getHorizontalVelocity());
    birdController->setJumpHeight(this->settings->getJumpHeight());
    birdController->setDropVelocity((double) this->settings->getVerticalVelocity() / 10);
    birdController->setSpritePath(this->settings->getPathToBirdSprite());
}




