int PULSADOR = 2;
int LAMPARA = 4;
int ESTADO = LOW;

void setup() {
  pinMode(PULSADOR, INPUT);
  pinMode(LAMPARA, OUTPUT);
}

void loop() {
  if (digitalRead(PULSADOR) == LOW) {
    delay(50);  // Anti-rebote, pequeño delay
    if (digitalRead(PULSADOR) == LOW) {  // Reconfirmamos estado
      ESTADO = digitalRead(LAMPARA);     // Leemos el estado actual de la lámpara
      digitalWrite(LAMPARA, !ESTADO);    // Cambiamos el estado de la lámpara
      while (digitalRead(PULSADOR) == LOW);  // Espera a que se suelte el pulsador
    }
  }
}