#ifndef AIRWIDGET_H
#define AIRWIDGET_H

#include <QWidget>
#include <QFrame>

namespace Ui {
class AirWidget;
}

class AirWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AirWidget(QWidget *parent = 0);
    QFrame *getFrame();
    ~AirWidget();

private:
    Ui::AirWidget *ui;
};

#endif // AIRWIDGET_H
