#ifndef FLAPPYBIRD_GROUND_H
#define FLAPPYBIRD_GROUND_H
#include "QImage"

class Ground {
    int y_;
    int x_ = 0;

public:
    explicit Ground (int height);

    int getY() const;
    int getX() const;

    static QImage getImage();

    void moveLeft();

    ~Ground() = default;
};


#endif //FLAPPYBIRD_GROUND_H
