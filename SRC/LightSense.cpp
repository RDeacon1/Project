#include "mbed.h"
#include "Constants.h"
#include "tempSensor.h"

extern things_data myData;
    AnalogIn LightLevelV(Lightout);

void readLight() {
    myData.LightLevel = LightLevelV.read() * 100;
    ThisThread::sleep_for(1s);
}