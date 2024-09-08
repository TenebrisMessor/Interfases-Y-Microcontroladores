#include <MatrizLed.h>
MatrizLed pantalla;
/*
void setup(){
  pantalla.begin(12,11,19,1);
  pantalla.borrar();
  pantalla.setLed(0,0,0, true);
  pantalla.setLed(0,1,1, true);
  pantalla.setLed(0,2,2, true);
  pantalla.setLed(0,3,3, true);
  pantalla.setLed(0,4,4, true);
  pantalla.setLed(0,5,5, true);
  pantalla.setLed(0,6,6, true);
  pantalla.setLed(0,7,7, true);
}*/


//PARTE 2
void setup(){}

void loop(){
efectoHorizontal();  
}

void efectoHorizontal(){
  for(int i = 0; i <= 7; i++){
    for(int j = 0; j <= 7; j++){
      pantalla.setLed(0,i,j,true);
    }
    delay(100);
    for (int j = 0; j <= 7; j++){
      pantalla.setLed (0,i,j,false);
    }
  }

}

