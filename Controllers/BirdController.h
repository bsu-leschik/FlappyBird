#ifndef FLAPPYBIRD_BIRDCONTROLLER_H
#define FLAPPYBIRD_BIRDCONTROLLER_H

#include "../Models/Bird.h"

class BirdController{
    Bird* bird_;
    double drop = 0;
    int screenHeight_;

public:
    explicit BirdController(Bird* bird, int screenHeight);

    void refresh();

    void jump();

    int getX();

    int getY();

    Bird* getBird();

    QRect getBoundingRect();

    ~BirdController();

};


#endif //FLAPPYBIRD_BIRDCONTROLLER_H
