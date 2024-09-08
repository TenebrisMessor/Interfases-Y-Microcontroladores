/* Display de 7 segmentos catodo comun de dos digitos. 
Max73219*/

#include <LedControl.h>

const int DIN = 11; 
const int CS_PIN = 10;  
const int CLK = 13;  

LedControl lc = LedControl(DIN, CLK, CS_PIN, 1);  

int horas = 12;
int minutos = 30;

void setup() {
  lc.shutdown(0, false);      
  lc.setIntensity(0, 8);      
  lc.clearDisplay(0);          
  
  actualizarDisplay();
}

void loop() {
  delay(1000);
  incrementarMinuto();
  actualizarDisplay();
}

void actualizarDisplay() {
  int digito_hora_unidad = horas % 10;
  int digito_hora_decena = horas / 10;

  int digito_minuto_unidad = minutos % 10;
  int digito_minuto_decena = minutos / 10;

  lc.setDigit(0, 3, digito_hora_decena, false); 
  lc.setDigit(0, 2, digito_hora_unidad, true); 

  lc.setDigit(0, 1, digito_minuto_decena, false);  
  lc.setDigit(0, 0, digito_minuto_unidad, false);  
}

void incrementarMinuto() {
  minutos++;
  if (minutos >= 60) {
    minutos = 0;
    horas++;
    if (horas >= 24) {
      horas = 0;
    }
  }
}