/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "stdio.h"
#include "tempSense.h"
#include "lightLevel.h"
#include "switchPos.h"
#include "displayTask.h"
#include "constants.h"
#include "vt100.h"
#include "wifiThread.h"

things_t myData;

// Initialise the digital pin LED1 as an output
DigitalOut led(LED1);


Thread readTempHandle;
Thread readLightHandle;
Thread readButtonHandle;
Thread displayTaskHandle;
Thread wifiHandle;

int main()
{
    displayTaskHandle.start(callback(displayTask));
    readTempHandle.start(callback(readTemp));
    readLightHandle.start(callback(readLight));
    readButtonHandle.start(callback(switchPos));
    wifiHandle.start(callback(wifiThreadTask));
    while (true) {
        led = !led;
        ThisThread::sleep_for(BLINKING_RATE);
    }
}