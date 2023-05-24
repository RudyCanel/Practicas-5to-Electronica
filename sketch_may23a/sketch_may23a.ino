#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#define ON(pin)        digitalWrite(pin,HIGH)
#define OFF(pin)       digitalWrite(pin,LOW)
#define Input(pin)     pinMode(pin,INPUT)
#define Output(pin)    pinMode(pin,OUTPUT)
#define lectura(pin)   digitalRead(pin)

Servo servo;
LiquidCrystal_I2C lcd(0x27, 16, 2);
int se = 0;
int x = 0;
int Q0 = 0;
int dis = 0;
void setup()
{
  configPin();
  inicializar();
  Serial.begin(9600);
}
void loop()
{
  silo();
}

void configPin()
{
  for (int x = 2; x < 8; x++) // Configura los pines 2-8 como entrada utilizando un for
  {
    Input(x);
  }
  Output(9);
  Output(10);
}
void inicializar()
{
  servo.attach(10);
}
int botones (int b1, int b2, int b3,    //Configuracion general de botones
             int b4, int b5, int b6)
{
  int Q1;    // Crea  una variable tipo float

  if (b1 == HIGH)
  {
    Q1 = 3;
  }
  else if (b2 == HIGH)
  {
    Q1 = 7;
  }
  else if (b3 == HIGH)
  {
    Q1 = 10;
  }
  else if (b4 == HIGH)
  {
    Q1 = 13;
  }
  else if (b5 == HIGH)
  {
    Q1 = 17;
  }
  else if (b6 == HIGH)
  {
    Q1 = 20;
  }
  else
  {
    Q1 = 0;
  }
  return Q1;
}

int sensor(int TRIG, int ECHO)
{
  int distancia;
  int duracion;
  int nivel;
  ON(TRIG);
  delayMicroseconds(2);
  OFF(TRIG);
  delayMicroseconds(10);

  if (((lectura(2) == LOW) && (lectura(3) == LOW)  && (lectura(4) == LOW) && (lectura(5) == LOW) && (lectura(6) == LOW) && (lectura(7) == LOW)))
  {
    duracion = pulseIn(ECHO, HIGH);
    distancia = duracion / 29.1 / 2;
    nivel = 21 - distancia;
    delay(75);
    return nivel;
  }


}

void silo ()
{
  int bt = botones (lectura(2), lectura(3), lectura(4), lectura(5), lectura(6), lectura(7));
  int sens = sensor (9, 8);
  int sens1 = sens + 1;
  if (sens != 0 && sens > 0 && sens < 22 && se == 0)
  {
    dis = sens;
  }
  if (bt != 0 && bt > 0 && bt < 22)
  {
    Q0 = bt;
  }

  x = dis - Q0;

  if (dis > x && x > 0 && x < 22)
  {
    se = 1;
    servo.write(90);
  }
  else {
    servo.write(0);
  }

  if (x >= sens && sens != 0)
  {
    se = 0;
    Q0 = 0;
  }

  Serial.print(sens);
  Serial.println("dis");
  Serial.print(x);
  Serial.println("x");
}
