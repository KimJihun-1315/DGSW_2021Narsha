
void setup() {
  Serial.begin(9600);
  pinMode(27, OUTPUT);
}

void loop() {
  digitalWrite(27, HIGH);
  delay(1000);
  digitalWrite(27, LOW);
  delay(1000);
  
}
