#include "Bird.h"

Bird::Bird(int x,int y) {
    bird = new QRect(x, y, width, height);
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

int Bird::getHeight() const {
    return height;
}

int Bird::getWidth() const{
    return width;
}




