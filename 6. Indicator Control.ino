//in future can optimize or reprogram this code..
const int s1 = 12;  // Button 1 pin
const int s2 = 5;   // Button 2 pin
const int led = 13; // LED pin

void setup() {
    Serial.begin(9600);

    // Configure pins
    pinMode(s1, INPUT);
    pinMode(s2, INPUT);
    pinMode(led, OUTPUT);
}

void loop() {
    //s3 = digitalRead(s1);
    //if (s3 == 1) {  // Check if Button 1 is pressed
       // digitalWrite(led, HIGH);
        while (true) { // Stay in loop while button is pressed
            if (digitalRead(s1) == 1 && digitalRead(s2) == 1) { // Check if Button 2 is pressed
                digitalWrite(led, HIGH);
                Serial.println("LED ON");
                Serial.println("N/C");
                delay(1000);
            } else if (digitalRead(s1) == 1 && digitalRead(s2) != 1) {
                digitalWrite(led, LOW);
                Serial.println("reset");
                delay(1000);
            }
            else if (digitalRead(s1) != 1 && digitalRead(s2) == 1){
                digitalWrite(led, LOW);
                Serial.println("reset");
                delay(1000);
            }
            else {
                digitalWrite(led, LOW);
                Serial.println("reset");
                delay(1000);
            }
        }
        
        //delay(1000);
}

//Code written by Murugavel

//SOURCE : https://wokwi.com/projects/424094057980385281
