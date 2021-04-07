void setup() {
    Serial.begin(9600);
    pinMode(7, OUTPUT);
}

void loop(){
    for (int i = 0; i < 50; i++)
    {
        digitalWrite(7, HIGH);
        delayMicroseconds(647);
        digitalWrite(7, LOW);
        delay(17);
        delayMicroseconds(3000-647);
    }
    for (int i = 0; i < 50; i++)
    {
        digitalWrite(7, HIGH);
        delayMicroseconds(1473);
        digitalWrite(7, LOW);
        delay(17);
        delayMicroseconds(3000-1473);
    }
}
