#pragma once
#include <Arduino.h>
enum class LedState {
    LED_ON = HIGH,
    LED_OFF = LOW
};

class LedControl {
public:
    LedControl(uint8_t pin, LedState led_state) : 
        pin{pin}, led_state{led_state}{

    }
    void init() {
        pinMode(pin, OUTPUT);
    }

    void set(LedState state) {
        led_state = state;
        digitalWrite(pin, static_cast<int> (state));   
    }

    LedState get_state() const{
        return led_state;
    }

private:
    LedState led_state;
    uint8_t pin;
};