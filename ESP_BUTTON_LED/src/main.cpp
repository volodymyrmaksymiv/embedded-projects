#include <Arduino.h>
#define LED_PIN 4
#define BUTTON_SLOW_PIN 1
#define BUTTON_FAST_PIN 2


//states
bool current_state[] = {LOW, LOW};
//delay values
u_int8_t delay_fast = 50;
u_int8_t delay_slow = 150;


void setup() {
  pinMode(BUTTON_SLOW_PIN, INPUT_PULLUP);
  pinMode(BUTTON_FAST_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
}

//slow blinking
void blinking_slow() {
  Serial.println("Slow mode");
  delay(delay_slow);
  digitalWrite(LED_PIN, HIGH);
  delay(delay_slow);
  digitalWrite(LED_PIN, LOW);
}

//fast blinking
void blinking_fast() {
  Serial.println("Fast mode");
  delay(delay_fast);
  digitalWrite(LED_PIN, HIGH);
  delay(delay_fast);
  digitalWrite(LED_PIN, LOW);
}

void loop() {
  bool button_state_slow = digitalRead(BUTTON_SLOW_PIN);
  bool button_state_fast = digitalRead(BUTTON_FAST_PIN);
  if(button_state_slow == HIGH){
    delay(170);
    current_state[0] = !current_state[0];
    current_state[1] = LOW;
  }
  else if(button_state_fast == HIGH) {
    delay(150);
    current_state[1] = !current_state[1];
    current_state[0] = LOW;
  }


  if(current_state[0] == HIGH)
    blinking_slow();
  else if(current_state[1] == HIGH)
    blinking_fast();
  else if (current_state[0] == LOW && current_state[1] == LOW)
    digitalWrite(LED_PIN, LOW);

}