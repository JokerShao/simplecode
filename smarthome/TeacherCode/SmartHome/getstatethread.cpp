#include "getstatethread.h"
//#include "yeelink_lzy.h"
#include "QDebug"

extern "C" {
#include "unistd.h"
}

GetStateThread::GetStateThread()
{

}

void GetStateThread::run()
{
//    while (1) {
//        int ret = get_sensor_status("118.190.25.51", "359638", "409822", "cc18f9d60f96f69d2465a34258dcd485");
//        if (ret < 0) {
//            qDebug() << "get sensor state error";
//            continue;
//        }
//        if (ret) {
//            emit stateSignal(1);
//        } else {
//            emit stateSignal(0);
//        }
//        sleep(1);
//    }
}
