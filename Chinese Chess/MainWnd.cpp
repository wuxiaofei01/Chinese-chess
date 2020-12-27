#include "MainWnd.h"
#include <QHBoxLayout>
#include "SingleGame.h"
#include "MultiGame.h"

MainWnd::MainWnd(QWidget *parent) : QWidget(parent)
{

    if(_gameType == 0)
    {
        SingleGame* game = new SingleGame;
        CtrlPanel* panel = new CtrlPanel;

        QHBoxLayout* hLay = new QHBoxLayout(this);
        hLay->addWidget(game, 1);
        hLay->addWidget(panel);
        connect(panel, SIGNAL(sigBack()), game, SLOT(slotBack()));
        connect(panel, SIGNAL(toMain()), game, SLOT(slotBack()));
    }
    else if(_gameType == 1)
    {
        MultiGame* game = new MultiGame;
        CtrlPanel* panel = new CtrlPanel;

        QHBoxLayout* hLay = new QHBoxLayout(this);
        hLay->addWidget(game, 1);
        hLay->addWidget(panel);
        connect(panel, SIGNAL(sigBack()), game, SLOT(slotBack()));
        connect(panel, SIGNAL(toMain()), game, SLOT(slotBack()));
    }
}

MainWnd::~MainWnd()
{

}

