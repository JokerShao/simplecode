#ifndef VIDEOWIDGET_H
#define VIDEOWIDGET_H

#include <QWidget>
#include <QFrame>

namespace Ui {
class VideoWidget;
}

class VideoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit VideoWidget(QWidget *parent = 0);
    QFrame *getFrame();
    ~VideoWidget();

private:
    Ui::VideoWidget *ui;
};

#endif // VIDEOWIDGET_H
