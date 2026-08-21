#include <Arduino.h>
#define BUTTON_PIN 1
#define LED_PIN 4

const uint8_t debounce_ms = 8;
const uint8_t poll_interval_ms = 10;
unsigned long start_debounce = 0;

unsigned long last_poll = 0;
bool button_state = true;
bool last_button_state = true;
bool reading = true;
bool led_state = false;

enum DebounceState {
  IDLE,
  DEBOUNCING
};

enum ButtonState {
  ON,
  OFF
};


ButtonState state = OFF;
DebounceState debState = IDLE;

void setup() {
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  if(millis() - last_poll >= poll_interval_ms){
    last_poll = millis();
    reading = digitalRead(BUTTON_PIN);
  }
  
  if(reading != last_button_state) {
    start_debounce = millis();
    debState = DEBOUNCING;
  }
  if(debState == DEBOUNCING && millis() - start_debounce > debounce_ms) {
    button_state = reading;
    debState = IDLE;
    switch(state) {
      case OFF:
        if(!button_state) {
          state = ON;
          Serial.println("State is ON");
        }
        break;
      case ON:
        if(button_state) {
          state = OFF;
          Serial.println("State is OFF");
        }
        break;
    }
  }
  last_button_state = reading;
}