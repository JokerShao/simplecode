#include "getstatethread.h"
#include "yeelink_lzy.h"
#include <QDebug>

extern "C" {
#include "unistd.h"
}
GetStateThread::GetStateThread()
{

}

// 1 按位获取状态，槽函数要移位，编程难度大    /////不好使
// 2 emit 0 1 2 3 ，槽函数switch，复制代码，代码多
// 3 两个参数，一个设备ID ，一个状态，和2差不多
// 4 emit数组，和1差不多
void GetStateThread::run()
{
    int state; //记录状态0x00000000 从低位到高位 led2 led3 led4 buzzer 0关1开
    int ret;
    while(1) {
        state = 0;
        ret = get_sensor_status("118.190.25.51","359625","409837","50bc63c1c6a73292d81d8bc53c585118");
        //qDebug()<<"led2:"<<ret<<endl;
        if(ret < 0) continue;
        state |= ret;
        ret = get_sensor_status("118.190.25.51","359625","410087","50bc63c1c6a73292d81d8bc53c585118");
        //qDebug()<<"led3:"<<ret<<endl;
        if(ret < 0) continue;
        state |= ret << 1;
        ret = get_sensor_status("118.190.25.51","359625","410088","50bc63c1c6a73292d81d8bc53c585118");
        //qDebug()<<"led4:"<<ret<<endl;
        if(ret < 0) continue;
        state |= ret << 2;
        emit ledStateSignal(state);
        ret = get_sensor_status("118.190.25.51","359625","410089","50bc63c1c6a73292d81d8bc53c585118");
        //qDebug()<<"buzzer:"<<ret<<endl;
        if(ret < 0) continue;
        emit buzzerStateSignal(ret);
        //qDebug()<<state<<" ";
        sleep(1);
        //qDebug()<<"thread run";
    }
}
