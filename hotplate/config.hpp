#pragma once

// Pinouts
#define SDA 24
#define SCL 25

#define HOT 17

#define BTN0 18
#define BTN1 29
#define BTN2 27
#define BTN3 19

#define GATE 5

#define THERM A0

//Thermistor Reading Values

#define NTC_RESISTANCE 100000
#define NTC_REF_TEMP 25
#define REF_RESISTOR 5100
#define ANALOG_RES 4095
#define B_VALUE 3950


//Screen Related Variables
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C
#define SCREEN_WIRE &Wire
#define SCREEN_REFRESH_RATE 1.0/10


enum PLATESTATE {
    INIT = -1,
    STARTUP,
    IDLE,
    ADJUST_TEMP,
    HEATING,
    STOPPED
}

struct TEMPERATURES {
    double targetTemp = 0.0;
    double currentTempC = 0.0;
    double currentTempF = 0.0;
}