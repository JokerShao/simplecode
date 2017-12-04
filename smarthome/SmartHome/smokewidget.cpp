#include "smokewidget.h"
#include "ui_smokewidget.h"

SmokeWidget::SmokeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SmokeWidget)
{
    ui->setupUi(this);
}

QFrame *SmokeWidget::getFrame()
{
    return ui->frame;
}

SmokeWidget::~SmokeWidget()
{
    delete ui;
}
