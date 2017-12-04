#ifndef SMOKEWIDGET_H
#define SMOKEWIDGET_H

#include <QWidget>
#include <QFrame>

namespace Ui {
class SmokeWidget;
}

class SmokeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SmokeWidget(QWidget *parent = 0);
    QFrame *getFrame();
    ~SmokeWidget();

private:
    Ui::SmokeWidget *ui;
};

#endif // SMOKEWIDGET_H
