/* Fundacion Kinal
* Centro educativo técnico laboral Kinal
* Perito en electronica
* Quinto perito
* Sección: A
* Curso : Taller de electronica digital y reparación de computadoras
* Alumno: Rudy Santiago Canel Par
* Carnet:2022449
* Proyecto:Alarma de distancia
*/
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#define setpinInput(pin)      pinMode(pin,INPUT)
#define setpinOutput(pin)     pinMode(pin,OUTPUT)
#define SBI(pin)              digitalWrite(pin,HIGH)
#define CBI(pin)              digitalWrite(pin,LOW)
LiquidCrystal_I2C lcd_I2C(0x27,16,2); 

int DISTANCIA=0;

void setup()
{
  Serial.begin(9600);
  ONLCD();
  configPin();
}


void loop()
{
   Serial.println(DISTANCIA);
  lcd(12);
  SENSOR(2,3);
  Bled(4,5,6,7,8,9,10,11,A2,A6);
}


void configPin(void)
{
  setpinOutput(2);
  setpinInput(3);
  setpinOutput(4);
  setpinOutput(5);
  setpinOutput(6);
  setpinOutput(7);
  setpinOutput(8);
  setpinOutput(9);
  setpinOutput(10);
  setpinOutput(11);
  setpinOutput(A2);
  setpinOutput(A0);
  setpinOutput(A6);
}
void ONLCD(void)
{
  lcd_I2C.init();                     
  lcd_I2C.backlight();
  lcd_I2C.setCursor(0,0);
}

void SENSOR (int TRIG, int ECHO)
{
  int TIEMPO=0;
  SBI(TRIG);
  delayMicroseconds(2);
  CBI(TRIG);
  delayMicroseconds(10);
  TIEMPO= pulseIn(ECHO,HIGH);
  DISTANCIA= TIEMPO/29.1/2;
  
}
void lcd(int BUZZER)
{ 
  if (DISTANCIA >45)
  {
    lcd_I2C.setCursor(0,0);
    lcd_I2C.print("Fuera de Alcance");
    lcd_I2C.setCursor(0,1);
    lcd_I2C.print("                ");
    noTone(BUZZER);
  }
  if (DISTANCIA>30 && DISTANCIA<44)
  {
    lcd_I2C.setCursor(0,0);
    lcd_I2C.print(" Persona/Objeto ");
    lcd_I2C.setCursor(0,1);
    lcd_I2C.print("  Acercandoce   ");
    noTone(BUZZER);
  }
  if (DISTANCIA>15 && DISTANCIA<29)
  {
    lcd_I2C.setCursor(0,0);
    lcd_I2C.print("Cuidado,Espacio ");
    lcd_I2C.setCursor(0,1);
    lcd_I2C.print("    Privado    ");
    tone(BUZZER,200);
  }
  if (DISTANCIA<14 && DISTANCIA>0)
  {
    lcd_I2C.setCursor(0,0);
    lcd_I2C.print("   Invadiendo   ");
    lcd_I2C.setCursor(0,1);
    lcd_I2C.print("Espacio Personal");
    tone(BUZZER,200);
  }
}
void Bled(int a, int b, int c, int d, int e,
          int f, int g, int h, int i, int j)
{
  if (DISTANCIA<5)
  {
    SBI(a);
    SBI(b);
    SBI(c);
    SBI(d);
    SBI(e);
    SBI(f);
    SBI(g);
    SBI(h);
    SBI(i);
    SBI(j);
    
  }
  if (DISTANCIA >5 && DISTANCIA <9)
  {
    SBI(a);
    SBI(b);
    SBI(c);
    SBI(d);
    SBI(e);
    SBI(f);
    SBI(g);
    SBI(h);
    SBI(i);
    CBI(j);
  }
  if (DISTANCIA >10 && DISTANCIA<14)
  {
    
    SBI(a);
    SBI(b);
    SBI(c);
    SBI(d);
    SBI(e);
    SBI(f);
    SBI(g);
    SBI(h);
    CBI(i);
    CBI(j);
  }
  if (DISTANCIA>15 && DISTANCIA<18)
  {
    SBI(a);
    SBI(b);
    SBI(c);
    SBI(d);
    SBI(e);
    SBI(f);
    SBI(g);
    CBI(h);
    CBI(i);
    CBI(j);
  }
  if (DISTANCIA>19 && DISTANCIA<23)
  {
    SBI(a);
    SBI(b);
    SBI(c);
    SBI(d);
    SBI(e);
    SBI(f);
    CBI(g);
    CBI(h);
    CBI(i);
    CBI(j);
  }
  if (DISTANCIA>24 && DISTANCIA<27)
  {
    
    SBI(a);
    SBI(b);
    SBI(c);
    SBI(d);
    SBI(e);
    CBI(f);
    CBI(g);
    CBI(h);
    CBI(i);
    CBI(j);
  }
  if (DISTANCIA>28 && DISTANCIA<32)
  {
    noTone(A0);
    SBI(a);
    SBI(b);
    SBI(c);
    SBI(d);
    CBI(e);
    CBI(f);
    CBI(g);
    CBI(h);
    CBI(i);
    CBI(j);
  }
  if (DISTANCIA>33 && DISTANCIA<36)
  {
    noTone(A0);
    SBI(a);
    SBI(b);
    SBI(c);
    CBI(d);
    CBI(e);
    CBI(f);
    CBI(g);
    CBI(h);
    CBI(i);
    CBI(j);
  }
  if (DISTANCIA>37 && DISTANCIA <41)
  {
    noTone(A0);
    SBI(a);
    SBI(b);
    CBI(c);
    CBI(d);
    CBI(e);
    CBI(f);
    CBI(g);
    CBI(h);
    CBI(i);
    CBI(j);
  }
  if (DISTANCIA>42 && DISTANCIA<45)
  {
    noTone(A0);
    SBI(a);
    CBI(b);
    CBI(c);
    CBI(d);
    CBI(e);
    CBI(f);
    CBI(g);
    CBI(h);
    CBI(i);
    CBI(j);
  }
  if (DISTANCIA >46)
  {
    noTone(A0);
    CBI(a);
    CBI(b);
    CBI(c);
    CBI(d);
    CBI(e);
    CBI(f);
    CBI(g);
    CBI(h);
    CBI(i);
    CBI(j);
  }
}
