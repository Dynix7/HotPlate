#pragma once

#include <Adafruit_SSD1306.h>
#include "config.hpp"

class HotPlateScreen {
    Adafruit_SSD1306 *Screen = nullptr;
    struct TEMPERATURES *Temps = nullptr;

    public:
        HotPlateScreen(Adafruit_SSD1306 *pScreen, struct TEMPERATURES *pTemps);

}