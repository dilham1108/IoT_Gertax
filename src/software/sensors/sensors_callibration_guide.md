# Sensor Calibration Guide

## Voltage Sensor Calibration

1. Connect the voltage sensor to a known voltage source.
2. Measure the actual voltage using a multimeter.
3. Read the ADC value using the `read_voltage()` function.
4. Calculate the conversion factor:
   - Conversion Factor = Measured Voltage / ADC Value
5. Adjust the conversion factor in the `read_voltage()` function accordingly.

## Current Sensor Calibration

1. Connect the current sensor to a known current source.
2. Measure the actual current using a multimeter.
3. Read the ADC value using the `read_current()` function.
4. Calculate the conversion factor:
   - Conversion Factor = Measured Current / ADC Value
5. Adjust the conversion factor in the `read_current()` function accordingly.

## RPM Sensor Calibration

1. Connect the RPM sensor to a known rotating device with a known RPM.
2. Measure the actual RPM using a tachometer.
3. Read the pulse count using the `read_rpm()` function.
4. Calculate the conversion factor if necessary, depending on the sensor used.
5. Adjust the `read_rpm()` function accordingly.

## Notes

- Ensure all connections are secure and there is no interference from other devices.
- Calibrate sensors in a stable environment to get accurate measurements.
- Document the calibration process and factors used for future reference.
