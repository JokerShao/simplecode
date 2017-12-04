#include "videowidget.h"
#include "ui_videowidget.h"
#include <QtWebEngineWidgets/QtWebEngineWidgets>

VideoWidget::VideoWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VideoWidget)
{
    ui->setupUi(this);

    QWebEngineView *view = new QWebEngineView(ui->frame);
    view->setWindowFlags(Qt::FramelessWindowHint);
    view->setGeometry(0, 0, 871, 520);
    view->setUrl(QUrl(QString("http://127.0.0.1:8080/?action=stream")));
    view->show();
}

QFrame *VideoWidget::getFrame()
{
    return ui->frame;
}

VideoWidget::~VideoWidget()
{
    delete ui;
}
