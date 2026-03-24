#pragma once

#include <Adafruit_SSD1306.h>
#include "config.hpp"

class HotPlateScreen {
    private:
        Adafruit_SSD1306 *Screen = nullptr;
        struct HEATINGPROFILE *profile = nullptr;
        enum PLATESTATE *state nullptr;

        // For Text Formatting
        const int leftAlign = SCREEN_WIDTH/5;
        const int row0 = 0;
        const int row1 = 8;
        const int row2 = 16;
        const int row3 = 24;
        const int row4 = 32;
        const int row5 = 40;
        const int row6 = 48;
        const int row7 = 56;

        //Manages Refresh Rate of Screen
        double screenTickStart = 0.0;
        double screenDeltaTime = 0.0;


        void displayButtons(string A, string B, string C, String D);

    public:
        HotPlateScreen(Adafruit_SSD1306 *pScreen, struct HEATINGPROFILE *pProfile, enum PLATESTATE *givenState);

        void initScreen();

        void updateScreen();
}