/* Fundacion Kinal
* Centro educativo técnico laboral Kinal
* Perito en electronica
* Quinto perito
* Sección: A
* Curso : Taller de electronica digital y reparación de computadoras
* Alumno: Rudy Santiago Canel Par
* Carnet:2022449
* Proyecto:Practica 7
*/
#include <LiquidCrystal_I2C.h>
#include <Adafruit_NeoPixel.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <OneWire.h>
#include <Servo.h>
#define ON(pin)      digitalWrite(pin,HIGH)
#define OFF(pin)     digitalWrite(pin,LOW)
#define Input(pin)   pinMode(pin,INPUT)
#define Output(pin)  pinMode(pin,OUTPUT)
Adafruit_NeoPixel led(12,5,NEO_GRB + NEO_KHZ800);
LiquidCrystal_I2C  lcd(0x27, 16, 2);
OneWire ourWire(6);
DallasTemperature sensortemp(&ourWire);
Servo servo1;
int x=0;
int y=0;
int z=0;
int anterior=0;
int z1=0;
int anterior1=0;
void setup()
{
  iniciar();
  configPin();
  Serial.begin(9600);
}

void loop()
{
  condicionalessens();
  condicionalestemp();
  condicionalesservo();
  condicionalreles();
}

void condicionalessens()
{
  int sens = SENSOR(4);
  
  if (sens==0)
  {
    int an = animacionpersona(1,0);
    int buz= animacionbuzz(0,1);
    lcd.setCursor(0,0);
    lcd.write(an);
    lcd.setCursor(1,0);
    lcd.write(buz);
    for (int i=12; i>=0; i--)
    {
      delay(20);
      led.setPixelColor(i,led.Color(0,0,0));
      led.show();
    };
    noTone(A7);
  }
  if (sens==1)
  {
    int an = animacionpersona(0,1);
    int buz= animacionbuzz(1,0);
    lcd.setCursor(0,0);
    lcd.write(an);
    lcd.setCursor(1,0);
    lcd.write(buz);
    for (int i=0; i<12; i++)
    {
      delay(20);
      led.setPixelColor(i,led.Color(0,128,0));
      led.show();
    };
    tone (A7,500);
  }
}

void condicionalestemp()
{
  float ctemp= temp();
  lcd.setCursor(5,0);
  lcd.print(ctemp);
  lcd.print("C");
  lcd.print((char)223);

  if (ctemp>15 && ctemp<21)
  {
    ON(7);
    ON(9);
    OFF(8);
  }
  if (ctemp>21 && ctemp<25)
  {
    ON(8);
    OFF(7);
    OFF(9);
  }
  if (ctemp>25 && ctemp<45)
  {
    ON(7);
    OFF(8);
    OFF(9);
  }
}

void condicionalesservo()
{
 int pin = digitalRead(2);
 if (pin==HIGH && z==0)
 {
  servo1.write(90);
  anterior= 1 - anterior;
 }
 z = pin;
 if (anterior==HIGH)
 {
  servo1.write(90);
  int ser1 = animacionpuerta(0,1);
  lcd.setCursor(14,0);
  lcd.write(ser1);
 }
 else {
  servo1.write(0);
  int ser2 = animacionpuerta(1,0);
  lcd.setCursor(14,0);
  lcd.write(ser2);
 }
  
}

void condicionalreles()
{
 int rele = digitalRead(3);
 if (rele==HIGH && x==0)
 {
  y= 1 - y;
 }
 x = rele;
 if (y==HIGH)
 {
  OFF(A0);
  lcd.setCursor(8,1);
  lcd.write(2);
 }
 else {
  lcd.setCursor(8,1);
  lcd.write(19);
  ON(A0);
 }
 
 int pin1 = digitalRead(12);
 if (pin1==HIGH && z1==0)
 {
  anterior1= 1 - anterior1;
 }
 z1 = pin1;
 if (anterior1==HIGH)
 {
  OFF(A1);
  lcd.setCursor(6,1);
  lcd.write(2);
 }
 else {
  ON(A1);
  lcd.setCursor(6,1);
  lcd.write(19);
 }
 
}

void configPin()
{
  Input(2);
  Input(3);
  Input(4);
  Output(11);
  Output(5);
  Output(7);
  Output(8);
  Output(9);
  Input(12);
  Output(13);
  Output(A0);
  Output(A1);
  Input(A7);
}

int SENSOR(int pin)
{
  bool sensor = digitalRead(pin);
  return sensor;
  
}



void iniciar()
{
  lcd.init();
  lcd.backlight();
  led.begin();
  led.clear();
  sensortemp.begin();
  servo1.attach(11);
}

int animacionfoco (int focosOFFF, int focosONN)
{
  byte focoOFF[] = {
    B11111,
    B01110,
    B10001,
    B10001,
    B10001,
    B01010,
    B11111,
    B11111
  };
  byte focoON[] = {
    B00000,
    B01110,
    B11111,
    B11111,
    B11111,
    B01110,
    B01110,
    B01110
  };
  lcd.createChar(14,focoOFF);
  lcd.createChar(2,focoON);
}

int animacionpuerta(int puerta11, int puerta22)
{
  byte puerta1[] = {
    B00000,
    B00100,
    B01010,
    B01010,
    B01000,
    B01110,
    B01010,
    B01110
  };
  byte puerta2[] = {
    B00000,
    B00000,
    B00100,
    B01010,
    B01010,
    B01110,
    B01010,
    B01110
  };
  lcd.createChar(3,puerta1);
  lcd.createChar(4,puerta2);
  if (puerta11==1)
  {
    return 3;
  }
  if (puerta22==1)
  {
    return 4;
  }
}

int animacionpersona(int persona11,int persona22)
{
  byte persona1[] = {
    B01110,
    B01110,
    B01110,
    B10101,
    B01110,
    B00100,
    B01010,
    B01010
  };
  byte persona2[] = {
    B00000,
    B01110,
    B01110,
    B01110,
    B00100,
    B01110,
    B10101,
    B01010
  };
  lcd.createChar(5,persona1);
  lcd.createChar(6,persona2);
  
  if (persona11 ==1)
  {
    return 5;
  }
  if (persona22==1)
  {
    return 6;
  }
}


int animaciontemp ( int temp)
{
  byte temperatura[] = {
    B00001,
    B00100,
    B01010,
    B01010,
    B01010,
    B01010,
    B01110,
    B00100
  };
  lcd.createChar(7,temperatura);
}
int animacionbuzz(int bocina11,int bocina22)
{
   byte bocina1[] = {
    B00001,
    B00100,
    B01101,
    B11100,
    B11101,
    B01100,
    B00101,
    B00000
  };
  byte bocina2[] = {
    B00000,
    B00100,
    B01100,
    B11100,
    B11100,
    B01100,
    B00100,
    B00000
  };
  lcd.createChar(8,bocina1);
  lcd.createChar(9,bocina2);
  
  if (bocina11 ==1)
  {
    return 8;
  }
  if (bocina22==1)
  {
    return 9;
  }
}

float temp()
{
  float TEMPC;
  sensortemp.requestTemperatures();
  TEMPC= sensortemp.getTempCByIndex(0);
  return TEMPC;
}
