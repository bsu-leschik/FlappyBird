#include "ScoreController.h"

ScoreController::ScoreController(int x, int y) {
    x_ = x;
    y_ = y;
}
void ScoreController::paint(QPainter* painter) {
    QString scoreStr;
    if (score <= 9){
        scoreStr = QString().fromStdString(std::to_string(score));
        painter->drawImage(QPoint(x_, y_),
                           QImage(folder + scoreStr));
    } else {
        std::vector<int> scores;
        while(score != 0){
            scores.push_back(score % 10);
            score /= 10;
        }

        while (!scores.empty()) {
            scoreStr = QString().fromStdString(std::to_string(scores.back()));
            painter->drawImage(QPoint(x_ - 30*scores.size(), y_ - 30*scores.size()),
                               QImage(folder + scoreStr));
            scores.pop_back();
        }

    }



}

void ScoreController::add() {
    score++;
}