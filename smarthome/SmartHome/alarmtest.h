#ifndef ALARMTEST_H
#define ALARMTEST_H

#include <QWidget>
#include <QFrame>

namespace Ui {
class AlarmTest;
}

class AlarmTest : public QWidget
{
    Q_OBJECT

public:
    explicit AlarmTest(QWidget *parent = 0);
    QFrame *getFrame();
    void alarmPressed(bool p);
    ~AlarmTest();

private slots:
    void on_pushButton_pressed();

    void on_pushButton_released();

private:
    Ui::AlarmTest *ui;
};

#endif // ALARMTEST_H
