#ifndef FLAPPYBIRD_GROUND_H
#define FLAPPYBIRD_GROUND_H

#include <QRect>
#include <QImage>

class Ground {

    QRect* boundingRect;
    QImage* sprite = new QImage("../sprites/bottom.png");

public:
    Ground(int width, int height, int x = 0, int y = 107);

    QRect getBoundingRectangle();
    QImage getSprite();

    void moveLeft();

};


#endif //FLAPPYBIRD_GROUND_H
