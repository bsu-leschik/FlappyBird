#include "ScoreController.h"

ScoreController::ScoreController(int x, int y) {
    x_ = x;
    y_ = y;
}

void ScoreController::paint(QPainter *painter) {
    QString scoreStr;
    if (score <= 9) {
        scoreStr = QString().fromStdString(std::to_string(score));
        painter->drawImage(QPoint(x_, y_),
                           QImage(folder + scoreStr));
    } else {
        std::vector<int> scores;
        int tempScore = score;
        while (score != 0) {
            scores.push_back(score % 10);
            score = (score - score % 10) / 10;
        }
        score = tempScore;

        while (!scores.empty()) {
            scoreStr = QString().fromStdString(std::to_string(scores.back()));
            painter->drawImage(QPoint(x_ - 30 * scores.size(), y_),
                               QImage(folder + scoreStr));
            scores.pop_back();
        }

    }


}

void ScoreController::add() {
    score++;
}