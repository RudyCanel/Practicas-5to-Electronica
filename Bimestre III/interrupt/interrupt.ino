/* Fundacion Kinal
* Centro educativo técnico laboral Kinal
* Perito en electronica
* Quinto perito
* Sección: A
* Curso : Taller de electronica digital y reparación de computadoras
* Alumno: Rudy Santiago Canel Par
* Carnet:2022449
* Proyecto: Contador de decadas por medio de interrupciones
*/
#define ON(pin)       digitalWrite(pin,HIGH)
#define OFF(pin)      digitalWrite(pin,LOW)
void Rising (void); // Funciones para la interrupcion
void Falling (void);

int i=0;
int j=0;
void setup()
{
  attachInterrupt(digitalPinToInterrupt(2),Rising, RISING);    // Indico el valor del pin a interrumpir, con modo de interrupcion RISING
  attachInterrupt(digitalPinToInterrupt(3),Falling, FALLING);  // Indico el valor del pin a interrumpir, con modo de interrupcion FALLING 
  pines(); // Llamo la funcion que contiene la configuracion de los pines 
}

void loop()
{
  condicionales();  // Llamo a la funcion que contiene las diferentes condicionales para el funcionamiento del programa
  Display();        // Llamo a la funcion que contiene los Switch Case, con cada modo de los pines para el display de 7 segmentos
}

void Rising(void)   // Indico la operacion a realizar para la funcion de la interrupcion por medio de RISING
{
  i = i+1;
}

void Falling (void) // Indico la operacion a realizar para la funcion de la interrupcion por medio de FALLING
{
  i = i-1;
}

void pines(void)  // Funcion que contiene las configuraciones de los pines
{
  pinMode(2,INPUT);
  pinMode(3,INPUT_PULLUP);
  for(int x=4; x<12; x++)
  {
    pinMode(x,OUTPUT);
  }
}
void condicionales(void)
{
  if (i>=10)
  {
    i=0;
    j=j+1;
  }
  if (i<=-1)
  {
    i=9;
    j=j-1;
  }
  if (j<=-1)
  {
    j=5;
    i=0;
  }
  if (j>=5 && i>0)
  {
    j=0;
    i=0;
  }
}
void Display()
{
  switch (i)
  {
    case (1):
    {
      ON(8);
      OFF(9);
      OFF(10);
      OFF(11);
      break;
    }
    case (2):
    {
      OFF(8);
      ON(9);
      OFF(10);
      OFF(11);
      break;
    }
    case (3):
    {
      ON(8);
      ON(9);
      OFF(10);
      OFF(11);
      break;
    }
    case (4):
    {
      OFF(8);
      OFF(9);
      ON(10);
      OFF(11);
      break;
    }
    case (5):
    {
      ON(8);
      OFF(9);
      ON(10);
      OFF(11);
      break;
    }
    case (6):
    {
      OFF(8);
      ON(9);
      ON(10);
      OFF(11);
      break;
    }
    case (7):
    {
      ON(8);
      ON(9);
      ON(10);
      OFF(11);
      break;
    }
    case (8):
    {
      OFF(8);
      OFF(9);
      OFF(10);
      ON(11);
      break;
    }
    case (9):
    {
      ON(8);
      OFF(9);
      OFF(10);
      ON(11);
      break;
    }
    default :
    {
      OFF(8);
      OFF(9);
      OFF(10);
      OFF(11);
      break;
    }
  }
  switch (j)
  {
    case (1):
    {
      ON(4);
      OFF(5);
      OFF(6);
      OFF(7);
      break;
    }
    case (2):
    {
      OFF(4);
      ON(5);
      OFF(6);
      OFF(7);
      break;
    }
    case (3):
    {
      ON(4);
      ON(5);
      OFF(6);
      OFF(7);
      break;
    }
    case (4):
    {
      OFF(4);
      OFF(5);
      ON(6);
      OFF(7);
      break;
    }
    case (5):
    {
      ON(4);
      OFF(5);
      ON(6);
      OFF(7);
      break;
    }
    default :
    {
      OFF(4);
      OFF(5);
      OFF(6);
      OFF(7);
      break;
    }
  }
}
