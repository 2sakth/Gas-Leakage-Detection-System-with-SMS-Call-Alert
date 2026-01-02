# Gas Leakage Detection System with SMS and Call Alert

This project is designed to detect gas leakages (like LPG, Butane, or Smoke) and provide immediate alerts through a loud buzzer, an SMS message, and a phone call to a predefined mobile number.

## 🚀 Features
- **Real-time Monitoring:** Continuously checks gas levels using the MQ-2 sensor.
- **Audio Alarm:** Triggers a buzzer when gas levels exceed the safety limit.
- **SMS Alert:** Sends a text notification via SIM800L GSM module.
- **Phone Call Alert:** Automatically dials a phone number for emergency notification.

## 🛠 Components Required
- **Microcontroller:** Arduino Uno
- **Sensor:** MQ-2 Gas Sensor
- **GSM Module:** SIM800L (with a valid 2G/4G SIM card)
- **Output:** Buzzer
- **Power:** 5V for Arduino, 3.7V-4.2V (2A) for SIM800L

## 🔌 Circuit Connection
| Component | Arduino Pin |
| :--- | :--- |
| MQ-2 VCC | 5V |
| MQ-2 GND | GND |
| MQ-2 A0 | A0 |
| SIM800L TX | Pin 2 |
| SIM800L RX | Pin 3 |
| SIM800L GND | GND (Common) |
| Buzzer (+) | Pin 8 |
| Buzzer (-) | GND |

## 💻 How to Use
1. Clone this repository or download the `.ino` file.
2. Open the code in **Arduino IDE**.
3. Replace `+91XXXXXXXXXX` with your actual mobile number.
4. Install `SoftwareSerial` library (usually built-in).
5. Upload the code to your Arduino Uno.
6. 
