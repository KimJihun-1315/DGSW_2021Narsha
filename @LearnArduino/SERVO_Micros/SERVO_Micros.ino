

void setup() {
    Serial.begin(9600);
    pinMode(7, OUTPUT);
}

int count = 0;
int dutyCount = 22;
unsigned long curr_millis = 0;
unsigned long pre_millis = 0;
unsigned long curr_micros = 0;
unsigned long pre_micros = 0;


void loop() {
    curr_micros = micros();
    curr_millis = millis();

    if (curr_micros - pre_micros > 32){
        pre_micros = curr_micros;

        if (count == 625){
            count = 0;
            digitalWrite(7, HIGH);
        }else if (count == dutyCount){
            digitalWrite(7, LOW);
        }
        count++;
    }

    if(curr_millis - pre_millis>100){
        pre_millis = curr_millis;

        dutyCount++;
        if(dutyCount>72) dutyCount= 22;
    }    
}



