//#include "rgswidget.h"
//#include "ui_rgswidget.h"

//RgsWidget::RgsWidget(QWidget *parent) :
//    QDialog(parent),
//    ui(new Ui::RgsWidget)
//{
//    ui->setupUi(this);
//}

//RgsWidget::~RgsWidget()
//{
//    delete ui;
//}


#include "rgswidget.h"
#include "ui_rgswidget.h"
#include <QString>
#include <QByteArray>
#include <QCryptographicHash>
#include <QDebug>
#include <QMessageBox>
#include "protocol.h"

RgsWidget::RgsWidget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RgsWidget)
{
    ui->setupUi(this);
    this->setWindowTitle(QString("注册"));

    socket = new QUdpSocket(this);
    //qt4
    socket->bind(0);//anyone
    connect(socket, SIGNAL(readyRead()), this, SLOT(readReadSlot()));

}

//套接字槽函数
void RgsWidget::readReadSlot()
{
    struct rgs_st rcvbuf;

    socket->readDatagram((char *)&rcvbuf, sizeof(rcvbuf));
    switch(rcvbuf.status) {
    case REGISTER_STATUS_OK:
        if (QMessageBox::information(this, QString("注册结果"), QString("恭喜你，注册成功！"), \
                                 QMessageBox::Yes) == QMessageBox::Yes) {
            close();
        }
        break;
    case REGISTER_STATUS_FAIL:
        if (QMessageBox::question(this, QString("注册结果"), QString("很遗憾，注册失败, 是否重新注册"),\
                              QMessageBox::Yes, QMessageBox::No) == QMessageBox::No) {

            close();
        } else {
            ui->countLineEdit->clear();
            ui->passwdLineEdit->clear();
        }
        break;
    default:
        break;
    }


}

RgsWidget::~RgsWidget()
{
    delete ui;
}

//注册按钮槽函数
void RgsWidget::on_pushButton_clicked()
{
    //获取注册帐号和密码---》组织数据包---》发送给服务器
    struct rgs_st sndbuf;

    //QString----->c string
    //QString----->QByteArray----->c string
    QString cntStr = ui->countLineEdit->text();
    QByteArray cntArr = cntStr.toAscii();
    const char *c = cntArr.data();
    strncpy(sndbuf.count, c, SIZE);

    QString pwdStr = ui->passwdLineEdit->text();
    QByteArray pwdArr = pwdStr.toAscii();
    pwdArr = QCryptographicHash::hash(pwdArr, QCryptographicHash::Md5);
    pwdArr = pwdArr.toHex();
    const char *p = pwdArr.data();
    strncpy(sndbuf.passwd, p, SIZE);

    //qDebug() << c << p;
    socket->writeDatagram((const char *)&sndbuf, sizeof(sndbuf), \
                          QHostAddress(REGISTER_SERVER_IP), REGISTER_SERVER_PORT);
   // close();

}

