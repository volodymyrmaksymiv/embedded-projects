#pragma once
#include <cstdint>

class Config {
public:
    static constexpr uint8_t led_pin = 1;
    static const uint32_t blinking_time_ms = 200;

    Config() = delete;
};