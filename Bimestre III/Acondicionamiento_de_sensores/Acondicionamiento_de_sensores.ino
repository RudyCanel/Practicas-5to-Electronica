/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Perito en Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: Taller de electronica digital
 * Nombres: Rudy Santiago Canel Par
 * Carnet: 2022449
 * Proyecto: Acondicionamiento de sensores analógicos e interfaces a los sistemas embebidos 
*/
#include <LedControl.h>
#include <Ticker.h>
#define ON(pin)     digitalWrite(pin,HIGH)
#define OFF(pin)    digitalWrite(pin,LOW)
#define Input(pin)  pinMode(pin,INPUT)
#define Output(pin) pinMode(pin,OUTPUT)

int sensor=0;
int lectura=0;
void MQ2 ();
unsigned long tiempo=0;
unsigned long anterior=0;
unsigned long resultado;
int q=0;
unsigned long k;
Ticker interrupt(MQ2,2000);
LedControl matriz = LedControl(12,11,10,1);

byte sprite1[8]= {        
  B01000000,        
  B00100000,
  B00111000,
  B00011100,
  B00011110,
  B00001110,
  B00011110,
  B00111100
};
byte sprite2[8]=
{
  B00001000,        
  B00010000,
  B00111000,
  B00111000,
  B00011100,
  B00001100,
  B00011100,
  B00111100
};

byte sprite3[8]=
{
  B00000010,        
  B00011100,
  B00111000,
  B00111000,
  B01110000,
  B00110000,
  B00111000,
  B00111100
};

byte copo[8]=
{
  B10011001,        
  B00100100,
  B01000010,
  B10011001,
  B10011001,
  B01000010,
  B00100100,
  B10011001
};
void setup() {
  Serial.begin(9600);
  matriz.shutdown(0,false);
  matriz.setIntensity(0,10);
  matriz.clearDisplay(0);
  Input(A0);
  interrupt.start();
}

void loop() {
  interrupt.update();
  tiempo = millis();
      if (lectura>50 or q==1)
  {
    for(int i=0; i<8;i++)
      {
        matriz.setRow(0,i,sprite1[i]);
      }
      delay(200);
      for(int i=0; i<8;i++)
      {
        matriz.setRow(0,i,sprite2[i]);
      }
      delay(200);
      for(int i=0; i<8;i++)
      {
        matriz.setRow(0,i,sprite3[i]);
      }
      delay(200);
      resultado = tiempo - k;
      q=1;
      if (resultado > 5000)
      {
        q=0;
      }
    }
  
  else {
    for(int i=0; i<8;i++)
      {
        matriz.setRow(0,i,copo[i]);
      }
  k=tiempo;
  }
}
void MQ2()
{
  sensor = analogRead(A0);
  lectura=map(sensor,0,1024,0,100);
  Serial.print(lectura);
  Serial.println("%");
}
