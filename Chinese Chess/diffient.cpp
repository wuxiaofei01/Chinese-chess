#include "diffient.h"
#include "ui_diffient.h"
#include "SingleGame.h"
diffient::diffient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::diffient)
{
    this->setWindowTitle("难度选择");
    ui->setupUi(this);
}

diffient::~diffient()
{
    delete ui;
}

void diffient::on_pushButton_clicked()
{
    singlegame* s=new singlegame();
    s->deep=2;
    s->show();
    this->close();
}

void diffient::on_pushButton_2_clicked()
{
    singlegame* s=new singlegame();
    s->deep=4;
    s->show();
    this->close();
}
