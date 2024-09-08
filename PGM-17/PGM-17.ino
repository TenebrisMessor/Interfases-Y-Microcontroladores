#include <SoftwareSerial.h>
SoftwareSerial MIBT(10,11);
char DATO = 0;
int LEDROJO = 2;
int LEDVERDE = 3;

void setup(){
  MIBT.begin(38400);
  pinMode(LEDROJO, OUTPUT);
  pinMode()
}