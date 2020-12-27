#include "detail.h"
#include "ui_detail.h"
#include "dialog.h"
detail::detail(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::detail)
{
    ui->setupUi(this);
    this->setWindowTitle("规则介绍");
}

detail::~detail()
{
    delete ui;
}

void detail::on_pushButton_clicked()
{
    Dialog *w=new Dialog();
    this->hide();
    w->show();
}
