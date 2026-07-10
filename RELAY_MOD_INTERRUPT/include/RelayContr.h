#pragma once
#include <Arduino.h>
enum class RelayState {
    RELAY_ON = HIGH,
    RELAY_OFF = LOW
};


class RelayContr {
    
public:
    RelayContr(uint8_t pinOut, uint8_t pinRead);
    void set(RelayState state);
    RelayState getState();
    bool getReadingState();

private:
    RelayState state = RelayState::RELAY_OFF;
    uint8_t pinOut;
    uint8_t pinRead;
};