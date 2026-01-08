# Temperature & Soil Moisture Monitoring System

Prototype B is an enhanced environmental monitoring system that measures temperature and soil moisture using sensors and displays real-time data on an OLED screen. It uses LED indicators to show temperature status and provides soil condition feedback, making it suitable for smart agriculture and plant monitoring projects.

# Components Used

* DHT11 Temperature Sensor

* Soil Moisture Sensor (Analog)

* OLED Display (128×64, I2C)

* Red LED (Hot indicator)

* Green LED (Cool indicator)

* Microcontroller (Arduino / ESP32)

# How It Works

* Reads temperature from the DHT11 sensor

* Reads soil moisture level 

* Compares temperature to a threshold (25°C)

* Turns RED LED ON if temperature is high

* Turns GREEN LED ON if temperature is normal

# Checks soil moisture:

* Displays “Soil Dry” if value exceeds threshold

* Displays “Soil Moist” otherwise

* Updates data every 2 seconds

# Output

* OLED Display: Temperature, soil moisture value, and status

* LEDs: Visual temperature indicators

* Serial Monitor: Sensor readings for debugging

# Use Case

* Smart plant monitoring system

* IoT 
