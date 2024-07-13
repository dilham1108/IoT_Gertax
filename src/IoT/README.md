# IoT Integration

This folder contains the code and setup guide for integrating the mini power generator project with an IoT platform using the ESP32 microcontroller.

## Files

- `communication/`: Folder containing the communication library.
  - `communication_library.h`: Library for handling communication with the IoT platform.
- `platform/`: Folder containing the main IoT platform code.
  - `platform_code.ino`: Main code file for the ESP32 microcontroller.

## Code Explanation

### platform_code.ino

The main code file `platform_code.ino` initializes the sensors and communication modules, reads sensor data, and sends the data to an IoT platform.

```cpp
#include "sensor_library.h"
#include "communication_library.h"

void setup() {
  // Initialize serial communication
  Serial.begin(115200);

  // Initialize sensors
  initSensors();

  // Initialize communication
  initCommunication();
}

void loop() {
  // Read sensor data
  float voltage = readVoltage();
  float current = readCurrent();
  float rpm = readRPM();

  // Send data to IoT platform
  sendData(voltage, current, rpm);

  // Delay for a second before next reading
  delay(1000);
}
