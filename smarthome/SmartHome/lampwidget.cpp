#include "lampwidget.h"
#include "ui_lampwidget.h"
#include <QDebug>
#include "yeelink_lzy.h"

LampWidget::LampWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LampWidget)
{
    ui->setupUi(this);
    ui->PosixOn->hide();
    ui->HomeOn->hide();
    ui->OrgOn->hide();

    flagLamppos = 0;
    flagLamphome =0;
    flagLamporg =0;

    btnGroupPosix = new QButtonGroup(this);
    btnGroupPosix->addButton(ui->btnPosixOn,0);
    btnGroupPosix->addButton(ui->btnPosixOff,1);
    ui->btnPosixOff->setChecked(true);
    btnGroupHome = new QButtonGroup(this);
    btnGroupHome->addButton(ui->btnHomeOn,0);
    btnGroupHome->addButton(ui->btnHomeOff,1);
    ui->btnHomeOff->setChecked(true);
    btnGroupOrg = new QButtonGroup(this);
    btnGroupOrg->addButton(ui->btnOrgOn,0);
    btnGroupOrg->addButton(ui->btnOrgOff,1);
    ui->btnOrgOff->setChecked(true);

    lastlamphome = btnGroupHome->checkedId();
    lastlamppos = btnGroupPosix->checkedId();
    lastlamporg = btnGroupOrg->checkedId();

    connect(&lamp1timer, SIGNAL(timeout()), this, SLOT(lamp1TimerHandler()));
    connect(&lamp2timer, SIGNAL(timeout()), this, SLOT(lamp2TimerHandler()));
    connect(&lamp3timer, SIGNAL(timeout()), this, SLOT(lamp3TimerHandler()));

    connect(ui->btnPosixOn,SIGNAL(clicked()),this,SLOT(posixSlot()));
    connect(ui->btnPosixOff,SIGNAL(clicked()),this,SLOT(posixSlot()));
    connect(ui->btnHomeOn,SIGNAL(clicked()),this,SLOT(homeSlot()));
    connect(ui->btnHomeOff,SIGNAL(clicked()),this,SLOT(homeSlot()));
    connect(ui->btnOrgOn,SIGNAL(clicked()),this,SLOT(orgSlot()));
    connect(ui->btnOrgOff,SIGNAL(clicked()),this,SLOT(orgSlot()));
}

QFrame *LampWidget::getFrame()
{
    return ui->frame;
}

void LampWidget::posixBtnOn(bool sw)
{
    if(sw) {
        ui->PosixOff->hide();
        ui->PosixOn->show();
        ui->btnPosixOn->setChecked(true);
    }
    else {
        ui->PosixOn->hide();
        ui->PosixOff->show();
        ui->btnPosixOff->setChecked(true);
    }
    lastlamppos = btnGroupPosix->checkedId();
}

void LampWidget::homeBtnOn(bool sw)
{
    if(sw) {
        ui->HomeOff->hide();
        ui->HomeOn->show();
        ui->btnHomeOn->setChecked(true);
    }
    else {
        ui->HomeOn->hide();
        ui->HomeOff->show();
        ui->btnHomeOff->setChecked(true);
    }
    lastlamphome = btnGroupHome->checkedId();
}

void LampWidget::orgBtnOn(bool sw)
{
    if(sw){
        ui->OrgOff->hide();
        ui->OrgOn->show();
        ui->btnOrgOn->setChecked(true);
    }
    else {
        ui->OrgOn->hide();
        ui->OrgOff->show();
        ui->btnOrgOff->setChecked(true);
    }
    lastlamporg = btnGroupOrg->checkedId();
}

LampWidget::~LampWidget()
{
    delete ui;
}

void LampWidget::posixSlot()
{
    switch(btnGroupPosix->checkedId())
    {
    case 0:
        ui->PosixOff->hide();
        ui->PosixOn->show();
        system("echo 1 > /sys/devices/platform/leds-gpio/leds/led2/brightness");
        break;
    case 1:
        ui->PosixOn->hide();
        ui->PosixOff->show();
        system("echo 0 > /sys/devices/platform/leds-gpio/leds/led2/brightness");
        break;
    }
    if(lastlamppos != btnGroupPosix->checkedId())
    {
        flagLamppos = 1;
        lamp1timer.start(12000);
    }
    lastlamppos = btnGroupPosix->checkedId();
}

void LampWidget::homeSlot()
{
    switch(btnGroupHome->checkedId())
    {
    case 0:
        ui->HomeOff->hide();
        ui->HomeOn->show();
        system("echo 1 > /sys/devices/platform/leds-gpio/leds/led3/brightness");
        break;
    case 1:
        ui->HomeOn->hide();
        ui->HomeOff->show();
        system("echo 0 > /sys/devices/platform/leds-gpio/leds/led3/brightness");
        break;
    }
    if(lastlamphome != btnGroupHome->checkedId())
    {
        flagLamphome = 1;\
        lamp2timer.start(12000);
    }
    lastlamphome = btnGroupHome->checkedId();
}

void LampWidget::orgSlot()
{
    switch(btnGroupOrg->checkedId())
    {
    case 0:
        ui->OrgOff->hide();
        ui->OrgOn->show();
        system("echo 1 > /sys/devices/platform/leds-gpio/leds/led4/brightness");
        break;
    case 1:
        ui->OrgOn->hide();
        ui->OrgOff->show();
        system("echo 0 > /sys/devices/platform/leds-gpio/leds/led4/brightness");
        break;
    }
    if(lastlamporg != btnGroupOrg->checkedId())
    {
        flagLamporg = 1;
        lamp3timer.start(12000);
    }
    lastlamporg = btnGroupOrg->checkedId();
}

void LampWidget::lamp1TimerHandler()
{
    set_sensor_status("118.190.25.51","359625","409837","50bc63c1c6a73292d81d8bc53c585118",!(btnGroupPosix->checkedId()));
    flagLamppos = 0;
}

void LampWidget::lamp2TimerHandler()
{
    set_sensor_status("118.190.25.51","359625","410087","50bc63c1c6a73292d81d8bc53c585118",!(btnGroupHome->checkedId()));
    flagLamphome = 0;
}

void LampWidget::lamp3TimerHandler()
{
    set_sensor_status("118.190.25.51","359625","410088","50bc63c1c6a73292d81d8bc53c585118",!(btnGroupOrg->checkedId()));
    flagLamporg = 0;
}


