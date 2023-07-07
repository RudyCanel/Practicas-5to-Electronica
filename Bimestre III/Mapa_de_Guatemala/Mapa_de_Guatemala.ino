/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Perito en Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: Taller de electronica digital
 * Nombres: Rudy Canel, Miguel Alvarado, David delCid
 * Carnet: 2022449, 2022486, 2022482
 * Proyecto: Mapa de Guatemala
*/
#include <Wire.h>
#include <PCF8574.h>
#define ON(pin) digitalWrite(pin,HIGH)
#define OFF(pin) digitalWrite(pin,LOW)
#define Input(pin) pinMode(pin,INPUT)
#define Output(pin) pinMode(pin,OUTPUT)
#define Print(text)     Serial.println(text)
#define PCF8574_HIGH  LOW
#define PCF8574_LOW   HIGH
PCF8574 expansor_PCF(0x27);

byte ran=0;
int j = 0;
String caracter;
unsigned int k = 0;
byte pregunta = 1;
byte respuesta=0;
int buzzerPin = 9;
int C4 = 262;
int D4 = 294;
int E4 = 330;
int F4 = 349;
int G4 = 392;
int Aq4 = 440;
int B4 = 494;
int C5 = 523;

void setup()
{
  Serial.begin(9600);
  Wire.begin();
  expansor_PCF.begin();
  for (int i=2; i<14; i++)
  {
    Output(i);
    OFF(i);
  }
  Output(A0);
  Output(A1);
  Output(A2);
  Output(A3);
  Output(A6);
  Output(A7);
  Serial.println("Nota: Iniciar con mayúscula, colocar tílde y sin espacio al final");
  Serial.println("Envie Espacio para Iniciar");
  expansor_PCF.write(0,LOW);
  expansor_PCF.write(1,LOW);
  expansor_PCF.write(2,LOW);
  expansor_PCF.write(5,LOW);
  expansor_PCF.write(4,LOW);
}
void loop()
{
  if (Serial.available() > 0)
  {
    caracter = Serial.readString();
    if ((j != k) and (respuesta==0))
    {
      k=j;
    }
    casos();
  } else
  {
    j=random(21);
  }
}


void casos()
{
  switch (k)
  {
    case (0) :
    {
      if (pregunta==1)
      {
      Print("Cual es la capital de: Alta Verapaz");
      respuesta=1;
      pregunta=0;  
      }
      
      if ((caracter == String("Cobán")) and (respuesta==1))
      {
        Print("Respuesta Correcta");
        ON(2);
        delay(3000);
        OFF(2);
        Print("Envie espacio para continuar");
        pregunta=1;
        respuesta=0;
      } else if ((caracter != String(" ")) and (caracter != String ("  ")))
      {
        Print("Respuesta Incorrecta");
        notas();
      }
      break;
    }

    case (1) :
    {
      if (pregunta==1)
      {
      Print("Cual es la capital de: Baja Verapaz");
      respuesta=1;
      pregunta=0;  
      }
      
      if ((caracter == String("Salamá")) and (respuesta==1))
      {
        Print("Respuesta Correcta");
        ON(3);
        delay(3000);
        OFF(3);
        Print("Envie espacio para continuar");
        pregunta=1;
        respuesta=0;
      } else if ((caracter != String(" ")) and (caracter != String ("  ")))
      {
        Print("Respuesta Incorrecta");
        notas();
      }
      break;
    }
    case (2) :
    {
      if (pregunta==1)
      {
      Print("Cual es la capital de: Chimaltenango");
      respuesta=1;
      pregunta=0;  
      }
      
      if ((caracter == String("Chimaltenango")) and (respuesta==1))
      {
        Print("Respuesta Correcta");
        ON(4);
        delay(3000);
        OFF(4);
        Print("Envie espacio para continuar");
        pregunta=1;
        respuesta=0;
      } else if ((caracter != String(" ")) and (caracter != String ("  ")))
      {
        Print("Respuesta Incorrecta");
        notas();
      }
      break;
    }

    case (3) :
    {
      if (pregunta==1)
      {
      Print("Cual es la capital de: Chiquimula");
      respuesta=1;
      pregunta=0;  
      }
      
      if ((caracter == String("Chiquimula")) and (respuesta==1))
      {
        Print("Respuesta Correcta");
        ON(5);
        delay(3000);
        OFF(5);
        Print("Envie espacio para continuar");
        pregunta=1;
        respuesta=0;
      } else if ((caracter != String(" ")) and (caracter != String ("  ")))
      {
        Print("Respuesta Incorrecta");
        notas();
      }
      break;
    }

    case (4) :
    {
      if (pregunta==1)
      {
      Print("Cual es la capital de: El Progreso");
      respuesta=1;
      pregunta=0;  
      }
      
      if ((caracter == String("Guastatoya")) and (respuesta==1))
      {
        Print("Respuesta Correcta");
        ON(6);
        delay(3000);
        OFF(6);
        Print("Envie espacio para continuar");
        pregunta=1;
        respuesta=0;
      } else if ((caracter != String(" ")) and (caracter != String ("  ")))
      {
        Print("Respuesta Incorrecta");
        notas();
      }
      break;
    }

    case (5) :
    {
      if (pregunta==1)
      {
      Print("Cual es la capital de: Escuintla");
      respuesta=1;
      pregunta=0;  
      }
      if ((caracter == String("Escuintla")) and (respuesta==1))
      {
        Print("Respuesta Correcta");
        ON(7);
        delay(3000);
        OFF(7);
        Print("Envie espacio para continuar");
        pregunta=1;
        respuesta=0;
      } else if ((caracter != String(" ")) and (caracter != String ("  ")))
      {
        Print("Respuesta Incorrecta");
        notas();
      }
      break;
    }
    case (6) :
    {
      if (pregunta==1)
      {
      Print("Cual es la capital de: Departamento de Guatemala");
      respuesta=1;
      pregunta=0;  
      }
      
      if ((caracter == String("Ciudad de Guatemala")) and (respuesta==1))
      {
        Print("Respuesta Correcta");
        ON(8);
        delay(3000);
        OFF(8);
        Print("Envie espacio para continuar");
        pregunta=1;
        respuesta=0;
      } else if ((caracter != String(" ")) and (caracter != String ("  ")))
      {
        Print("Respuesta Incorrecta");
        notas();
      }
      break;
    }
    case (7) :
    {
      if (pregunta==1)
      {
      Print("Cual es la capital de: Huehuetenango");
      respuesta=1;
      pregunta=0;  
      }
      
      if ((caracter == String("Huehuetenango")) and (respuesta==1))
      {
        Print("Respuesta Correcta");
        ON(10);
        delay(3000);
        OFF(10);
        Print("Envie espacio para continuar");
        pregunta=1;
        respuesta=0;
      } else if ((caracter != String(" ")) and (caracter != String ("  ")))
      {
        Print("Respuesta Incorrecta");
        notas();
      }
      break;
    }
    case (8) :
    {
      if (pregunta==1)
      {
      Print("Cual es la capital de: Izabal");
      respuesta=1;
      pregunta=0;  
      }
      
      if ((caracter == String("Puerto Barrios")) and (respuesta==1))
      {
        Print("Respuesta Correcta");
        ON(11);
        delay(3000);
        OFF(11);
        Print("Envie espacio para continuar");
        pregunta=1;
        respuesta=0;
      } else if ((caracter != String(" ")) and (caracter != String ("  ")))
      {
        Print("Respuesta Incorrecta");
        notas();
      }
      break;
      }
  

    case (9) :
      {
      if (pregunta==1)
      {
      Print("Cual es la capital de: Jalapa");
      respuesta=1;
      pregunta=0;  
      }
      
      if ((caracter == String("Jalapa")) and (respuesta==1))
      {
        Print("Respuesta Correcta");
        ON(12);
        delay(3000);
        OFF(12);
        Print("Envie espacio para continuar");
        pregunta=1;
        respuesta=0;
      } else if ((caracter != String(" ")) and (caracter != String ("  ")))
      {
        Print("Respuesta Incorrecta");
        notas();
      }
      break;
    }

    case (10) :
    {
      if (pregunta==1)
      {
      Print("Cual es la capital de: Jutiapa");
      respuesta=1;
      pregunta=0;  
      }
      
      if ((caracter == String("Jutiapa")) and (respuesta==1))
      {
        Print("Respuesta Correcta");
        ON(13);
        delay(3000);
        OFF(13);
        Print("Envie espacio para continuar");
        pregunta=1;
        respuesta=0;
      } else if ((caracter != String(" ")) and (caracter != String ("  ")))
      {
        Print("Respuesta Incorrecta");
        notas();
      }
      break;
    }
    case (11) :
    {
      if (pregunta==1)
      {
      Print("Cual es la capital de: Peten");
      respuesta=1;
      pregunta=0;  
      }
      
      if ((caracter == String("Flores")) and (respuesta==1))
      {
        Print("Respuesta Correcta");
        ON(A0);
        delay(3000);
        OFF(A0);
        Print("Envie espacio para continuar");
        pregunta=1;
        respuesta=0;
      } else if ((caracter != String(" ")) and (caracter != String ("  ")))
      {
        Print("Respuesta Incorrecta");
        notas();
      }
      break;
    }
    case (12) :
    {
      if (pregunta==1)
      {
      Print("Cual es la capital de: Quetzaltenango");
      respuesta=1;
      pregunta=0;  
      }
      
      if ((caracter == String("Quetzaltenango")) and (respuesta==1))
      {
        Print("Respuesta Correcta");
        ON(A1);
        delay(3000);
        OFF(A1);
        Print("Envie espacio para continuar");
        pregunta=1;
        respuesta=0;
      } else if ((caracter != String(" ")) and (caracter != String ("  ")))
      {
        Print("Respuesta Incorrecta");
        notas();
      }
      break;
    }
    case (13) :
    {
      if (pregunta==1)
      {
      Print("Cual es la capital de: Quiche");
      respuesta=1;
      pregunta=0;  
      }
      
      if ((caracter == String("Santa Cruz del Quiché")) and (respuesta==1))
      {
        Print("Respuesta Correcta");
        ON(A2);
        delay(3000);
        OFF(A2);
        Print("Envie espacio para continuar");
        pregunta=1;
        respuesta=0;
      } else if ((caracter != String(" ")) and (caracter != String ("  ")))
      {
        Print("Respuesta Incorrecta");
        notas();
      }
      break;
    }
    case (14) :
    {
      if (pregunta==1)
      {
      Print("Cual es la capital de: Retalhuleu");
      respuesta=1;
      pregunta=0;  
      }
      
      if ((caracter == String("Retalhuleu")) and (respuesta==1))
      {
        Print("Respuesta Correcta");
        ON(A3);
        delay(3000);
        OFF(A3);
        Print("Envie espacio para continuar");
        pregunta=1;
        respuesta=0;
      } else if ((caracter != String(" ")) and (caracter != String ("  ")))
      {
        Print("Respuesta Incorrecta");
        notas();
      }
      break;
    }
    case (15) :
    {
      if (pregunta==1)
      {
      Print("Cual es la capital de: Sacatepequez");
      respuesta=1;
      pregunta=0;  
      }
      
      if ((caracter == String("Antigua Guatemala")) and (respuesta==1))
      {
        Print("Respuesta Correcta");
        ON(A6);
        delay(3000);
        OFF(A6);
        Print("Envie espacio para continuar");
        pregunta=1;
        respuesta=0;
      } else if ((caracter != String(" ")) and (caracter != String ("  ")))
      {
        Print("Respuesta Incorrecta");
        notas();
      }
      break;
    }
    case (16) :
    {
      if (pregunta==1)
      {
      Print("Cual es la capital de: San Marcos");
      respuesta=1;
      pregunta=0;  
      }
      
      if ((caracter == String("San Marcos")) and (respuesta==1))
      {
        Print("Respuesta Correcta");
        ON(A7);
        delay(3000);
        OFF(A7);
        Print("Envie espacio para continuar");
        pregunta=1;
        respuesta=0;
      } else if ((caracter != String(" ")) and (caracter != String ("  ")))
      {
        Print("Respuesta Incorrecta");
        notas();
      }
      break;
    }
    case (17) :
    {
      if (pregunta==1)
      {
      Print("Cual es la capital de: Santa Rosa");
      respuesta=1;
      pregunta=0;  
      }
      
      if ((caracter == String("Cuilapa")) and (respuesta==1))
      {
        Print("Respuesta Correcta");
        expansor_PCF.write(0,HIGH);
        delay(3000);
        expansor_PCF.write(0,LOW);
        Print("Envie espacio para continuar");
        pregunta=1;
        respuesta=0;
      } else if ((caracter != String(" ")) and (caracter != String ("  ")))
      {
        Print("Respuesta Incorrecta");
        notas();
      }
      break;
    }
    case (18) :
    {
      if (pregunta==1)
      {
      Print("Cual es la capital de: Solola");
      respuesta=1;
      pregunta=0;  
      }
      
      if ((caracter == String("Sololá")) and (respuesta==1))
      {
        Print("Respuesta Correcta");
        expansor_PCF.write(1,HIGH);
        delay(3000);
        expansor_PCF.write(1,LOW);
        Print("Envie espacio para continuar");
        pregunta=1;
        respuesta=0;
      } else if ((caracter != String(" ")) and (caracter != String ("  ")))
      {
        Print("Respuesta Incorrecta");
        notas();
      }
      break;
    }
    case (19) :
    {
      if (pregunta==1)
      {
      Print("Cual es la capital de: Suchitepequez");
      respuesta=1;
      pregunta=0;  
      }
      
      if ((caracter == String("Mazatenango")) and (respuesta==1))
      {
        Print("Respuesta Correcta");
        expansor_PCF.write(2,HIGH);
        delay(3000);
        expansor_PCF.write(2,LOW);
        Print("Envie espacio para continuar");
        pregunta=1;
        respuesta=0;
      } else if ((caracter != String(" ")) and (caracter != String ("  ")))
      {
        Print("Respuesta Incorrecta");
        notas();
      }
      break;
    }
    case (20) :
    {
      if (pregunta==1)
      {
      Print("Cual es la capital de: Totonicapan");
      respuesta=1;
      pregunta=0;  
      }
      
      if ((caracter == String("Totonicapán")) and (respuesta==1))
      {
        Print("Respuesta Correcta");
        expansor_PCF.write(5,HIGH);
        delay(3000);
        expansor_PCF.write(5,LOW);
        Print("Envie espacio para continuar");
        pregunta=1;
        respuesta=0;
      } else if ((caracter != String(" ")) and (caracter != String ("  ")))
      {
        Print("Respuesta Incorrecta");
        notas();
      }
      break;
    }
    case (21) :
    {
      if (pregunta==1)
      {
      Print("Cual es la capital de: Zacapa");
      respuesta=1;
      pregunta=0;  
      }
      
      if ((caracter == String("Zacapa")) and (respuesta==1))
      {
        Print("Respuesta Correcta");
        expansor_PCF.write(4,HIGH);
        delay(3000);
        expansor_PCF.write(4,LOW);
        Print("Envie espacio para continuar");
        pregunta=1;
        respuesta=0;
      } else if ((caracter != String(" ")) and (caracter != String ("  ")))
      {
        Print("Respuesta Incorrecta");
        notas();
      }
      break;
    }
}
}

void tocarNota(int nota, int duracion) {
  tone(buzzerPin, nota, duracion);
  delay(duracion + 2);
}

void notas()
{
  tocarNota(Aq4, 250);
  tocarNota(C5, 250);
  tocarNota(Aq4, 250);
  tocarNota(C5, 250);
  tocarNota(Aq4, 250);
  tocarNota(C5, 250);
  tocarNota(E4, 250);
  tocarNota(C4, 500);
  tocarNota(E4, 250);
  tocarNota(C4, 500);
  tocarNota(E4, 250);
  tocarNota(Aq4, 250);
  tocarNota(Aq4, 250);
  tocarNota(C5, 250);
  tocarNota(Aq4, 250);
  tocarNota(C5, 250);
  tocarNota(Aq4, 250);
  tocarNota(C5, 250);
  tocarNota(E4, 250);
  tocarNota(C4, 500);
  tocarNota(E4, 250);
  tocarNota(C4, 500);
  tocarNota(E4, 250);
  tocarNota(Aq4, 250);
}
