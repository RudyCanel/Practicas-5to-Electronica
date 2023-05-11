/* Fundacion Kinal
* Centro educativo técnico laboral Kinal
* Perito en electronica
* Quinto perito
* Sección: A
* Curso : Taller de electronica digital y reparación de computadoras
* Alumno: Rudy Santiago Canel Par
* Carnet:2022449
* Proyecto:Sensor de parqueo
*/
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#define setpinInput(pin)      pinMode(pin,INPUT)
#define setpinOutput(pin)     pinMode(pin,OUTPUT)
#define SBI(pin)              digitalWrite(pin,HIGH)
#define CBI(pin)              digitalWrite(pin,LOW)
LiquidCrystal_I2C lcd(0x27,16,2); 

int DISTANCIA=0;

void setup()
{
  ONLCD();
  configPin();
}


void loop()
{
   
  lcdC(A0);
  SENSOR(2,3);
 
}


void configPin(void)
{
  setpinOutput(2);
  setpinInput(3);
}
void ONLCD(void)
{
  lcd.init();                     
  lcd.backlight();
  lcd.setCursor(0,0);
}

void SENSOR (int TRIG, int ECHO)
{
  float TIEMPO=0;
  SBI(TRIG);
  delayMicroseconds(2);
  CBI(TRIG);
  delayMicroseconds(10);
  TIEMPO= pulseIn(ECHO,HIGH);
  DISTANCIA= TIEMPO/29.1/2;
  
}
void lcdC(int BUZZER)
{
  byte ON[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};

lcd.createChar(1,ON);
  if (DISTANCIA>30 && DISTANCIA<50)
  {
    lcd.setCursor(0,0);
    lcd.write(1);
    lcd.setCursor(1,0);
    lcd.write(1);
    lcd.setCursor(2,0);
    lcd.write(1);
    lcd.print("    50    ");
    lcd.setCursor(15,0);
    lcd.write(1);
    lcd.setCursor(14,0);
    lcd.write(1);
    lcd.setCursor(13,0);
    lcd.write(1);
    lcd.setCursor(0,1);
    lcd.print("     Libre      ");
  }
  if (DISTANCIA>10 && DISTANCIA<30)
  {
    lcd.setCursor(0,0);
    lcd.write(1);
    lcd.setCursor(1,0);
    lcd.write(1);
    lcd.setCursor(2,0);
    lcd.write(1);
    lcd.setCursor(3,0);
    lcd.write(1);
    lcd.setCursor(4,0);
    lcd.write(1);
    lcd.print("  30  ");
    lcd.setCursor(15,0);
    lcd.write(1);
    lcd.setCursor(14,0);
    lcd.write(1);
    lcd.setCursor(13,0);
    lcd.write(1);
    lcd.setCursor(12,0);
    lcd.write(1);
    lcd.setCursor(11,0);
    lcd.write(1);
    lcd.setCursor(0,1);
    lcd.print("    Cuidado     ");  
  }
  if (DISTANCIA<10)
  {
    lcd.setCursor(0,0);
    lcd.write(1);
    lcd.setCursor(1,0);
    lcd.write(1);
    lcd.setCursor(2,0);
    lcd.write(1);
    lcd.setCursor(3,0);
    lcd.write(1);
    lcd.setCursor(4,0);
    lcd.write(1);
    lcd.setCursor(5,0);
    lcd.write(1);
    lcd.setCursor(6,0);
    lcd.write(1);
    lcd.print("10");
    lcd.setCursor(15,0);
    lcd.write(1);
    lcd.setCursor(14,0);
    lcd.write(1);
    lcd.setCursor(13,0);
    lcd.write(1);
    lcd.setCursor(12,0);
    lcd.write(1);
    lcd.setCursor(11,0);
    lcd.write(1);
    lcd.setCursor(10,0);
    lcd.write(1);
    lcd.setCursor(9,0);
    lcd.write(1);
    lcd.setCursor(0,1);
    lcd.print("      Alto      ");
  }
  
}
