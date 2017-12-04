#include "homewidget.h"
#include "ui_homewidget.h"
#include "QtWebEngineWidgets/QtWebEngineWidgets"

HomeWidget::HomeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomeWidget)
{
    ui->setupUi(this);

    QWebEngineView *view = new QWebEngineView(this);
    view->setWindowFlags(Qt::FramelessWindowHint);
    view->setGeometry(50, 50, 900, 600);
    view->setUrl(QUrl(QString("http://www.baidu.com")));
    view->show();
}

HomeWidget::~HomeWidget()
{
    delete ui;
}
