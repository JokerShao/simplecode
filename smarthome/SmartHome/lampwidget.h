#ifndef LAMPWIDGET_H
#define LAMPWIDGET_H

#include <QWidget>
#include <QFrame>
#include <QButtonGroup>
#include <QTimer>

namespace Ui {
class LampWidget;
}

class LampWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LampWidget(QWidget *parent = 0);
    QFrame *getFrame();
    void posixBtnOn(bool sw);
    void homeBtnOn(bool sw);
    void orgBtnOn(bool sw);
    ~LampWidget();
    int flagLamppos;
    int flagLamphome;
    int flagLamporg;

    int lastlamppos;
    int lastlamphome;
    int lastlamporg;

private slots:
    void posixSlot();
    void homeSlot();
    void orgSlot();

    void lamp1TimerHandler();
    void lamp2TimerHandler();
    void lamp3TimerHandler();

private:
    Ui::LampWidget *ui;
    QTimer lamp1timer;
    QTimer lamp2timer;
    QTimer lamp3timer;
    QButtonGroup *btnGroupPosix;
    QButtonGroup *btnGroupHome;
    QButtonGroup *btnGroupOrg;
};

#endif // LAMPWIDGET_H
