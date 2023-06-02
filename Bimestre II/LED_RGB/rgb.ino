#define BUTTON1 2
#define BUTTON2 3
#define LEDR 4
#define LEDG 5
#define LEDB 6
#define setpinInput(pin)   pinMode(pin,INPUT)
#define setpinOutput(pin)  pinMode(pin,OUTPUT)
#define SBI(pin)  digitalWrite(pin,HIGH)
#define CBI(pin)  digitalWrite(pin,LOW)

void setup() {
  setpinInput(BUTTON1);
  setpinInput(BUTTON2);
  setpinOutput(LEDR);
  setpinOutput(LEDG);
  setpinOutput(LEDB);
}

void loop() {
  bool ESTADO1=digitalRead(BUTTON1);
  bool ESTADO2=digitalRead(BUTTON2);
  
  if ((ESTADO1==1) && (ESTADO2==0)) {
    delay(25);
    CBI(LEDB);
    SBI(LEDR);
    SBI(LEDG);
  }

  if ((ESTADO1==0) && (ESTADO2==1)) {
    delay(25);
    CBI(LEDR);
    SBI(LEDG);
    SBI(LEDB);
  }
  if ((ESTADO1==1) && (ESTADO2==1)) {
    delay(25);
    CBI(LEDG);
    SBI(LEDR);
    SBI(LEDB);
  }
  if ((ESTADO1==0) && (ESTADO2==0))
  {
  CBI(LEDG);
  CBI(LEDB);
  SBI(LEDR);
  delay(500);
  CBI(LEDR);
  SBI(LEDG);
  delay(500);
  CBI(LEDG);
  SBI(LEDB);
  delay(500);
  CBI(LEDB);
  }

  

 
 
 

  

}
