/*
************************************************************************
* 作者:  IntoRobot Team    
* 版本:  V1.0.0
* 日期:  03-30-15
************************************************************************
功能描述：
可上送加速度计、陀螺仪、磁力计数据

所需器件:
1、加速度计模块
2、陀螺仪模块
3、磁力计模块

*/

/*该头文件引用由IntoRobot自动添加.*/
#include <WidgetInertialSensor.h>

WidgetInertialSensor sensor;

int a=10000;
int b=-9991;
int c=-618;

void setup() 
{
    // put your setup code here, to run once.
    sensor.begin();
}

void loop() 
{
    // put your main code here, to run repeatedly.
    sensor.displayAcceleration(a,b,c);
    sensor.displayGyroscope(a,b,c);
    sensor.displayMagnetometer(a,b,c);
    delay(2000);
}
