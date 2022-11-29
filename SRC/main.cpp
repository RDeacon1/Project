#include "mbed.h"
#include "stdio.h"
#include "tempSensor.h"
#include "Constants.h"
#include "Lightsense.h"
#include "SwitchState.h"
#include "displayTask.h"
#include <cstdio>

things_data myData;

 // Name outputs and supplies
    DigitalOut led(LED1);
    

    Thread readTempHandle;
    Thread readLightHandle;
    Thread readButtonHandle;
    Thread displayTaskHandle;

int main()
{
    displayTaskHandle.start(callback(displayTask));
    readTempHandle.start(callback(readTemp));
    readLightHandle.start(callback(readLight));
    readButtonHandle.start(callback(switchPos));
    while (true) {
        led = !led;
        ThisThread::sleep_for(BLINKING_RATE);
    }
}