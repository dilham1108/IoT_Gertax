#ifndef SENSOR_LIBRARY_H
#define SENSOR_LIBRARY_H

#include <Arduino.h>

// Function prototypes
void initSensors();
float readVoltage();
float readCurrent();
float readRPM();

// Pin definitions
const int voltageSensorPin = A0;
const int currentSensorPin = A1;
const int rpmSensorPin = 2;

void initSensors() {
  pinMode(voltageSensorPin, INPUT);
  pinMode(currentSensorPin, INPUT);
  pinMode(rpmSensorPin, INPUT);
}

float readVoltage() {
  int sensorValue = analogRead(voltageSensorPin);
  float voltage = sensorValue * (5.0 / 1023.0); // Adjust based on your voltage sensor
  return voltage;
}

float readCurrent() {
  int sensorValue = analogRead(currentSensorPin);
  float current = sensorValue * (5.0 / 1023.0); // Adjust based on your current sensor
  return current;
}

float readRPM() {
  // Example RPM reading function, modify as needed for your sensor
  static unsigned long lastTime = 0;
  static int pulseCount = 0;
  
  if (digitalRead(rpmSensorPin) == HIGH) {
    pulseCount++;
  }

  unsigned long currentTime = millis();
  if (currentTime - lastTime >= 1000) {
    float rpm = (pulseCount * 60.0) / (currentTime - lastTime) * 1000;
    pulseCount = 0;
    lastTime = currentTime;
    return rpm;
  }
  
  return 0.0;
}

#endif // SENSOR_LIBRARY_H
