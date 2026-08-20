#include <Arduino.h>
#define BUTTON_PIN 1

//software timer debug
const uint8_t debounce_ms = 50;


//timer for interrupt on
volatile uint16_t counter = 0;
volatile uint64_t timeWhenFired; 
bool isrAttached = 1;

void IRAM_ATTR ISR() {
  timeWhenFired = millis();
  counter++;
}

void setup() {
  pinMode(BUTTON_PIN, INPUT);
  attachInterrupt(BUTTON_PIN, ISR, FALLING);
  Serial.begin(115200);
}

void loop() {
  // if time is bigger than 50 and isrAttached = 0 then
  if(millis() - timeWhenFired > debounce_ms && !isrAttached) { 
    attachInterrupt(BUTTON_PIN, ISR, FALLING);
    isrAttached = !isrAttached;
  }
  // if time is less than 50 and isrAttached = 1 then 
  else if (millis() - timeWhenFired < debounce_ms && isrAttached) { 
    Serial.println("How many times interrupt fired: ");
    Serial.println(counter);
    detachInterrupt(BUTTON_PIN);
    isrAttached = !isrAttached;
    counter = 0;
  }
}
