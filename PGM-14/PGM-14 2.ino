int IN1 = 2;
int IN2 = 3;
int ENA = 5;

void setup(){
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
}

void loop(){
  digitalWrite (ENA, HIGH);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  delay(3000);
  digitalWrite(ENA, LOW);
  delay(2000);

  digitalWrite(ENA, HIGH);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  delay(3000);
  digitalWrite(ENA, LOW);
  delay(2000);
}
