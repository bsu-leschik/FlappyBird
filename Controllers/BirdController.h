#ifndef FLAPPYBIRD_BIRDCONTROLLER_H
#define FLAPPYBIRD_BIRDCONTROLLER_H

#include "../Models/Bird.h"
#include "cmath"


class BirdController{
    Bird* bird_;
    double drop = 0;

public:
    explicit BirdController(Bird* bird);

    void refresh();

    void jump();

};


#endif //FLAPPYBIRD_BIRDCONTROLLER_H
