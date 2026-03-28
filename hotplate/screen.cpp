#include <Adafruit_SSD1306.h>

#include "screen.hpp"
#include "helper.hpp"
#include "config.hpp"

HotPlateScreen::HotPlateScreen(
    Adafruit_SSD1306 *pScreen, 
    struct HEATINGPROFILE *pProfile, 
    enum PLATESTATE *givenState) :
    Screen(pScreen),
    profile(pProfile),
    state(givenState) {
        if (Screen != nullptr && profile != nullptr, && state != nullptr) {
            Serial.println("Screen ObjectInputs Good");
        } else {
            Serial.println("Fix Inputs to Screen Object");
        }
    }

void HotPlateScreen::initScreen() {
    Screen->begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
    Screen->clearDisplay();
    Screen->setTextSize(2);
    Screen->setTextColor(SSD1306_WHITE);

    screenTickStart = getTime();
}

void HotPlateScreen::displayButtons(char *A, char *B, char *C, char *D) {
    Screen->setTextSize(1);

    Screen->setCursor(0, row0);
    Screen->print(A);

    Screen->setCursor(SCREEN_WIDTH-30, row0);
    Screen->print(B);

    Screen->setCursor(0, row7);
    Screen->print(C);

    Screen->setCursor(SCREEN_WIDTH-30, row7);
    Screen->print(D);
}

void HotPlateScreen::displayCurve() {
    Screen->drawLine(0, SCREEN_HEIGHT, 25, row6, SSD1306_WHITE);
    Screen->drawLine(25, row6, 60, row6, SSD1306_WHITE);
    Screen->drawLine(60, row6, 75, row4, SSD1306_WHITE);
    Screen->drawLine(75, row4, 100, row4, SSD1306_WHITE);
    Screen->drawLine(100, row4, SCREEN_WIDTH, SCREEN_HEIGHT, SSD1306_WHITE);
}

void HotPlateScreen::displayParameters() {
    // Start->Soak Rate
    Screen->setCursor(0, row2);
    Screen->print(profile->targetRates[0], 1);

    //Soak Temp
    Screen->setCursor(35, row2);
    Screen->print(profile->targetTemps[0], 0);

    //Soak Time
    Screen->setCursor(35, row3);
    Screen->print(profile->targetTimes[0], 0);

    //Soak-> Reflow Rate
    Screen->setCursor(60, row7);
    Screen->print(profile->targetRates[1], 1);

    //Reflow Temp
    Screen->setCursor(75, row2);
    Screen->print(profile->targetTemps[1], 0);

    //Reflow Time
    Screen->setCursor(75, row3);
    Screen->print(profile->targetTimes[1], 0);

    // Reflow->End 
    Screen->setCursor(110, row2);
    Screen->print(profile->targetRates[2], 1);
}

void HotPlateScreen::updateScreen() {
    screenDeltaTime = getTime() - screenTickStart;

    if (screenDeltaTime >= SCREEN_REFRESH_RATE) {
        screenTickStart = getTime();

        Screen->clearDisplay();

        switch (*state) {
            case INIT:
                Screen->setTextSize(2);

                Screen->setCursor(0, row3);
                Screen->print("STARTUP :D");
            
            case IDLE:
                displayButtons("START", "EDIT", "", "");
                Screen->setTextSize(1);

                Screen->displayCurve();
                Screen->displayParameters();
        }
    }
}