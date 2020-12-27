#include "dialog.h"
#include "ui_dialog.h"
#include "diffient.h"
#include "SingleGame.h"
#include "multigame.h"
#include "detail.h"
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setWindowTitle("象棋");
    this->show();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    this->hide();
    diffient *mu=new diffient();
    mu->show();
}

void Dialog::on_pushButton_2_clicked()
{
    this->hide();
    multigame *mu=new multigame();
    mu->show();
}

void Dialog::on_pushButton_3_clicked()
{
    detail *d=new detail();
    this->hide();
    d->show();
}
