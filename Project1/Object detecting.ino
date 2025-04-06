#include <SoftwareSerial.h> 
 
#include <Wire.h>  
#include <LiquidCrystal_I2C.h> 
char a [] = {'*','*','*','*','*','/'}; 
 
#define SENSORS 4  // No of ultrasonic sensors 
 
LiquidCrystal_I2C lcd(0x27,16,2); 
 
const int trigPins[SENSORS] = {4, 6, 8, 10};  // Trigger pins 
const int echoPins[SENSORS] = {5, 7, 9, 11};  // Echo pins 
const int buzzer = 12; //Buzzer 
const int ledPin = 13; //LED 
 
SoftwareSerial sim800c(2, 3); // SIM800C RX → Arduino TX (3), TX → Arduino RX (2) 
 
bool smsSent[SENSORS] = {false, false, false, false};  // One-time SMS flags 
 
void setup() { 
  Serial.begin(115200); //Serial Monitor window baudrate 
  sim800c.begin(9600); 
  lcd.init(); 
  lcd.backlight(); 
  lcd.setCursor(0, 0); 
  lcd.print("System ON!!"); 
  delay(750); 
  lcd.setCursor(0, 1); 
  for (int i = 0; i <6 ; i++){ //for loading UI 
    lcd.print(a[i]); 
    delay(350); 
  } 
  lcd.clear(); 
  pinMode(ledPin, OUTPUT); 
  digitalWrite(ledPin, LOW); 
 
 
 
 
  for (int i = 0; i < SENSORS; i++) { 
    pinMode(trigPins[i], OUTPUT); 
    pinMode(echoPins[i], INPUT); 
  } 
 
  delay(2000); 
  Serial.println("System Ready with 4 Sensors..."); 
} 
 
void sendSMS(int sensorNum, long distance) { 
  Serial.print("Sending SMS for Sensor "); 
  Serial.println(sensorNum + 1); 
 
  sim800c.println("AT+CMGF=1"); //this command sends an SMS message to a GSM 
phone 
  delay(1000); 
  sim800c.println("AT+CMGS=\"+91\"");  // Replace with your number 
  delay(1000); 
  sim800c.print("Alert! Sensor "); 
  sim800c.print(sensorNum + 1); 
  sim800c.print(" detected an object at "); 
  sim800c.print(distance); 
  sim800c.println(" cm."); 
  sim800c.write(26); // CTRL+Z 
  delay(3000); 
 
  Serial.println("SMS Sent!"); 
} 
 
void loop() { 
  bool objectDetected = false; 
 
  for (int i = 0; i < SENSORS; i++) { 
    digitalWrite(trigPins[i], LOW); 
    delayMicroseconds(2); 
    digitalWrite(trigPins[i], HIGH); 
    delayMicroseconds(10); 
    digitalWrite(trigPins[i], LOW); 
 
    long duration = pulseIn(echoPins[i], HIGH, 30000); 
    long distance = duration * 0.034 / 2; 
 
    Serial.print("Sensor "); 
    Serial.print(i + 1); 
    Serial.print(": "); 
 
 
 
    Serial.print(distance); 
    Serial.println(" cm"); 
 
    if (distance > 0 && distance < 100) { //checking the Sensor close to 100cm 
range 
      digitalWrite(ledPin, HIGH); 
      tone(buzzer, 10000); 
      delay(200); 
      noTone(buzzer); 
      delay(100); 
      objectDetected = true; 
      lcd.clear(); 
      lcd.setCursor(0, 0); 
      lcd.print("Detect"); 
      delay(500); 
      if (!smsSent[i]) { //sms send only one time 
        sendSMS(i, distance); 
        smsSent[i] = true; 
 
      } 
    } else { 
      smsSent[i] = false; // Reset flag when object is gone 
    } 
  } 
 
  if (!objectDetected) { //sensors not detect object 
    digitalWrite(ledPin, LOW); 
    Serial.println("LED OFF: No object detected."); 
    noTone(buzzer); 
    lcd.clear(); 
    lcd.setCursor(0, 0); 
    lcd.print("not detect"); 
    delay(500); 
  } 
 
  Serial.println(); 
  delay(500); 
} 
 
//code END
