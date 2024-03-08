#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
const int trig=4;
const int echo=5;
void setup() {
  // put your setup code here, to run once:
  lcd.begin();
  lcd.backlight();
  lcd.print("Distance : ");
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig,LOW);
  delay(2);
  digitalWrite(trig,HIGH);
  delay(10);
  digitalWrite(trig,LOW);
  long duration = pulseIn(echo,HIGH);
  long distance=duration*0.034/2; //speed of sound=340 m/s =0.034 cm/microsecond.
  lcd.setCursor(10,0);
  lcd.print("    ");
  lcd.setCursor(10,0);
  lcd.print(distance);
  Serial.print("Distance : ");
  Serial.println(distance);
  Serial.print(" cm")
  delay(10);
}
