#ifndef WIDGET_INERTIALSENSOR_H_
#define WIDGET_INERTIALSENSOR_H_

#include "application.h"

class WidgetInertialSensor : public WidgetBaseClass
{
    public:
        WidgetInertialSensor(uint8_t ucItem = 0);
        ~WidgetInertialSensor();
        void begin(void (*UserCallBack)(void) = NULL);
        void displayAcceleration(int x,int y, int z);
        void displayGyroscope(int x,int y, int z);
        void displayMagnetometer(int x,int y, int z);

    private:
        char pDataAccelerationTopic[64];
        char pDataGyroscopeTopic[64];
        char pDataMagnetometerTopic[64];
        uint8_t _Item = 0;
        
        aJsonClass aJson;
        
        void uploadData(char *topic,int x,int y,int z);

        void (*_EventCb)(void);
        void widgetBaseCallBack(uint8_t *payload, uint32_t len);
};

#endif
