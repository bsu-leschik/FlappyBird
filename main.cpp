#include "flappybird.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FlappyBird w;
    w.setWindowState(Qt::WindowFullScreen);
    w.show();
    return a.exec();
}
