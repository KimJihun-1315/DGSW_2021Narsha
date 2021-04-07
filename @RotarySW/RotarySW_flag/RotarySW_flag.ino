#define ENCODER_A 10
#define ENCODER_B 11
#define ENCODER_BTN 16

void setup(){
    Serial.begin(9600);

    pinMode(ENCODER_A, INPUT);
    pinMode(ENCODER_B, INPUT);
    pinMode(ENCODER_BTN, INPUT);

    digitalWrite(ENCODER_A, HIGH);
    digitalWrite(ENCODER_B, HIGH);
    digitalWrite(ENCODER_BTN, HIGH);
    
}

char flag_button = 0;
char flag_up = 0;
char flag_dn = 0;

unsigned long curr_millis = 0;
unsigned long pre_millis = 0;

void loop(){

    //---------------------------------------------------
    // int in = digitalRead(ENCODER_BTN);
    //
    // if (in == 1)
    // {   
    //     if(flag_up==0)
    //     {
    //         Serial.println("up");
    //         flag_up = 1;
    //         flag_dn = 0;
    //     }
    // }
    // else  if (in == 0)
    // {
    //     if(flag_dn==0)
    //     {
    //         Serial.println("down");
    //         flag_dn = 1;
    //         flag_up = 0;
    //     }
    // }
    // delay(10);
    //---------------------------------------------------

    //---------------------------------------------------
    // int in = digitalRead(ENCODER_BTN);
    //
    // if (in == 1 && flag_button == 0){   
    //     Serial.println("up");
    //     flag_button = 1;
    // }else  if (in == 0 && flag_button == 1){
    //     Serial.println("down");
    //     flag_button = 0;
    // }
    // delay(10);
    //---------------------------------------------------
    
    //---------------------------------------------------
    curr_millis = millis();
    
    if(curr_millis - pre_millis>10){
        pre_millis = curr_millis;

        int in = digitalRead(ENCODER_BTN);

        if(in ==1 &&flag_button==0){
            Serial.println("up");
            flag_button = 1;
        }
        else if (in == 0 && flag_button == 1){
            Serial.println("down");
            flag_button = 0;
        }

    }
}
