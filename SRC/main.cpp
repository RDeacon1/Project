#include "mbed.h"
#include "stdio.h"
#include "tempSensor.h"
#include "Constants.h"

 // Name outputs and supplies
    DigitalOut led(LED1);

int main()
{
       while (true) {
        led = !led;
        ThisThread::sleep_for(BLINKING_RATE);
        float Temperature = readTemp();
        printf("The temperature is: %2.1f'c\n", Temperature);
    }
}