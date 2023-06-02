#include <DallasTemperature.h>
#include <OneWire.h>

OneWire myWire(4);
DallasTemperature temp(&myWire);

void setup() {
  temp.begin();
}

void loop() {
 
  
}
