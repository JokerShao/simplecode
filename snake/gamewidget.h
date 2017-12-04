#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QString>
#include <QTimer>
#include <QKeyEvent>

#define SNAKESIZE             200
#define DIRECTION_NR        4
#define DIRECTION_UP        0
#define DIRECTION_DOWN   1
#define DIRECTION_LEFT     2
#define DIRECTION_RIGHT   3

class GameWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GameWidget(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *);

signals:
    void upsignal();
    void downsignal();
    void leftsignal();
    void rightsignal();

private slots:
    void startBtnSlot();
    void timeoutSlot();
    void onUpSlot();
    void onDownSlot();
    void onLeftSlot();
    void onRightSlot();
private:
    QPushButton *upBtn;
    QPushButton *downBtn;
    QPushButton *leftBtn;
    QPushButton *rightBtn;
    QPushButton *startBtn;
    QPushButton *backBtn;
    QLabel *scoreLabel;
    QLabel *levelLabel;
    QLabel *scoreShow;
    QLabel *levelshow;
    int score, level;
    QString scoreStr, levelStr;
    int foodx, foody;
    int snake[SNAKESIZE][2];
    int foodcount;
    int direction;
    QTimer *tm;
};

#endif // GAMEWIDGET_H
