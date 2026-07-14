#include "Arduino.h"

class Config {
    public:
        constexpr static uint8_t led1Pin = 4;
        constexpr static uint8_t led2Pin = 5;
        constexpr static uint8_t led3Pin = 6;

        constexpr static uint32_t delayLed1Pin = 200;
        constexpr static uint32_t delayLed2Pin = 500;
        constexpr static uint32_t delayLed3Pin = 1000;

    Config() = delete;
};