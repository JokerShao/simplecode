#include <iostream>
using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include "yeelink_lzy.h"

int main(void)
{
	//获取开关状态
	//根据获取到的开关状态来设置灯的状态
	int ret = 0;
	while(1) {
		ret = get_sensor_status("118.190.25.51", "359625", "409837", \
				"50bc63c1c6a73292d81d8bc53c585118");
	//	printf("state is %d",ret);
		if (ret < 0) {
			fprintf(stderr,"get error");
			continue;
		}
		if (ret) {
			system("echo 1 > /sys/devices/platform/leds-gpio/leds/led4/brightness");
		} else {
			system("echo 0 > /sys/devices/platform/leds-gpio/leds/led4/brightness");	
		}
	}
}
