#define X_DI 21
#define X_ST 15
#define Y_DI 23
#define Y_ST 22
#define XYEN 14

int needLen;
double XYlen;

void setup() {
  Serial.begin(9600);
  
  pinMode(X_DI, OUTPUT);
  pinMode(X_ST, OUTPUT);
  pinMode(Y_DI, OUTPUT);
  pinMode(Y_ST, OUTPUT);
  pinMode(XYEN, OUTPUT);

  digitalWrite(XYEN, LOW);
}

void loop() {
  needLen = Serial.parseInt();
  XYlen = needLen *80 ;
  Serial.println(XYlen);
  
  DrawTriangle();
}

void DrawTriangle(){
  digitalWrite(X_DI, HIGH);
  doMoveX();
  digitalWrite(Y_DI, HIGH);
  doMoveY();
  
  digitalWrite(X_DI, LOW);
  digitalWrite(Y_DI, LOW);
  doMoveCross();
}

void doMoveX(){
  for(int i = 0; i<XYlen;i++){
    digitalWrite(X_ST, HIGH);
    delayMicroseconds(500);
    digitalWrite(X_ST, LOW);
    delayMicroseconds(500);
  }
}

void doMoveY(){
  for(int i = 0; i<XYlen;i++){
    digitalWrite(Y_ST, HIGH);
    delayMicroseconds(500);
    digitalWrite(Y_ST, LOW);
    delayMicroseconds(500);
  }
}

void doMoveCross(){
  for(int i = 0; i<XYlen;i++){
    digitalWrite(X_ST, HIGH);
    digitalWrite(Y_ST, HIGH);
    delayMicroseconds(500);
    digitalWrite(X_ST, LOW);
    digitalWrite(Y_ST, LOW);
    delayMicroseconds(500);
  }
}
