#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QDialog>
#include <QUdpSocket>
#include "sqlite3.h"

namespace Ui {
class LoginWidget;
}

class LoginWidget : public QDialog
{
    Q_OBJECT

public:
    explicit LoginWidget(QWidget *parent = 0);
    ~LoginWidget();

private slots:
    void on_registerPushButton_clicked();

    void on_loginPushButton_clicked();

    void readReadSlot();

    void on_rpwdRadioButton_clicked(bool checked);

    void on_cntLineEdit_textChanged(const QString &arg1);

private:
    Ui::LoginWidget *ui;
    QUdpSocket *socket;
    bool isClicked;
    sqlite3 *db;
    int rmbaddrHandler();

};

#endif // LOGINWIDGET_H
