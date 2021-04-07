void setup() {
    Serial.begin(9600);
    pinMode(7, OUTPUT);
}


int count =0;
int dutyCount = 22;
unsigned int count_1 = 0;

void loop() {
    for (int i = 0; i < 50; i++)
    {
        digitalWrite(7, HIGH);
        delayMicroseconds(700);
        digitalWrite(7, LOW);
        delay(17);
        delayMicroseconds(2300);
    }
    for (int i = 0; i < 50; i++)
    {
        digitalWrite(7, HIGH);
        delayMicroseconds(2300);
        digitalWrite(7, LOW);
        delay(17);
        delayMicroseconds(700);
    }
}



