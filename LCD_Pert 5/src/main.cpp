#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

int SDA_pin = D2;
int SCL_pin = D3;
LiquidCrystal_I2C lcd(0x27, 16, 2); // 16 karakter 2 baris

void setup() {
  Wire.begin(SDA_pin, SCL_pin);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0); 
  lcd.print("athifa♡♡♡");
  lcd.setCursor(0, 1);
  lcd.print("♡♡♡mas nuansa");
}

void loop() {
  lcd.scrollDisplayLeft();
  delay(200);
}