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

void HotPlateScreen::displayButtons(string A, string B, string C, string D) {
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

void HotPlateScreen::updateScreen() {
    screenDeltaTime = getTime() - screenTickStart;

    if (screenDeltaTime >= SCREEN_REFRESH_RATE) {
        screenTickStart = getTime();

        Screen->clearDisplay();

        switch (*state) {
            case 
        }
    }
}