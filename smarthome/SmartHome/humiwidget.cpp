#include "humiwidget.h"
#include "ui_humiwidget.h"

HumiWidget::HumiWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HumiWidget)
{
    ui->setupUi(this);
}

QFrame *HumiWidget::getFrame()
{
    return ui->frame;
}

HumiWidget::~HumiWidget()
{
    delete ui;
}
