#include <Arduino.h>
#include "Config.h"

bool ledState1 = 0;
long lastLed1 = 0;

bool ledState2 = 0;
long lastLed2 = 0;

bool ledState3 = 0;
long lastLed3 = 0;

void setup() {
  pinMode(Config::led1Pin, OUTPUT);
  pinMode(Config::led2Pin, OUTPUT);
  pinMode(Config::led3Pin, OUTPUT);
}

void loop() {
  unsigned long  now = millis();
  if(now - lastLed1 >= Config::delayLed1Pin) {
    lastLed1 = millis();
    ledState1 = !ledState1;
    digitalWrite(Config::led1Pin, ledState1);
  }

  if(now - lastLed2 >= Config::delayLed2Pin) {
    lastLed2 = millis();
    ledState2 = !ledState2;
    digitalWrite(Config::led2Pin, ledState2);
  }

  if(now - lastLed3 >= Config::delayLed3Pin) {
    lastLed3 = millis();
    ledState3 = !ledState3;
    digitalWrite(Config::led3Pin, ledState3);
  }
  
}
