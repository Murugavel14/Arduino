#include "DHT.h"
#include <LiquidCrystal.h>

#define DHTPIN 6     
#define DHTTYPE DHT22  

int speaker = 13;
int ld = 7;

LiquidCrystal lcd(12,11,5,4,3,2);

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  pinMode(ld, OUTPUT);
  pinMode(speaker, OUTPUT); 
  Serial.begin(9600);
  dht.begin();
  lcd.begin(16, 2);
  //lcd.print("welcome");
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  Serial.print(F("Humidity: "));
  Serial.print(humidity);
  Serial.print(F("%  Temperature: "));
  Serial.print(temperature);
  Serial.println(F("°C "));

  

  if (temperature < 32) {
    Serial.println("tempreture is normal");
    digitalWrite(ld, LOW); 
    digitalWrite(speaker, LOW);  
    noTone(speaker); 
    lcd.setCursor(0, 0);
    lcd.print("Temp is normal");
    //lcd.clear(); 
  } else {
      
    lcd.setCursor(0, 0);
    lcd.print("Temp is rising");
    //lcd.clear(); 
    digitalWrite(ld, HIGH); 
    tone(speaker, 200); 
    Serial.println("Tempreture is rising");
    }


  delay(1000); 
}

//code written by Murugavel
