#include "mbed.h"
#include "Constants.h"
#include "displayTask.h"

extern things_data myData;
    DigitalIn switchValue(SwitchInput);

void displayTask() {
    /*set up code.*/
    DigitalOut LEDGn (GreenLED);
    while(true){    /*loop forever*/
    ThisThread::sleep_for(100ms);
    LEDGn = myData.SwState;
    }
    
}