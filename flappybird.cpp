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

    deltaWindow = this->height()/4;
    firstTubeX = this->width();
    distance = this->width()/3;
    windowTube = this->height()/5;
    tubeWidth = this->width()/15;

    generateRect();
    connect(refreshTimer, SIGNAL(timeout()), SLOT(refreshController()));
    refreshTimer->start(refreshTime);
}

void FlappyBird::refreshController() {
    for (TubePair* rectPair : this->tubes) {
        rectPair->moveLeft();
    }

        if (this->tubes.back()->getX() + distance == firstTubeX) {
            generateRect();
        }

    if (tubes.front()->getX() <= 0 - tubeWidth){
        tubes.erase(tubes.cbegin());
    }
    this->update();
}



void FlappyBird::paintEvent(QPaintEvent *e) {
    QPainter painter(this);
    for (TubePair* tPair: tubes) {
        painter.drawImage(*tPair->getLower(), *(this->tubeJPG_));
        painter.drawImage(*tPair->getUpper(), *(this->upsideTubeJPG_));
    }
}

void FlappyBird::generateRect() {
    quint32 lower = windowTube + 100;
    quint32 upper = this->height() - lower;
    if (!this->tubes.empty()){
        if (tubes.back()->getLower()->height() > deltaWindow + 50) {
            lower = tubes.back()->getLower()->height() - deltaWindow;
        }
        upper = lower + 2*deltaWindow;
    }

    quint32 result = rand.bounded(lower, upper);

    TubePair* tPair = new TubePair(this->width(), result, tubeWidth, this->height(), windowTube);
    tubes.push_back(tPair);
}

FlappyBird::~FlappyBird(){
    delete ui;
    delete tubeJPG_;
    delete upsideTubeJPG_;
    delete backPNG_;

}
