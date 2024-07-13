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
