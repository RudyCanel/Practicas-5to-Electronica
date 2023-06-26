/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Perito en Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: Taller de electronica digital
 * Nombre: Rudy Santiago Canel Par
 * Carnet: 2022449
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
  serv.write(0);
}

void stepper (int IC1, int IC2, int IC3, int IC4)  // Funcion para el funcionamiento del motor stepper 
{
int k=2;
  unsigned char sens = obstaculo(9);
  if (sens == 1)
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
    detectado=0;
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
  else  // Despues de detectar el color, la cinta continua moviendose
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
  delay(500);
  intensidad = analogRead(A0);
  led_rojo = map(intensidad,0,1023,0,1023);
  Serial.print("rojo  ");
  Serial.println(intensidad);
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
  {
    OFF(13);
    ON(12);
    OFF(10);
    serv.write(0);
    detectado=1;
  }
  else if(led_verde > led_rojo && led_verde > led_azul)
  {
    ON(10);
    OFF(12);
    OFF(13);
    serv.write(90);
    detectado=1;
  }
  else if (led_azul > led_rojo && led_azul > led_verde)
  {
    OFF(12);
    OFF(10);
    ON(13);
    serv.write(0);
    detectado=1;
  }
  else {
    OFF(12);
    OFF(10);
    OFF(13);
    serv.write(0);
  }
   delay(2000);
}
