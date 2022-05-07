#include "Ground.h"

Ground::Ground(int height) {
    y_ = height;
}

void Ground::moveLeft() {
    x_--;
}

int Ground::getX() const {
    return x_;
}

int Ground::getY() const {
    return y_;
}

QImage Ground::getImage() {
    return QImage("../sprites/bottom.png");
}
