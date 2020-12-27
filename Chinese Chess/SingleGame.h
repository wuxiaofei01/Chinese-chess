#ifndef SINGLEGAME_H
#define SINGLEGAME_H

#include <QWidget>
#include "mainwindow.h"
namespace Ui {
class singlegame;
}

class singlegame : public MainWindow
{
    Q_OBJECT

public:
    explicit singlegame(QWidget *parent = nullptr);
    ~singlegame();
     virtual void click(int id, int row, int col);
     void getAllPossibleMove(QVector<Step*>&steps);

        //电脑走棋
     void fakeMove(Step* steps);
     void unFakeMove(Step* steps);

     int getMaxScore(int deep,int max);
     int getMinScore(int deep,int min);
     int calcScore();

     int deep;
     Step* computerMove();

private slots:
     void on_pushButton_clicked();

     void on_pushButton_2_clicked();

private:
    Ui::singlegame *ui;
};

#endif // SINGLEGAME_H
