#include "GroundController.h"

GroundController::GroundController(Ground *ground) {
    this->ground0_ = ground;
    this->ground1_ = new Ground(ground->getBoundingRectangle().width(), ground->getBoundingRectangle().height(), ground->getBoundingRectangle().width(), ground->getBoundingRectangle().y());
}

void GroundController::refresh() {
    if (ground1_->getBoundingRectangle().x() == 0){
        ground0_ = ground1_;
        ground1_ = new Ground(ground0_->getBoundingRectangle().width(), ground0_->getBoundingRectangle().height(), ground0_->getBoundingRectangle().width(), ground0_->getBoundingRectangle().y());
    }
    ground0_->moveLeft();
    ground1_->moveLeft();
}

void GroundController::paint(QPainter *painter) {
    painter->drawPixmap(ground0_->getBoundingRectangle(), ground0_->getSprite());
    painter->drawPixmap(ground1_->getBoundingRectangle(), ground1_->getSprite());
}

QRect GroundController::getBoundingRect() {
    return {0, ground0_->getBoundingRectangle().y(), ground0_->getBoundingRectangle().width(),ground0_->getBoundingRectangle().height() };
}
