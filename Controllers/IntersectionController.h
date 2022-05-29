#ifndef FLAPPYBIRD_INTERSECTIONCONTROLLER_H
#define FLAPPYBIRD_INTERSECTIONCONTROLLER_H

#include "BirdController.h"
#include "TubeController.h"
#include "GroundController.h"

class IntersectionController {

    bool inTube = false;
    bool isOut = false;

public:
    IntersectionController(BirdController* bird, TubeController* tubes, GroundController* ground);

    bool isIntersection();

    bool passed() const;

    ~IntersectionController() = default;
private:
    BirdController* bird_;
    TubeController* tubes_;
    GroundController* ground_;
};


#endif //FLAPPYBIRD_INTERSECTIONCONTROLLER_H
