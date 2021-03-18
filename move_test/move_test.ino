#define X_DI 21
#define X_ST 15
#define Y_DI 23
#define Y_ST 22
#define XYEN 14

void setup() {
  pinMode(X_DI, OUTPUT);
  pinMode(X_ST, OUTPUT);
  pinMode(Y_DI, OUTPUT);
  pinMode(Y_ST, OUTPUT);
  pinMode(XYEN, OUTPUT);

  digitalWrite(XYEN, LOW);
  
  for(int i = 0; i<5000;i++){
    digitalWrite(X_ST, HIGH);
    delayMicroseconds(500);
    digitalWrite(X_ST, LOW);
    delayMicroseconds(500);
  }
}

void loop(){
  
}
