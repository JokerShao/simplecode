#ifndef TEMPWIDGET_H
#define TEMPWIDGET_H

#include <QWidget>
#include <QFrame>

namespace Ui {
class TempWidget;
}

class TempWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TempWidget(QWidget *parent = 0);
    QFrame *getFrame();
    ~TempWidget();

private:
    Ui::TempWidget *ui;
};

#endif // TEMPWIDGET_H
