#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QPushButton>
#include <QWidget>
#include <QFrame>
#include <QPushButton>
#include "tempwidget.h"
#include "humiwidget.h"
#include "smokewidget.h"
#include "airwidget.h"
#include "lampwidget.h"
#include "videowidget.h"
#include "alarmtest.h"

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();

private slots:
    void on_btnTemp_clicked();

    void on_btnHumi_2_clicked();

    void on_btnHumi_clicked();

    void on_btnSmoke_clicked();

    void on_btnAir_clicked();

    void on_btnLamp_clicked();

    void on_btnVideo_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_14_clicked();

    void getStateSignalHandler(int state);

    void getBuzzerStateSignalHandler(int state);

private:
    Ui::MainWidget *ui;
    QFrame *Temp;
    QPushButton *btnLast;
    TempWidget *T;
    HumiWidget *H;
    SmokeWidget *S;
    AirWidget *A;
    LampWidget *L;
    VideoWidget *V;
    AlarmTest *alarm;
};

#endif // MAINWIDGET_H
