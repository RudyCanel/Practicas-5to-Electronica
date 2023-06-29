/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Perito en Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: Taller de electronica digital
 * Nombres: Rudy Santiago Canel Par
 * Carnet: 2022449
 * Proyecto: Aplicacion Bluetooth
*/
#include <Ticker.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <SoftwareSerial.h>
#define ON(pin)       digitalWrite(pin,HIGH)
#define OFF(pin)      digitalWrite(pin,LOW)
#define output(pin)   pinMode(pin,OUTPUT)
#define input(pin)    pinMode(pin,INPUT)
void temp (void);

float valor=25;

Ticker interrupt(temp, 10000);
OneWire temperatura(5);
DallasTemperature mytemp(&temperatura);
SoftwareSerial rxtx(8,9);
void setup()
{
  interrupt.start();
  mytemp.begin();
  Serial.begin(9600);
  rxtx.begin(9600);
  output(2);
  OFF(2);
}

void loop()
{
  interrupt.update();
  while (rxtx.available() > 0)
  {
    
    char caracter = rxtx.read();

    if (caracter == '1')
    {
      ON(2);
    }
    else if (caracter == '0')
    {
      OFF(2);
    }
  }
   
  mytemp.requestTemperatures();
  rxtx.print(valor);
  rxtx.print(";");

}

void temp(void)
{
  valor = mytemp.getTempCByIndex(0);
}
