# Sensors

This folder contains the code and calibration guide for the sensors used in the mini power generator project.

## Files

- `sensor_code.py`: Main code file for reading sensor data.
- `sensor_calibration_guide.md`: Instructions for calibrating the sensors.

## Code Explanation

### sensor_code.py

The main code file `sensor_code.py` is used for reading data from various sensors. This example uses Python, which might be used for sensor data processing or testing on a different platform such as a Raspberry Pi.

```python
import time
import Adafruit_ADS1x15

# Create an ADS1115 ADC (16-bit) instance.
adc = Adafruit_ADS1x15.ADS1115()

# Gain settings for the ADC
GAIN = 1

def read_voltage():
    # Read the ADC channel 0 (connected to voltage sensor)
    adc_value = adc.read_adc(0, gain=GAIN)
    voltage = adc_value * (4.096 / 32767)  # Adjust the conversion factor as needed
    return voltage

def read_current():
    # Read the ADC channel 1 (connected to current sensor)
    adc_value = adc.read_adc(1, gain=GAIN)
    current = adc_value * (4.096 / 32767)  # Adjust the conversion factor as needed
    return current

def read_rpm():
    # Example RPM reading function, modify as needed for your sensor
    # Here, a simple counter for pulses over time might be implemented
    pulse_count = 0
    start_time = time.time()
    while (time.time() - start_time) < 1:
        # Check the digital input for RPM pulses
        if read_digital_input():
            pulse_count += 1
    rpm = pulse_count * 60  # Convert to RPM
    return rpm

def read_digital_input():
    # Placeholder function for reading digital input
    # Replace this with actual GPIO reading code
    return False

if __name__ == "__main__":
    while True:
        voltage = read_voltage()
        current = read_current()
        rpm = read_rpm()
        
        print(f"Voltage: {voltage} V, Current: {current} A, RPM: {rpm}")
        
        time.sleep(1)

