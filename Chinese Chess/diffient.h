#ifndef DIFFIENT_H
#define DIFFIENT_H

#include <QMainWindow>

namespace Ui {
class diffient;
}

class diffient : public QMainWindow
{
    Q_OBJECT

public:
    explicit diffient(QWidget *parent = nullptr);
    ~diffient();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::diffient *ui;
};

#endif // DIFFIENT_H
