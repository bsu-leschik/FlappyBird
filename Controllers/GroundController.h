#ifndef FLAPPYBIRD_GROUNDCONTROLLER_H
#define FLAPPYBIRD_GROUNDCONTROLLER_H

#include "../Models/Ground.h"
#include <QPainter>

class GroundController {
    Ground* ground0_;
    Ground* ground1_;
public:
    explicit GroundController(Ground* ground);

    void refresh();

    QRect getBoundingRect();

    void setSpeed(int speed);

    void paint(QPainter* painter);
};


#endif //FLAPPYBIRD_GROUNDCONTROLLER_H
