#ifndef MULTIGAME_H
#define MULTIGAME_H

#include <QWidget>
#include "mainwindow.h"
namespace Ui {
class multigame;
}

class multigame : public MainWindow
{
    Q_OBJECT

public:
    explicit multigame(QWidget *parent = nullptr);
    ~multigame();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::multigame *ui;
};

#endif // MULTIGAME_H
