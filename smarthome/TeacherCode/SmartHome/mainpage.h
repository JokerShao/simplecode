#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QWidget>
#include <QPixmap>
#include "QTimer"
#include "buzzerops.h"
#include "getstatethread.h"
#include "QtNetwork/QNetworkAccessManager"
#include "QtNetwork/QNetworkRequest"
#include "QtNetwork/QNetworkReply"

namespace Ui {
class MainPage;
}

class MainPage : public QWidget
{
    Q_OBJECT

public:
    explicit MainPage(QWidget *parent = 0);
    ~MainPage();

private slots:
    void recvReplyHandler(QNetworkReply *reply);

    void on_tempButton_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_10_clicked();

    void timerHandler();

    void on_pushButton_26_pressed();

    void on_pushButton_26_released();

    //void recvStateSingalHandler(int state);
private:
    Ui::MainPage *ui;
    QTimer *timer;
    BuzzerOps buzzerOps;
    QNetworkAccessManager *manager;
    QNetworkRequest yeelinkRequest;
};

#endif // MAINPAGE_H
