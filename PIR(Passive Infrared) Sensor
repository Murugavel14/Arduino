int led = 13;
int pirpin = 12;

void setup() {
  Serial.begin(9600);
  //pinMode declare is not necessary
}

void loop() {
  int sensorvalue = digitalRead(pirpin);  //Read sensor value
  if (sensorvalue == HIGH)
  {
    Serial.println("Motion detect");
    digitalWrite(led, HIGH);            //Motion detect to LED is ON
    delay(500);
  }
  else
  {
    Serial.println("No detect");
    digitalWrite(led, LOW);            //Motion is not detect to LED is OFF
    delay(500);
  }
}

//code writen by Murugavel
