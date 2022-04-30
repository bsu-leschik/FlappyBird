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
#include "Controllers/TubeController.h"

QT_BEGIN_NAMESPACE
namespace Ui { class FlappyBird; }
QT_END_NAMESPACE

class FlappyBird : public QMainWindow
{
    Q_OBJECT

public:
    explicit FlappyBird(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *e) override;
    void keyPressEvent(QKeyEvent *e) override;

    ~FlappyBird() override;

public slots:
    void refreshController();
    void start();

private:
    int refreshTime = 10;

    QImage* backPNG_ = new QImage(QString("/home/skalem/FlappyBird/sprites/back.png"), "PNG");

    Ui::FlappyBird *ui;


    QTimer* refreshTimer = new QTimer(this);

    Bird* bird;
    BirdController* birdController = nullptr;
    TubeController* tubeController = nullptr;
};
#endif // FLAPPYBIRD_H
