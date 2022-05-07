#ifndef FLAPPYBIRD_H
#define FLAPPYBIRD_H

#include <QMainWindow>
#include <QImage>
#include <QString>
#include <QPainter>
#include <QTimer>
#include <QKeyEvent>
#include "Models/TubePair.h"
#include "Controllers/BirdController.h"
#include "Controllers/TubeController.h"
#include "Controllers/IntersectionController.h"

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
    //void resizeEvent(QResizeEvent *e) override;

    void stop();

    ~FlappyBird() override;

public slots:
    void refreshController();
    void start();

private:
    int refreshTime = 10;

    QImage* backPNG_ = new QImage("/home/skalem/FlappyBird/sprites/back.png");

    Ui::FlappyBird *ui;


    QTimer* refreshTimer = new QTimer(this);

    Bird* bird;
    BirdController* birdController = nullptr;
    TubeController* tubeController = nullptr;
    IntersectionController*  intersectionController;
};
#endif // FLAPPYBIRD_H
