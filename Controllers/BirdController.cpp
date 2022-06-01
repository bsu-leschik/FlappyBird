#include "BirdController.h"
BirdController::BirdController(Bird *bird, int screenHeight){
    bird_ = bird;
    startPosY = bird->getY();
    screenHeight_ = screenHeight;
}

void BirdController::refresh() {
    toChangeBird += 0.1;
    if ((int) toChangeBird == 3){
        toChangeBird = 0;
    }
    bird_->setPathToSprite(pathsToBirdSprite[(int)toChangeBird]);
    if(bird_->getRect().bottom() <= screenHeight_) {
        drop -= dropVelocity;
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


void BirdController::restart() {
    this->bird_->setY(startPosY);
    this->drop = 0;
}

void BirdController::setJumpHeight(int height) {
    jumpHeight = height;
}

void BirdController::setDropVelocity(double height) {
    dropVelocity = height;
}

void BirdController::setSpritePath(const QVector<QString>& path) {
    pathsToBirdSprite = path;
}
