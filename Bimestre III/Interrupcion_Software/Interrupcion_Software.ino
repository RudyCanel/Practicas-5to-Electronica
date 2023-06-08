/* Fundacion Kinal
* Centro educativo técnico laboral Kinal
* Perito en electronica
* Quinto perito
* Sección: A
* Curso : Taller de electronica digital y reparación de computadoras
* Alumno: Rudy Santiago Canel Par
* Carnet:2022449
* Proyecto: Interrupcion por medio de software
*/
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
  temp.requestTemperatures();   // Inicia la comunicacion para obtener la temperatura
  delay(2);
}
void software ()
{
  Serial.print("Temperatura:  ");
  Serial.print(temp.getTempCByIndex(0));  //Imprime la temperatura en grados Centigrados
  Serial.println("C");
}
void interrupt()
{
  Serial.println(text);    // Imprime el texto almacenado en la variable text
}
void condicionales()
{
  x= digitalRead(2);    // Guardo la lectura en la variable x
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
