#define digital_write_7_HIGH  PORTH |= 0x10;
#define digital_write_7_LOW   PORTH &= ~0x10;


void setup() {
    Serial.begin(9600);
    pinMode(7, OUTPUT);
}

unsigned int curr_micros = 0;
unsigned int prev_micros = 0;
unsigned int curr_millis = 0;
unsigned int prev_millis = 0;

int count = 0;
int dutyServo = 20;
char toggle_1sec = 0;

void loop(){
    curr_micros = micros();
    curr_millis = millis();
    
    if (curr_micros - prev_micros > 32 ){
        prev_micros = curr_micros;
        if(count == 625){
            count = 0;
            digital_write_7_HIGH;
        }else if (count == dutyServo){
            digital_write_7_LOW;
        }
        count++;
    }

    if (curr_millis-prev_millis>1000){
        prev_millis = curr_millis;
        if(toggle_1sec == 0)
        {
            toggle_1sec = 1;
            dutyServo = 20;
        }else 
        {
            toggle_1sec = 0;
            dutyServo = 46;
        }
    }
}



