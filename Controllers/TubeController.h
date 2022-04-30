#ifndef FLAPPYBIRD_TUBECONTROLLER_H
#define FLAPPYBIRD_TUBECONTROLLER_H

#include <QRandomGenerator>
#include <QPainter>
#include "../Models/TubePair.h"

class TubeController {
    QRandomGenerator rand;
    int deltaWindow_, firstTubeX_, windowTube_, tubeWidth_, width_, height_;

    QImage* tubeJPG_ = new QImage(QString("/home/skalem/FlappyBird/sprites/tube.png"), "PNG");
    QImage* upsideTubeJPG_ = new QImage(QString("/home/skalem/FlappyBird/sprites/uTube.png"), "PNG");
    std::vector<TubePair*> tubes_;

    quint32 distance;


public:
    explicit TubeController(int width, int height);

    void generateTube();

    void paint(QPainter* painter);

    void refresh();
};


#endif //FLAPPYBIRD_TUBECONTROLLER_H
