#include "multigame.h"
#include "ui_multigame.h"
#include "dialog.h"
multigame::multigame(QWidget *parent) :
    MainWindow(parent),
    ui(new Ui::multigame)
{
    ui->setupUi(this);
    this->setWindowTitle("多人模式");
}

multigame::~multigame()
{
    delete ui;
}

void multigame::on_pushButton_clicked()
{
    back();
}

void multigame::on_pushButton_2_clicked()
{
    Dialog* back=new Dialog();
    back->show();
    this->close();
}
