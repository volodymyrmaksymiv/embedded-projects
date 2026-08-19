#include <Arduino.h>
#define BUTTON_PIN 1



volatile uint64_t counter = 0;

uint64_t start_timer_ms = 0;
bool last_button_state = 1;
volatile bool intr_act = 0;

void IRAM_ATTR ISR(){
  counter++;
  intr_act = 1;
}


void setup() {
  pinMode(BUTTON_PIN, INPUT);
  attachInterrupt(BUTTON_PIN, ISR, FALLING);
  Serial.begin(115200);
}

void loop() {
  bool reading = digitalRead(BUTTON_PIN);
  if(reading != last_button_state) {
    start_timer_ms = millis();
  }
  if(millis() - start_timer_ms > 20) {
    if(reading && intr_act){
      Serial.println("Count interrupt: ");
      Serial.println(counter);
      counter = 0;
      intr_act = 0;
    }
  }
  last_button_state = reading;
}
