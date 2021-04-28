void setup(){
    //pinMode(13, OUTPUT);
    DDRB |= (0x01 << 7);

    TCCR2A = 0x00;
    TCCR2B = 0x02;
    TCNT2 = 56;
    TIMSK2 = 0x01;
}

void loop(){

}
unsigned int count = 0;
char toggle_flag = 0;

SIGNAL(TIMER2_OVF_vect){
    /*
    count++;
    if(count == 10000){
        count = 0;
        
        if (toggle_flag==0){
            toggle_flag = 1;
            PORTB |= (0x01<<7);
        }
        else{
            toggle_flag = 0;
            PORTB |= ~(0x01 << 7);
        }
    }
    */
    TCNT2 = 56;

    count++;
    if(count == 100){
        count = 0;
        PORTB |= (0x01<<7);
    }
    else if (count == 10){
        PORTB &= ~(0x01<<7);
    }
}