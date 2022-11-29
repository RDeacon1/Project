#include "mbed.h"
#include "stdio.h"
#include "tempSensor.h"
#include "Constants.h"
#include "Lightsense.h"
#include "SwitchState.h"
#include <cstdio>

 // Name outputs and supplies
    DigitalOut led(LED1);
    DigitalOut LEDGn (GreenLED);

int main()
{
       while (true) {
        led = !led;
        ThisThread::sleep_for(BLINKING_RATE);
        float Temperature = readTemp();
        printf("The temperature is: %2.1f'c\n", Temperature);
        float LightLevel = readLight();
        printf("The light level is: %2.1f%c\n", LightLevel, '%');
        int SwState = switchPos();
        LEDGn = !SwState;
        printf("The switch is %s\n", SwState?"Not Pressed":"Pressed");
    }
}