# 🔆 Smart Brightness Control using ESP32 & OLED

A smart embedded system project that controls LED brightness using a potentiometer and displays real-time brightness levels on an OLED display using ESP32-C3.

---

## 📌 Features
- Real-time LED brightness control
- OLED display output
- Potentiometer-based input
- Smooth PWM brightness control
- I2C communication

---

## 🧰 Components Used
- ESP32-C3 (Geeky Board XC3M)
- OLED Display (SSD1306, I2C)
- LED
- Potentiometer
- Resistors
- Breadboard & Jumper Wires

---

## 🔌 Circuit Connections

### OLED (I2C)
| OLED Pin | ESP32-C3 |
|--------|----------|
| VCC | 3.3V |
| GND | GND |
| SDA | GPIO 3 |
| SCL | GPIO 2 |

### LED
| LED | ESP32-C3 |
|----|----------|
| Anode | GPIO 5 |
| Cathode | GND |

### Potentiometer
| Pin | ESP32-C3 |
|----|----------|
| VCC | 3.3V |
| GND | GND |
| OUT | GPIO 4 (ADC) |

---

## 🧠 Working
- Potentiometer value is read using ADC.
- LED brightness is controlled using PWM.
- Brightness percentage is displayed on the OLED screen in real-time.

---

## 📷 Output
![OLED Output](![WhatsApp Image 2025-12-14 at 09 28 26_58ca1090](https://github.com/user-attachments/assets/6bbeff80-2a25-4018-9478-2fc145ae2122)
)

---

## 🧑‍💻 Technologies Used
- Embedded C / C++
- Arduino IDE
- ESP32
- I2C Communication
- PWM & ADC

---

## 🚀 Future Improvements
- Automatic brightness using LDR
- Wi-Fi control using ESP32
- Mobile App integration

---

## 📄 Author
**Aasif**  
Embedded Systems & IoT Enthusiast
