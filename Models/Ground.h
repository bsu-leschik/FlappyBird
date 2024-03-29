#ifndef FLAPPYBIRD_GROUND_H
#define FLAPPYBIRD_GROUND_H

#include <QRect>
#include <QPixmap>

class Ground {

    QRect* boundingRect;
    QPixmap* sprite = new QPixmap(":/sprites/bottom.png");

    int speed  = 2;
public:
    Ground(int width, int height, int x = 0, int y = 107);

    QRect getBoundingRectangle();
    QPixmap getSprite();

    void setSpeed(int i);

    void moveLeft();

};


#endif //FLAPPYBIRD_GROUND_H
