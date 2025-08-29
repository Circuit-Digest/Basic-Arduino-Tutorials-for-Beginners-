# GP2Y1014AU0F Dust Sensor Arduino Interface

![Dust Sensor](https://img.shields.io/badge/Sensor-GP2Y1014AU0F-blue.svg)
![Arduino](https://img.shields.io/badge/Platform-Arduino-green.svg)
![License](https://img.shields.io/badge/License-MIT-yellow.svg)

## 📝 Project Overview

This project demonstrates how to interface the [**GP2Y1014AU0F Dust Sensor**](https://circuitdigest.com/microcontroller-projects/interfacing-sharp-gp2y1014au0f-sensor-with-arduino-to-build-air-quality-analyzer) with Arduino to create an affordable air quality monitoring system. The sensor provides basic particle detection capabilities for dust and smoke using optical sensing technology, making it perfect for educational projects and basic air quality monitoring applications.

## 🖼️ Main Project Image
![Interfacing Dust Sensor with Arduino](https://circuitdigest.com/sites/default/files/projectimage_mic/Arduino-Dust-Sensor-Interfacing.jpg)  

## 🔗 Tutorial Reference

Complete tutorial and technical details available at: [Interfacing Dust Sensor with Arduino - CircuitDigest](https://circuitdigest.com/microcontroller-projects/interfacing-dust-sensor-with-arduino)

## ✨ Key Features

- **💰 Budget-Friendly**: Economical alternative to expensive PM sensors (~$5)
- **🔌 Simple Interface**: Single analog output for easy Arduino integration
- **🎯 Reliable Detection**: Optical dust and smoke detection technology
- **📏 Compact Design**: Small form factor ideal for portable projects
- **🌐 Versatile Applications**: Air quality monitoring, HVAC systems, industrial automation

## 🛠️ Hardware Requirements

### Components Needed:
- Arduino Uno/Nano/ESP32
- GP2Y1014AU0F Dust Sensor Module
- 150Ω Resistor (for LED current limiting)
- 220μF Capacitor (for pulse timing)
- Jumper wires
- Breadboard (optional)

### Sensor Specifications:
- **Operating Voltage**: 4.5V - 5.5V
- **Output Type**: Analog (0V - 3.4V)
- **Detection Range**: 0.5μm particles and larger
- **Response Time**: < 1 second
- **Operating Temperature**: -10°C to +65°C

## 🔌 Pin Configuration & Wiring

### GP2Y1014AU0F Pinout:

| Pin | Function | Description |
|-----|----------|-------------|
| V-LED | LED Power | Connect to 5V via 150Ω resistor |
| LED-GND | LED Ground | Connect to Arduino GND |
| LED | LED Control | Connect to Digital Pin (D7) |
| S-GND | Sensor Ground | Connect to Arduino GND |
| VOUT | Analog Output | Connect to Analog Pin (A0) |
| VCC | Power Supply | Connect to Arduino 5V |

### Circuit Connections:

```
GP2Y1014AU0F    →    Arduino Uno
─────────────────────────────────
V-LED           →    5V (via 150Ω resistor)
LED-GND         →    GND
LED             →    Digital Pin 7
S-GND           →    GND
VOUT            →    Analog Pin A0
VCC             →    5V
```

### ⚠️ Important Circuit Notes:
- **150Ω Resistor**: Must be connected between V-LED and 5V supply
- **220μF Capacitor**: Connect between V-LED and LED-GND for proper pulse timing
- **5V Power Supply**: Sensor requires stable 5V supply for accurate readings

## 💻 Arduino Code

```cpp
/*
 * GP2Y1014AU0F Dust Sensor Interface with Arduino
 * Measures dust particle density in μg/m³
 */

#define measurePin A0    // Analog pin for sensor output
#define ledPower 7       // Digital pin for LED control

// Timing parameters (microseconds)
int samplingTime = 280;  // Sampling delay
int deltaTime = 40;      // Additional pulse width
int sleepTime = 9680;    // Sleep period

// Variables for calculations
float voMeasured = 0;
float calcVoltage = 0;
float dustDensity = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ledPower, OUTPUT);
  Serial.println("GP2Y1014AU0F Dust Sensor Initialized");
  Serial.println("Dust Density (μg/m³):");
}

void loop() {
  // LED pulse timing sequence
  digitalWrite(ledPower, LOW);          // Turn on LED
  delayMicroseconds(samplingTime);      // Wait 280μs
  voMeasured = analogRead(measurePin);  // Read sensor value
  delayMicroseconds(deltaTime);         // Wait 40μs more
  digitalWrite(ledPower, HIGH);         // Turn off LED
  delayMicroseconds(sleepTime);         // Sleep for remaining time
  
  // Convert ADC reading to voltage
  calcVoltage = voMeasured * (5.0 / 1024.0);
  
  // Calculate dust density using linear equation
  dustDensity = 170 * calcVoltage - 0.1;
  
  // Print results
  Serial.print("Dust Density: ");
  Serial.print(dustDensity);
  Serial.println(" μg/m³");
  
  delay(1000);  // Update every second
}
```

## 🔍 How It Works

The GP2Y1014AU0F sensor uses **optical detection technology** with three main components:

1. **LED Light Source**: Infrared LED provides illumination
2. **Photodiode Detector**: Receives reflected/scattered light
3. **Optical Lenses**: Focus light beam in detection area

### Detection Process:
1. LED is pulsed with specific timing (0.32ms pulse width)
2. When dust particles enter the detection area, they scatter the LED light
3. Photodiode detects the scattered light intensity
4. Current from photodiode is converted to proportional voltage
5. Voltage level indicates dust particle concentration

### Timing Requirements:
- **Total cycle**: 10ms
- **LED pulse width**: 0.32ms maximum
- **Sampling time**: 0.28ms after LED activation
- **Sleep period**: 9.68ms between measurements

## 📊 Calibration & Accuracy

### Sensor Characteristics:
- **Accuracy**: ±15% under ideal conditions
- **Sensitivity**: Detects particles ≥0.5μm
- **Output Range**: 0V - 3.4V (corresponds to dust density)
- **Baseline**: ~0.6V in clean air

### Dust Density Calculation:
```
Dust Density (μg/m³) = 170 × Voltage - 0.1
```

*Note: This equation is based on empirical calibration by Chris Nafis*

## 🔧 Troubleshooting Guide

| Issue | Possible Cause | Solution |
|-------|---------------|----------|
| No readings | Power supply issues | Verify stable 5V supply |
| Erratic values | Missing components | Check 150Ω resistor and 220μF capacitor |
| Low sensitivity | Timing problems | Verify microsecond delays in code |
| Negative readings | Voltage offset | Implement baseline calibration |
| Inconsistent data | Electrical noise | Improve grounding and shielding |

### Common Issues:
1. **Incorrect Power Supply**: Sensor requires exactly 5V operation
2. **Missing RC Components**: 150Ω resistor and 220μF capacitor are mandatory
3. **Timing Precision**: Microsecond-level timing is critical for accurate readings
4. **USB Power Limitations**: Use external 5V supply for stable operation

## 🚀 Advanced Features & Extensions

### Multi-Sensor Setup:
- Connect multiple sensors using different analog pins
- Implement time-division multiplexing to avoid interference
- Use Arduino Mega for projects with 3+ sensors

### Data Logging:
- Add SD card module for data storage
- Implement WiFi connectivity for IoT integration
- Create web dashboard for remote monitoring

### Display Options:
- OLED/LCD display for real-time readings
- LED indicators for air quality levels
- Buzzer alerts for high particle concentrations

## 📈 Related Projects

1. **[IoT Air Quality Index Monitoring](https://circuitdigest.com/microcontroller-proejcts/iot-based-air-quality-index-monitoring-system-measure-pm25-pm10-co-using-esp32)** - Advanced system with PM2.5/PM10 sensors
2. **[SDS011 PM Monitor](https://circuitdigest.com/microcontroller-projects/air-quality-analyzer-using-arduino-and-nova-air-quality-sensor-sds011)** - Professional-grade particle measurement

## 📚 Technical Resources

- **[Sensor Datasheet](https://datasheet.lcsc.com/szlcsc/1905131608_Sharp-Microelectronics-GP2Y1014AU0F_C390729.pdf)**
- **[Application Note](https://www.elecrow.com/wiki/images/4/48/Gp2y1010au_appl_e.pdf)**
- **[Circuit Digest Tutorial](https://circuitdigest.com/microcontroller-projects/interfacing-dust-sensor-with-arduino)**

## ⚖️ Sensor Limitations

### GP2Y1014AU0F vs Professional PM Sensors:
- **GP2Y1014AU0F**: General dust detection, ±15% accuracy, $5 cost
- **PM2.5 Sensors**: Specific particle size measurement, ±5% accuracy, higher cost
- **Laser Sensors**: Advanced scattering technology, scientific-grade accuracy

### Best Use Cases:
- ✅ Educational projects and learning
- ✅ Basic air quality monitoring
- ✅ DIY home automation systems
- ✅ Proof-of-concept development
- ❌ Scientific research requiring high precision
- ❌ Regulatory compliance measurements

## 🤝 Contributing

1. Fork this repository
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🙏 Acknowledgments

- **Sharp Corporation** - For the GP2Y1014AU0F sensor
- **Chris Nafis** - For the dust density calculation equation
- **Circuit Digest** - For comprehensive tutorial and technical guidance
- **Arduino Community** - For continuous support and resources

---

**⭐ If this project helped you, please give it a star!**

**📧 Questions or suggestions? Feel free to open an issue!**
