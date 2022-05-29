#ifndef FLAPPYBIRD_TUBECONTROLLER_H
#define FLAPPYBIRD_TUBECONTROLLER_H

#include <QRandomGenerator>
#include <QPainter>
#include <random>
#include "../Models/TubePair.h"

class TubeController {
    int firstTubeX_, windowTube_, tubeWidth_, width_, height_, velocity_ = 2;

    QImage* tubeJPG_ = new QImage(QString("../sprites/tube.png"), "PNG");
    QImage* upsideTubeJPG_ = new QImage(QString("../sprites/uTube.png"), "PNG");
    std::vector<TubePair*> tubes_;

    quint32 distance;



public:
    TubeController(int width, int height);

    void restart();

    void generateTube();

    void paint(QPainter* painter);

    void setVelocity(int velocity);

    void refresh();

    TubePair* getTubeByX(int startX, int endX);



    ~TubeController();
};


#endif //FLAPPYBIRD_TUBECONTROLLER_H
