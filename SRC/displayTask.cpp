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
            printf("\033[2;15H\033[4mRyan's Data \033[0;37m");
            printf("\033[4;3H\033[1;37mLED is %s\n", myData.switchState? "\033[0;32mOn \033[0;37m":"\033[0;31mOff \033[0;37m");
            printf("\033[4;1H%s", myData.switchState
                                  ? "\033[1;42m \033[0;37m"
                                  : "\033[1;41m \033[0;37m");            
            printf("\033[7;3H\033[1;37mTemperature is: \033[1;34m%2.1fc\n \033[0;37m", myData.temperature);
            printf("\033[7;1H%s", myData.heaterstate
                                  ? "\033[1;42m \033[0;37m"
                                  : "\033[1;41m \033[0;37m");
            printf("\033[10;3H\033[1;37mLight is at \033[1;36m%2.2f%c\n \033[0;37m", myData.lightLevel, '%');
            printf("\033[10;1H%s", myData.lightState
                                  ? "\033[1;42m \033[0;37m"
                                  : "\033[1;41m \033[0;37m");
            period = 0;
        }
    }

}