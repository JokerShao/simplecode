#include "homepage.h"
#include "ui_homepage.h"
#include "QtWebEngineWidgets/QtWebEngineWidgets"
#include <QNetworkReply>
#include "QPixmap"
#include "QDateTime"

HomePage::HomePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomePage)
{
    ui->setupUi(this);

    QWebEngineView *view = new QWebEngineView(this);
    view->setWindowFlags(Qt::FramelessWindowHint);
    view->setGeometry(10, 10, 640, 480);
    view->setUrl(QUrl(QString("http://192.168.200.105:8080/?action=stream")));
    view->show();

    //创建网络访问对象
    m = new QNetworkAccessManager();
    //绑定信号与槽，请求完成后调用槽函数
    connect(m, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
}

HomePage::~HomePage()
{
    delete ui;
}

void HomePage::on_pushButton_clicked()
{
    //从下面的url下载一张图片存储到文件系统
    // /home/zyli/bhht/2017-07-011_15:05:29.jpg
    //http://192.168.200.105:8080/?action=snapshot
    //创建网络请求
    QNetworkRequest request;
    //设置请求url
    request.setUrl(QUrl(QString("http://192.168.200.105:8080/?action=snapshot")));
    //开始请求
    m->get(request);
}

void HomePage::replyFinished(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        QPixmap p;
        p.loadFromData(reply->readAll());
        // /home/zyli/bhht/2017-07-011_15:05:29.jpg
        QPixmap p1 = p.scaled(ui->label->size());
        ui->label->setPixmap(p1);
        QString name;
        name.clear();
        name.append("/home/zyli/bhht/");
        QDateTime t = QDateTime::currentDateTime();
        name.append(t.toString(QString("yyyy-MM-dd_hh:mm:ss")));
        name.append(".jpg");
        p.save(name);
    }
}




