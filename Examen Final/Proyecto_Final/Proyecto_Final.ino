/* Fundacion Kinal
* Centro educativo técnico laboral Kinal
* Perito en electronica
* Quinto perito
* Sección: A
* Curso : Taller de electronica digital y reparación de computadoras
* Alumno: Rudy Santiago Canel Par
* Carnet:2022449
* Proyecto: Examen Final
*/
float sens = 0.66;
float corriente = 0.0;
float ajust= 0.05;
unsigned int i=0;
float j=0;
unsigned int x;
float voltaje;
float resistencia;
char caracter;
  
void setup() {
  Serial.begin(9600);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
}

void loop() { 
  while ( Serial.available() > 0)

  caracter = Serial.read();

  if(caracter == 'R')
  {
  i = analogRead(A1);
  j = map (i,0,1023,0,1023);
  j= (j*5)/(1023);
  resistencia = (50000/j)-(10000);
  Serial.println(resistencia);
  caracter=0;
  }
  if (caracter == 'V')
  {
    x= analogRead(A2);
    voltaje= fmap(x,0,1023,0.0,25.0);
    Serial.println(voltaje);
  }
  if (caracter =='I')
  {
    corriente = prom(500);
    if (corriente>=0.01)
    {
      corriente= ((corriente*10)+ajust);
      Serial.println(corriente);
      delay(100);
    }else {
      Serial.println("0.0");
      delay(100);
    }
  }


  if(caracter == 'O')
  {
    caracter=0;
  }
}

float fmap(float y, float in_min, float in_max, float out_min, float out_max)
{
  return (y-in_min)*(out_max - out_min)/(in_max - in_min) + out_min;
}
float prom(int muestras)
{
  float sensorA3;
  float intencidad=0;
  for (int i; i<=muestras;i++)
  {
    sensorA3 = analogRead(A3);
    intencidad = intencidad+(sensorA3-2.5)/sens;
  }
  intencidad = intencidad / muestras;
  return (intencidad);
}
