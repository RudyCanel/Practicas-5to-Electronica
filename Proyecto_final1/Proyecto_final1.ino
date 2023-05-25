// Librerias
#include <Servo.h>
#include <LiquidCrystal_I2C.h>

// Directivas preprocesador
#define ON(pin)          digitalWrite(pin,HIGH)
#define OFF(pin)         digitalWrite(pin,LOW)
#define Input(pin)       pinMode(pin,INPUT)
#define Output(pin)      pinMode(pin,OUTPUT)
#define lectura(pin)     digitalRead(pin)

// Constructores
Servo servo;
LiquidCrystal_I2C lcd(0x27, 16, 2);

//Variables globales
int se = 0;
int x = 0;
int Q0 = 0;
int dis = 0;
int se1 = 0;

void setup()
{
  //Llamado de las funciones de inicio de pines y librerias
  configPin();
  inicializar();
}
void loop()
{
  //Llamado de la funcion general del silo
  silo();
}

// Funcion de configuracion de pines
void configPin()
{
  for (int x = 2; x < 8; x++)   // Configura los pines 2-8 como entrada utilizando un for
  {
    Input(x);
  }

  // Pines configurados como salida
  Output(9);
  Output(10);
  Output(11);
}

// Funcion de inicializacion de las librerias
void inicializar()
{
  servo.attach(10);   // Indico el numero del pin donde estara conectado el servomotor
  servo.write(0);     // Indico que el servomotor inicie con un angulo de 0
  lcd.init();         // Inicio la LCD por medio de I2C
  lcd.backlight();    // Enciendo la luz de fondo de la LCD
}

// Funcion de los valores de los diferentes botones
int botones (int b1, int b2, int b3,                 //Configuracion general de botones
             int b4, int b5, int b6)
{
  int Q1;                                           // Crea  una variable local tipo int


  // Indico que, dependiendo del boton presionado, le asigna un valor a la variable Q1
  if (b1 == HIGH)
  {
    Q1 = 2;
  }
  else if (b2 == HIGH)
  {
    Q1 = 4;
  }
  else if (b3 == HIGH)
  {
    Q1 = 10;
  }
  else if (b4 == HIGH)
  {
    Q1 = 16;
  }
  else if (b5 == HIGH)
  {
    Q1 = 18;
  }
  else if (b6 == HIGH)
  {
    Q1 = 20;
  }

  // Si ningun boton esta presionado, asigno un valor 0 a Q1
  else
  {
    Q1 = 0;
  }
  return Q1;
}

// Funcion para los valores de el sensor ultrasonico
int sensor(int TRIG, int ECHO)
{
  // Variables tipo int para guardar los diferentes datos numericos
  int distancia;
  int duracion;
  int nivel;

  ON(TRIG);                 // Envio un pulso por medio del pin TRIG
  delayMicroseconds(2);     // Espero 2 microsegundos
  OFF(TRIG);                // Dejo de enviar el pulso
  delayMicroseconds(10);    // Espero 10 microsegundos

  // Condicional if para detener la lectura de pulso de TRIG, si algun boton esta presionado
  // Condicional que se cumple si todos los botones son cero
  if (((lectura(2) == LOW) && (lectura(3) == LOW)  && (lectura(4) == LOW) && (lectura(5) == LOW) && (lectura(6) == LOW) && (lectura(7) == LOW)))
  {
    duracion = pulseIn(ECHO, HIGH);     // Guardo el valor de pulso recibido en ECHO en la variable duracion
    distancia = duracion / 29.1 / 2;    // Formula para calcular la distancia
    nivel = 22 - distancia;             // Guardo en nivel el resultado de la resta de el numero maximo de granos con la distancia del sensor
    delay(75);                          // Espero 75 milisegundos
    return nivel;                       // Regresa a la funcion principal el valor de la variable nivel
  }
}

// Funcion general del funcionamiento del silo de granos
void silo ()
{

  // Llamo y guardo, en una variable int, el valor de Q1
  int bt = botones (lectura(2), lectura(3), lectura(4), lectura(5), lectura(6), lectura(7));



  // Llamo y guardo en una variable int, el valor del sensor
  int sens = sensor (9, 8);

  // Creo una condicional para que guarde el valor anterior la lectura de el sensor en la variable dis
  // Cuando se presiona un boton

  if (sens != 0 && sens > 0 && sens < 22 && se == 0)   // Si la lectura del sensor no es cero y mayor que cero pero no menor que 22
    // Y si "se" se encuentra en cero
  {
    dis = sens;
  }


  // Creo una condicional para que guarde el valor de Q1 en la variable Q0
  if (bt != 0 && bt > 0 && bt < 22)   // Si la lectura del boton no es cero y es mayor que cero pero no es mayor que 22
  {
    Q0 = bt;
  }


  // Guardo en la varieble x, el resultado de la resta de
  x = dis - Q0;

  // Creo una condicional para que guarde guarde un 1 en la variable se
  // Indico que el servomotor se mueva en un angulo de 90 grados
  // Indico que guarde un valor 0 en la variable se1

  if (dis > x && x > 0 && x < 22)   // Si la distancia guardada es mayor a el resultado de la resta y no es cero pero tampoco mayor que 22
  {
    se = 1;
    servo.write(90);
    se1 = 0;
  }

  // Si la condicional no se cumple, indico que el servomotor vuelva a un estado de grado 0
  else
  {
    servo.write(0);
  }

  // Creo una condicional, la cual asigna un valor 0 a la variable se
  // Indico que la variable Q0 tenga un valor de 0

  if (x >= sens && sens != 0)                           // Si el resultado de la resta es mayor a el sensor y no es 0
  {
    se = 0;
    Q0 = 0;
  }

  // Creo un acondicional que imprime en la pantalla LCD un mensaje si no hay granos suficientes
  if (x <= -1 && se1 == 0)    // Si x es menor o igual a -1 y si se1 tiene un valor de 0
  {
    lcd.setCursor(0, 0);
    lcd.print("   Sin Granos   ");
    lcd.setCursor(0, 1);
    lcd.print("  Suficientes   ");
  }

  // Si la condicional no se cumple, una condicional me imprime la cantidad de granos disponibles
  else if (sens >= 0) {     // Si el sensor es mayor o igual que 0

    lcd.setCursor(0, 0);
    lcd.print("     Granos     ");
    lcd.setCursor(0, 1);
    lcd.print("Disponibles:");
    lcd.print(sens);
    lcd.print("cm");
  }

  // Creo una condicional que emite un tono en el buzzer
  if (x <= -1 && se1 == 0)   // Si x es menor o igual a -1 y se1 es igual a 0
  {
    tone(11, 700, 200);
    delay(300);
    tone(11, 700, 200);
    delay(300);
    tone(11, 700, 200);
    delay(300);
    se1 = 1;
  }
}
