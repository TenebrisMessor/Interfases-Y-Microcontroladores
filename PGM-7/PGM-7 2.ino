int RELAY = 2;

void setup() {
  pinMode (RELAY, OUTPUT);
}

void loop (){
  digitalWrite(RELAY, LOW);
  delay(5000);
  digitalWrite (RELAY, HIGH);
  delay(5000); 
}
