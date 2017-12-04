#ifndef GETSTATETHREAD_H
#define GETSTATETHREAD_H

#include "QThread"

class GetStateThread : public QThread
{
    Q_OBJECT
public:
    GetStateThread();
signals:
    void stateSignal(int state);
private:
    void run();
};

#endif // GETSTATETHREAD_H
