#define X_DI 21
#define X_ST 15
#define Y_DI 23
#define Y_ST 22
#define XYEN 14

/*
//len값 = (원하는길이mm) / 0.0125 
//     = (원하는길이mm) * 80
//len값의 단위는 1ns(나노스텝)
//1ns당 0.0125mm이동
int XYlen = 4000;
*/
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
  
  DrawSquare();
}

void DrawSquare(){
  doMoveX();
  doMoveY();
  digitalWrite(X_DI, HIGH);
  digitalWrite(Y_DI, HIGH);
  doMoveX();
  doMoveY();
  digitalWrite(X_DI, LOW);
  digitalWrite(Y_DI, LOW);
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
