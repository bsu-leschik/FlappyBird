#ifndef FLAPPYBIRD_GROUNDCONTROLLER_H
#define FLAPPYBIRD_GROUNDCONTROLLER_H
#include <QPainter>
#include "../Models//Ground.h"

class GroundController {
    Ground* ground;
public:
    GroundController(int y);

    void paint(QPainter* painter);

    void refresh();
};


#endif //FLAPPYBIRD_GROUNDCONTROLLER_H
