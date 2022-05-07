#include "GroundController.h"

void GroundController::paint(QPainter *painter) {
    painter->drawImage(ground->getX(), ground->getY(), ground->getImage());
}

void GroundController::refresh() {
    ground->moveLeft();
}

GroundController::GroundController(int y) {
    ground = new Ground(y);
}
