#include <Arduino.h>
#define BUTTON 2
#define LED_1  4

int buttonState;
bool ledState = false;
bool lastButtonState = true;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 60;

int16_t counter = 0;
void IRAM_ATTR reaction() {
  counter++;
  Serial.println("\nButton Pressed! Count: " + String(counter));
}


void setup() {

  Serial.begin(115200);

  pinMode(BUTTON, INPUT);
  pinMode(LED_1, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(BUTTON), reaction, FALLING);

}

void loop() {

  int reading = digitalRead(BUTTON);
  if (reading != (int)lastButtonState) {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {

    if (reading != buttonState) {
      buttonState = reading;
     if (buttonState == LOW) {
       ledState = !ledState;
     }
    }
  }
  digitalWrite(LED_1, ledState);
    
  lastButtonState = reading;
}