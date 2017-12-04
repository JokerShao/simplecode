#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include "gamewidget.h"

class mainWidget : public QWidget
{
    Q_OBJECT

public:
    mainWidget(QWidget *parent = 0);
    ~mainWidget();
private slots:
    void on_startBtn_slot();
    void on_exitBtn_slot();
private:
    QPushButton *startBtn;
    QPushButton *exitBtn;
    QLabel *label;
    GameWidget *g;
};

#endif // MAINWIDGET_H
