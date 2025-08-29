# Arduino Micro SD Card Module Project  

[![Arduino](https://img.shields.io/badge/Board-Arduino-blue?logo=arduino)](https://www.arduino.cc/en/Main/ArduinoBoardUno)  [![Language](https://img.shields.io/badge/Language-Arduino%20C++-orange?logo=c%2B%2B)](https://www.arduino.cc/reference/en/)  [![Project](https://img.shields.io/badge/Project-CircuitDigest-green)](https://circuitdigest.com)  

---

## 📖 Tutorial  
Read the complete guide here: [Arduino Micro SD Card Module Project](https://circuitdigest.com/microcontroller-projects/interfacing-micro-sd-card-module-with-arduino)  

## 🔧 Project Type  
👉 [Arduino Project](https://circuitdigest.com/arduino-projects)  

---

## 🖼️ Main Project Image  
![Arduino Micro SD Card Module](https://circuitdigest.com/sites/default/files/projectimage_mic/Arduino-Micro-SD-Card-Module.jpg)  

---

## 🚀 Features  
- Interface Micro SD Card module with Arduino using SPI communication.  
- Store and retrieve data from an SD card.  
- Simple and expandable example for **data logging projects**.  
- Demonstrates **file creation, writing, and reading** using Arduino SD library.  

---

## 🛠️ Hardware Requirements  

| Component | Quantity | Description |
|-----------|----------|-------------|
| Arduino UNO | 1 | Main microcontroller board |
| Micro SD Card Module | 1 | SPI-based storage module |
| Micro SD Card | 1 | Formatted in FAT16/FAT32 |
| Jumper Wires | As needed | For connections |
| Breadboard | 1 | Optional for easy wiring |

---

## ⚙️ How It Works  
1. The Arduino initializes the SD card module via SPI.  
2. It checks if `data_log.txt` exists on the card.  
3. If not present, the file is created automatically.  
4. Arduino writes sample data (`Testing Data Write 1, 2, 3.`) into the file.  
5. The file is then read back, and the contents are printed on the **Serial Monitor**.  
6. This demonstrates **read/write capability**, essential for data logging.  

---

## 🔌 Circuit Connection  

![Arduino Micro SD Card Module Circuit](https://circuitdigest.com/sites/default/files/inlineimages/u4/Micro-SD-Card-Module-with-Arduino.png)  

| Micro SD Module Pin | Arduino UNO Pin |
|----------------------|-----------------|
| VCC | 5V |
| GND | GND |
| MISO | D11 |
| MOSI | D12 |
| SCK | D13 |
| CS | D10 |

---

## 🧠 Troubleshooting  

| Issue | Solution |
|-------|----------|
| SD card not detected | Ensure card is formatted as FAT16/FAT32 |
| Initialization failed | Check CS pin connection and correct power supply |
| File not created | Verify chip select pin number in code |
| Old SD card errors | Clean contacts and reformat properly |

---

## 📱 Applications  
- Data loggers (temperature, humidity, GPS).  
- Event recording systems.  
- Portable storage for embedded systems.  
- Projects needing large storage beyond Arduino’s memory.  

---

## 🔮 Future Enhancements  
- Add **real-time clock (RTC)** for timestamped logs.  
- Expand to **multi-sensor logging** (environmental monitoring).  
- Use **wireless modules** (ESP8266/ESP32) to upload logs to the cloud.  

---

## 🧪 Technical Specifications  

| Parameter | Value |
|-----------|-------|
| Operating Voltage | 3.3V – 5V |
| Communication Protocol | SPI |
| File Systems Supported | FAT16 / FAT32 |
| Typical Current Consumption | ~50mA |
| Max Storage | Depends on SD card capacity (tested up to 32GB) |

---

## 🔗 Links  
- Tutorial: [Arduino Micro SD Card Module Project](https://circuitdigest.com/microcontroller-projects/interfacing-micro-sd-card-module-with-arduino)  
- IDE: [Arduino IDE Download](https://www.arduino.cc/en/software)  
- GitHub Code: [CircuitDigest Arduino SD Card Repo](https://github.com/Circuit-Digest/Basic-Arduino-Tutorials-for-Beginners-/tree/main/SD%20Card%20Module%20with%20Arduino)  
- Datasheet: [LM1117 Voltage Regulator](https://www.ti.com/lit/ds/symlink/lm1117.pdf)  
- Related Project: [Arduino Data Logger](https://circuitdigest.com/microcontroller-projects/arduino-data-logger-project)  

---

## ⭐ Support  
This project is published by [CircuitDigest](https://circuitdigest.com).  
Explore more tutorials, projects, and resources at **CircuitDigest.com** 🚀  

---

## 🔖 Keywords  
`Arduino` `Micro SD Card Module` `SPI Communication` `Arduino Data Logger` `FAT16` `FAT32` `Data Storage` `Embedded Systems`
