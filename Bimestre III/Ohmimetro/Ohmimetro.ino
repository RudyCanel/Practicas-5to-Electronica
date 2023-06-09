/* Fundacion Kinal
* Centro educativo técnico laboral Kinal
* Perito en electronica
* Quinto perito
* Sección: A
* Curso : Taller de electronica digital y reparación de computadoras
* Alumno: Rudy Santiago Canel Par
* Carnet:2022449
* Proyecto: Ohmimetro
*/
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
unsigned int i=0;
float j=0;
float x;
float resistencia;
LiquidCrystal_I2C lcd (0x20,16,2);
void setup() {
  pinMode(A1,INPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
}

void loop() {
  i = analogRead(A1);
  j = map (i,0,1023,0,1023);
  resistencia = ((50000/((j*5)/1023)))-(10000);
  resistencia = resistencia +10;
  lcd.setCursor(0,0);
  lcd.print("Ohmimetro");
  lcd.setCursor(0,1);
  lcd.print("");
  lcd.print(resistencia);
}
