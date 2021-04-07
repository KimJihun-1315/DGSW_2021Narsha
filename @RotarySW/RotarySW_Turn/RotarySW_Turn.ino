#define ENCODER_A 10
#define ENCODER_B 11
#define ENCODER_BTN 16

#define LEFT 1
#define RIGHT 2

void setup(){
    Serial.begin(9600);

    pinMode(ENCODER_A, INPUT);
    pinMode(ENCODER_B, INPUT);
    pinMode(ENCODER_BTN, INPUT);

    digitalWrite(ENCODER_A, HIGH);
    digitalWrite(ENCODER_B, HIGH);
    digitalWrite(ENCODER_BTN, HIGH);
    
}

int left_state = 0;
int right_state = 0;

void loop(){
    int in_a = digitalRead(ENCODER_A);
    int in_b = digitalRead(ENCODER_B);
    
    if(in_a == 1 && in_b == 1)
    {
        if (right_state == 3)
        {
            Serial.println("R");
        }
        else if (left_state == 3)
        {
            Serial.println("L");
        }

        left_state = 0;
        right_state = 0;
    }
    if(in_a == 0 && in_b == 1)
    {
        if(right_state == 0){
            right_state = 1;
        }
        else if(left_state == 2){
            left_state = 3;
        }
    }
    if(in_a == 0 && in_b == 0)
    {
        if(right_state == 1){
            right_state = 2;
        }
        else if(left_state == 1){
            left_state = 2;
        }
    }
    if(in_a == 1 && in_b == 0)
    {
        if(right_state == 2){
            right_state = 3;
        }
        else if(left_state == 0){
            left_state = 1;
        }
    }

    delay(1);
}
