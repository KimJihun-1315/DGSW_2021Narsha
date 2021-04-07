void setup() {
    Serial.begin(9600);
    pinMode(7, OUTPUT);
}

int count = 0;
unsigned int count_1sec = 0;
volatile int duty_servo = 22;
char toggle_1sec = 0;

void loop() {
// --------------------------------------------------
//   for문 사용
// --------------------------------------------------

    // for (int i = 0; i < 50; i++)
    // {
    //     digitalWrite(7, HIGH);
    //     delayMicroseconds(700);
    //     digitalWrite(7, LOW);
    //     delay(17);
    //     delayMicroseconds(2300);
    // }
    // for (int i = 0; i < 50; i++)
    // {
    //     digitalWrite(7, HIGH);
    //     delayMicroseconds(2300);
    //     digitalWrite(7, LOW);
    //     delay(17);
    //     delayMicroseconds(700);
    // }
    // count++;
    // delayMicroseconds(32);
//---------------------------------------------------

// --------------------------------------------------
//   if문 사용
// --------------------------------------------------

    if(count == 625){
        count = 0;
        digitalWrite(7, HIGH);
    }
    else if (count == duty_servo){
        digitalWrite(7, LOW);
    }

    if (count_1sec == 625*50){
        count_1sec = 0;

        if (toggle_1sec == 0){
            toggle_1sec = 1;
            duty_servo = 22;
        }else{
            toggle_1sec = 0;
            duty_servo = 72;
        }
    }

    count_1sec++;
    count++;
    delayMicroseconds(32);

//---------------------------------------------------
}



