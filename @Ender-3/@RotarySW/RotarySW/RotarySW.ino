#define ENCODER_A 10
#define ENCODER_B 11
#define ENCODER_BTN 16

void setup(){
    Serial.begin(9600);

    pinMode(ENCODER_A, INPUT);
    pinMode(ENCODER_B, INPUT);
    pinMode(ENCODER_BTN, INPUT);

    digitalWrite(ENCODER_A, HIGH);
    digitalWrite(ENCODER_B, HIGH);
    digitalWrite(ENCODER_BTN, HIGH);
    
}

void loop(){
    int in = digitalRead(ENCODER_BTN);
    Serial.println(in);

    delay(10);
}
