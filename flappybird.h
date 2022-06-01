#ifndef FLAPPYBIRD_H
#define FLAPPYBIRD_H

#include <QMainWindow>
#include <QImage>
#include <QString>
#include <QPainter>
#include <QTimer>
#include <QKeyEvent>
#include <QPushButton>
#include "Menu/StartMenu.h"
#include "Models/TubePair.h"
#include "Controllers/BirdController.h"
#include "Controllers/TubeController.h"
#include "Controllers/IntersectionController.h"
#include "Controllers/ScoreController.h"
#include "Controllers/GroundController.h"
#include "Settings/SettingsWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class FlappyBird; }
QT_END_NAMESPACE

class FlappyBird : public QMainWindow
{
    Q_OBJECT

public:
    explicit FlappyBird(QWidget *parent = nullptr);

    void start();
    void openSettings();

    void paintEvent(QPaintEvent *e) override;
    void keyPressEvent(QKeyEvent *e) override;

    void stop();

    ~FlappyBird() override;

public slots:
    void refreshController();
    void startMenuController(int id);
    void settingsController();
    void init();

private:
    bool inGame = false;
    int refreshTime = 7;

    QString backPNG_ = ":/sprites/back.png";

    Ui::FlappyBird *ui;


    QTimer* refreshTimer = new QTimer(this);

    Bird* bird;
    Ground* ground;
    BirdController* birdController = nullptr;
    TubeController* tubeController = nullptr;
    GroundController* groundController = nullptr;
    IntersectionController*  intersectionController;
    ScoreController* scoreController;

    StartMenu* menu;
    SettingsWindow* settings = nullptr;
};
#endif // FLAPPYBIRD_H
