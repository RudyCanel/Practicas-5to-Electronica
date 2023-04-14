/* Fundacion Kinal
* Centro educativo técnico laboral Kinal
* Perito en electronica
* Quinto perito
* Sección: A
* Curso : Taller de electronica digital y reparación de computadoras
* Alumno: Rudy Santiago Canel Par
* Carnet:2022449
* Proyecto:Autofantastico
*/
#define setpinOutput(pin) digitalWrite(pin,OUTPUT)
#define SBI(pin) digitalWrite(pin,HIGH)
#define CBI(pin) digitalWrite(pin,LOW)
#define DLY(ms)  delay(ms)
int X=0;
int Y=0;
void setup() {
  setpinOutput(2);
  setpinOutput(3);
  setpinOutput(4);
  setpinOutput(5);
  setpinOutput(6);
  setpinOutput(7);
  setpinOutput(8);
  setpinOutput(9);
  setpinOutput(10);
  setpinOutput(11);
  for(int Z=2; Z<11; Z++){
    CBI(Z);
  };
}


void loop() {
for (X=2; (X<11) && (Y==0); X++) {
  SBI(X);
  DLY(100);
  CBI(X);
}
Y=1;
for(X=X; (X>2) && (Y==1); X--) {
  SBI(X);
  DLY(100);
  CBI(X);

 
}
Y=0;
}
