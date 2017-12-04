#include "loginwidget.h"
#include "ui_loginwidget.h"
#include <QPixmap>
#include "rgswidget.h"
#include "chatwidget.h"
#include "protocol.h"
#include <QCryptographicHash>
#include <QMessageBox>

LoginWidget::LoginWidget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWidget)
{
    ui->setupUi(this);
    this->setWindowTitle(QString("登录"));
    this->setWindowIcon(QIcon(":/new/prefix1/img/icon.png"));

    //logo图片
    QPixmap logomap = QPixmap(":/new/prefix1/img/logo.jpg");
    logomap = logomap.scaled(ui->logoLabel->width(), ui->logoLabel->height());
    ui->logoLabel->setPixmap(logomap);

    QPixmap imgmap = QPixmap(":/new/prefix1/img/img.png");
    imgmap = imgmap.scaled(ui->imgLabel->width(), ui->imgLabel->height());
    ui->imgLabel->setPixmap(imgmap);

    //创建套接字
    socket = new QUdpSocket(this);
    socket->bind(0);

    connect(socket, SIGNAL(readyRead()), this, SLOT(readReadSlot()));

    isClicked = false;

    int ret = sqlite3_open("/root/nettalk_huahang/client.sqlite3", &db);
    if (ret != SQLITE_OK) {
        qDebug() << "sqlite3_open";
    }
}

//套接字槽函数
void LoginWidget::readReadSlot()
{
    struct login_st rcvbuf;
    ChatWidget *chat;

    socket->readDatagram((char *)&rcvbuf, sizeof(rcvbuf));
    switch(rcvbuf.status) {
    case LOGIN_STATUS_OK:
        //成功
        chat = new ChatWidget();
        chat->setAttribute(Qt::WA_DeleteOnClose);
        chat->showChat(ui->cntLineEdit->text());
        if (isClicked) {
            //记住密码----》将成功登录的帐号信息存储数据库
            rmbaddrHandler();
        }

        close();
        break;
    case LOGIN_STATUS_FAIL:
        //失败
        if (QMessageBox::warning(this, QString("登录"), QString("用户名或密码错误,重新登录？"), \
                             QMessageBox::Yes, QMessageBox::No) == QMessageBox::No)
            close();
        break;
    default:
        break;
    }
}

int  LoginWidget::rmbaddrHandler()
{
    const char *sql;
    sqlite3_stmt *stmt;
    int ret;
    char *errmsg;

    QString cntStr = ui->cntLineEdit->text();
    QByteArray cntArr = cntStr.toAscii();
    const char *c = cntArr.data();

    QString pwdStr = ui->passwdLineEdit->text();
    QByteArray pwdArr = pwdStr.toAscii();
    const char *p = pwdArr.data();

    sql = "create table if not exists rmbaddr(count text primary key not null, passwd text not null)";
    ret = sqlite3_exec(db, sql, NULL, NULL, &errmsg);
    if (ret != SQLITE_OK) {
        qDebug() << "sqlite3_exec():" << errmsg;
        return -1;
    }
    sql = "select * from rmbaddr where count=?";
    sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    sqlite3_bind_text(stmt, 1, c, -1, NULL);
    ret = sqlite3_step(stmt);
    if (ret != SQLITE_ROW && ret != SQLITE_DONE) {
        qDebug() << "sqlite3_step() error";
        sqlite3_finalize(stmt);
        return -1;
    }
    if (ret == SQLITE_ROW) {
        sql = "update rmbaddr set passwd=? where count=?";
    } else {
        sql = "insert into rmbaddr(passwd, count) values(?, ?)";
    }
    sqlite3_finalize(stmt);
    sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    sqlite3_bind_text(stmt, 1, p, -1, NULL);
    sqlite3_bind_text(stmt, 2, c, -1, NULL);
    ret = sqlite3_step(stmt);
    if (ret != SQLITE_DONE) {
        qDebug() << "sqlite3_step() error";
        sqlite3_finalize(stmt);
        return -1;
    }

    sqlite3_finalize(stmt);

    return 0;
}


LoginWidget::~LoginWidget()
{
    sqlite3_close(db);
    delete ui;
}

void LoginWidget::on_registerPushButton_clicked()
{
    RgsWidget *rgs = new RgsWidget();
    rgs->setAttribute(Qt::WA_DeleteOnClose);

    rgs->show();
}

//登录按钮槽函数
void LoginWidget::on_loginPushButton_clicked()
{
    //当点击登录按钮，获取登录帐号和密码，组织数据包发送给服务器
    struct login_st sndbuf;

    //QString----->c string
    //QString----->QByteArray----->c string
    QString cntStr = ui->cntLineEdit->text();
    QByteArray cntArr = cntStr.toAscii();
    const char *c = cntArr.data();
    strncpy(sndbuf.count, c, SIZE);

    QString pwdStr = ui->passwdLineEdit->text();
    QByteArray pwdArr = pwdStr.toAscii();
    pwdArr = QCryptographicHash::hash(pwdArr, QCryptographicHash::Md5);
    pwdArr = pwdArr.toHex();
    const char *p = pwdArr.data();
    strncpy(sndbuf.passwd, p, SIZE);

    //登录帐号和密码都不能为空
    if (strcmp(c, "") == 0 || strcmp(p, "") == 0)
        return;

    sndbuf.status = -1;

    qDebug() << sndbuf.count << sndbuf.passwd;
    socket->writeDatagram((const char *)&sndbuf, sizeof(sndbuf), \
                          QHostAddress(LOGIN_SERVER_IP), LOGIN_SERVER_PORT);

}

void LoginWidget::on_rpwdRadioButton_clicked(bool checked)
{
    //qDebug() << checked;
    isClicked = checked;
}

//当帐号变化触发槽函数
void LoginWidget::on_cntLineEdit_textChanged(const QString &arg1)
{
    //traval数据库
    const char *sql;
    sqlite3_stmt *stmt;
    int ret;
    const char *getp;

    QByteArray cntArr = arg1.toAscii();
    const char *c = cntArr.data();

    qDebug() << c;

    sql = "select * from rmbaddr where count=?";
    sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    sqlite3_bind_text(stmt, 1, c, -1, NULL);
    ret = sqlite3_step(stmt);
    if (ret != SQLITE_ROW && ret != SQLITE_DONE) {
        qDebug() << "sqlite3_step() error";
        sqlite3_finalize(stmt);
        return;
    }
    if (ret == SQLITE_ROW) {
        getp = (const char *)sqlite3_column_text(stmt, 1);
        qDebug() << getp;
        ui->passwdLineEdit->setText(QString(getp));
    } else
        ui->passwdLineEdit->clear();
    sqlite3_finalize(stmt);
}

