/*
 * Project: Gas Leakage Detection System
 * Author: [Your Name]
 * Components: MQ-2, SIM800L, Arduino Uno, Buzzer
 */

#include <SoftwareSerial.h>

// GSM Module: RX Pin 2, TX Pin 3
SoftwareSerial gsmSerial(2, 3); 

const int gasSensorPin = A0;
const int buzzerPin = 8;
const int threshold = 400; // Adjust sensitivity here

void setup() {
  pinMode(gasSensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  
  Serial.begin(9600);
  gsmSerial.begin(9600);

  Serial.println("System Initializing...");
  delay(10000); // Wait for GSM network
  Serial.println("System Ready!");
}

void loop() {
  int gasValue = analogRead(gasSensorPin);
  Serial.print("Gas Level: ");
  Serial.println(gasValue);

  if (gasValue > threshold) {
    digitalWrite(buzzerPin, HIGH);
    Serial.println("GAS LEAKAGE DETECTED!");
    
    sendSMS();
    makeCall();
    
    // Prevent continuous calling/SMS
    delay(30000); 
  } else {
    digitalWrite(buzzerPin, LOW);
  }
  delay(500);
}

void sendSMS() {
  gsmSerial.println("AT+CMGF=1"); 
  delay(1000);
  gsmSerial.println("AT+CMGS=\"+91XXXXXXXXXX\""); // <-- CHANGE NUMBER HERE
  delay(1000);
  gsmSerial.print("ALERT: Gas Leakage Detected at Home!");
  delay(100);
  gsmSerial.write(26); 
  delay(5000);
  Serial.println("SMS Sent.");
}

void makeCall() {
  Serial.println("Calling...");
  gsmSerial.println("ATD+91XXXXXXXXXX;"); // <-- CHANGE NUMBER HERE
  delay(20000); 
  gsmSerial.println("ATH"); 
  Serial.println("Call Finished.");
}
