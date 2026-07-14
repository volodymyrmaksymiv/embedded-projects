#include <Arduino.h>
#include "RelayContr.h"
#include "Config.h"
RelayContr relaycon = RelayContr(Config::pinOut, Config::pinRead);
unsigned long previous_millis = 0;
volatile bool responseDetected = false;  // set true in ISR after a debounced RISING edge is processed; cleared in loop() once printed

volatile unsigned long lastInterruptTime = 0; // timestamp of the last RISING edge accepted by the debounce filter (updated only if enough time passed since the previous one)

volatile unsigned long lastResponseTime = 0; // counting how much time is needed for NO contact to start work

volatile unsigned long turnOnRelayTime = 0; // reading time for turning the relay

volatile uint64_t counter = 0; // counter for every rising in pinRead

//interrupt
void IRAM_ATTR relayInterrupt() {
    unsigned long now = millis();
    if(now - lastInterruptTime < Config::delay_time)
        return;
    lastInterruptTime = now;
    lastResponseTime = lastInterruptTime - turnOnRelayTime;
    counter++; // counts only debounced RISING edges
    responseDetected = true;
} 

void setup() {
    Serial.begin(115200);
    attachInterrupt(digitalPinToInterrupt(Config::pinRead), relayInterrupt, RISING); //setting up the pin for interrupt
}

// printing result
void print() {
    Serial.print(counter);
    Serial.print(": ");
    Serial.print(lastResponseTime);
    Serial.println(" ms");
}



void loop() {
    unsigned long current_millis = millis();
    bool reading = relaycon.getReadingState();
    if(current_millis - previous_millis >= Config::delay_time) { // condition with a delay when to turn on and turn off the relay
        previous_millis = current_millis;
        relaycon.set((relaycon.getState() == RelayState::RELAY_ON) ? RelayState::RELAY_OFF : RelayState::RELAY_ON);
        turnOnRelayTime = millis();
    }
    if(responseDetected == true) { // 
        print();
        responseDetected = !responseDetected;
    }

    



}
