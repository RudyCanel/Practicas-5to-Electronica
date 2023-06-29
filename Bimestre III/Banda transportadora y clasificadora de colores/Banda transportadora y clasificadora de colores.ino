/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Perito en Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: Taller de electronica digital
 * Nombres: Rudy Santiago Canel Par, Miguel Angel Alvarado 
 * Carnet: 2022449, 2022486
 * Proyecto: Banda transportadora y clasificadora de colores
*/
#define ON(pin)     digitalWrite(pin,HIGH)
#define OFF(pin)    digitalWrite(pin,LOW)
#define Input(pin)  pinMode(pin,INPUT)
#define Output(pin) pinMode(pin,OUTPUT)
#include <Servo.h>

Servo serv;
int obstaculo(int pinSens);
void configpin(void);
void stepper (int IC1, int IC2, int IC3, int IC4);

int led_rojo, led_verde, led_azul;
int detectado=0;
int intensidad;
void setup()
{
  configpin();
  Serial.begin(9600);
}

void loop()
{
  stepper(2,3,4,5);
}

int obstaculo(int pinSens)
{
  int sensObs;
  sensObs = digitalRead(pinSens);
  return sensObs;
}

void configpin(void)
{
  Output(2);
  Output(3);
  Output(4);
  Output(5);
  Output(6);
  Output(7);
  Output(8);
  Input(9);
  Output(10);
  Output(11);
  Output(12);
  Output(13);
  Input(A0);
  serv.attach(11);
  serv.write(180);
}

void stepper (int IC1, int IC2, int IC3, int IC4)  // Funcion para el funcionamiento del motor stepper 
{
int k=2;
  unsigned char sens = obstaculo(9);   // Llamo a la funcion del sensor de obstaculos
  if (sens == 1)  // Si el sensor de obstaculos no me detecta ningun objeto, el motor stepper gira 
  {
    ON(IC1);
    OFF(IC2);
    OFF(IC3);
    ON(IC4);
    delay(k);

    ON(IC1);
    ON(IC2);
    OFF(IC3);
    OFF(IC4);
    delay(k);
    
    OFF(IC1);
    ON(IC2);
    ON(IC3);
    OFF(IC4);
    delay(k);

    OFF(IC1);
    OFF(IC2);
    ON(IC3);
    ON(IC4);
    delay(k);

    ON(IC1);
    OFF(IC2);
    OFF(IC3);
    ON(IC4);
    delay(k);

    ON(IC1);
    ON(IC2);
    OFF(IC3);
    OFF(IC4);
    delay(k);
    
    OFF(IC1);
    ON(IC2);
    ON(IC3);
    OFF(IC4);
    delay(k);

    OFF(IC1);
    OFF(IC2);
    ON(IC3);
    ON(IC4);
    delay(k);

    ON(IC1);
    OFF(IC2);
    OFF(IC3);
    ON(IC4);
    delay(k);

    ON(IC1);
    ON(IC2);
    OFF(IC3);
    OFF(IC4);
    delay(k);
    
    OFF(IC1);
    ON(IC2);
    ON(IC3);
    OFF(IC4);
    delay(k);

    OFF(IC1);
    OFF(IC2);
    ON(IC3);
    ON(IC4);
    delay(k);
    detectado=0; // Asigna un valor de 0 a la variable encargada de verificar si el objeto aun se encuentra en la area de verificacion de color
  }
  else if (sens==0 && detectado==0)  // Condicional para que cuando detecte el objeto mueva un poco la cinta y empiece con las lecturas de los colores
  {
    for (int x = 0; x<20; x++)
    {
      ON(IC1);
    OFF(IC2);
    OFF(IC3);
    ON(IC4);
    delay(k);

    ON(IC1);
    ON(IC2);
    OFF(IC3);
    OFF(IC4);
    delay(k);
    
    OFF(IC1);
    ON(IC2);
    ON(IC3);
    OFF(IC4);
    delay(k);

    OFF(IC1);
    OFF(IC2);
    ON(IC3);
    ON(IC4);
    delay(k);
    }
    color(A0, 6, 7, 8);
  }
  else  // Despues de detectar el color y el objeto aun sigue en el area de clasificacion, la cinta continua moviendose
  {
    ON(IC1);
    OFF(IC2);
    OFF(IC3);
    ON(IC4);
    delay(k);

    ON(IC1);
    ON(IC2);
    OFF(IC3);
    OFF(IC4);
    delay(k);

    OFF(IC1);
    ON(IC2);
    ON(IC3);
    OFF(IC4);
    delay(k);

    OFF(IC1);
    OFF(IC2);
    ON(IC3);
    ON(IC4);
    delay(k);
  }
}

void color(int pinLDR, int pinRojo, int pinVerde, int pinAzul)  // Funcion para la lectura de los colores
{
  ON(pinRojo);   
  delay(500);   // Enciendo del pin del led Rojo durante medio segundo
  intensidad = analogRead(A0);     // Guardo el valor de la lectura en la variable intensidad
  led_rojo = map(intensidad,0,1023,0,1023);   // Hago un mapeo para evitar errores de lectura
  Serial.print("rojo  ");   
  Serial.println(intensidad);    // Imprimo el valor de luz que ha detectado el LDR tras el color rojo
  OFF(pinRojo);


  ON(pinVerde);
  delay(500);
  intensidad=analogRead(A0);
  led_verde = map(intensidad,0,1023,0,1023);
  Serial.print("Verde  ");
  Serial.println(intensidad);
  OFF(pinVerde);
  
  ON(pinAzul);
  delay(500);
  intensidad=analogRead(A0);
  led_azul = map(intensidad,0,1023,0,1023);
  Serial.print("Azul  ");
  Serial.println(intensidad);
  OFF(pinAzul);


  if (led_rojo > led_verde && led_rojo > led_azul)     // Condicionales para saber cual de los tres colores (Rojo, Verde o Azul) es el objeto
    // Condicional que indica que el color que mas valor tenga, es el color del objeto
  {
    OFF(13);
    ON(12);        // Enciendo y apago leds de referencia para la lectura de los colores
    OFF(10);
    serv.write(180);   // Servo con un angulo de 180 grados
    detectado=1;      // Asigna un valor de 1 a la variable detectado para indicar que el objeto se encuentra en el area de detector de color 
  }
  else if(led_verde > led_rojo && led_verde > led_azul)
  {
    ON(10);
    OFF(12);
    OFF(13);
    serv.write(90);   // Debido a que el color que queremos clasificar, por medio de el servo, clasificamos el color verde 
    delay(400);     // Esperamos 400 milisegundos anes de regresar el servo a su posicion inicial
    serv.write(180);  // Regresa el servo a su posicion inicial
    detectado=1;
  }
  else if (led_azul > led_rojo && led_azul > led_verde)
  {
    OFF(12);
    OFF(10);
    ON(13);
    serv.write(180);
    detectado=1;
  }
  else {
    OFF(12);
    OFF(10);
    OFF(13);
    serv.write(180);
  }
   delay(2000);  // Despues de hacer las lecturas y condicionales, esperamos dos segundos para evitar cualquier problema de lecturas 
}
