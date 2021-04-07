#define XYE_EN 14
#define X_DIR 21
#define X_STEP 15
#define X_STOP 18

void setup() {
  Serial.begin(9600);

  pinMode(X_DIR, OUTPUT);
  pinMode(X_STEP, OUTPUT);
  pinMode(X_STOP, INPUT);
  pinMode(XYE_EN, OUTPUT);

  digitalWrite(X_DIR, HIGH);
  digitalWrite(XYE_EN, LOW);
}


//===========================================

unsigned long curr_micros = 0;
unsigned long pre_micros = 0;
char step_toggle = 0;
char motor_stop = 0;

void loop() {
  curr_micros = micros();

  if(curr_micros - pre_micros>200){
    pre_micros = curr_micros;

    if(motor_stop == 0)
    {
      if(step_toggle == 0)
      {
        step_toggle = 1;
        digitalWrite(X_STEP, HIGH);
      }  
      else if (step_toggle == 1){
        step_toggle= 0;
        digitalWrite(X_STEP, LOW);
    }
  }
}
  
  int in_value = digitalRead(X_STOP);
  if(in_value == 1){
      motor_stop = 1;
      
  }
}
