#ifndef FLAPPYBIRD_TUBEPAIR_H
#define FLAPPYBIRD_TUBEPAIR_H

#include <QRect>

class TubePair {
private:
    QRect* lowerRect;
    QRect* upperRect;
public:
    TubePair(int x, int y, int width, int screenHeight, int window);

    QRect* getLower();
    QRect* getUpper();
    int getX();
    void moveLeft();

    ~TubePair();
};


#endif //FLAPPYBIRD_TUBEPAIR_H
