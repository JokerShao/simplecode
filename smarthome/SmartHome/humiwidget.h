#ifndef HUMIWIDGET_H
#define HUMIWIDGET_H

#include <QWidget>
#include <QFrame>

namespace Ui {
class HumiWidget;
}

class HumiWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HumiWidget(QWidget *parent = 0);
    QFrame *getFrame();
    ~HumiWidget();

private:
    Ui::HumiWidget *ui;
};

#endif // HUMIWIDGET_H
