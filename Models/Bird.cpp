#include "Bird.h"

Bird::Bird(int x,int y, const QString& pathToSprite) {
    bird = new QRect(x, y, 17, 12);
    x_ = x;
    y_ = y;
}

void Bird::moveDown(int height) {
    y_ -= height;
}

void Bird::moveUp(int height) {
    y_ += height;
}

Bird::~Bird() {
    delete bird;
    delete img;
}

int Bird::getX() const {
    return x_;
}

int Bird::getY() const {
    return y_;
}

QImage Bird::getSprite() {
    return *img;
}




