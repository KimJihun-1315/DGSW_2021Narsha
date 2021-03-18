//X_DIR     PC5  pin21
//X_STEP    PD7  pin31
//Y_DIR     PC7  pin23
//Y_STEP    PC6  pin22
//XYEENABLE PD6  pin14


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
}

void doMove(){
  for(int i = 0; i<1000;i++){
    digitalWrite(X_ST, HIGH);
    digitalWrite(Y_ST, HIGH);
    delayMicroseconds(500);
    digitalWrite(X_ST, LOW);
    digitalWrite(Y_ST, LOW);
    delayMicroseconds(500);
  }
}

void loop() {
  doMove();
  digitalWrite(X_DI, HIGH);
  digitalWrite(Y_DI, HIGH);
  doMove();
  digitalWrite(X_DI, LOW);
  digitalWrite(Y_DI, LOW);
  

}
