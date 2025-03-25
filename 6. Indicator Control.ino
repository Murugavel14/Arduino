const int s1 = 12;  // Button 1 pin
const int s2 = 5;   // Button 2 pin
const int led = 13; // LED pin
int c1 = 0;
int c2 = 0;

//int s3 = 0;
void setup() {
    Serial.begin(9600);

    // Configure pins
    pinMode(s1, INPUT);
    pinMode(s2, INPUT);
    pinMode(led, OUTPUT);
}

void loop() {
    c1 = digitalRead((5));
    digitalWrite(led, c1);
    delay(5000);
    while (c1 == 1){
      delay(5000);
      c2 = digitalRead((12));
      if (c1 ==1 && c2 == 1){
        Serial.println("N/C");
        delay(5000);
      }
      
      else if(c1 == 1 && c2 == 0){
        Serial.println("Reset");
        digitalWrite(led, LOW);
        delay(5000);
      }
      Serial.println("done");
    }
    Serial.println("not in loop");
       // delay(1000);
}

//Code written by Murugavel

//SOURCE:https://wokwi.com/projects/424094057980385281
