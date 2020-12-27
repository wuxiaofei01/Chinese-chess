#ifndef DETAIL_H
#define DETAIL_H

#include <QMainWindow>

namespace Ui {
class detail;
}

class detail : public QMainWindow
{
    Q_OBJECT

public:
    explicit detail(QWidget *parent = nullptr);
    ~detail();

private slots:
    void on_pushButton_clicked();

private:
    Ui::detail *ui;
};

#endif // DETAIL_H
