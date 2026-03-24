#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Thermistor.h>
#include <NTC_Thermistor.h>

#include "thermistor.hpp"
#include "temperature.hpp"
#include "screen.hpp"
#include "helper.hpp"
#include "config.hpp"


NTC_Thermistor thermistor(THERM, REF_RESISTOR, NTC_RESISTANCE, NTC_REF_TEMP, B_VALUE, ANALOG_RES);
Adafruit_SSD1306 OLED_1306(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_WIRE, OLED_RESET);

enum PLATESTATE currentState = STARTUP;

struct HEATINGPROFILE profile = {
    .targetTemps = {150.0, 220.0}, // Soak Temp, Reflow Temp-Celsius
    .targetTimes = {100, 60}, //Length of Soak, Length of Reflow-Seconds
    .targetRates = {2.5, 2.5, 3.5} // Start->Soak, Soak->Reflow, Reflow->End  -  Celsius/Second
}

HotPlateScreen SCREEN(&OLED_1306, &profile, &currentState);

void setup() {
    Serial.begin(115200);

    //I2C stuff
    Wire.begin();
    Wire.setSDA(SDA);
    Wire.setSCL(SCL);

    // Pinout Setup
    pinMode(BTN0, INPUT);
    pinMode(BTN1, INPUT);
    pinMode(BTN2, INPUT);
    pinMode(BTN3, INPUT);

    pinMode(GATE, OUTPUT);
    pinMode(HOT, OUTPUT); //LED

    pinMode(THERM, INPUT);

    SCREEN.initScreen();
}

void loop() {



}
