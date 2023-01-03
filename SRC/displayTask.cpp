#include "mbed.h"
#include "constants.h"
#include "displayTask.h"
#include "vt100.h"

extern things_t myData;

void displayTask() {
/* setup */
int period = 0;
    DigitalOut green(greenLed);
    RIS; //Reset the VT100 terminal to text mode
    ThisThread::sleep_for(1s);
    while(true){ /* loop forever */
        ThisThread::sleep_for(100ms);
        green = myData.switchState;
        if (period++ > 4){
            HOME; //put cursor in position 1.1
            HIDE_CURSOR; //Remove cursor from screen
            printf("LED is %s\n", myData.switchState? "\033[0;31mOn \033[0;37m":"\033[0;32mOff \033[0;37m");            
            printf("Temperature is: %2.1fc\n", myData.temperature);
            printf("Light is at %2.2f%c\n", myData.lightLevel, '%');
            period = 0;
        }
    }

}