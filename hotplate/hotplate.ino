#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Thermistor.h>
#include <NTC_Thermistor.h>

#include "temperature.hpp"
#include "screen.hpp"
#include "config.hpp"

NTC_Thermistor thermistor(THERM, REF_RESISTOR, NTC_RESISTANCE, NTC_REF_TEMP, B_VALUE, ANALOG_RES);

enum PLATESTATE currentState = STARTUP;

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


}

void loop() {



}
