/* Fundacion Kinal
* Centro educativo técnico laboral Kinal
* Perito en electronica
* Quinto perito
* Sección: A
* Curso : Taller de electronica digital y reparación de computadoras
* Alumno: Rudy Santiago Canel Par
* Carnet:2022449
* Proyecto:Motor de Agua
*/
#define SBI(pin) digitalWrite(pin,HIGH)
#define CBI(pin) digitalWrite(pin,LOW)
#define setpinInput(pin)   pinMode(pin,INPUT)
#define setpinOutput(pin)  pinMode(pin,OUTPUT)
void setup() {
  setpinInput(A5);
  setpinOutput(12);
  setpinOutput(2);
  setpinOutput(3);

}

void loop() {
    bool SENSOR = digitalRead(A5);
    switch (SENSOR) {
      case (LOW) : 
      {
        CBI(12);
        CBI(2);
        SBI(3);
        break;
      }
      case(HIGH) : 
      {
        CBI(3);
        SBI(12);
        SBI(2);
        break;
      }
    }

}
