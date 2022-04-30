#include "TubeController.h"
#include <iostream>

TubeController::TubeController(int width, int height) {
    firstTubeX_ = width;
    distance = width/3;
    windowTube_ = height/3;
    tubeWidth_ = width/15;
    width_ = width;
    height_ = height;
    rand = std::mt19937(rd());
    generateTube();
}

void TubeController::generateTube() {
    int lower = 100 + windowTube_;
    int upper = height_ - lower;

    std::uniform_int_distribution<int> dist(lower, upper);

    quint32 result = dist(rand);

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

TubeController::~TubeController() {
    delete tubeJPG_;
    delete upsideTubeJPG_;
}
