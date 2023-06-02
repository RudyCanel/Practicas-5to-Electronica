/* Fundacion Kinal
  Centro educativo técnico laboral Kinal
  Perito en electronica
  Quinto perito
  Sección: A
  Curso : Taller de electronica digital y reparación de computadoras
  Alumno: Rudy Santiago Canel Par
  Carnet:2022449
  Proyecto:Productos disponibles en stock
*/
#define Button0 2
#define Button1 3
#define setpinInput0(pin) pinMode(pin,INPUT)
#define setpinInput1(pin) pinMode(pin,INPUT)


struct stock {
  String golosina1;
  String golosina2;
  String golosina3;
  String golosina4;
  String fechavencimiento1;
  String fechavencimiento2;
  String fechavencimiento3;
  String fechavencimiento4;
  int cantidad1;
  int cantidad2;
  int cantidad3;
  int cantidad4;

};

stock productos = {
  "TORTRIX LIMON", "TORTRIX BARBACOA", "TORTRIX PICANTE",
  "TORTRIX TACOS CHILE-ROS", "24/05/2032", "12/01/2039",
  "30/10/2035", "17/12/2037", 12, 25, 20, 30,
};

int X = 1;
char y = 0;
void setup() {

  Serial.begin(9600);
  setpinInput0(Button0);
  setpinInput1(Button1);

  Serial.println("                                Tienda la Comunidad");
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println("Productos Disponibles:");
  Serial.println();
}

void loop() {


  bool navegacion0 = digitalRead(Button0);
  bool navegacion1 = digitalRead(Button1);

  if (navegacion0 == HIGH) {
    delay(100);
    X++;
  }

  if (navegacion1 == HIGH) {
    delay(100);
    X = X - 3;
  }

  if (X >= 0 or X <= 8) {
    if (X == 1) {
      Serial. print("   --");

      Serial.println(productos.golosina1);
      delay(500);
      X = 2;
      for (char Y; Y < 1 ; Y++) {
        delay(50);
        Serial.println("                                                           Fecha de caducidad:");

      }
      Serial.print("        Cantidad de TORTRIX sabor LIMON en stock:              ");
      Serial.println(productos.fechavencimiento1);
      delay(90);
      Serial.print("                           ");
      Serial.println(productos.cantidad1);
      Serial.println();
      Serial.println();
    }

    if (X == 3) {
      Serial. print("   --");
      Serial.println(productos.golosina2);
      delay(500);
      X = 4;
      for (char Y = 0; Y < 1 ; Y++) {
        delay(50);
        Serial.println("                                                           Fecha de caducidad:");

      }
      Serial.print("        Cantidad de TORTRIX sabor BARBACOA en stock:             ");
      Serial.println(productos.fechavencimiento2);
      delay(90);
      Serial.print("                           ");
      Serial.println(productos.cantidad2);
      Serial.println();
      Serial.println();
    }

    if (X == 5) {
      Serial. print("   --");
      Serial.println(productos.golosina3);
      delay(500);
      X = 6;
      for (char Y = 0; Y < 1 ; Y++) {
        delay(50);
        Serial.println("                                                           Fecha de caducidad:");

      }
      Serial.print("        Cantidad de TORTRIX sabor PICANTE en stock:             ");
      Serial.println(productos.fechavencimiento3);
      delay(90);
      Serial.print("                           ");
      Serial.println(productos.cantidad3);
      Serial.println();
      Serial.println();
    }

    if (X == 7) {
      Serial. print("   --");
      Serial.println(productos.golosina4);
      delay(500);
      X = 8;
      for (char Y = 0; Y < 1 ; Y++) {
        delay(50);
        Serial.println("                                                           Fecha de caducidad:");

      }
      Serial.print("        Cantidad de TORTRIX sabor TACOS CHILE-ROS en stock:      ");
      Serial.println(productos.fechavencimiento4);
      delay(90);
      Serial.print("                           ");
      Serial.println(productos.cantidad4);
      Serial.println();
      Serial.println();
    }

  }
  if (X < 0) {
    X = 7;
  }
  if (X >= 8) {
    delay(25);
    X = 0;

  }
  delay(100);
}
