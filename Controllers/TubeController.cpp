#include "TubeController.h"

TubeController::TubeController(int width, int height) {
    firstTubeX_ = width;
    distance = width/3;
    windowTube_ = height/3;
    tubeWidth_ = width/15;
    width_ = width;
    height_ = height + 20;
    generateTube();
}

void TubeController::generateTube() {
    int lower = 100 + windowTube_;
    int upper = height_ - lower;

    std::random_device rd;
    std::mt19937 rand;

    rand = std::mt19937(rd());

    std::uniform_int_distribution<int> dist(lower, upper);

    quint32 result = dist(rand);

    auto* tPair = new TubePair(width_, result, tubeWidth_, height_, windowTube_, velocity_);
    tubes_.push_back(tPair);
}

void TubeController::refresh() {
    for (TubePair* rectPair : this->tubes_) {
        rectPair->moveLeft();
    }

    if (this->tubes_.back()->getX() + distance <= firstTubeX_) {
        generateTube();
    }

    if (tubes_.front()->getX() <= 0 - tubeWidth_){
        tubes_.erase(tubes_.cbegin());
    }
}

void TubeController::paint(QPainter *painter) {
    if(tubes_.back() == nullptr){return;}
    for (TubePair* tPair: tubes_) {
        painter->drawImage(*tPair->getLower(), *(this->tubeJPG_));
        painter->drawImage(*tPair->getUpper(), *(this->upsideTubeJPG_));
    }
}

TubePair* TubeController::getTubeByX(int startX, int endX) {
    for (TubePair* pair : tubes_) {
        if (startX <= (pair->getX() + tubeWidth_) && endX >= pair->getX()){
            return pair;
        }
    }
    return nullptr;
}

TubeController::~TubeController() {
    delete tubeJPG_;
    delete upsideTubeJPG_;
}

void TubeController::setVelocity(int velocity) {
    velocity_ = velocity;
    for (TubePair* pair: tubes_) {
        pair->setVelocity(velocity);
    }
}

void TubeController::restart() {
    tubes_.erase(tubes_.cbegin(), tubes_.cend());
    generateTube();
}
