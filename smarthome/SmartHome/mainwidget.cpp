#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "QPalette"
#include "QPixmap"
#include "QFrame"
#include "QPushButton"
#include <QDebug>
#include <QMessageBox>
#include <unistd.h>
#include "getstatethread.h"
#include "lampwidget.h"

#define DEV_NUM 4
/*
    槽函数都是复制的
    等于两个全局变量btnLast Temp
    每一个控件都有show方法
    这个工程造独立的类不如造继承的类，


*/
MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
//设置背景
    QPalette palette;
    palette.setBrush(QPalette::Background, \
                           QBrush(QPixmap(":/new/prefix1/img/maindesk.png").scaled(1024,600)));
    this->setPalette(palette);
    T = new TempWidget();
    H = new HumiWidget();
    S = new SmokeWidget();
    A = new AirWidget();
    L = new LampWidget();
    V = new VideoWidget();
    alarm = new AlarmTest();
    Temp = new QFrame();
    btnLast = new QPushButton();
    Temp = ui->frame;
    btnLast = ui->btnTemp;
    //1测试隐藏无用图标
//    ui->btnTemp_2->hide();
//    ui->btnHumi_2->hide();
//    ui->btnSmoke_2->hide();
//    ui->btnAir_2->hide();
//    ui->btnLamp_2->hide();
//    ui->btnCurtain_2->hide();
//    ui->btnVideo_2->hide();
//    ui->btnOther_2->hide();
//测试类对象赋值
//    btn = new QPushButton(this);
//    btn->setText("1111111111111");
//    btn->setParent(this);
//    ui->btnAir =  btn;

//测试qframe
//    frame = new QFrame(this);
//    frame->show();
//    QPushButton *btn = new QPushButton(frame);
//    btn->setText("wang");

//测试了两个类传递ui->frame,需要setparent(this);
//    T = new TempWidget();
//    Temp = T->getFrame();
//    Temp->setParent(this);
//    ui->frame->hide();
//    ui->frame = Temp;
    GetStateThread *g = new GetStateThread();
    connect(g,SIGNAL(ledStateSignal(int)),this,SLOT(getStateSignalHandler(int)));
    connect(g,SIGNAL(buzzerStateSignal(int)),this,SLOT(getBuzzerStateSignalHandler(int)));
    g->start();

}

MainWidget::~MainWidget()
{
    delete ui;
}


void MainWidget::on_btnTemp_clicked()
{
    //更改Frame
    btnLast->show();
    btnLast = ui->btnTemp;
    Temp->hide();
    Temp = T->getFrame();
    Temp->setParent(this);
    Temp->show();
/*    Temp = T->getFrame();
    Temp->setParent(this);
    ui->frame = Temp;
    ui->frame->show(); */             // 2 所有的控件都有一个show()
    //ui->frame->hide();
    //this->update();///////////////////////////     1
    //更改MainWidget  ??
    QPalette palette;
    palette.setBrush(QPalette::Background, \
                           QBrush(QPixmap(":/new/prefix1/img/temp_desk.png").scaled(1024,600)));
    this->setPalette(palette);
    ui->btnTemp->hide();
    ui->btnTemp_2->show();
}

void MainWidget::on_btnHumi_clicked()
{
    //更改Frame
    btnLast->show();
    btnLast = ui->btnHumi;
    Temp->hide();
    Temp = H->getFrame();
    Temp->setParent(this);
    Temp->show();
    QPalette palette;
    palette.setBrush(QPalette::Background, \
                           QBrush(QPixmap(":/new/prefix1/img/humidity_desk.png").scaled(1024,600)));
    this->setPalette(palette);
    ui->btnHumi->hide();            //   2怎么把上一个显示出来？
    ui->btnHumi_2->show();
}


void MainWidget::on_btnHumi_2_clicked()
{

}

void MainWidget::on_btnSmoke_clicked()
{
    //更改Frame
    btnLast->show();
    btnLast = ui->btnSmoke;
    Temp->hide();
    Temp = S->getFrame();
    Temp->setParent(this);
    Temp->show();
    QPalette palette;
    palette.setBrush(QPalette::Background, \
                           QBrush(QPixmap(":/new/prefix1/img/smoke_desk.png").scaled(1024,600)));
    this->setPalette(palette);
    ui->btnSmoke->hide();            //   2怎么把上一个显示出来？
    ui->btnSmoke_2->show();
}

void MainWidget::on_btnAir_clicked()
{
    //更改Frame
    btnLast->show();
    btnLast = ui->btnAir;
    Temp->hide();
    Temp = A->getFrame();
    Temp->setParent(this);
    Temp->show();
    QPalette palette;
    palette.setBrush(QPalette::Background, \
                           QBrush(QPixmap(":/new/prefix1/img/smoke_desk.png").scaled(1024,600)));
    this->setPalette(palette);
    ui->btnAir->hide();            //   2怎么把上一个显示出来？
    ui->btnAir_2->show();
}

void MainWidget::on_btnLamp_clicked()
{
    //更改Frame
    btnLast->show();
    btnLast = ui->btnLamp;
    Temp->hide();
    Temp = L->getFrame();
    Temp->setParent(this);
    Temp->show();
    QPalette palette;
    palette.setBrush(QPalette::Background, \
                           QBrush(QPixmap(":/new/prefix1/img/smoke_desk.png").scaled(1024,600)));
    this->setPalette(palette);
    ui->btnLamp->hide();            //   2怎么把上一个显示出来？
    ui->btnLamp_2->show();
}

void MainWidget::on_btnVideo_clicked()
{
    //更改Frame
    btnLast->show();
    btnLast = ui->btnVideo;
    Temp->hide();
    Temp = V->getFrame();
    Temp->setParent(this);
    Temp->show();
    QPalette palette;
    palette.setBrush(QPalette::Background, \
                           QBrush(QPixmap(":/new/prefix1/img/smoke_desk.png").scaled(1024,600)));
    this->setPalette(palette);
    ui->btnVideo->hide();            //   2怎么把上一个显示出来？
    ui->btnVideo_2->show();
}

void MainWidget::on_pushButton_12_clicked()
{
    //更改Frame
    btnLast->show();
    Temp->hide();
    Temp = ui->frame;
    Temp->setParent(this);
    Temp->show();
    QPalette palette;
    palette.setBrush(QPalette::Background, \
                           QBrush(QPixmap(":/new/prefix1/img/maindesk.png").scaled(1024,600)));
    this->setPalette(palette);
}

void MainWidget::on_pushButton_9_clicked()
{
    //更改Frame
    btnLast->show();
    Temp->hide();
    Temp = alarm->getFrame();
    Temp->setParent(this);
    Temp->show();
    QPalette palette;
    palette.setBrush(QPalette::Background, \
                           QBrush(QPixmap(":/new/prefix1/img/maindesk.png").scaled(1024,600)));
    this->setPalette(palette);
}

void MainWidget::on_pushButton_14_clicked()
{
    QMessageBox::about(this,"提示","欢迎下次使用！\n");
    exit(0);
}

void MainWidget::getStateSignalHandler(int state)
{
    static int state_last = state;
    if(state_last != state) ui->btnLamp->clicked();
    //qDebug()<<"slot: "<<state <<" ";
    //ui->btnLamp->click();
    if(L->flagLamppos == 0)
    {
        if(state & 1)
        {
            system("echo 1 > /sys/devices/platform/leds-gpio/leds/led2/brightness");
            L->posixBtnOn(true);
        }
        else
        {
            system("echo 0 > /sys/devices/platform/leds-gpio/leds/led2/brightness");
            L->posixBtnOn(false);
        }
    }
    if(L->flagLamphome == 0)
    {
        if(state & (1<<1))
        {
            system("echo 1 > /sys/devices/platform/leds-gpio/leds/led3/brightness");
            L->homeBtnOn(true);
        }
        else
        {
            system("echo 0 > /sys/devices/platform/leds-gpio/leds/led3/brightness");
            L->homeBtnOn(false);
        }
    }
    if(L->flagLamporg == 0)
    {
        if(state & (1<<2))
        {
            system("echo 1 > /sys/devices/platform/leds-gpio/leds/led4/brightness");
            L->orgBtnOn(true);
        }
        else
        {
            system("echo 0 > /sys/devices/platform/leds-gpio/leds/led4/brightness");
            L->orgBtnOn(false);
        }
    }
    state_last = state;
}

void MainWidget::getBuzzerStateSignalHandler(int state)
{
        static int state_last = state;
        if(state_last != state) ui->pushButton_9->clicked();
        if(state == 1)
        {
            system("echo 1 > /sys/devices/platform/x6818-beep/state");
            alarm->alarmPressed(true);
        }
        else
        {
            system("echo 0 > /sys/devices/platform/x6818-beep/state");
            alarm->alarmPressed(false);
        }
        state_last = state;
}

