#ifndef FLAPPYBIRD_BIRD_H
#define FLAPPYBIRD_BIRD_H

#include "QString"
#include "QPixmap"

class Bird {
    int x_;
    int y_;
    QRect* bird;
    QImage* img = new QImage("/home/skalem/FlappyBird/sprites/bird.png");
    //12*17
public:
    Bird(int x, int y);

    void moveUp(int height);
    void moveDown(int height);

    void move(int height);

    int getX() const;
    int getY() const;

    QRect getRect();

    QImage getSprite();

    ~Bird();
};

#endif //FLAPPYBIRD_BIRD_H
