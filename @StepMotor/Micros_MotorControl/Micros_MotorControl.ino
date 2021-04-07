#define XYE_EN 14
#define X_DIR 21
#define X_STEP 15
#define X_STOP 18

#define Y_DIR 23
#define Y_STEP 22
#define Y_STOP 19


void setup() {
  Serial.begin(9600);

  pinMode(X_DIR, OUTPUT);
  pinMode(X_STEP, OUTPUT);
  pinMode(X_STOP, INPUT);

  pinMode(Y_DIR, OUTPUT);
  pinMode(Y_STEP, OUTPUT);
  pinMode(Y_STOP, INPUT);
  
  pinMode(XYE_EN, OUTPUT);

  digitalWrite(X_DIR, HIGH);
  digitalWrite(Y_DIR, HIGH);
  digitalWrite(XYE_EN, LOW);
}


//===========================================

unsigned long curr_micros = 0;
unsigned long curr_millis = 0;

unsigned long pre_micros_x = 0;
unsigned long pre_millis_x = 0;
char motor_stop_x = 0;
char step_toggle_x = 0;
char dir_toggle_x = 0;

unsigned long pre_micros_y = 0;
unsigned long pre_millis_y = 0;
char motor_stop_y = 0;
char step_toggle_y = 0;
char dir_toggle_y = 0;

unsigned int step_count_x = 0;
unsigned int step_count_y = 0;


void loop() {
  curr_micros = micros();
  curr_millis = millis();


//--------------------------------------------
//                X control
//--------------------------------------------
  if(curr_micros - pre_micros_x>200){
    pre_micros_x = curr_micros;

    if(motor_stop_x == 0)
    {
      if(step_toggle_x == 0)
      {
        step_toggle_x = 1;
        digitalWrite(X_STEP, HIGH);
      }  
      else if (step_toggle_x == 1){
        step_toggle_x= 0;
        digitalWrite(X_STEP, LOW);

        step_count_x++;
        if(step_count_x>4000){
          step_count_x=0;
          motor_stop_x=1;
        }
      }
    }
  }


//--------------------------------------------
  if (curr_millis - pre_millis_x > 1000)
  {
    pre_millis_x = curr_millis;
    if(dir_toggle_x == 0)
    {
      dir_toggle_x = 1;
      digitalWrite(X_DIR, LOW);
    }
    else if(dir_toggle_x == 1){
      dir_toggle_x = 0;
      digitalWrite(X_DIR, HIGH);
    }
  }
//--------------------------------------------


//============================================
//                Y control
//============================================

//--------------------------------------------
  if(curr_micros - pre_micros_y>200){
    pre_micros_y = curr_micros;

    if(motor_stop_y == 0)
    {
      if(step_toggle_y == 0)
      {
        step_toggle_y = 1;
        digitalWrite(Y_STEP, HIGH);
      }  
      else if (step_toggle_y == 1){
        step_toggle_y= 0;
        digitalWrite(Y_STEP, LOW);

        step_count_y++;
        if(step_count_y>4000){
          step_count_y=0;
          motor_stop_y=1;
        }
      }
    }
  }
//--------------------------------------------

//--------------------------------------------
  if (curr_millis - pre_millis_y > 1000)
  {
    pre_millis_y = curr_millis;
    if(dir_toggle_y == 0)
    {
      dir_toggle_y = 1;
      digitalWrite(Y_DIR, LOW);
    }
    else if(dir_toggle_y == 1){
      dir_toggle_y = 0;
      digitalWrite(Y_DIR, HIGH);
    }
  }
//---------------------------------------------



//---------------------------------------------
  int in_value_x = digitalRead(X_STOP);
  int in_value_y = digitalRead(Y_STOP);
  if(in_value_x == 1){
      motor_stop_x = 1;
  }
  if(in_value_y == 1){
      motor_stop_y = 1;
  }
}
