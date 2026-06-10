#include <Arduino.h>
#define LDR_PIN 1
#define LED_PIN 4
const u_int16_t adc_max = 4095;
const double voltage_ref = 3.3;
const u_int16_t max_analogwrite = 255;
void setup() {
  pinMode(LDR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
}

double calc_voltage(u_int16_t raw) {
  return ((double)raw / adc_max) * 3.3;
}

u_int16_t calculate_led_light(u_int16_t raw) {
  return ((double)raw * max_analogwrite)/ adc_max;
}

void loop() {
  u_int16_t read_analog = analogRead(LDR_PIN);
  Serial.print("RAW: ");
  Serial.println(read_analog);
  Serial.print("Calculated voltage: ");
  Serial.println(calc_voltage(read_analog));
  Serial.print("Calculated voltage by analogReadMilivolts(): ");
  Serial.println((double)analogReadMilliVolts(LDR_PIN) / 1000);
  delay(100);
  analogWrite(LED_PIN, calculate_led_light(read_analog));
  
}
