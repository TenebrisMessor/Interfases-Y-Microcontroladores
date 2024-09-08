int TRIG = 10;
int ECO = 9;
int LED = 3;
long DURACION;
int DISTANCIA;

void setup(){
  pinMode(TRIG, OUTPUT);
  pinMode(ECO, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}
//PRIMERA PARTE DE LA PRACTICA COMENTAR UNA VEZ CALIFICADA Y DESCOMENTAR LA SEGUNDA PARTE.
/*
void loop(){
  digitalWrite(TRIG, HIGH);
  delay(1);
  digitalWrite(TRIG, LOW);
  DURACION = pulseIn(ECO, HIGH);
  DISTANCIA = DURACION / 58.2;
  Serial.println(DISTANCIA);
  delay(200);
}
*/

// PARTE dos. Descomentar y comentar la funcion loop  de arriba.

void loop(){
  digitalWrite(TRIG, HIGH);
  delay(1);
  digitalWrite(TRIG, LOW);
  DURACION = pulseIn(ECO, HIGH);
  DISTANCIA = DURACION / 58.2;
  Serial.println(DISTANCIA);
  delay(200);
  if(DISTANCIA <= 20 && DISTANCIA >= 0){
    digitalWrite(LED, HIGH);
    delay(DISTANCIA * 10);
    digitalWrite(LED, LOW);
  }
}
