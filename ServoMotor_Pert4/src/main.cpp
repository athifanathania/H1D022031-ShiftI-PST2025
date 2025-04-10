#include <Arduino.h>
#include <Servo.h>

Servo myservo;

void setup() {
  myservo.attach(D1);
}

void loop() {
  for (int pos = 0; pos <= 180; pos++)
  {
    myservo.write(pos);
    delay(1);
  }
  for (int pos = 180; pos >= 0; pos--)
  {
    myservo.write(pos);
    delay(1);
  }
  // myservo.write(180);
  // delay(1000);
  // myservo.write(0);
  // delay(1000);
  // myservo.write(180);
  // delay(1000);
}

