/* Fundacion Kinal
* Centro educativo técnico laboral Kinal
* Perito en electronica
* Quinto perito
* Sección: A
* Curso : Taller de electronica digital y reparación de computadoras
* Alumno: Rudy Santiago Canel Par
* Carnet:2022449
* Proyecto: Control de brillo de un led 
*/
#define pinled 9
#define pinpot A0
unsigned int pot=0;
unsigned int led=0;
void setup()
{
  Serial.begin(9600);
  pinMode(pinled,OUTPUT);
  pinMode(pinpot,INPUT);
}

void loop()
{
  pot = analogRead(pinpot);
  led = map(pot, 0, 1023,0,255);
  analogWrite(pinled,led);
  Serial.println(led);
}
