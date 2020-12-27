#include "SingleGame.h"
#include "ui_singlegame.h"
#include "mainwindow.h"
#include "dialog.h"
singlegame::singlegame(QWidget *parent) :
    MainWindow(parent),
    ui(new Ui::singlegame)
{
    deep=2;
    ui->setupUi(this);
    this->setWindowTitle("人机对战");
}

singlegame::~singlegame()
{
    delete ui;
}
void singlegame::click(int id, int row, int col)
{
    //人红，电脑黑
    if(!this->_bRedTurn)
        return;
    MainWindow::click(id, row, col);

    if(!this->_bRedTurn)
    {
        Step* step=computerMove();
        moveStone(step->_moveid,step->_killid,step->_rowTo,step->_colTo);
    }

}
//
void singlegame::getAllPossibleMove(QVector<Step*>&steps)//得到所有可能走的位置
{
    int begin=16,end=32;
    if(this->_bRedTurn)
    {
        begin=0,end=16;
    }
        for(int i=begin;i<end;++i)
        {
            if(_s[i]._dead)continue;
            for(int row=0;row<=9;++row)
            {
                for(int col=0;col<=8;++col)
                {
                    int killid=this->getStoneId(row,col);//走棋的可能位置
                    if(sameColor(i,killid))continue;
                    if(canMove(i,killid,row,col))
                    {
                        saveStep(i,killid,row,col,steps);
                    }
                }
            }
        }
}
void singlegame::fakeMove(Step *step)
{
    if(!_s[20]._dead){
    killStone(step->_killid);
    moveStone(step->_moveid, step->_rowTo, step->_colTo);
    }
    else return;
}

void singlegame::unFakeMove(Step *step)
{
    reliveStone(step->_killid);
    moveStone(step->_moveid, step->_rowFrom, step->_colFrom);

}
int singlegame::calcScore()//计算黑棋减红旗 分数调用函数
{
    //车马炮相士将兵
    static int chessScore[]={100,40,50,30,31,10000,10};
    int redScore=0,blackScore=0;
    for(int i=0;i<16;i++)
    {
        if(_s[i]._dead)continue;
        redScore+=chessScore[_s[i]._type];
    }
    for(int i=16;i<31;i++)
    {
        if(_s[i]._dead)continue;
        blackScore+=chessScore[_s[i]._type];
    }
    return blackScore-redScore;
}
int singlegame::getMinScore(int level, int curMin)
{
    if(level == 0)
        return calcScore();

    QVector<Step*> steps;
    getAllPossibleMove(steps);
    int minInAllMaxScore = 300000;

    while(steps.count())
    {
        Step* step = steps.last();
        steps.removeLast();

        fakeMove(step);
        int maxScore = getMaxScore(level-1, minInAllMaxScore);
        unFakeMove(step);
        delete step;

        if(maxScore <= curMin)
        {
            while(steps.count())
            {
                Step* step = steps.last();
                steps.removeLast();
                delete step;
            }
            return maxScore;
        }

        if(maxScore < minInAllMaxScore)
        {
            minInAllMaxScore = maxScore;
        }


    }
    return minInAllMaxScore;
}
int singlegame::getMaxScore(int level, int curMax)
{
    if(level == 0)
        return calcScore();

    QVector<Step*> steps;
    getAllPossibleMove(steps);
    int maxInAllMinScore = -300000;

    while(steps.count())
    {
        Step* step = steps.last();
        steps.removeLast();

        fakeMove(step);
        int minScore = getMinScore(level-1, maxInAllMinScore);
        unFakeMove(step);
        delete step;

        if(minScore >= curMax)
        {
            while(steps.count())
            {
                Step* step = steps.last();
                steps.removeLast();
                delete step;
            }
            return minScore;
        }
        if(minScore > maxInAllMinScore)
        {
            maxInAllMinScore = minScore;
        }


    }
    return maxInAllMinScore;
}
Step* singlegame::computerMove()//遍历，算取最大值，选取最优解
{
    Step* ret = NULL;
    QVector<Step*> steps;
    getAllPossibleMove(steps);
    int maxInAllMinScore = -300000;

    while(steps.count())
    {
        Step* step = steps.last();
        steps.removeLast();

        fakeMove(step);
        int minScore = getMinScore(this->deep-1,maxInAllMinScore);
        unFakeMove(step);

        if(minScore > maxInAllMinScore)
        {
            if(ret) delete ret;

            ret = step;
            maxInAllMinScore = minScore;
        }
        else
        {
            delete step;
        }
    }
    return ret;
}

void singlegame::on_pushButton_clicked()
{
    back();
    back();
}

void singlegame::on_pushButton_2_clicked()
{
    Dialog* back=new Dialog();
    back->show();
    this->close();
}
