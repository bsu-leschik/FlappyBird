#ifndef FLAPPYBIRD_BIRD_H
#define FLAPPYBIRD_BIRD_H

#include "QString"
#include "QPixmap"

class Bird {
    int x_;
    int y_;
    int width = 120;
    int height = 80;
    QRect* bird;
    QImage* img = new QImage("../sprites/bird.png");
    //12*17
public:
    Bird(int x, int y);

    void moveUp(int height);
    void moveDown(int height);

    void move(int height);

    int getX() const;
    int getY() const;
    void setY(int y);

    int getWidth() const;
    int getHeight() const;

    QRect getRect();

    QImage getSprite();
    void setPathToSprite(const QString& path);

    ~Bird() = default;
};

#endif //FLAPPYBIRD_BIRD_H
