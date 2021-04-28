void setup(){
    //pinMode(13, OUTPUT);
    DDRB |= (0x01 << 7);
}

void loop(){
    //digitalWrite(13, HIGH);
    PORTB |=(0x01 << 7);
    delay(1000);

    //digitalWrite(13, LOW);
    PORTB &= ~(0x01 << 7);
    delay(1000);
    
}