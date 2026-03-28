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

#define READ_RATE 1.0/20

//Screen Related Variables
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C
#define SCREEN_WIRE &Wire
#define SCREEN_REFRESH_RATE 1.0/10


enum PLATESTATE {
    INIT,
    IDLE,
    ADJUST_TEMP,
    ADJUST_TIMES,
    ADJUST_RATES,
    HEATING,
    STOPPED
}

enum HEATSTATE {
    START,
    RAMPSOAK,
    SOAK,
    RAMPREFLOW,
    REFLOW,
    COOLING,
    END
}
//Stores the Reflow  Profile
struct HEATINGPROFILE {
    enum HEATSTATE heatState = START;

    double targetTemps[2] = {0}; // Soak Temp, Reflow Temp-Celsius
    double targetTimes[2] = {0}; //Length of Soak Plataeu, Length of Reflow Plataeu-Seconds
    double targetRates[3] = {0}; // Start->Soak, Soak->Reflow, Reflow->End  -  Celsius/Second

    double currentTempTarget = 0.0;

    double timeFromStart = 0.0;
    double currentTempC = 0.0;
    double currentTempF = 0.0;
}

struct CONTROL {
    double Kp = 0.0;
    double Ki = 0.0;
    
    double deltaTime = READ_RATE;
    
    double error = 0.0;
    double prevError = 0.0;
}