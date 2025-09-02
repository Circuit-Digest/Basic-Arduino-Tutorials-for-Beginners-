# Arduino MPU6050 Sensor Module

[![Arduino](https://img.shields.io/badge/Board-Arduino-blue?logo=arduino)](https://www.arduino.cc/en/Main/Products)
[![Language](https://img.shields.io/badge/Language-Arduino%20C++-brightgreen?logo=c%2B%2B)](https://www.arduino.cc/reference/en/)
[![CircuitDigest Project](https://img.shields.io/badge/Project-CircuitDigest-orange)](https://circuitdigest.com)

---

## 🔗 Tutorial Link  
[Arduino MPU6050 Sensor Module](https://circuitdigest.com/microcontroller-projects/interfacing-mpu6050-module-with-arduino)

## 🔗 Project Type  
[Arduino Project](https://circuitdigest.com/arduino-projects)

---

![Arduino MPU6050 Sensor Module](https://circuitdigest.com/sites/default/files/projectimage_mic/Arduino-MPU6050-Sensor-Module.jpg)

---

## 🚀 Features
- Reads **3-axis accelerometer** and **3-axis gyroscope** data.  
- Provides **temperature sensor output**.  
- Uses **I2C communication** for simple wiring.  
- Supports **multiple sensor modules** via address configuration.  
- Compatible with Arduino using **Adafruit MPU6050 library**.  

---

## 🛠️ Hardware Requirements

| Component             | Quantity | Description |
|------------------------|----------|-------------|
| Arduino Uno/Nano       | 1        | Microcontroller board |
| MPU6050 Module         | 1        | Accelerometer + Gyroscope sensor |
| Jumper Wires           | As req.  | Male-to-female for connections |
| Breadboard             | 1        | For prototyping |
| USB Cable              | 1        | For Arduino programming |

---

## ⚙️ How It Works
1. The **MPU6050 IMU** combines a 3-axis accelerometer and a 3-axis gyroscope in a single chip.  
2. It communicates with the Arduino via the **I2C bus (SCL & SDA pins)**.  
3. The onboard **Digital Motion Processor (DMP)** preprocesses motion data before sending it to Arduino.  
4. Arduino collects acceleration, gyroscope, and temperature readings and displays them on the Serial Monitor.  
5. Libraries like **Adafruit MPU6050** simplify setup and sensor reading.  

---

## 🔌 Circuit Connection

![Arduino MPU6050 Circuit Diagram](https://circuitdigest.com/sites/default/files/inlineimages/u4/Arduino-MPU6050-Connection.jpg)

| MPU6050 Pin | Arduino Pin | Description |
|-------------|-------------|-------------|
| VCC         | 5V          | Power supply |
| GND         | GND         | Ground |
| SCL         | A5          | I2C Clock |
| SDA         | A4          | I2C Data |
| INT         | D2 (opt.)   | Interrupt output (optional) |

---

## 🧠 Troubleshooting

| Issue                        | Possible Cause                      | Solution |
|-------------------------------|-------------------------------------|----------|
| “Failed to find MPU6050 chip” | Loose connection / wrong wiring     | Recheck pin mapping |
| Garbage values in Serial      | Baud rate mismatch                  | Set Serial Monitor to **115200 baud** |
| No readings                   | Libraries not installed properly    | Install Adafruit MPU6050, Unified Sensor, and Bus IO libraries |
| Fluctuating readings          | Electrical noise / poor wiring      | Use shorter jumper wires and ensure proper ground |

---

## 📱 Applications
- **DIY Self-Balancing Robot using Arduino**  
- **Hand Gesture Controlled Robotic Arm using Arduino Nano**  
- **Portable Step Counter using ATtiny85**  
- Motion sensing in **drones and robotics**  
- Orientation detection in **wearable electronics**  

---

## 🔮 Future Enhancements
- Add **OLED/LCD display** for real-time data visualization.  
- Implement **sensor fusion algorithms** (e.g., Kalman filter) for smoother results.  
- Use **wireless communication** (Bluetooth/Wi-Fi) to transmit motion data.  
- Combine with a **magnetometer** for full 9-axis IMU capability.  

---

## 🧪 Technical Specifications

| Parameter                  | Value |
|-----------------------------|-------|
| Accelerometer Range         | ±2g, ±4g, ±8g, ±16g |
| Gyroscope Range             | ±250, ±500, ±1000, ±2000 °/s |
| Communication Interface     | I2C (up to 400kHz) |
| Operating Voltage           | 3V – 5V |
| Measurement Resolution      | 16-bit |
| Built-in Processor          | Digital Motion Processor (DMP) |
| Dimensions (Module)         | ~20mm x 15mm |

---

## 🔗 Links
- [Arduino MPU6050 Sensor Module](https://circuitdigest.com/microcontroller-projects/interfacing-mpu6050-module-with-arduino)  
- [Arduino IDE Download](https://www.arduino.cc/en/software)  
- [MPU6050 Datasheet](https://invensense.tdk.com/products/motion-tracking/6-axis/mpu-6050/)  
- [Hand Gesture Controlled Robotic Arm using Arduino Nano](https://circuitdigest.com/microcontroller-projects/diy-hand-gesture-controlled-robotic-arm-using-arduino-nano)  
- [DIY Self-Balancing Robot using Arduino](https://circuitdigest.com/microcontroller-projects/arduino-based-self-balancing-robot)  
- [Portable Step Counter using ATtiny85](https://circuitdigest.com/microcontroller-proejcts/build-a-portable-step-counter-using-attiny85-and-mpu6050)  
- [GitHub Code & Schematics](https://github.com/Circuit-Digest/Basic-Arduino-Tutorials-for-Beginners-/tree/main/Interfacing%20MPU6050%20With%20Arduino)  

---

## ⭐ Support
This project is published by [CircuitDigest](https://circuitdigest.com) — a community of engineers and makers.  
If you found this helpful, consider exploring more tutorials and projects on our website.

---

## 🔖 Keywords
`Arduino` `MPU6050` `Accelerometer` `Gyroscope` `I2C` `Sensor Module` `IMU` `Motion Tracking` `CircuitDigest`
