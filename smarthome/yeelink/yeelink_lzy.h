#ifndef __YEELINK_LZY__
#define __YEELINK_LZY__
/*
函数功能：向yeelink服务器上传数据
参数：
ip：yeelink服务器ip
device：设备
sensor：传感器
id：key
data：要上传的数据
*/ 
int set_sensor_data(const char *ip, const char *device, const char *sensor, const char *id, double data);

/*
函数功能：设置开关状态
参数：
ip：yeelink服务器ip
device：设备
sensor：传感器
id：key
status：开关的状态
*/
int set_sensor_status(const char *ip, const char *device, const char *sensor, const char *id, int status);

/*
函数功能：从yeelink服务器获取开关状态
参数：
ip：yeelink服务器ip
device：设备
sensor：传感器
id：key
*/
int get_sensor_status(const char *ip, const char *device, const char *sensor, const char *id);

#endif
