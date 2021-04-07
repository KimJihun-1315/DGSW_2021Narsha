

void setup() {
    Serial.begin(9600);
    pinMode(7, OUTPUT);
}

int time = 2;
int servoDuty = 700;


// 좌우 무한반복
// void loop() {
//     for (int i = 0; i < 50; i++)
//     {
//         digitalWrite(7, HIGH);
//         delayMicroseconds(servoDuty);
//         digitalWrite(7, LOW);
//         delayMicroseconds(3000-servoDuty);
//         delay(17);
//     }
//     for (int i = 0; i < 50; i++)
//     {
//         digitalWrite(7, HIGH);
//         delayMicroseconds(3000-servoDuty);
//         digitalWrite(7, LOW);
//         delayMicroseconds(servoDuty);
//         delay(17);
//     }
// }



// void loop() {
//     //for (int j = 0; j < 50; j++)
//     //{
//         for (int i = 0; i < time; i++)
//         {
//             digitalWrite(7, HIGH);
//             delayMicroseconds(servoDuty);
//             digitalWrite(7, LOW);
//             delayMicroseconds(3000-servoDuty);
//             delay(17);
//         }
//         servoDuty += 32;
//         if(servoDuty>2300)servoDuty = 700;
//     //}
// }
