// Blinking rate in milliseconds
#define BLINKING_RATE     4s

//#define thermVoltage P10_3 //Naming terminal 10_3 Therm_VDD
//#define thermGround P10_0 // Naming terminal 10_0 Therm_GND
#define thermOut P10_1 // Naming terminal 10_1 Therm_Out
#define lightOut P10_4
/* Reference resistor in series with the thermistor is of 10kohm */
#define R_REFERENCE                         (float)(10000)

/* A constant of NCP18XH103F03RB thermistor is */
#define A_COEFF                          (float)(0.0009032679f)
/* B constant of NCP18XH103F03RB thermistor is */
#define B_COEFF                          (float)(0.000248772f)
/* C constant of NCP18XH103F03RB thermistor is */
#define C_COEFF                          (float)(0.0000002041094f)

/* Zero Kelvin in degree C */
#define ABSOLUTE_ZERO                       (float)(-273.15)

#define Lightout P10_4
#define SwitchInput P0_4
#define GreenLED P0_5

struct things_data {
    float Temperature;
    float LightLevel;
    int SwState;
};