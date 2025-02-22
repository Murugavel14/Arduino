//In further modification on future

#include <Servo.h>
int servoPin=11;
Servo servo1;
const char* a[]={"RED","BLUE"};// must declare on this type
int i = 0;
void setup() {
  servo1.attach(servoPin);//it's like 
}

void loop() {
 servo1.write(90);
  delay(3000);
 for (i=0;i<2;i++){
  if (strcmp(a[i], "RED") == 0){ //string compare, str can't compare directly 
    servo1.write(0);
    delay(2000);
    servo1.write(90);
   delay(2000);
  }
  else{
    servo1.write(180);
    delay(2000);
  }
 }
}
//Code written by Murugavel
