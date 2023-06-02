/* Fundacion Kinal
* Centro educativo técnico laboral Kinal
* Perito en electronica
* Quinto perito
* Sección: A
* Curso : Taller de electronica digital y reparación de computadoras
* Alumno: Rudy Santiago Canel Par
* Carnet:2022449
* Proyecto:LCD
*/

#include <LiquidCrystal.h>
LiquidCrystal NOMBRE_CARNET (2,3,9,10,11,12);
void setup()
{

  NOMBRE_CARNET.begin(16,2);
  NOMBRE_CARNET.print("RUDY");
  NOMBRE_CARNET.setCursor(0,1);
  NOMBRE_CARNET.print("2022449");
}
void loop()
{
}




  
