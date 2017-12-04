#include "alarmtest.h"
#include "ui_alarmtest.h"

AlarmTest::AlarmTest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AlarmTest)
{
    ui->setupUi(this);
}

QFrame *AlarmTest::getFrame()
{
    return ui->frame;
}

void AlarmTest::alarmPressed(bool p)
{
    if(p)
        ui->pushButton->pressed();
    else
        ui->pushButton->released();
}

AlarmTest::~AlarmTest()
{
    delete ui;
}

void AlarmTest::on_pushButton_pressed()
{
    ui->pushButton->setStyleSheet(QString("border-image: url(:/new/prefix1/img/buzzer_on.ico)"));
    system("echo 1 > /sys/devices/platform/x6818-beep/state");
}

void AlarmTest::on_pushButton_released()
{
    ui->pushButton->setStyleSheet(QString("border-image: url(:/new/prefix1/img/buzzer_off.ico)"));
    system("echo 0 > /sys/devices/platform/x6818-beep/state");
}
