#include <LiquidCrystal.h>

int rs = 7;
int e = 6;
int d4 = 5;
int d5 = 4;
int d6 = 3;
int d7 = 2;

LiquidCrystal lcd(rs, e, d4, d5, d6, d7);

void setup() {
  lcd.begin(16,2);
}
//Primera parte solicitando clave y colocando un punto indicador parpadeante.
void loop(){
  lcd.setCursor(0,0);
  lcd.print("INGRESA LA CLAVE");
  lcd.setCursor(0,1);
  lcd.cursor();
  delay(500);
  lcd.noCursor();
  delay(500);
}

//Alerta de alarma activada
/*void loop(){
  lcd.setCursor(0,0);
  lcd.print("ALARMA ACTIVA!");
  lcd.display();
  delay(500);
  lcd.noDisplay();
  delay(500);
}*/


//Nombre
/*
  lcd.setCursor(0,0);
  lcd.print("ARIEL HR");
  lcd.display();
  delay(500);
  lcd.noDisplay();
  delay(500);

*/