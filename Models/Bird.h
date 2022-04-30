#ifndef FLAPPYBIRD_BIRD_H
#define FLAPPYBIRD_BIRD_H

#include "QString"
#include "QPixmap"

class Bird {
    int x_;
    int y_;
    QRect* bird;
    QImage* img = new QImage(":/sprites/bird.png");
    //12*17
public:
    Bird(int x, int y, const QString& pathToSprite);

    void moveUp(int height);
    void moveDown(int height);

    int getX() const;
    int getY() const;

    QImage getSprite();

    ~Bird();
};

#endif //FLAPPYBIRD_BIRD_H
