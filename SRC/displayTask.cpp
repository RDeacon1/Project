#include "mbed.h"
#include "constants.h"
#include "displayTask.h"

extern things_t myData;

void displayTask() {
/* setup */
int period = 0;
    DigitalOut green(greenLed);
    while(true){ /* loop forever */
        ThisThread::sleep_for(100ms);
        green = myData.switchState;
        if (period++ > 4){
            printf("Switch is %s pressed\n", myData.switchState? "is":"is not");
            printf("Temperature is: %2.1fc\n", myData.temperature);
            printf("Light is at %2.2f%c\n", myData.lightLevel, '%');
            period = 0;
        }
    }

}