#include "Bird.h"

Bird::Bird(int x,int y) {
    bird = new QRect(x, y, 170, 120);
    x_ = x;
    y_ = y;
}

void Bird::moveDown(int height) {
    y_ += height;
    bird->setY(y_);
    bird->setHeight(bird->height() + height);
}

void Bird::moveUp(int height) {
    y_ -= height;
    bird->setY(y_);
    bird->setHeight(bird->height() - height);
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

void Bird::move(int height) {
    y_ -= height;
    bird->setY(y_);
    bird->setHeight(bird->height() - height);
}

QRect Bird::getRect() {
    return *bird;
}




