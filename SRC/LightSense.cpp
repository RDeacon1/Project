#include "mbed.h"
#include "Constants.h"
#include "tempSensor.h"

    AnalogIn LightLevelV(Lightout);

float readLight() {

    float LightLevel = LightLevelV.read() * 100; // Range of light level 0 - 100%
    return LightLevel;
}