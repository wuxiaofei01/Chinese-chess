#include "new_widget.h"
#include "ui_new_widget.h"

new_widget::new_widget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::new_widget)
{
    ui->setupUi(this);
}

new_widget::~new_widget()
{
    delete ui;
}
