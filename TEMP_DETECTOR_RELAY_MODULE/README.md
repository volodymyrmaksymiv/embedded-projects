# Temperature-Based Safety Alarm System (ESP32)

Embedded device for real-time temperature monitoring with automatic relay control.

## Demo
<img width="960" height="1280" alt="photo20260615041316___cf0c7d3e-9873-4f21-9738-4b4c64f7635f" src="https://github.com/user-attachments/assets/e2db64eb-6cd1-4d61-b61b-6d52ded38a9f" />



## How it works
- Voltage divider circuit: 10kΩ resistor + thermistor connected to ESP32 analog input
- NPN transistor used as a switch to drive the relay module from a GPIO pin
- When temperature exceeds threshold, relay module cuts power automatically
- Blue/red LED indicates alarm
- Push-button for manual reset

## Components
- ESP32
- Thermistor + 10kΩ resistor
- Relay module
- NPN transistor
- 2x LED (blue, red)
- Push-button
- Breadboard + jumper wires

##Video
- https://github.com/user-attachments/assets/6be711a6-dd7e-45ee-b022-57f77af99d71





