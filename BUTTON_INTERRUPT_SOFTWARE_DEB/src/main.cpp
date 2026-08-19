#include <Arduino.h>
#define BUTTON_PIN 1

//software timer debug


const uint8_t debounce_ms = 50;


//timer for interrupt on
volatile uint16_t counter = 0;
volatile uint64_t timeWhenFired; 

volatile bool interruptFired = 0;


void IRAM_ATTR ISR() {
  timeWhenFired = millis();
  counter++;
  interruptFired = 1;
}

void setup() {
  pinMode(BUTTON_PIN, INPUT);
  attachInterrupt(BUTTON_PIN, ISR, FALLING);
  Serial.begin(115200);
}

void loop() {
  if(interruptFired && millis() - timeWhenFired > 50) {
    interruptFired = !interruptFired;
    Serial.println("How many times interrupt fired: ");
    Serial.println(counter);
    counter = 0;
    attachInterrupt(BUTTON_PIN, ISR, FALLING);
  } 
  else if (interruptFired && millis() - timeWhenFired < 50) {
    detachInterrupt(BUTTON_PIN);
  }
}
