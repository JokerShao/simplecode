//#include "chatwidget.h"
//#include "ui_chatwidget.h"

//ChatWidget::ChatWidget(QWidget *parent) :
//    QDialog(parent),
//    ui(new Ui::ChatWidget)
//{
//    ui->setupUi(this);
//}

//ChatWidget::~ChatWidget()
//{
//    delete ui;
//}

#include "chatwidget.h"
#include "ui_chatwidget.h"
#include "addfrdwidget.h"
#include <QDateTime>
#include "protocol.h"
#include <QTreeWidgetItem>

ChatWidget::ChatWidget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChatWidget)
{
    ui->setupUi(this);
    this->setWindowTitle(QString("正在聊天"));
    this->setWindowIcon(QIcon(":/new/prefix1/img/icon.png"));

    //添加好友按钮的图标
    ui->addFrdPushButton->setIcon(QIcon(":/new/prefix1/img/add.png"));
    ui->addFrdPushButton->setIconSize(QSize(ui->addFrdPushButton->width(), \
                                            ui->addFrdPushButton->height()));
    ui->addFrdPushButton->setFlat(true);
    //设置按钮图标
    ui->setPushButton->setIcon(QIcon(":/new/prefix1/img/setup.png"));
    ui->setPushButton->setIconSize(QSize(ui->setPushButton->width(), \
                                         ui->setPushButton->height()));
    ui->setPushButton->setFlat(true);

    //创建时钟对象
    tm = new QTimer(this);
    tm->start(1000);
    connect(tm, SIGNAL(timeout()), this, SLOT(timeoutSlot()));

    socket = new QUdpSocket(this);
    socket->bind(0);
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyReadHandler()));
}

//套接字槽函数
void ChatWidget::readyReadHandler()
{
    struct chat_st rcvbuf;
    QTreeWidgetItem *item;

    socket->readDatagram((char *)&rcvbuf, sizeof(rcvbuf));
    qDebug() << rcvbuf.status;
    switch(rcvbuf.status) {
    case CHAT_STATUS_LIST:
        item = new QTreeWidgetItem(ui->treeWidget);
        item->setText(0, QString(rcvbuf.dcount));
        item->setIcon(0, QIcon(":/new/prefix1/img/icon.png"));
        break;
    case CHAT_STATUS_MSG:
        ui->chatTextEdit->append(QString(rcvbuf.msg));
        break;
    default:
        break;
    }


}

//时钟槽函数
void ChatWidget::timeoutSlot()
{
    QDateTime date = QDateTime::currentDateTime();
    QString dateStr = date.toString(QString("yyyy-MM-dd hh:mm:ss"));
    qDebug() << dateStr;
    ui->lcdNumber->display(dateStr);
}

ChatWidget::~ChatWidget()
{
    delete ui;
}

//添加好友槽函数
void ChatWidget::on_addFrdPushButton_clicked()
{
    AddFrdWidget *add = new AddFrdWidget();
    add->setCount(curCount);
    add->setTreeWidget(ui->treeWidget);
    add->show();
}

//重写show
void ChatWidget::showChat(QString str)
{
    curCount = str;
    timeoutSlot();
    //将成功登录帐号的地址发送给服务器
    struct rmb_st sndbuf;

    QByteArray carr = curCount.toAscii();
    const char *c = carr.data();
    strncpy(sndbuf.count, c, SIZE);

    socket->writeDatagram((const char *)&sndbuf, sizeof(sndbuf), \
                          QHostAddress(RMB_SERVER_IP), RMB_SERVER_PORT);

    show();
}

//发送按钮槽函数
void ChatWidget::on_sendPushButton_clicked()
{
    //将inputTextEdit对象的内容发送服务器，并显示chatTextEdit
    QString inputStr = ui->inputTextEdit->toPlainText();
    ui->chatTextEdit->append(inputStr);
    ui->inputTextEdit->clear();

    struct chat_st sndbuf;

    QByteArray sArr = curCount.toAscii();
    const char *s = sArr.data();
    strncpy(sndbuf.scount, s, SIZE);

    QString dStr = ui->showNameLabel->text();
    QByteArray dArr = dStr.toAscii();
    const char *d = dArr.data();
    strncpy(sndbuf.dcount, d, SIZE);

    QByteArray mArr = inputStr.toAscii();
    const char *m = mArr.data();
    strncpy(sndbuf.msg, m, MSGSIZE);

    socket->writeDatagram((const char *)&sndbuf, sizeof(sndbuf), \
                          QHostAddress(CHAT_SERVER_IP), CHAT_SERVER_PORT);

}
//双击好友列表槽函数
void ChatWidget::on_treeWidget_doubleClicked(const QModelIndex &index)
{
   QTreeWidgetItem *item = ui->treeWidget->currentItem();
   ui->showNameLabel->setText(item->text(0));
   ui->chatTextEdit->clear();
}

