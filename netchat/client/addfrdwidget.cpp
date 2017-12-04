#include "addfrdwidget.h"
#include "ui_addfrdwidget.h"
#include "protocol.h"
#include <QMessageBox>
#include <QTreeWidgetItem>

AddFrdWidget::AddFrdWidget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddFrdWidget)
{
    ui->setupUi(this);

    this->setWindowTitle(QString("添加好友"));

    socket = new QUdpSocket(this);
    socket->bind(0);
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyReadSlot()));

}
//套接字槽函数
void AddFrdWidget::readyReadSlot()
{
    struct addfrd_st rcvbuf;
    QTreeWidgetItem *item;

    socket->readDatagram((char *)&rcvbuf, sizeof(rcvbuf));
    qDebug() << rcvbuf.status;
    switch(rcvbuf.status) {
    case ADDFRD_STATUS_ALREADY:
        if (QMessageBox::question(this, QString("好友状态"), \
                              QString("对方已经是您的好友，是否重新添加?"),\
                              QMessageBox::Yes, QMessageBox::No) == QMessageBox::No)
            close();
        else {
            ui->lineEdit->clear();
        }

        break;
    case ADDFRD_STATUS_NOEXIST:
        if (QMessageBox::question(this, QString("好友状态"), \
                              QString("帐号不存在，是否重新添加?"),\
                              QMessageBox::Yes, QMessageBox::No) == QMessageBox::No)
            close();
        else {
            ui->lineEdit->clear();
        }
        break;
    case ADDFRD_STATUS_OK:
        QMessageBox::about(this, QString("好友状态"), QString("恭喜你！成功添加"));
        item = new QTreeWidgetItem(treeWidget);
        item->setText(0, rcvbuf.dcount);
        item->setIcon(0, QIcon(":/new/prefix1/img/icon.png"));
        close();
        break;
    default:
        break;
    }

}

void AddFrdWidget::setTreeWidget(QTreeWidget *widget)
{
    treeWidget =  widget;
}

AddFrdWidget::~AddFrdWidget()
{
    delete ui;
}

void AddFrdWidget::setCount(QString str)
{
    myCount = str;
}

//确认添加按钮的槽函数
void AddFrdWidget::on_pushButton_clicked()
{
    //获取添加好友的帐号---》组织数据包发送服务器
    struct addfrd_st sndbuf;//scount dcount

    QByteArray sarr = myCount.toAscii();
    const char *s = sarr.data();
    strncpy(sndbuf.scount, s, SIZE);

    QString dstr = ui->lineEdit->text();
    QByteArray darr = dstr.toAscii();
    const char *d = darr.data();
    strncpy(sndbuf.dcount, d, SIZE);

    socket->writeDatagram((const char *)&sndbuf, sizeof(sndbuf), \
                          QHostAddress(ADDFRD_SERVER_IP), ADDFRD_SERVER_PORT);
}

