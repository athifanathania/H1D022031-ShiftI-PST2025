#include <Arduino.h>

// Deklarasi pin
int trigPin = D0;
int echoPin = D1;
int ledMerah = D2; //LED peringatan
int ledHijau = D3; //LED aman

long duration;
long distance;

void setup() {
  pinMode(ledMerah, OUTPUT);
  pinMode(ledHijau, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // Mengirimkan sinyal ultrasonik
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Menerima sinyal pantulan
  duration = pulseIn(echoPin, HIGH);
  distance = 0.034 * duration / 2;

  // Menampilkan jarak di Serial Monitor
  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Logika LED
  if (distance <= 10){
    digitalWrite(ledMerah, HIGH); // Tanda peringatan menyala
    digitalWrite(ledHijau, LOW); // Tanda aman mati
  } else {
    digitalWrite(ledMerah, LOW); // Tanda peringatan mati
    digitalWrite(ledHijau, HIGH); // Tanda aman menyala
  }
  delay(1000);
}
