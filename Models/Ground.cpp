#include "Ground.h"

Ground::Ground(int width, int height, int x, int y) {
    sprite->scaled(width, height, Qt::KeepAspectRatio);
    boundingRect = new QRect(x, y, width, height);
    // 398:107 2px per square single part - 25:107
}

void Ground::moveLeft() {
    boundingRect->moveLeft(boundingRect->x() - 1);
}

QRect Ground::getBoundingRectangle() {
    return *boundingRect;
}

QPixmap Ground::getSprite() {
    return *sprite;
}

