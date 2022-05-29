#include "SettingsWindow.h"

SettingsWindow::SettingsWindow(QWidget *parent) : QWidget(parent) {
    birdVelocity = new QSlider(Qt::Horizontal, this);
    birdVelocity->setGeometry(100, 0, this->width() - 200, this->height() / 5);
    birdVelocityLabel = new QLabel(birdVelocity);
    birdVelocityLabel->setAlignment(Qt::AlignTop);
    birdVelocityLabel->setText("Fall velocity:");
    birdVelocity->setMaximum(10);
    birdVelocity->setMinimum(1);
    birdVelocity->setSliderPosition(1);
    birdVelocity->setTickInterval(3);
    birdVelocity->setTickPosition(QSlider::TicksBelow);
    birdVelocity->setTracking(true);


    tubeVelocity = new QSlider(Qt::Horizontal, this);
    tubeVelocity->setGeometry(100, this->height() / 5, this->width() - 200, this->height() / 5);
    tubeVelocityLabel = new QLabel(tubeVelocity);
    tubeVelocityLabel->setText("Horizontal velocity:");
    tubeVelocity->setMaximum(10);
    tubeVelocity->setMinimum(1);
    tubeVelocity->setSliderPosition(2);
    tubeVelocity->setTracking(true);

    jumpHeight = new QSlider(Qt::Horizontal, this);
    jumpHeight->setGeometry(100, 2 * this->height() / 5, this->width() - 200, this->height() / 5);
    jumpHeightLabel = new QLabel(jumpHeight);
    jumpHeightLabel->setText("Jump height: ");
    jumpHeight->setMinimum(30);
    jumpHeight->setMinimum(1);
    jumpHeight->setSliderPosition(1);
    jumpHeight->setTracking(true);

    dropWidget = new QWidget(this);
    dropWidget->setGeometry(100, 3*this->height() / 5, this->width() - 200, 200);
    dropWidget->setAutoFillBackground(true);
    QPalette palette;
    palette.setColor(QPalette::Window, QColor(150, 150, 150));
    dropWidget->setPalette(palette);
    dropWidget->setAcceptDrops(true);
    dropLabel = new QLabel("Drop the image of your bird in here", dropWidget);
    dropLabel->setMargin(100);

    birdVelocity->show();
    tubeVelocity->show();
    jumpHeight->show();
    dropWidget->show();
}

SettingsWindow::~SettingsWindow() {
    delete birdVelocity;
    delete tubeVelocity;
    delete jumpHeight;

    delete birdVelocityLabel;
    delete tubeVelocityLabel;
    delete jumpHeightLabel;
}

void SettingsWindow::closeEvent(QCloseEvent *event) {
    QWidget::closeEvent(event);
    tubeVelocity->setSliderPosition(tubeVelocity->value());
    emit onCloseSignal();
}

int SettingsWindow::getJumpHeight() {
    return jumpHeight->value();
}

int SettingsWindow::getHorizontalVelocity() {
    return tubeVelocity->value();
}

int SettingsWindow::getVerticalVelocity() {
    return birdVelocity->value();
}
