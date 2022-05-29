#include "BirdController.h"
BirdController::BirdController(Bird *bird, int screenHeight){
    bird_ = bird;
    startPosY = bird->getY();
    screenHeight_ = screenHeight;
}

void BirdController::refresh() {
    if(bird_->getRect().bottom() <= screenHeight_) {
        drop -= 0.1;
        bird_->move((int)drop);
    }
}

void BirdController::jump() {
    drop = jumpHeight;
    bird_->moveUp((int)drop);
}

int BirdController::getX() {
    return bird_->getX();
}

int BirdController::getY() {
    return bird_->getY();
}

QRect BirdController::getBoundingRect() {
    return bird_->getRect();
}

Bird *BirdController::getBird() {
    return bird_;
}

BirdController::~BirdController() {
    delete bird_;
}

void BirdController::restart() {
    this->bird_->setY(startPosY);
}

void BirdController::setJumpHeight(int height) {
    jumpHeight = height;
}
