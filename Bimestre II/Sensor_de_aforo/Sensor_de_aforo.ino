  /* Fundacion Kinal
  * Centro educativo técnico laboral Kinal
  * Perito en electronica
  * Quinto perito
  * Sección: A
  * Curso : Taller de electronica digital y reparación de computadoras
  * Alumno: Rudy Santiago Canel Par
  * Carnet:2022449
  * Proyecto:Contador de Aforo
  */
  #define SBI(pin)                digitalWrite(pin,HIGH)
  #define CBI(pin)                digitalWrite(pin,LOW)
  #define setpinInput(pin)        pinMode(pin,INPUT)
  #define setpinInputPullup(pin)  pinMode(pin,INPUT_PULLUP)
  #define setpinOutput(pin)       pinMode(pin,OUTPUT)
  int PERSONAS=0;
  void CONFIG_PIN_SRF05 (void);
  void DISTANCIA (int ECHO);
  void PULSO (int TRIG);
  int RESULTADO;
  int CONTEO=0;
  
  
  void setup()
  {
    Serial.begin(9600);
    digitalWrite(A0,HIGH);
    
  }
  
  void loop() 
  {
    CONFIG_PIN_SRF05();
    PULSO(2);
    DISTANCIA(3);
  

    
    if (RESULTADO>6 && RESULTADO<10) {
      delay(100);
      CONTEO=CONTEO+1;
      Serial.println(RESULTADO);
      
     
    }
    if (CONTEO >=9) 
       {
        
        CBI(A0);
       }
       else 
       {
        SBI(A0);
       }

   
    switch (CONTEO) 
    {
        case(1) :
        {
         CBI(4);
         SBI(5);
         SBI(6);
         CBI(7);
         CBI(8);
         CBI(9);
         CBI(10);
         break;
         }
       case (2):
       {
         SBI(4);
         SBI(5);
         CBI(6);
         SBI(7);
         SBI(8);
         CBI(9);
         SBI(10);
         break;
       }
       case (3) : 
       {
         SBI(4);
         SBI(5);
         SBI(6);
         SBI(7);
         CBI(8);
         CBI(9);
         SBI(10);
         break;
       }
       case (4) :
       {
         CBI(4);
         SBI(5);
         SBI(6);
         CBI(7);
         CBI(8);
         SBI(9);
         SBI(10);
         break;
       }
       case (5):
       {
         SBI(4);
         CBI(5);
         SBI(6);
         SBI(7);
         CBI(8);
         SBI(9);
         SBI(10);
         break;
       }
       case (6) :
       {
         SBI(4);
         CBI(5);
         SBI(6);
         SBI(7);
         SBI(8);
         SBI(9);
         SBI(10);
         break;
       }
       case (7) : 
       {
         SBI(4);
         SBI(5);
         SBI(6);
         CBI(7);
         CBI(8);
         CBI(9);
         CBI(10);
         break;
       }
       case (8) :
       {
         SBI(4);
         SBI(5);
         SBI(6);
         SBI(7);
         SBI(8);
         SBI(9);
         SBI(10);
         break;
       }
       case(9) :
       {
         SBI(4);
         SBI(5);
         SBI(6);
         CBI(7);
         CBI(8);
         SBI(9);
         SBI(10);
         break;
       }
       case(0) :
       {
         SBI(4);
         SBI(5);
         SBI(6);
         SBI(7);
         SBI(8);
         SBI(9);
         CBI(10);
         break;
       }
       case(10) :
       {
        CONTEO=0;
       }

       
    }
  }
  void CONFIG_PIN_SRF05 (void) 
  {
    setpinInput(3);
    setpinOutput(2);
    setpinOutput(4);
    setpinOutput(5);
    setpinOutput(6);
    setpinOutput(7);
    setpinOutput(8);
    setpinOutput(9);
    setpinOutput(10);
    setpinOutput(A0);
  
  }
  void DISTANCIA (int ECHO)
  {
   int TIEMPO;
   
    TIEMPO = pulseIn(ECHO,HIGH);
    RESULTADO = TIEMPO/29.1/2;
    Serial.print("distancia:");
    Serial.println(RESULTADO);
    delay(100);
  
  }
  
  void PULSO (int TRIG)
  {
    CBI(TRIG);
    delayMicroseconds(2);
    SBI(TRIG);
    delayMicroseconds(10);
    CBI(TRIG);
  }
