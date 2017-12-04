#include "buzzerops.h"

extern "C" {
#include "unistd.h"
}

BuzzerOps::BuzzerOps(QObject *parent) : QObject(parent)
{

}

void BuzzerOps::buzzerOn()
{
    system("echo 1 > /sys/devices/platform/x6818-beep/state");
}

void BuzzerOps::buzzerOff()
{
    system("echo 0 > /sys/devices/platform/x6818-beep/state");
}
