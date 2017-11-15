#include "WidgetInertialSensor.h"


WidgetInertialSensor::WidgetInertialSensor(uint8_t ucItem)
{
    _Item=ucItem;
    memset(pDataAccelerationTopic,0,sizeof(pDataAccelerationTopic));
    memset(pDataGyroscopeTopic,0,sizeof(pDataGyroscopeTopic));
    memset(pDataMagnetometerTopic,0,sizeof(pDataMagnetometerTopic));
    sprintf(pDataAccelerationTopic,"channel/inertialSensor_%d/data/acceleration",_Item);
    sprintf(pDataGyroscopeTopic,"channel/inertialSensor_%d/data/gyroscope",_Item);
    sprintf(pDataMagnetometerTopic,"channel/inertialSensor_%d/data/magnetometer",_Item);
}

WidgetInertialSensor::~WidgetInertialSensor()
{
}

void WidgetInertialSensor::begin(void (*UserCallBack)(void))
{
}

void WidgetInertialSensor::displayAcceleration(int x,int y, int z)
{
    uploadData(pDataAccelerationTopic,x,y,z);
}

void WidgetInertialSensor::displayGyroscope(int x,int y, int z)
{
    uploadData(pDataGyroscopeTopic,x,y,z);
}

void WidgetInertialSensor::displayMagnetometer(int x,int y, int z)
{
    uploadData(pDataMagnetometerTopic,x,y,z);
}

void WidgetInertialSensor::uploadData(char *topic,int x,int y,int z)
{
    aJsonObject* root = aJson.createObject();
    if (root == NULL)
    {
        return;
    }
    
    aJson.addNumberToObject(root, "x",x);
    aJson.addNumberToObject(root, "y",y);
    aJson.addNumberToObject(root, "z",z);
    
    char* str = aJson.print(root);
    
    IntoRobot.publish(topic,str);
    free(str);
    aJson.deleteItem(root);
}


void WidgetInertialSensor::widgetBaseCallBack(uint8_t *payload, uint32_t len)
{
}

