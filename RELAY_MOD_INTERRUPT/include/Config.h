#pragma once
#include <Arduino.h>
class Config {
public:
    constexpr static uint8_t pinOut = 1;
    constexpr static uint8_t pinRead = 2;

    constexpr static uint16_t delay_time = 5000;

    Config() = delete;
};