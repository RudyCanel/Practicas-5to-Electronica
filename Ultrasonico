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

void CONFIG_PIN_SRF05 (void);
int DISTANCIA (int ECHO, int TIEMPO, int RESULTADO);
void PULSO (int TRIG);


void setup()
{

}

void loop() 
{
    CONFIG_PIN_SRF05();
  PULSO(2);
  Serial.begin(9600);
  Serial.println(DISTANCIA(3));
  delay(500);

}


void CONFIG_PIN_SRF05 (void) 
{
  pinMode(2,OUTPUT);
  pinMode(3,INPUT);
}

int DISTANCIA (int ECHO)
{
  int TIEMPO; 
  int RESULTADO;
  TIEMPO = pulseIn(ECHO,HIGH);
  RESULTADO = TIEMPO / 29.1 / 2;

}
void PULSO (int TRIG)
{

  digitalWrite(TRIG,LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG,LOW);

}
