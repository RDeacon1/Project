#include "mbed.h"
#include "Constants.h"
#include "tempSensor.h"

    DigitalOut Pwr(thermVoltage);
    DigitalOut Gnd(thermGround);
    AnalogIn TempV(thermOut);

float readTemp() {
    Gnd = false;
    Pwr = true;
    float refVoltage = TempV.read() * 2.4; // Range of ADC 0->2*Vref
    Pwr = false;
    float refCurrent = refVoltage  / 10000.0; // 10k Reference Resistor
    float thermVoltage = 3.3 - refVoltage;    // Assume supply voltage is 3.3v
    float thermResistance = thermVoltage / refCurrent; 
    float logrT = (float32_t)log((float64_t)thermResistance);    /* Calculate temperature from the resistance of thermistor using Steinhart-Hart Equation */
    float stEqn = (float32_t)((A_COEFF) + ((B_COEFF) * logrT) + ((C_COEFF) * pow((float64)logrT, (float32)3)));
    float temperatureC = (float32_t)(((1.0 / stEqn) + ABSOLUTE_ZERO)  + 0.05);
    return temperatureC;
}