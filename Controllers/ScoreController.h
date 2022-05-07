#ifndef FLAPPYBIRD_SCORECONTROLLER_H
#define FLAPPYBIRD_SCORECONTROLLER_H
#include <QPainter>
#include <string>
#include <QPoint>
#include <QImage>
#include <QString>
#include <vector>

class ScoreController {

    QString folder = "../sprites/numbers/";
    int score = 0;
    int x_;
    int y_;

public:
    ScoreController(int x, int y);

    void add();

    void paint(QPainter* painter);

    ~ScoreController() = default;
};


#endif //FLAPPYBIRD_SCORECONTROLLER_H