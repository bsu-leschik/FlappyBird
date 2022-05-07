#ifndef FLAPPYBIRD_INTERSECTIONCONTROLLER_H
#define FLAPPYBIRD_INTERSECTIONCONTROLLER_H

#include "BirdController.h"
#include "TubeController.h"

class IntersectionController {

public:
    IntersectionController(BirdController* bird, TubeController* tubes);

    bool isIntersection();

    ~IntersectionController() = default;
private:
    BirdController* bird_;
    TubeController* tubes_;
};


#endif //FLAPPYBIRD_INTERSECTIONCONTROLLER_H
