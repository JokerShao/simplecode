#include "mainpage.h"
#include "ui_mainpage.h"
#include "QPixmap"
#include "QDateTime"

#include "QJsonParseError"
#include "QJsonObject"
#include "QJsonDocument"

//当服务器有回应的时候调用 json
void MainPage::recvReplyHandler(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray b = reply->readAll();
        qDebug() << b;
        QJsonParseError jsonpe;
        QJsonDocument json = QJsonDocument::fromJson(b, &jsonpe);
        QJsonObject obj = json.object();
        if (obj.contains(QString("value"))) {
            //通过判断sensor_id键所对应的值便可知道开关的编号
            if (obj.take("sensor_id").toString() == QString("409822")) {
                QJsonValue jsonValue = obj.take("value");
                //recvStateHandler(4, jsonValue.toInt());
            }
            //qDebug() << jsonValue.toDouble();
        }
    }
}

MainPage::MainPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainPage)
{
    ui->setupUi(this);

    ui->allBackLabel->setPixmap(QPixmap(QString("/abc/images/maindesk1.png")));
    ui->backLabel->setPixmap(QPixmap(QString("/abc/images/temp_desk.png")));
    ui->lampBackLabel->setPixmap(QPixmap(QString("/abc/images/lamp_desk.png")));
    ui->testBackLabel->setPixmap(QPixmap(QString("/abc/images/air_condition_desk.png")));

    ui->pushButton_26->setIcon(QIcon(QString("/abc/images/buzzer_off.ico")));
    ui->pushButton_26->setIconSize(ui->pushButton_26->size());
    ui->pushButton_26->setFlat(true);

    setFixedSize(1024, 600);

    //灯光
    ui->tempButton->setIcon(QIcon(QString("/abc/images/lamp_btn.png")));
    ui->tempButton->setIconSize(ui->tempButton->size());

    //温度
    ui->pushButton_2->setIcon(QIcon(QString("/abc/images/temp_btn.png")));
    ui->pushButton_2->setIconSize(ui->pushButton_2->size());

    //湿度
    ui->pushButton_3->setIcon(QIcon(QString("/abc/images/humidity_btn.png")));
    ui->pushButton_3->setIconSize(ui->pushButton_3->size());

    //视频
    ui->pushButton_4->setIcon(QIcon(QString("/abc/images/camera_btn.png")));
    ui->pushButton_4->setIconSize(ui->pushButton_4->size());

    //窗帘
    ui->pushButton_5->setIcon(QIcon(QString("/abc/images/curtain_btn.png")));
    ui->pushButton_5->setIconSize(ui->pushButton_5->size());

    //空调
    ui->pushButton_6->setIcon(QIcon(QString("/abc/images/air_condition_btncam.png")));
    ui->pushButton_6->setIconSize(ui->pushButton_6->size());

    //灯按钮
    ui->pushButton->setIcon(QIcon(QString("/abc/images/lamp_off.png")));
    ui->pushButton->setIconSize(ui->pushButton->size());
    ui->pushButton_11->setIcon(QIcon(QString("/abc/images/lamp_off.png")));
    ui->pushButton_11->setIconSize(ui->pushButton->size());
    ui->pushButton_12->setIcon(QIcon(QString("/abc/images/lamp_off.png")));
    ui->pushButton_12->setIconSize(ui->pushButton->size());
    ui->pushButton_13->setIcon(QIcon(QString("/abc/images/lamp_off.png")));
    ui->pushButton_13->setIconSize(ui->pushButton->size());
    ui->pushButton_14->setIcon(QIcon(QString("/abc/images/lamp_off.png")));
    ui->pushButton_14->setIconSize(ui->pushButton->size());
    ui->pushButton_15->setIcon(QIcon(QString("/abc/images/lamp_off.png")));
    ui->pushButton_15->setIconSize(ui->pushButton->size());
    ui->pushButton_16->setIcon(QIcon(QString("/abc/images/lamp_off.png")));
    ui->pushButton_16->setIconSize(ui->pushButton->size());
    ui->pushButton_17->setIcon(QIcon(QString("/abc/images/lamp_off.png")));
    ui->pushButton_17->setIconSize(ui->pushButton->size());

    ui->lampFrame->setVisible(false);
    ui->testFrame->setVisible(false);
    ui->tempFrame->setVisible(false);

    manager = new QNetworkAccessManager(this);
    yeelinkRequest.setRawHeader(QString("U-ApiKey").toLatin1(), QString("cc18f9d60f96f69d2465a34258dcd485").toLatin1());
    yeelinkRequest.setUrl(QUrl(QString("http://api.yeelink.net/v1.1/device/359638/sensor/409822/datapoints")));
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(recvReplyHandler(QNetworkReply*)));

    timerHandler();
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(timerHandler()));
    timer->start(1000);

//    GetStateThread *g = new GetStateThread();
//    connect(g, SIGNAL(stateSignal(int)), this, SLOT(recvStateSingalHandler(int)));
//    g->start();
}

//void MainPage::recvStateSingalHandler(int state)
//{
//    if (state) {
//        on_pushButton_26_pressed();
//    } else {
//        on_pushButton_26_released();
//    }
//}

MainPage::~MainPage()
{
    delete ui;
}

//灯光
void MainPage::on_tempButton_clicked()
{
    ui->testFrame->setVisible(false);
    ui->tempFrame->setVisible(false);
    ui->lampFrame->setVisible(true);
    ui->lcdNumber->setVisible(false);
}

//系统测试
void MainPage::on_pushButton_8_clicked()
{
    ui->lampFrame->setVisible(false);
    ui->tempFrame->setVisible(false);
    ui->testFrame->setVisible(true);
    ui->lcdNumber->setVisible(false);
}

//温度
void MainPage::on_pushButton_2_clicked()
{
    ui->lampFrame->setVisible(false);
    ui->tempFrame->setVisible(true);
    ui->testFrame->setVisible(false);
    ui->lcdNumber->setVisible(false);
}

//返回
void MainPage::on_pushButton_10_clicked()
{
    ui->lampFrame->setVisible(false);
    ui->tempFrame->setVisible(false);
    ui->testFrame->setVisible(false);
    ui->lcdNumber->setVisible(true);
}

void MainPage::timerHandler()
{
    QDateTime d = QDateTime::currentDateTime();
    ui->lcdNumber->display(d.toString(QString("yyyy-MM-dd hh:mm:ss")));

    static int count = 0;
    static double temp = 20.5;

    count++;
    if (count == 15) {
        temp += 2.5;
        if (temp >= 40) temp = 20.5;

        count = 0;

        //构建json数据
        QJsonObject json;
        json.insert("value", temp);
        QJsonDocument document;
        document.setObject(json);
        //把json数据转换为字符数组
        QByteArray byte_array = document.toJson(QJsonDocument::Compact);
        QNetworkRequest request;
        //设置请求的头
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json;charset=utf-8");
        request.setHeader(QNetworkRequest::ContentLengthHeader, "100");
        request.setRawHeader(QString("U-ApiKey").toLatin1(), QString("cc18f9d60f96f69d2465a34258dcd485").toLatin1());
        request.setRawHeader("Connection","close");
        //设置请求url
        request.setUrl(QString("http://api.yeelink.net/v1.1/device/359638/sensor/409777/datapoints"));
        //发送post请求
        manager->post(request, byte_array);
    }

    manager->get(yeelinkRequest);
}

//testFram button
void MainPage::on_pushButton_26_pressed()
{
    //打开蜂鸣器
    buzzerOps.buzzerOn();
}

void MainPage::on_pushButton_26_released()
{
    //关闭蜂鸣器
    buzzerOps.buzzerOff();
}



