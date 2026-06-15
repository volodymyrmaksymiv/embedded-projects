#include <Arduino.h>
#define RELAY_MODULE_PIN 6
#define NTC_PIN 7
#define BLUE_LED_PIN 2
#define RED_LED_PIN 1
#define BUTTON_PIN 5

const u_int16_t blinking_delay_val = 150;
const u_int8_t debounce_time = 50;
const u_int16_t analog_val = 4095;
const double vref = 3.3;  
const double allowed_voltage = 2.3;
bool relay_module_state = LOW;
bool button_state = LOW;
bool last_button_state = LOW;
unsigned long last_debounce_time = 0;

bool error = false;


void setup() {
  pinMode(NTC_PIN, INPUT);
  pinMode(RELAY_MODULE_PIN, OUTPUT);

  pinMode(BLUE_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);

  pinMode(BUTTON_PIN, INPUT);
  digitalWrite(RELAY_MODULE_PIN, relay_module_state); //setting relay module state as LOW
  Serial.begin(115200);
}

void blinkingLed(){ 
  digitalWrite(RED_LED_PIN, HIGH);
  delay(blinking_delay_val);
  digitalWrite(RED_LED_PIN, LOW);
  delay(blinking_delay_val);
  digitalWrite(BLUE_LED_PIN, HIGH);
  delay(blinking_delay_val);
  digitalWrite(BLUE_LED_PIN, LOW);
}

void stopBlinking() {
  digitalWrite(RED_LED_PIN, LOW);
  digitalWrite(BLUE_LED_PIN, LOW);
}

void controlrelmodule() {
  double reading_voltage = analogRead(NTC_PIN);
  if(((reading_voltage / analog_val) * vref) > allowed_voltage) { //if reading voltage is bigger then make error
    error = true;
    relay_module_state = LOW;
  }
  digitalWrite(RELAY_MODULE_PIN, relay_module_state);
  
}

void buttonPushDebounce(bool reading) {
  if(reading != last_button_state) //debounce
    last_debounce_time = millis();
  if((millis() - last_debounce_time) > debounce_time) {
    if(reading != button_state){
      button_state = reading;
      if(reading == HIGH){
        relay_module_state = !relay_module_state;
        if(error) //turning off the error
          error = !error;
      }
    }
  }
  controlrelmodule();
}

void loop() {
  bool reading = digitalRead(BUTTON_PIN);
  buttonPushDebounce(reading);
  // blinking error
  if(error){ 
    blinkingLed();
  }else { 
    stopBlinking();    
  }
  Serial.println(relay_module_state);
  last_button_state = reading;
}