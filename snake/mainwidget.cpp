#include "mainwidget.h"
#include <QIcon>
#include <QPalette>
#include <QBrush>
#include <QFont>
#include <QMessageBox>
#include <QDebug>

mainWidget::mainWidget(QWidget *parent)
    : QWidget(parent)
{
    this->resize(480, 270);
    this->setMaximumSize(480, 270);
    this->setMinimumSize(480, 270);
    this->setWindowIcon(QIcon(":/new/prefix1/img/icon.png"));
    this->setWindowTitle(QString("贪吃蛇"));

    //创建调色板类-----》加背jing图片
    QPalette palette;
    palette.setBrush(QPalette::Background, \
                     QBrush(QPixmap(":/new/prefix1/img/back.jpg").scaled(480,270)));
    this->setPalette(palette);

    startBtn = new QPushButton(this);//malloc
    startBtn->setGeometry(250, 170, 75, 75);
    startBtn->setIcon(QIcon(":/new/prefix1/img/start.png"));
    startBtn->setIconSize(QSize(75,75));
    startBtn->setFlat(true);

    exitBtn = new QPushButton(this);
    exitBtn->setGeometry(350, 170, 75,75);
    exitBtn->setIcon(QIcon(":/new/prefix1/img/quit.png"));
    exitBtn->setIconSize(QSize(75,75));
    exitBtn->setFlat(true);

    QFont font;
    font.setPixelSize(20);
    font.setBold(true);

    label = new QLabel(this);
    label->setText(QString("游戏说明：xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"));
    label->setGeometry(10, 10, 400, 50);
    label->setFont(font);

    //信号与槽
    connect(startBtn, SIGNAL(clicked()), this, SLOT(on_startBtn_slot()));
    connect(exitBtn, SIGNAL(clicked()), this, SLOT(on_exitBtn_slot()));

}

mainWidget::~mainWidget()
{
    delete startBtn;
    delete exitBtn;
    delete label;
}

void mainWidget::on_startBtn_slot()
{
    //qDebug() << "on_startBtn_slot";
    g = new GameWidget(this);
    g->show();
}

void mainWidget::on_exitBtn_slot()
{
    if (QMessageBox::question(this, QString("退出游戏"), QString("确定要退出吗？"), \
                          QMessageBox::Yes, QMessageBox::No) == QMessageBox::Yes) {
        exit(0);
    }
}

