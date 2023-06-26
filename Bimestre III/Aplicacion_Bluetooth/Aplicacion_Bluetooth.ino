#include <Ticker.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <SoftwareSerial.h>
#define ON(pin)       digitalWrite(pin,HIGH)
#define OFF(pin)      digitalWrite(pin,LOW)
#define output(pin)   pinMode(pin,OUTPUT)
#define input(pin)    pinMode(pin,INPUT)
void temp (void);

volatile static int temperatura;
unsigned int valor;

Ticker interrupt(temp, 10000);
OneWire temperatura1(5);
DallasTemperature mytemp(&temperatura1);
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
  while (rxtx.available() != 0)
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
  delay(1025);
}

void temp(void)
{
  valor = mytemp.getTempCByIndex(0);
  
}
