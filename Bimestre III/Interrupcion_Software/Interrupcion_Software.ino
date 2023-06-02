#include <DallasTemperature.h>
#include <OneWire.h>
#include <Ticker.h>
int x;                           // Variable para 
OneWire myWire(4);               // OneWire
DallasTemperature temp(&myWire); // DallasTemperature

String text;             // Variable para almacenar el texto 
void software();        // Funcion para imprimir la temperatura 
void interrupt();       // Funcion para imprimir el texto de la variable text  
void condicionales();

Ticker sens(software,400);
Ticker timer(interrupt,900);
void setup() {
  temp.begin();
  sens.start();
  timer.start();
  Serial.begin(9600);
  pinMode(2,INPUT);
}
void loop() {  
  temperatura();
  sens.update();
  timer.update();
  condicionales();
}
void temperatura()
{
  temp.requestTemperatures();
  delay(2);
}
void software ()
{
  Serial.print("Temperatura:  ");
  Serial.print(temp.getTempCByIndex(0));
  Serial.println("C");
}
void interrupt()
{
  Serial.println(text);
}
void condicionales()
{
  x= digitalRead(2);
  if (x==1)
  {
    text= "Sensor Digital Cerrado";
  }
  else if(x==0)
  {
    text= "Sensor Digital Abierto";
  }
  else {
    text= "";
  }
}
