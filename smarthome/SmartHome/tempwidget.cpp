#include "tempwidget.h"
#include "ui_tempwidget.h"

TempWidget::TempWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TempWidget)
{
    ui->setupUi(this);
}

QFrame *TempWidget::getFrame()
{
    return ui->frame;
}

TempWidget::~TempWidget()
{
    delete ui;
}
