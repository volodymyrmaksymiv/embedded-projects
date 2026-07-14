#include "RelayContr.h"
RelayContr::RelayContr(uint8_t pinOut, uint8_t pinRead): 
    pinOut{pinOut}, pinRead{pinRead} {
    pinMode(pinOut, OUTPUT);
    pinMode(pinRead, INPUT_PULLDOWN);    
};

void RelayContr::set(RelayState state){ //setting up the state for pinOut
    this->state = state;
    digitalWrite(pinOut, static_cast<bool> (state));
}
RelayState RelayContr::getState() {
    return state;
}
bool RelayContr::getReadingState() {
    return digitalRead(pinRead);
}

