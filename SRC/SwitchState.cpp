#include "mbed.h"
#include "Constants.h"
#include "tempSensor.h"

extern things_data myData;
    DigitalIn switchValue(SwitchInput);

void switchPos() {
    /*set up code.*/
    while(true){    /*loop forever*/
    ThisThread::sleep_for(50ms);
    myData.SwState = switchValue;
    }
    
}