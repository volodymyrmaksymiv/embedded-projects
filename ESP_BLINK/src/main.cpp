#include <Arduino.h>
//Macros:
#define LED_ONBOARDBLUE 1
#define LED_ONBOARDRED 2
// put function declarations here:


void setup() {
  pinMode(LED_ONBOARDBLUE, OUTPUT);
  pinMode(LED_ONBOARDRED, OUTPUT);
}

void blueled_on(){ //function for blue led
  digitalWrite(LED_ONBOARDBLUE, HIGH);
  delay(100);
  digitalWrite(LED_ONBOARDBLUE, LOW);
  delay(100);
  digitalWrite(LED_ONBOARDBLUE, HIGH);
  delay(100);
  digitalWrite(LED_ONBOARDBLUE, LOW);
  delay(50);
}

void redled_on() { //function for red led
  digitalWrite(LED_ONBOARDRED, HIGH);
  delay(100);
  digitalWrite(LED_ONBOARDRED, LOW);
  delay(100);
  digitalWrite(LED_ONBOARDRED, HIGH);
  delay(100);
  digitalWrite(LED_ONBOARDRED, LOW);
  delay(50);
}

void loop() {
  redled_on();
  blueled_on();
}