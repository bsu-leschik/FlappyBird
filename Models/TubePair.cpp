#include "TubePair.h"

TubePair::TubePair(int x, int y, int width, int screenHeight, int window) {
    lowerRect = new QRect(x, y, width, screenHeight - y);
    upperRect = new QRect(x, 0, width, y - window);
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
    lowerRect->moveLeft(lowerRect->x() - 1);
    upperRect->moveLeft(upperRect->x() - 1);
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



