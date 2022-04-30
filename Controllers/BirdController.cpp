#include "BirdController.h"

BirdController::BirdController(Bird *bird) {
    bird_ = bird;
}

void BirdController::refresh() {
    drop -= 0.1;
    bird_->move((int)drop);
}

void BirdController::jump() {
    drop = 5;
    bird_->moveUp((int)drop);
}

BirdController::~BirdController() {
    delete bird_;
}
