#include "mbed.h"
#include "Constants.h"
#include "tempSensor.h"

    DigitalIn switchValue(SwitchInput);

int switchPos() {

    return switchValue;
}