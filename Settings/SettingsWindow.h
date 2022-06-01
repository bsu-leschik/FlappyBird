#ifndef FLAPPYBIRD_SETTINGSWINDOW_H
#define FLAPPYBIRD_SETTINGSWINDOW_H

#include <QWidget>
#include <QSlider>
#include <QPaintEvent>
#include <QLabel>
#include <QPalette>
#include <QCloseEvent>
#include <QPushButton>
#include <QFileDialog>
#include <QString>
#include <QButtonGroup>
#include <QVector>

class SettingsWindow : public QWidget{
    Q_OBJECT;
private:
    QSlider* birdVelocity;
    QSlider* tubeVelocity;
    QSlider* jumpHeight;

    QLabel* birdVelocityLabel;
    QLabel* tubeVelocityLabel;
    QLabel* jumpHeightLabel;


    QButtonGroup* spriteButtons;
    QPushButton* birdSelectionButton0;
    QPushButton* birdSelectionButton1;
    QPushButton* birdSelectionButton2;
    QPushButton* chooseTubeSprite;
    QPushButton* changeBackground;

    QVector<QString> spritePaths = {"../sprites/Birds/bird0.png","../sprites/Birds/bird1.png","../sprites/Birds/bird2.png"};
    QString backgroundPath = "../sprites/back.png";
    QString tubeSpritePath = "../sprites/tube.png";
public:

    static bool Linux;

    explicit SettingsWindow(QWidget* parent = nullptr);

    void closeEvent(QCloseEvent *event) override;

    int getJumpHeight();
    int getHorizontalVelocity();
    int getVerticalVelocity();
    QVector<QString> getPathToBirdSprite();
    QString getBackground();
    QString getTube();

    ~SettingsWindow() override;

public slots:
    void openExplorer(int);
    void findTubeSprite();
    void findBackground();

signals:
    void onCloseSignal();
};


#endif //FLAPPYBIRD_SETTINGSWINDOW_H
