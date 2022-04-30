#ifndef FLAPPYBIRD_H
#define FLAPPYBIRD_H

#include <QMainWindow>
#include <vector>
#include <QPoint>
#include <QImage>
#include <QString>
#include <QPainter>
#include <QRect>
#include <QRandomGenerator>
#include <iostream>
#include <QTimer>
#include <utility>
#include <QKeyEvent>
#include "Models/TubePair.h"
#include "Controllers/BirdController.h"

QT_BEGIN_NAMESPACE
namespace Ui { class FlappyBird; }
QT_END_NAMESPACE

class FlappyBird : public QMainWindow
{
    Q_OBJECT

public:
    FlappyBird(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *e);
    void keyPressEvent(QKeyEvent *e) override;

    ~FlappyBird();

public slots:
    void refreshController();
    void start();

private:
    int refreshTime = 10, deltaWindow, firstTubeX, windowTube, tubeWidth;

    quint32 distance;

    QImage* tubeJPG_ = new QImage(QString("/home/skalem/FlappyBird/sprites/tube.png"), "PNG");
    QImage* upsideTubeJPG_ = new QImage(QString("/home/skalem/FlappyBird/sprites/uTube.png"), "PNG");
    QImage* backPNG_ = new QImage(QString("/home/skalem/FlappyBird/sprites/back.png"), "PNG");

    std::vector<TubePair*> tubes;
    Ui::FlappyBird *ui;

    QRandomGenerator rand;

    QTimer* refreshTimer = new QTimer(this);

    Bird* bird;
    BirdController* birdController;

    void generateRect();
};
#endif // FLAPPYBIRD_H
