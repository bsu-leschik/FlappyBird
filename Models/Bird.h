#ifndef FLAPPYBIRD_BIRD_H
#define FLAPPYBIRD_BIRD_H

#include "QPoint"
#include "QRect"

class Bird {
    QRect *bird_;

    //12*17
public:
    Bird(int x, int y);

    void moveUp(int height);
    void moveDown(int height);
    QRect* getRect();

    ~Bird();
};

#endif //FLAPPYBIRD_BIRD_H
