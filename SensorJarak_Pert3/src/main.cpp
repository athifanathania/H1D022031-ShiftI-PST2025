#include <Arduino.h>

// deklarasi fungsi
int trigPin = D0;
int echoPin = D1;
int LED = D2;

long duration;
long distance;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = 0.034 * duration / 2;

  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.println("cm");
  if (distance <= 10){
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
  delay(1000);
}

/*
CATATAN:
- ucc +, gnd -
- trig mengeluarkan sinyal
- echo menangkap sinyal 
- 3v3 positif 3volt 
- gnd ground negatif
- led hanya untuk mengeluarkan sinyal(cahaya)
- trigerpin untuk mengeluarkan gelombang yang nantinya akan ditangkap oleh echopin yang memiliki inputan
- pada sistem ini nantinya akan ada waktu dan jarak untuk keluar masuk maka menggunakan distance dan duration
*/