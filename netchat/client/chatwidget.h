#ifndef CHATWIDGET_H
#define CHATWIDGET_H

#include <QDialog>
#include <QTimer>
#include <QUdpSocket>
#include <QModelIndex>

namespace Ui {
class ChatWidget;
}

class ChatWidget : public QDialog
{
    Q_OBJECT

public:
    explicit ChatWidget(QWidget *parent = 0);
    ~ChatWidget();
    void showChat(QString str);

private slots:
    void on_addFrdPushButton_clicked();
    void timeoutSlot();
    void readyReadHandler();

    void on_sendPushButton_clicked();

    void on_treeWidget_doubleClicked(const QModelIndex &index);

private:
    Ui::ChatWidget *ui;
    QTimer *tm;
    QString curCount;
    QUdpSocket *socket;

};

#endif // CHATWIDGET_H
