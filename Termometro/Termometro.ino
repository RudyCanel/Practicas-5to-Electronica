/* Fundacion Kinal
* Centro educativo técnico laboral Kinal
* Perito en electronica
* Quinto perito
* Sección: A
* Curso : Taller de electronica digital y reparación de computadoras
* Alumno: Rudy Santiago Canel Par
* Carnet:2022449
* Proyecto:Termometro
*/

#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>
#define ON(pin)     digitalWrite(pin,HIGH)
#define OFF(pin)    digitalWrite(pin,LOW)
#define input(pin)  pinMode(pin,INPUT)
#define output(pin) pinMode(pin,OUTPUT)
#define pin 2

LiquidCrystal_I2C  lcd (0x27,16,2);
OneWire ourWire(pin);
DallasTemperature sensors(&ourWire);

float TEMPC;
float TEMPF;
void setup()
{
  Inicializar();
  configLCD();
  configPines();
}

void loop()
{
  Temperatura();
  condicionales();
  LCD();
  condicionales();
}

void Inicializar()
{
  delay(1000);
  sensors.begin();
}

void Temperatura()
{
  sensors.requestTemperatures();
  TEMPC= sensors.getTempCByIndex(0);
  TEMPF= sensors.getTempFByIndex(0);
  Serial.print(sensors.getTempCByIndex(0));
  delay(1000);
}
void configLCD()
{
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
}
void LCD ()
{
  byte termometro[] = {
  B00001,
  B00100,
  B01010,
  B01010,
  B01010,
  B01110,
  B01110,
  B00100
};
  lcd.createChar(1,termometro);
  lcd.setCursor(0,0);
  lcd.print("TERMOMETRO ");
  lcd.write(1);
  lcd.setCursor(0,1);
  lcd.print(TEMPC);
  lcd.print((char)223);
  lcd.print("C  ");
  lcd.print(TEMPF);
  lcd.print((char)223);
  lcd.print("F");
  lcd.setCursor(0,0);
  
  
}
void configPines()
{
  output(3);
  output(4);
  output(5);
  
}
void condicionales()
{
  if (TEMPC >30)
  {
    ON(3);
    OFF(4);
    OFF(5);
  }
  else if(TEMPC>15 && TEMPC<30)
  {
    OFF(3);
    ON(4);
    OFF(5);
  }
  else if (TEMPC<15)
  {
    OFF(3);
    OFF(4);
    ON(5);
  }
}
