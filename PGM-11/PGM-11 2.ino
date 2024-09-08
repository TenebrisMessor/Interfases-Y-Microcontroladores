int X, Y, SW;
int LED_IZQUIERDO = 3;
int LED_DERECHO = 5;
int LED_ABAJO = 6;
int LED_ARRIBA = 9;
int PULSADOR = 10;
int LED_SW = 11;

void setup(){
  pinMode(LED_IZQUIERDO, OUTPUT);
  pinMode(LED_DERECHO, OUTPUT);
  pinMode(LED_ABAJO, OUTPUT);
  pinMode(LED_ARRIBA, OUTPUT);
  pinMode(LED_SW, OUTPUT);
  pinMode(PULSADOR, INPUT);
}

void loop(){
  X = analogRead(A0);
  Y = analogRead(A1);
  SW = digitalRead(PULSADOR);
  if (X >=0 && X < 480){
    analogWrite(LED_IZQUIERDO, map(X, 0, 480, 255, 0));
  }else{
    analogWrite(LED_IZQUIERDO, 0);
  }
  if(X >= 520 && X < 1023){
    analogWrite(LED_DERECHO, map(X,520, 1023, 0, 255));
  }else{
    analogWrite(LED_DERECHO, 0);
  }
    if (Y >= 0 && Y < 480){
    analogWrite(LED_ABAJO, map(X, 0, 480, 255, 0));
  }else{
    analogWrite(LED_ABAJO, 0);
  }
    if (Y >= 520 && Y <1023){
    analogWrite(LED_ARRIBA, map(Y, 520, 10230, 0, 255));
  }else{
    analogWrite(LED_ARRIBA, 0);
  }
  digitalWrite(LED_SW, !SW);
}