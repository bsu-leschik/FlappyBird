#include "IntersectionController.h"
#include <iostream>

IntersectionController::IntersectionController(BirdController *bird, TubeController* tubes, GroundController* ground) {
    bird_ = bird;
    tubes_ = tubes;
    ground_ = ground;
}

bool IntersectionController::isIntersection() {

    TubePair* pair = tubes_->getTubeByX(bird_->getX(), bird_->getX() + bird_->getBird()->getWidth());
    if (pair != nullptr){
        inTube = true;
        if(pair->intersects(bird_->getBoundingRect()) || ground_->getBoundingRect().y() - 5 <= bird_->getY()){
            return true;
        }
        return false;
    }
    if(inTube){
        isOut = true;
        inTube = false;
    } else {
        isOut = false;
    }
    return false;
}

bool IntersectionController::passed() const {
    return isOut;
}

