#ifndef NEW_WIDGET_H
#define NEW_WIDGET_H

#include <QDialog>

namespace Ui {
class new_widget;
}

class new_widget : public QDialog
{
    Q_OBJECT

public:
    explicit new_widget(QWidget *parent = nullptr);
    ~new_widget();

private:
    Ui::new_widget *ui;
};

#endif // NEW_WIDGET_H
