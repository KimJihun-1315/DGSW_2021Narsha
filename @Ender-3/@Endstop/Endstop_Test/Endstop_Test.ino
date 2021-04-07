//X_STOP  PC2  18
//Y_STOP  PC3  19
//Z_STOP  PC4  20

#define X_DI 21
#define X_ST 15
#define Y_DI 23
#define Y_ST 22
#define XYEN 14

#define Xstp 18
#define Ystp 19
#define Zstp 20
#define XYEN 14

void setup() {
  Serial.begin(9600);
  
  pinMode(X_DI, OUTPUT);
  pinMode(X_ST, OUTPUT);
  pinMode(Y_DI, OUTPUT);
  pinMode(Y_ST, OUTPUT);
  pinMode(XYEN, OUTPUT);
  
  pinMode(Xstp, INPUT);
  pinMode(Ystp, INPUT);
  pinMode(Zstp, INPUT);
  
  digitalWrite(XYEN, LOW);
}

void loop() {
  int XEnd = digitalRead(Xstp);

//  Serial.println(XEnd);

  if(XEnd == 0){
    digitalWrite(X_DI, HIGH);
    doMoveX();
  }else if (XEnd == 1){
    digitalWrite(X_DI, LOW);
    for(int i = 0; i<100; i++){
      doMoveX();
    }
  }
}

void doMoveX(){
  digitalWrite(X_ST, HIGH);
  delayMicroseconds(200);
  digitalWrite(X_ST, LOW);
  delayMicroseconds(200);
}
