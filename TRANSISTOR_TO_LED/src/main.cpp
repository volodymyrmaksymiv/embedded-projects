#include <Arduino.h>
#define PIN_TRANS_BASE 4

void setup() {
  pinMode(PIN_TRANS_BASE, OUTPUT);
}

void loop() {
  digitalWrite(PIN_TRANS_BASE, HIGH);
  delay(100);
  digitalWrite(PIN_TRANS_BASE, LOW);
  delay(100);
}

