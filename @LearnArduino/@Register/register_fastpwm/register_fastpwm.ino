void setup(){
    //pinMode(13, OUTPUT);
    DDRB |= (0x01 << 7);

    TCCR2A = 0x03;
    TCCR2B = 0x05;
    TCNT2 = 6;
    OCR2A = 31;
    TIMSK2 = 0x03;
}

unsigned long curr_millis = 0;
unsigned long prev_millis = 0;
int pwm_duty = 1;

void loop(){
    curr_millis = millis();
    if(curr_millis-prev_millis > 5){
        prev_millis = curr_millis;

        pwm_duty++;
        if(pwm_duty == 255) pwm_duty = 1;
    }
}

unsigned int count = 0;
char toggle_flag = 0;

SIGNAL(TIMER2_COMPA_vect){
    PORTB &= ~(0x01<<7);
}


SIGNAL(TIMER2_OVF_vect){
    TCNT2 = 6;
    PORTB |=(0x01<<7);

    OCR2A = pwm_duty;
}
