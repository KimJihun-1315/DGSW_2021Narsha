
void setup() {
  pinMode (13, OUTPUT);
}

int duty = 1;
int count = 0;
int count_variable = 0;
int top = 0;


void loop() {

//======================================
  if(count==100){
    count = 0;
    digitalWrite(13, HIGH);
  }
  else if (count == duty){
    digitalWrite(13, LOW);
  }
//--------------------------------------
//가변
  count_variable++;
  if (count_variable == 100){
    count_variable = 0;
    
    if(duty == 99)top = 1;
    if(duty == 1)top  = 0;
    
    if(top == 0)duty++;
    if(top == 1)duty--;
  }
//--------------------------------------
  count++;
  delayMicroseconds(100);
//--------------------------------------
  


}
