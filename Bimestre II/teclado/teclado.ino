/* Fundacion Kinal
* Centro educativo técnico laboral Kinal
* Perito en electronica
* Quinto perito
* Sección: A
* Curso : Taller de electronica digital y reparación de computadoras
* Alumno: Rudy Santiago Canel Par
* Carnet:2022449
* Proyecto:Keypad
*/
#include <Keypad.h>
#define filas 4
#define columnas 4
#define f1 2
#define f2 3
#define f3 4
#define f4 5
#define c1 6
#define c2 7
#define c3 8
#define c4 9
#define ON(pin)  digitalWrite(pin,HIGH)
#define OFF(pin) digitalWrite(pin,LOW)
#define pinOutput(pin) pinMode(pin,OUTPUT)
char teclas [filas][columnas] ={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
enum disp {
  caso1,
  caso2,
  caso3,
  caso4,
  caso5,
  caso6,
  caso7,
 
};

//pin 10=a, pin11=b, pin12=c pin13=d, pinA2=e, pinA3=f, pinA4=g.



byte pines_fila[filas] = { f1,f2,f3,f4};
byte pines_columnas[columnas] = {c1,c2,c3,c4};

Keypad tecla = Keypad(makeKeymap(teclas),pines_fila,pines_columnas,filas,columnas);
int Z=0;

void setup() {
  Serial.begin(9600);
  pinOutput(10);
  pinOutput(11);
  pinOutput(12);
  pinOutput(13);
  pinOutput(A2);
  pinOutput(A3);
  pinOutput(A4);
 

}

void loop() {
   int X=1;
  char presionado = tecla.getKey();
  if (presionado)
  {
    Serial.println(presionado);
  }

switch (presionado) {

  case ('1'):{
    OFF(10);
    ON(11);
    ON(12);
    OFF(13);
    OFF(A2);
    OFF(A3);
    OFF(A4);

    delay(300);
    X=0;
    break;
  }
  case('2') :{
    ON(10);
    ON(11);
    OFF(12);
    ON(13);
    ON(A2);
    OFF(A3);
    ON(A4);

    delay(300);
    X=0;
    break;
  }
  case('3'):{
    ON(10);
    ON(11);
    ON(12);
    ON(13);
    OFF(A2);
    OFF(A3);
    ON(A4);
    delay(300);
    X=0;
    break;
  }
  case ('4') :{
    OFF(10);
    ON(11);
    ON(12);
    OFF(13);
    OFF(A2);
    ON(A3);
    ON(A4);
    delay(300);
    X=0;
    break;
  }
  case ('5') :{
    ON(10);
    OFF(11);
    ON(12);
    ON(13);
    OFF(A2);
    ON(A3);
    ON(A4);
    delay(300);
    X=0;
    break;
  }
  case ('6'): {
    ON(10);
    OFF(11);
    ON(12);
    ON(13);
    ON(A2);
    ON(A3);
    ON(A4);
    delay(300);
    X=0;
    break;
  }
  case ('7') : {
    ON(10);
    ON(11);
    ON(12);
    OFF(13);
    OFF(A2);
    OFF(A3);
    OFF(A4);
    delay(300);
    X=0;
    break;
  }
  case ('8') : {
    ON(10);
    ON(11);
    ON(12);
    ON(13);
    ON(A2);
    ON(A3);
    ON(A4);
    delay(300);
    X=0;
    break;
  }
  case ('9') : {
    ON(10);
    ON(11);
    ON(12);
    OFF(13);
    OFF(A2);
    ON(A3);
    ON(A4);
    delay(300);
    X=0;
    break;
  }
  case ('A') : {
    ON(10);
    ON(11);
    ON(12);
    OFF(13);
    ON(A2);
    ON(A3);
    ON(A4);
    delay(300);
    X=0;
    break;
  }
  case ('B') : {
    OFF(10);
    OFF(11);
    ON(12);
    ON(13);
    ON(A2);
    ON(A3);
    ON(A4);
    delay(300);
    X=0;
    break;
  }
  case ('C') : {
    OFF(10);
    OFF(11);
    OFF(12);
    ON(13);
    ON(A2);
    OFF(A3);
    ON(A4);
    delay(300);
    X=0;
    break;
  }
  case ('D') : {
    OFF(10);
    ON(11);
    ON(12);
    ON(13);
    ON(A2);
    OFF(A3);
    ON(A4);
    delay(300);
    X=0;
    break;
  }
  case ('#') : {
    ON(10);
    OFF(11);
    OFF(12);
    ON(13);
    ON(A2);
    ON(A3);
    ON(A4);
    delay(300);
    X=0;
    break;
  }
  case ('*') : {
    ON(10);
    OFF(11);
    OFF(12);
    OFF(13);
    ON(A2);
    ON(A3);
    ON(A4);
    delay(300);
    X=0;
    break;
  }
}
if (X==0) {
    ON(10);
    ON(11);
    ON(12);
    ON(13);
    ON(A2);
    ON(A3);
    OFF(A4);
}


   
  }
