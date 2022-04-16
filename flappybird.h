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
#include "QResizeEvent"
#include "Models/TubePair.h"

QT_BEGIN_NAMESPACE
namespace Ui { class FlappyBird; }
QT_END_NAMESPACE

class FlappyBird : public QMainWindow
{
    Q_OBJECT

public:
    FlappyBird(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *e);
    void resizeEvent(QResizeEvent* event);

    ~FlappyBird();

public slots:
    void refreshController();

private:
    int refreshTime = 10;
    int deltaWindow = this->height()/4;
    int firstTubeX = this->width();
    quint32 distance = this->width()/3;

    int windowTube = this->height()/5;
    int tubeWidth = this->width()/13;

    QImage* tubeJPG_ = new QImage(QString("/home/skalem/FlappyBird/sprites/tube.png"), "PNG");
    QImage* upsideTubeJPG_ = new QImage(QString("/home/skalem/FlappyBird/sprites/uTube.png"), "PNG");
    QImage* backPNG_ = new QImage(QString("/home/skalem/FlappyBird/sprites/back.png"), "PNG");

    std::vector<TubePair*> tubes;
    Ui::FlappyBird *ui;

    QRandomGenerator rand;

    void generateRect();
};
#endif // FLAPPYBIRD_H
