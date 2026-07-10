#include <Arduino.h>
#include "RelayContr.h"
#include "Config.h"
RelayContr relaycon = RelayContr(Config::pinOut, Config::pinRead);
unsigned long previous_millis = 0;
volatile bool responceDetect = false;
volatile unsigned long lastInterruptTime = 0;
volatile unsigned long lastResponseTime = 0;
volatile unsigned long turnOnRelayTime = 0;

volatile uint64_t counter = 0;
void IRAM_ATTR relayInterrupt() {
    unsigned long now = millis();
    if(now - lastInterruptTime < Config::delay_time)
        return;
    lastInterruptTime = now;
    lastResponseTime = lastInterruptTime - turnOnRelayTime;
    counter++;
    responceDetect = true;
} 

void setup() {
    Serial.begin(115200);
    attachInterrupt(digitalPinToInterrupt(Config::pinRead), relayInterrupt, RISING);
}

void print() {
    Serial.print(counter);
    Serial.print(": ");
    Serial.print(lastResponseTime);
    Serial.println(" ms");
}



void loop() {
    unsigned long current_millis = millis();
    bool reading = relaycon.getReadingState();
    if(current_millis - previous_millis >= Config::delay_time) {
        previous_millis = current_millis;
        relaycon.set((relaycon.getState() == RelayState::RELAY_ON) ? RelayState::RELAY_OFF : RelayState::RELAY_ON);
        turnOnRelayTime = millis();
    }
    if(responceDetect == true) {
        print();
        responceDetect = !responceDetect;
    }

    



}
