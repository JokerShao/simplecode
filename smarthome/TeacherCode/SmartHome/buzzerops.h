#ifndef BUZZEROPS_H
#define BUZZEROPS_H

#include <QObject>

class BuzzerOps : public QObject
{
    Q_OBJECT
public:
    explicit BuzzerOps(QObject *parent = 0);
    void buzzerOn();
    void buzzerOff();

signals:

public slots:
};

#endif // BUZZEROPS_H
