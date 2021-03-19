unsigned long pre_millis0 = 0;
unsigned long pre_millis1 = 0;
unsigned long cur_millis = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  cur_millis = millis();
  if(cur_millis - pre_millis0>1000){
    pre_millis0 = cur_millis;

    Serial.print(pre_millis0);
    Serial.println("haha");
  }
  cur_millis = millis();
  if(cur_millis - pre_millis1>1000){
    pre_millis1 = cur_millis;

    Serial.print(pre_millis1);
    Serial.println("hehe");
  }
}
