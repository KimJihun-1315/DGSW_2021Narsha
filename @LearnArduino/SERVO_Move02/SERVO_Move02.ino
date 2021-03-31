void setup() {
    Serial.begin(9600);
    pinMode(7, OUTPUT);
}


int count =0;
int dutyCount = 22;
unsigned int count_1 = 0;

void loop() {
//-------------------------------------
    count++;
    if (count == 625)
    {
        count = 0;
        digitalWrite(7, HIGH);
    }else if (count == dutyCount)
    {
        digitalWrite(7, LOW);
    }
//-------------------------------------
    if (count_1 == 625){
        count_1 = 0;
        dutyCount++;
        if(dutyCount==72) dutyCount = 22;
    }
    count_1++;
//-------------------------------------
    delayMicroseconds(32);
}



