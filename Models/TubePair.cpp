#include "TubePair.h"

TubePair::TubePair(int x, int y, int width, int screenHeight, int window, int velocity) {
    lowerRect = new QRect(x, y, width, screenHeight - y);
    upperRect = new QRect(x, 0, width, y - window);
    velocity_ = velocity;
}

QRect *TubePair::getLower() {
    return lowerRect;
}

QRect *TubePair::getUpper() {
    return upperRect;
}

int TubePair::getX() {
    return lowerRect->x();
}

void TubePair::moveLeft() {
    lowerRect->moveLeft(lowerRect->x() - velocity_);
    upperRect->moveLeft(upperRect->x() - velocity_);
}

bool TubePair::intersects(QRect rect) {
    if (lowerRect->intersects(rect) || upperRect->intersects(rect)){
        return true;
    }
    return false;
}

TubePair::~TubePair() {
    delete lowerRect;
    delete upperRect;
}

void TubePair::setVelocity(int velocity) {
    velocity_ = velocity;
}



