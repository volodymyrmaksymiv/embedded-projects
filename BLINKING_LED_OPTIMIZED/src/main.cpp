#include <Arduino.h>
#include "LedControl.h"
#include "Config.h"

unsigned long previous_millis = 0;
volatile bool button_pressed = false;

LedControl led_con = LedControl(Config::led_pin, LedState::LED_OFF);




void setup() {
    led_con.init();
}



void loop() {
    unsigned long current_millis = millis();
    if(current_millis - previous_millis > Config::blinking_time_ms) {
        previous_millis = current_millis;
        led_con.set((led_con.get_state() == LedState::LED_ON) ? LedState::LED_OFF : LedState::LED_ON);
    }
}

