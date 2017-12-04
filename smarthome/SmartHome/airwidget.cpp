#include "airwidget.h"
#include "ui_airwidget.h"

AirWidget::AirWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AirWidget)
{
    ui->setupUi(this);
}

QFrame *AirWidget::getFrame()
{
    return ui->frame;
}

AirWidget::~AirWidget()
{
    delete ui;
}
