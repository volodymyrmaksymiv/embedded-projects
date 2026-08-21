#include <Arduino.h>
#define BUTTON_PIN 1

const uint8_t debounce_ms = 10;
unsigned long start_debounce = 0;



bool button_state = true;
bool last_button_state = true;
bool button_pushed = false;


void setup() {
  pinMode(BUTTON_PIN, INPUT);
  Serial.begin(115200);
}

void loop() {
  bool reading = digitalRead(BUTTON_PIN);
  // if something has changed with reading or last_button_state and they are not equal to each other  then 
  if(reading != last_button_state) {
    start_debounce = millis();
  }
  if(millis() - start_debounce > debounce_ms) {
    button_state = reading;
    // if button is pressed (button_state is false) and button_pushed is false then 
    if(!button_state && !button_pushed) { 
      Serial.println("Button pushed");
      button_pushed = !button_pushed;

    }else if(button_state && button_pushed) { // if button is not pressed and button_pushed is true then 
      button_pushed = false;
      Serial.println("Button released");
    }
  }
  last_button_state = reading;
}