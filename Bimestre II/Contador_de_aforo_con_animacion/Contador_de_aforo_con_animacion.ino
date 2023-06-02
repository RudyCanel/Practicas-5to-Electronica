/* Fundacion Kinal
* Centro educativo técnico laboral Kinal
* Perito en electronica
* Quinto perito
* Sección: A
* Curso : Taller de electronica digital y reparación de computadoras
* Alumno: Rudy Santiago Canel Par
* Carnet:2022449
* Proyecto:Contador de aforo con lcd, Sensor ultrasonico y buzzer
*/
#include <LiquidCrystal.h>
#define setpinInput(pin)       pinMode(pin,INPUT)
#define setpinOutput(pin)       pinMode(pin,OUTPUT)
#define SBI(pin)                digitalWrite(pin,HIGH)
#define CBI(pin)                digitalWrite(pin,LOW)

int DISTANCIA=0;
int PERSONAS=0;
void configPines(void);
void contadorAforo(void);
void SENSOR (int TRIG, int ECHO);
void LCD (void);

LiquidCrystal CONTADOR (2,3,4,5,6,7);

void setup()
{
  CONTADOR.begin(16,2);
  configPines();
  
}

void loop()
{
  contadorAforo();
  SENSOR(9,10);
  LCD();
  //BUZZER(8,523,587,659,698,783,880,987);

}



void configPines(void)
{
  
  setpinOutput(9);
  setpinInput(10);
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
void contadorAforo(void)
{
   if (DISTANCIA>6 && DISTANCIA<10 && (PERSONAS<17))
   {
    PERSONAS++;
    delay(200);
   }
}
void LCD (void)
{
 
  if (PERSONAS<17)
  {
    CONTADOR.setCursor(0,0);
    CONTADOR.print("Personas:");
    CONTADOR.print(PERSONAS);
    
  }
  if (PERSONAS==17)
  {
    CONTADOR.clear();
    PERSONAS++;
  }

  if (PERSONAS==18)
  {
    byte P1[] = {
   B00100,
  B01111,
  B00101,
  B01110,
  B10100,
  B10100,
  B01010,
  B01010
  };
  
byte P2[] = {
   B00100,
  B11110,
  B10100,
  B01110,
  B00101,
  B00101,
  B01010,
  B10001
};

CONTADOR.createChar(1,P1);
  CONTADOR.createChar(2,P2);
  CONTADOR.setCursor(0,0);
  CONTADOR.write(2);
  CONTADOR.setCursor(0,1);
  CONTADOR.write(1);
  tone (8,600,2000);
  delay(70);
  CONTADOR.clear();
  CONTADOR.setCursor(1,0);
  CONTADOR.write(1);
  CONTADOR.setCursor(1,1);
  CONTADOR.write(2);
  delay(70);
  CONTADOR.clear();
  CONTADOR.setCursor(2,0);
  CONTADOR.write(2);
  CONTADOR.setCursor(2,1);
  CONTADOR.write(1);
  delay(70);
  CONTADOR.clear();
  CONTADOR.setCursor(3,0);
  CONTADOR.write(1);
  CONTADOR.setCursor(3,1);
  CONTADOR.write(2);
  delay(70);
  CONTADOR.clear();
  CONTADOR.setCursor(4,0);
  CONTADOR.write(2);
  CONTADOR.setCursor(4,1);
  CONTADOR.write(1);
  delay(70);
  CONTADOR.clear();
  CONTADOR.setCursor(5,0);
  CONTADOR.write(1);
  CONTADOR.setCursor(5,1);
  CONTADOR.write(2);
  delay(70);
  CONTADOR.clear();
  CONTADOR.setCursor(6,0);
  CONTADOR.write(2);
  CONTADOR.setCursor(6,1);
  CONTADOR.write(1);
  delay(70);
  CONTADOR.clear();
  CONTADOR.setCursor(7,0);
  CONTADOR.write(1);
  CONTADOR.setCursor(7,1);
  CONTADOR.write(2);
  delay(70);
  CONTADOR.clear();
  CONTADOR.setCursor(8,0);
  CONTADOR.write(2);
  CONTADOR.setCursor(8,1);
  CONTADOR.write(1);
  delay(70);
  CONTADOR.clear();
  CONTADOR.setCursor(9,0);
  CONTADOR.write(1);
  CONTADOR.setCursor(9,1);
  CONTADOR.write(2);
  delay(70);
  CONTADOR.clear();
  CONTADOR.setCursor(10,0);
  CONTADOR.write(2);
  CONTADOR.setCursor(10,1);
  CONTADOR.write(1);
  delay(70);
  CONTADOR.clear();
  CONTADOR.setCursor(11,0);
  CONTADOR.write(1);
  CONTADOR.setCursor(11,1);
  CONTADOR.write(2);
  delay(70);
  CONTADOR.clear();
  CONTADOR.setCursor(12,0);
  CONTADOR.write(2);
  CONTADOR.setCursor(12,1);
  CONTADOR.write(1);
  delay(70);
  CONTADOR.clear();
  CONTADOR.setCursor(13,0);
  CONTADOR.write(1);
  CONTADOR.setCursor(13,1);
  CONTADOR.write(2);
  delay(70);
  CONTADOR.clear();
  CONTADOR.setCursor(14,0);
  CONTADOR.write(2);
  CONTADOR.setCursor(14,1);
  CONTADOR.write(1);
  delay(70);
  CONTADOR.clear();
  CONTADOR.setCursor(15,0);
  CONTADOR.write(1);
  CONTADOR.setCursor(15,1);
  CONTADOR.write(2);
  
  delay(70);
    CONTADOR.clear();
    CONTADOR.print("     AFORO");
    CONTADOR.setCursor(0,1);
    CONTADOR.print("     MAXIMO");
    tone(8,100,200);
    delay(200);
    CONTADOR.clear();
    delay(200);
    CONTADOR.print("     AFORO");
    CONTADOR.setCursor(0,1);
    CONTADOR.print("     MAXIMO");
    tone(8,100,200);
    delay(200);
    CONTADOR.clear();
    delay(200);
    CONTADOR.print("     AFORO");
    CONTADOR.setCursor(0,1);
    CONTADOR.print("     MAXIMO");
    tone(8,100,200);
    delay(200);
    CONTADOR.clear();
    delay(200);
  }
 
}
