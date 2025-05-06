int SIG[] = {3,4,6,7,9,10,12,13};
int RED[] = {2,2,5,5,8,8,11,11};
//int deet[] = {2,5,8,11};
void setup()
{
  //Nothing
  //digitalWrite(deet[], HIGH);
}

void loop()
{
  //for (int i=0;i<12;i++){
    //digitalWrite(SIG[i], HIGH);
    //delay(500);
    //digitalWrite(SIG[i], LOW);
    //delay(500);
  //}
  for (int i=0;i<9;i++){
    digitalWrite(2, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(RED[i], LOW);
    delay(300);
    digitalWrite(SIG[i], HIGH);
    delay(1000);
    digitalWrite(SIG[i], LOW);
    delay(1000);
  }
}
