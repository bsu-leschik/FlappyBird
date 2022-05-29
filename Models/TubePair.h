#ifndef FLAPPYBIRD_TUBEPAIR_H
#define FLAPPYBIRD_TUBEPAIR_H

#include <QRect>

class TubePair {
private:
    QRect* lowerRect;
    QRect* upperRect;
    int velocity_;
public:
    TubePair(int x, int y, int width, int screenHeight, int window, int velocity = 1);

    QRect* getLower();
    QRect* getUpper();
    int getX();
    void moveLeft();
    void setVelocity(int velocity);
    bool intersects(QRect rect);

    ~TubePair();
};


#endif //FLAPPYBIRD_TUBEPAIR_H
