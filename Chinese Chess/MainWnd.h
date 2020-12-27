#ifndef MAINWND_H
#define MAINWND_H

#include <QWidget>
#include "Board.h"
namespace Ui{
class MainWnd;
}
class MainWnd : public QWidget
{
    Q_OBJECT
public:
    explicit MainWnd(QWidget *parent = 0);
    ~MainWnd();

    int _gameType;

signals:

public slots:
};

#endif // MAINWND_H
