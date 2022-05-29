#ifndef FLAPPYBIRD_BIRDCONTROLLER_H
#define FLAPPYBIRD_BIRDCONTROLLER_H

#include "../Models/Bird.h"

class BirdController{
    int startPosY;
    Bird* bird_;
    double drop = 0;
    double dropVelocity = 0.1;
    int jumpHeight = 5;
    int screenHeight_;

public:
    explicit BirdController(Bird* bird, int screenHeight);

    void restart();

    void refresh();

    void jump();

    void setJumpHeight(int height);

    void setDropVelocity(double height);

    int getX();

    int getY();

    Bird* getBird();

    QRect getBoundingRect();

    ~BirdController() = default;

};


#endif //FLAPPYBIRD_BIRDCONTROLLER_H
