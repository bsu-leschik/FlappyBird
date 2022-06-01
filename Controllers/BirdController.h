#ifndef FLAPPYBIRD_BIRDCONTROLLER_H
#define FLAPPYBIRD_BIRDCONTROLLER_H

#include "../Models/Bird.h"
#include <QVector>

class BirdController{
    int startPosY;
    Bird* bird_;
    double drop = 0;
    double dropVelocity = 0.1;
    int jumpHeight = 5;
    int screenHeight_;
    double toChangeBird = 0;
    QVector<QString> pathsToBirdSprite = {":/sprites/Birds/bird0.png", ":/sprites/Birds/bird1.png", ":/sprites/Birds/bird2.png"};

public:
    explicit BirdController(Bird* bird, int screenHeight);

    void restart();

    void refresh();

    void jump();

    void setJumpHeight(int height);

    void setDropVelocity(double height);

    void setSpritePath(const QVector<QString>& path);

    int getX();

    int getY();

    Bird* getBird();

    QRect getBoundingRect();

    ~BirdController() = default;

};


#endif //FLAPPYBIRD_BIRDCONTROLLER_H
