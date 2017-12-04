#ifndef RGSWIDGET_H
#define RGSWIDGET_H

#include <QDialog>
#include <QUdpSocket>

namespace Ui {
class RgsWidget;
}

class RgsWidget : public QDialog
{
    Q_OBJECT

public:
    explicit RgsWidget(QWidget *parent = 0);
    ~RgsWidget();

private slots:
    void on_pushButton_clicked();
    void readReadSlot();

private:
    Ui::RgsWidget *ui;
    QUdpSocket *socket;
};

#endif // RGSWIDGET_H
