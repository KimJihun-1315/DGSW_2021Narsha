void setup(){
    //pinMode(13, OUTPUT);
    DDRB |= (0x01 << 7);

    TCCR2A = 0x00;
    TCCR2B = 0x02;
    TCNT2 = 56;
    TIMSK2 = 0x01;
}

unsigned long curr_millis = 0;
unsigned long prev_millis = 0;
int pwm_duty = 1;

void loop(){
    curr_millis = millis();
    if(curr_millis -prev_millis>10){
        prev_millis = curr_millis;

        pwm_duty++;
        if(pwm_duty == 99) pwm_duty = 1;
    }
}



unsigned int count = 0;
char toggle_flag = 0;

SIGNAL(TIMER2_OVF_vect){
    TCNT2 = 56;

    count++;
    if(count == 100){
        count = 0;
        PORTB |= (0x01<<7);
    }
    else if (count == pwm_duty){
        PORTB &= ~(0x01<<7);
    }
}