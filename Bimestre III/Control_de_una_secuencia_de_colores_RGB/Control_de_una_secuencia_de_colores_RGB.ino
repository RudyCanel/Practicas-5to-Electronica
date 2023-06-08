#define output(pin)       pinMode(pin,OUTPUT)
#define input(pin)        pinMode(pin,INPUT)
#define ON(pin,pwm)       analogWrite(pin,pwm)
#define OFF(pin)          analogWrite(pin,0);
unsigned int pot=0;
unsigned int R=0;
unsigned int G=0;
unsigned int B=0;
void setup() {
  output(3);
  output(5);
  output(6);
  input(A0);
  Serial.begin(9600);
}

void loop() {
  pot = analogRead(A0);
  R= map(pot,0,1023,90,230);
  ON(3,174);
  ON(5,92);
  ON(6,230);
  delay(R);
  ON(3,255);
  ON(5,255);
  ON(6,255);
  delay(R);
  ON(3,0);
  ON(5,255);
  ON(6,255);
  delay(R);
  ON(3,189);
  ON(5,174);
  ON(6,20);
  delay(R);
  ON(3,225);
  ON(5,87);
  ON(6,35);
  delay(R);
}
