unsigned long pre_micros0 = 0;
unsigned long pre_micros1 = 0;
unsigned long cur_micros = 0;

void setup() {
  Serial.begin(9600);

  pinMode(13, OUTPUT);
}

int count = 0;

void loop() {
  cur_micros = micros();
  if(cur_micros - pre_micros0>100){
    pre_micros0 = cur_micros;

    count++;
    if(count == 100){
      count = 0;
      digitalWrite(13, HIGH);
    }else if (count == 10){
      digitalWrite(13, LOW);
    }
  }
}
