#include <DallasTemperature.h>
#include <OneWire.h>
int sensorPin = 2;
OneWire oneWire (sensorPin); 
DallasTemperature sensor (&oneWire);

void setup() {
   Serial.begin (9600);
}

void loop() {
  sensor.requestTemperatures ();
  float temp = sensor.getTempCByIndex (0);
  Serial.print ("Temperature: ");
  Serial.print (temp);
  Serial.println ("ºC");
  delay (1000);
}

//code written by vel
