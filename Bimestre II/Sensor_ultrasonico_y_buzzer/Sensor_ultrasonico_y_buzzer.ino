/* Fundacion Kinal
* Centro educativo técnico laboral Kinal
* Perito en electronica
* Quinto perito
* Sección: A
* Curso : Taller de electronica digital y reparación de computadoras
* Alumno: Rudy Santiago Canel Par
* Carnet:2022449
* Proyecto:Sensor ultrasonico y Buzzer
*/
#define SBI(pin)            digitalWrite(pin,HIGH)
#define CBI(pin)            digitalWrite(pin,LOW)
#define setpinInput(pin)    pinMode(pin,INPUT)
#define setpinOutput(pin)   pinMode(pin,OUTPUT)

void SENSOR (int TRIG, int ECHO);
void NOTAS (int BUZZER, int c, int d, int e, int f, int g, int a, int b);
int DISTANCIA1=0;

void setup ()
{
}
void loop() 
{
  NOTAS(12,261,294,329,349,391,440,466);
  SENSOR(2,3);
}




void SENSOR(int TRIG, int ECHO)
{
  int DISTANCIA=0;
  setpinInput(3);
  setpinOutput(2);
  int TIEMPO=0;
  SBI(TRIG);
  delayMicroseconds(2);
  CBI(TRIG);
  delayMicroseconds(10);
  TIEMPO= pulseIn(ECHO,HIGH);
  DISTANCIA1= TIEMPO/29.1/2;
  
  
}

void NOTAS (int BUZZER, int c, int d, int e, int f, int g, int a, int b)
{
  if (DISTANCIA1==1)
  {
    tone(BUZZER,c,90);
    delay(100);
  }
  if (DISTANCIA1==2) 
  {
    tone(BUZZER,d,90);
    delay(100);
  }
  if (DISTANCIA1==3)
  {
    tone(BUZZER,e,90);
    delay(100);
   
  }
  
  if (DISTANCIA1==4)
  {
    tone(BUZZER,f,90);
    delay(100);
  }
  
  if (DISTANCIA1==5)
  {
    tone(BUZZER,g,90);
    delay(100);
  }
  
  if (DISTANCIA1==6)
  {
    tone(BUZZER,a,90);
    delay(100);
   
  }
  
  if (DISTANCIA1==7)
  {
    tone(BUZZER,b,90);
    delay(100);
  }
}
