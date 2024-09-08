#include <Servo.h>
Servo servo01;

int PINSERVO = 2;
int PULSOMIN = 1000;
int PULSOMAX = 2000;

void setup(){
  servo01.attach(PINSERVO, PULSOMIN, PULSOMAX);
}

void loop(){
  servo01.write(0);
  delay(5000);
  servo01.write(180);
  delay(5000);
}