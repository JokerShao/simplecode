#ifndef ADDFRDWIDGET_H
#define ADDFRDWIDGET_H

#include <QDialog>
#include <QUdpSocket>
#include <QTreeWidget>

namespace Ui {
class AddFrdWidget;
}

class AddFrdWidget : public QDialog
{
    Q_OBJECT

public:
    explicit AddFrdWidget(QWidget *parent = 0);
    ~AddFrdWidget();
    void setCount(QString str);
    void setTreeWidget(QTreeWidget *widget);

private slots:
    void on_pushButton_clicked();

    void readyReadSlot();

private:
    Ui::AddFrdWidget *ui;
    QString myCount;
    QUdpSocket *socket;
    QTreeWidget *treeWidget;
};

#endif // ADDFRDWIDGET_H
