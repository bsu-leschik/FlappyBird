#include "TubeController.h"
#include <iostream>

TubeController::TubeController(int width, int height) {
    deltaWindow_ = height/3;
    firstTubeX_ = width;
    distance = width/3;
    windowTube_ = height/3;
    tubeWidth_ = width/15;
    width_ = width;
    height_ = height;
    generateTube();
}

void TubeController::generateTube() {
    quint32 lower = 100 + windowTube_;
    quint32 upper = height_ - lower;

    quint32 result = rand.bounded(lower, upper);

    std::cout << result << std::endl;
    TubePair* tPair = new TubePair(width_, result, tubeWidth_, height_, windowTube_);
    tubes_.push_back(tPair);
}

void TubeController::refresh() {
    for (TubePair* rectPair : this->tubes_) {
        rectPair->moveLeft();
    }

    if (this->tubes_.back()->getX() + distance == firstTubeX_) {
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
