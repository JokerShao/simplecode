#include "gamewidget.h"
#include <QPalette>
#include <QBrush>
#include <QDebug>
#include <QFont>
#include <QPainter>
#include <QRect>

#define ROW 13
#define COL  16

GameWidget::GameWidget(QWidget *parent) :
    QWidget(parent)
{
    //qDebug() << "gameWidget";
    this->setAutoFillBackground(true);
    this->resize(480, 270);
    this->setMaximumSize(480, 270);
    this->setMinimumSize(480, 270);
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(\
                         QPixmap(":/new/prefix1/img/green.jpg").scaled(480, 270)));
    this->setPalette(palette);

    upBtn = new QPushButton(this);
    upBtn->setText(QString("↑"));
    upBtn->setGeometry(380, 90, 40, 30);
    downBtn = new QPushButton(QString("↓"), this);
    downBtn->setGeometry(380, 170, 40, 30);
    leftBtn = new QPushButton(QString("←"), this);
    leftBtn->setGeometry(340, 130, 40, 30);
    rightBtn = new QPushButton(QString("→"), this);
    rightBtn->setGeometry(420, 130, 40, 30);
    startBtn = new QPushButton(QString("开始"), this);
    startBtn->setGeometry(350, 220, 40, 30);
    backBtn = new QPushButton(QString("返回"), this);
    backBtn->setGeometry(410, 220, 40, 30);

    score = level = 0;
    scoreLabel = new QLabel(QString("分数:"), this);
    scoreLabel->setGeometry(325, 1, 60, 30);
    levelLabel = new QLabel(QString("等级:"), this);
    levelLabel->setGeometry(325, 30, 60, 30);

    QFont font;
    font.setPixelSize(20);
    font.setBold(true);
    scoreStr = QString::number(score);
    levelStr = QString::number(level);
    scoreShow = new QLabel(this);
    scoreShow->setText(scoreStr);
    scoreShow->setGeometry(385, 1, 60, 30);
    scoreShow->setFont(font);
    levelshow = new QLabel(this);
    levelshow->setText(levelStr);
    levelshow->setGeometry(385, 30, 60, 30);
    levelshow->setFont(font);

    //产生蛇头和食物的位置
    srand(time(NULL));
    foodx = rand() % COL;
    foody = rand() % ROW;
    snake[0][0] = rand() % COL;
    snake[0][1] = rand() % ROW;
    while (1) {
        if (foodx == snake[0][0] && foody == snake[0][1]) {
            foodx = rand() % COL;
            foody = rand() % ROW;
        } else
            break;
    }
    foodcount = 0;
    direction = rand() % DIRECTION_NR;

    //
    tm = new QTimer(this);
    tm->setInterval(500);
    connect(startBtn, SIGNAL(clicked()), this, SLOT(startBtnSlot()));
    connect(tm, SIGNAL(timeout()), this, SLOT(timeoutSlot()));

    //连接方向按钮的信号与槽
    connect(upBtn, SIGNAL(clicked()), this, SLOT(onUpSlot()));
    connect(downBtn, SIGNAL(clicked()), this, SLOT(onDownSlot()));
    connect(leftBtn, SIGNAL(clicked()), this, SLOT(onLeftSlot()));
    connect(rightBtn, SIGNAL(clicked()), this, SLOT(onRightSlot()));

    //连接按键信号与槽
    connect(this, SIGNAL(upsignal()), upBtn, SLOT(click()));
    connect(this, SIGNAL(downsignal()), downBtn, SLOT(click()));
    connect(this, SIGNAL(leftsignal()), leftBtn, SLOT(click()));
    connect(this, SIGNAL(rightsignal()), rightBtn, SLOT(click()));

}

void GameWidget::startBtnSlot()
{
    static int i = 1;
    if (i % 2)
        tm->start();
    else
        tm->stop();
    i++;
}

void GameWidget::timeoutSlot()
{
    int i;

    //判断蛇是否吃到食物
    if (foodx == snake[0][0] && foody == snake[0][1]) {
        foodcount ++;
        srand(time(NULL));
        foodx = rand() % COL;
        foody = rand() % ROW;
        i = 0;
        while (i <= foodcount) {
            if (foodx == snake[i][0] && foody == snake[i][1]) {
                srand(time(NULL));
                foodx = rand() % COL;
                foody = rand() % ROW;
                i = 0;
            }
            i++;
        }
        score ++;
        scoreStr = QString::number(score);
        scoreShow->setText(scoreStr);
        switch(score/10) {
        case 1:
            level=1;
            break;
        case 2:
            level=2;
            break;
        case 5:
            level=3;
            break;
        default:
            break;
        }
        levelStr = QString::number(level);
        levelshow->setText(levelStr);
    }

    //蛇运动
    for (int i = foodcount; i > 0; i--) {
        snake[i][0] = snake[i-1][0];
        snake[i][1] = snake[i-1][1];
    }
    switch(direction) {
    case DIRECTION_UP:
        snake[0][1] --;
        break;
    case DIRECTION_DOWN:
        snake[0][1] ++;
        break;
    case DIRECTION_LEFT:
        snake[0][0] --;
        break;
    case DIRECTION_RIGHT:
        snake[0][0] ++;
        break;
    }

    //蛇是否碰到蛇身

    //蛇是否碰到边界


    this->update();//paintEvent();
}

//画图
void GameWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    //画格子
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            painter.drawRect(QRect(j*20, i*20, 20, 20));
        }
    }

    //画食物
    painter.drawImage(foodx*20, foody*20, \
                      QImage(":/new/prefix1/img/apple.png").scaled(20,20));
    //画蛇头
    switch(direction) {
    case DIRECTION_UP:
        painter.drawImage(snake[0][0]*20, snake[0][1]*20, \
                          QImage(":/new/prefix1/img/headup.png").scaled(20, 20));
        break;
    case DIRECTION_DOWN:
        painter.drawImage(snake[0][0]*20, snake[0][1]*20, \
                          QImage(":/new/prefix1/img/headdown.png").scaled(20, 20));
        break;
    case DIRECTION_LEFT:
        painter.drawImage(snake[0][0]*20, snake[0][1]*20, \
                          QImage(":/new/prefix1/img/headleft.png").scaled(20, 20));
        break;
    case DIRECTION_RIGHT:
        painter.drawImage(snake[0][0]*20, snake[0][1]*20, \
                          QImage(":/new/prefix1/img/headright.png").scaled(20, 20));
        break;
    default:
        break;
    }
    //画蛇身
    for (int i = 1; i <= foodcount; i++) {
        if (foodcount == i) {
            //蛇尾
            if(snake[i][0] == snake[i-1][0] && snake[i][1] == snake[i-1][1]+1) {
                painter.drawImage(snake[foodcount][0]*20, snake[foodcount][1]*20,\
                                  QImage(":/new/prefix1/img/tailup.png").scaled(20, 20));
                break;
            } else if(snake[i][0] == snake[i-1][0] && snake[i][1] == snake[i-1][1]-1) {
                painter.drawImage(snake[foodcount][0]*20, snake[foodcount][1]*20,\
                                  QImage(":/new/prefix1/img/taildown.png").scaled(20, 20));
                break;
            }else if (snake[i][0] == snake[i-1][0]+1 && snake[i][1] == snake[i-1][1]) {
                painter.drawImage(snake[foodcount][0]*20, snake[foodcount][1]*20,\
                                  QImage(":/new/prefix1/img/tailleft.png").scaled(20, 20));
                break;
            }else if(snake[i][0] == snake[i-1][0]-1 && snake[i][1] == snake[i-1][1]) {
                painter.drawImage(snake[foodcount][0]*20, snake[foodcount][1]*20,\
                                  QImage(":/new/prefix1/img/tailright.png").scaled(20, 20));
                break;
            }
        } else {
            if (((snake[i][0] == snake[i-1][0]+1 && snake[i][1] == snake[i-1][1]) &&\
                 (snake[i][0] == snake[i+1][0] && snake[i][1] == snake[i+1][1]-1)) || \
                    ((snake[i][0] == snake[i+1][0]+1 && snake[i][1] == snake[i+1][1]) &&\
                     (snake[i][0] == snake[i-1][0] && snake[i][1] == snake[i-1][1]-1))) {
                //拐弯右上
                painter.drawImage(snake[i][0]*20, snake[i][1]*20, \
                                  QImage(":/new/prefix1/img/tr_corner.png").scaled(20, 20));
            } else if (((snake[i][0] == snake[i-1][0]+1 && snake[i][1] == snake[i-1][1]) &&\
                        (snake[i][0] == snake[i+1][0] && snake[i][1] == snake[i+1][1]+1)) || \
                       ((snake[i][0] == snake[i+1][0]+1 && snake[i][1] == snake[i+1][1]) &&\
                        (snake[i][0] == snake[i-1][0] && snake[i][1] == snake[i-1][1]+1))) {
                //拐弯右下
                painter.drawImage(snake[i][0]*20, snake[i][1]*20, \
                                  QImage(":/new/prefix1/img/br_corner.png").scaled(20, 20));
            }else if (((snake[i][0] == snake[i-1][0]-1 && snake[i][1] == snake[i-1][1]) &&\
                       (snake[i][0] == snake[i+1][0] && snake[i][1] == snake[i+1][1]-1)) || \
                      ((snake[i][0] == snake[i+1][0]-1 && snake[i][1] == snake[i+1][1]) &&\
                       (snake[i][0] == snake[i-1][0] && snake[i][1] == snake[i-1][1]-1))) {
                //拐弯左上
                painter.drawImage(snake[i][0]*20, snake[i][1]*20, \
                                  QImage(":/new/prefix1/img/tl_corner.png").scaled(20, 20));

            }else if (((snake[i][0] == snake[i-1][0]-1 && snake[i][1] == snake[i-1][1]) &&\
                       (snake[i][0] == snake[i+1][0] && snake[i][1] == snake[i+1][1]+1)) || \
                      ((snake[i][0] == snake[i+1][0]-1 && snake[i][1] == snake[i+1][1]) &&\
                       (snake[i][0] == snake[i-1][0] && snake[i][1] == snake[i-1][1]+1))) {
                //拐弯左下
                painter.drawImage(snake[i][0]*20, snake[i][1]*20, \
                                  QImage(":/new/prefix1/img/bl_corner.png").scaled(20, 20));
            } else if (snake[i][0] == snake[i-1][0] && snake[i][0] == snake[i+1][0]){
                painter.drawImage(snake[i][0]*20, snake[i][1]*20, \
                                  QImage(":/new/prefix1/img/v_body.png").scaled(20, 20));
            } else  {
                painter.drawImage(snake[i][0]*20, snake[i][1]*20, \
                                  QImage(":/new/prefix1/img/h_body.png").scaled(20, 20));
            }
        }
    }


}

void GameWidget::onUpSlot()
{
    if (direction == DIRECTION_DOWN)
        return;
    else
        direction = DIRECTION_UP;
}

void GameWidget::onDownSlot()
{
    if (direction == DIRECTION_UP)
        return;
    else
        direction = DIRECTION_DOWN;
}
void GameWidget::onLeftSlot()
{
    if (direction == DIRECTION_RIGHT)
        return;
    else
        direction = DIRECTION_LEFT;
}
void GameWidget::onRightSlot()
{
    if(direction == DIRECTION_LEFT)
        return;
    else
        direction = DIRECTION_RIGHT;
}
//按键
void GameWidget::keyPressEvent(QKeyEvent *k)
{
    int key = k->key();
   // qDebug() << key;
    switch (key) {
    case Qt::Key_A:
        emit leftsignal();
        break;
    case Qt::Key_S:
        emit downsignal();
        break;
    case Qt::Key_W:
        emit upsignal();
        break;
    case Qt::Key_D:
        emit rightsignal();
        break;
    default:
        break;
    }

}

