#include <Thermistor.h>
#include <NTC_Thermistor.h>

#include "thermistor.hpp"

double getTempC() {
    return thermistor.readCelsius();
}

double getTempF() {
    return thermistor.readFahrenheit();
}

void updateTemps(struct HEATINGPROFILE *pProfile) {
    pProfile->currentTempC = getTempC();
    pProfile->currentTempF = getTempF();
}
