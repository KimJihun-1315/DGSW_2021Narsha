void setup() {
    Serial.begin(9600);
    pinMode(7, OUTPUT);
}

unsigned int curr_micros = 0;
unsigned int prev_micros = 0;
unsigned int curr_millis = 0;
unsigned int prev_millis = 0;

int count = 0;
int dutyServo = 23;
char toggle_1sec = 0;

void loop(){
    curr_micros = micros();
    curr_millis = millis();
    
    if (curr_micros - prev_micros > 32){
        prev_micros = curr_micros;
        if(count == 625){
            count = 0;
            digitalWrite(7, HIGH);
        }else if (count == dutyServo){
            digitalWrite(7, LOW);
        }
        count++;
    }


    if (curr_millis-prev_millis>1000){
        prev_millis = curr_millis;
        if(toggle_1sec == 0){
            toggle_1sec = 1;
            dutyServo = 23;
        }else {
            toggle_1sec = 0;
            dutyServo = 70;
        }

    }
}


