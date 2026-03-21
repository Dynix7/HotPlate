#include <Thermistor.h>
#include <NTC_Thermistor.h>

#include "temperature.hpp"

double getTempC() {
    return thermistor.readCelsius();
}

double getTempF() {
    return thermistor.readFahrenheit();
}

