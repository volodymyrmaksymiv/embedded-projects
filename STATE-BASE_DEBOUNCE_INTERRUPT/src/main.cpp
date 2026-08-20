#include <Arduino.h>
#define BUTTON_PIN 1

//flag to turn on
volatile bool interrupt_fired = 0;
bool waitRelease = false;

void IRAM_ATTR ISR() {
  interrupt_fired = true;
}

void setup() {
  pinMode(BUTTON_PIN, INPUT);
  attachInterrupt(BUTTON_PIN, ISR, FALLING);
  Serial.begin(115200);
}



void loop() {
  bool reading = digitalRead(BUTTON_PIN);

  
  if(interrupt_fired){
    interrupt_fired = false;
    //checking the waitRelease if it's released and reading is 0 then
    if(!waitRelease && !reading){
      Serial.println("Interrupt fired");
      waitRelease = true;
    }
  }else if(waitRelease && reading) { 
    waitRelease = false;
  }
}
