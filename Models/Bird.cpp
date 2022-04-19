#include "Bird.h"

Bird::Bird(int x,int y) {
    bird_ = new QRect(x, y, 17, 12);
}

QRect *Bird::getRect() {
    return bird_;
}


void Bird::moveDown(int height) {
    bird_->moveBottom(bird_->y() - height);
}

void Bird::moveUp(int height) {
    bird_->moveTop(bird_->y() + height);
}

Bird::~Bird() {
    delete bird_;
}



