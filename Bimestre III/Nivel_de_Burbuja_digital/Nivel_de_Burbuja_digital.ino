/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Perito en Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: Taller de electronica digital
 * Nombres: Rudy Santiago Canel Par
 * Carnet: 2022449
 * Proyecto: Nivel de burbuja digital
*/
#include <Wire.h>
#include <SparkFun_ADXL345.h>
#include <LedControl.h>
ADXL345 acelerometro = ADXL345();
LedControl matrix =LedControl(12,11,10);

int x;
int y;
int z;

byte C[8] = {
   B00000000,
   B00000000,
   B00000000,
   B00011000,
   B00011000,
   B00000000,
   B00000000,
   B00000000
  };
  byte R1[8] = {
   B00000000,
   B00000000,
   B00000000,
   B00001100,
   B00001100,
   B00000000,
   B00000000,
   B00000000
  };
  
  byte R2[8] = {
   B00000000,
   B00000000,
   B00000000,
   B00000110,
   B00000110,
   B00000000,
   B00000000,
   B00000000
  };
  byte R3[8] = {
   B00000000,
   B00000000,
   B00000000,
   B00000011,
   B00000011,
   B00000000,
   B00000000,
   B00000000
  };
  byte L1[8] = {
   B00000000,
   B00000000,
   B00000000,
   B00110000,
   B00110000,
   B00000000,
   B00000000,
   B00000000
  };
  
  byte L2[8] = {
   B00000000,
   B00000000,
   B00000000,
   B01100000,
   B01100000,
   B00000000,
   B00000000,
   B00000000
  };
  byte L3[8] = {
   B00000000,
   B00000000,
   B00000000,
   B11000000,
   B11000000,
   B00000000,
   B00000000,
   B00000000
  };
void setup ()
{
  Serial.begin(9600);
  acelerometro.powerOn();
  matrix.shutdown(0,false);
  matrix.setIntensity(0,10);
  matrix.clearDisplay(0);
  acelerometro.setRangeSetting(16);
}

void loop ()
{
  acelero();
  derecha();
  izquierda();
}


void acelero()
{
  acelerometro.readAccel(&x,&y,&z);
}

void derecha()
{
  if (x<4 && x>=0)
  {
    for(int i=0; i<9;i++)
        {
          matrix.setRow(0,i,C[i]);
        }
  } else if(x>4 && x<8)
  {
  for(int i=0; i<9;i++)
      {
        matrix.setRow(0,i,R1[i]);
      }
  }else if(x>8 && x<12)
  {
  for(int i=0; i<9;i++)
      {
        matrix.setRow(0,i,R2[i]);
      }
  } else if(x>12) {
  for(int i=0; i<9;i++)
      {
        matrix.setRow(0,i,R3[i]);
      }
  }
}

void izquierda()
{
  if (x<0 && x>-4)
  {
  for(int i=0; i<9;i++)
      {
        matrix.setRow(0,i,C[i]);
      }
  }

  if (x<-4 && x>-8)
  {
  for(int i=0; i<9;i++)
      {
        matrix.setRow(0,i,L1[i]);
      }
  }

  if (x<-8 && x>-12)
  {
  for(int i=0; i<9;i++)
      {
        matrix.setRow(0,i,L2[i]);
      }
  }
  if (x<-12)
  {
  for(int i=0; i<9;i++)
      {
        matrix.setRow(0,i,L3[i]);
      }
  }
}
