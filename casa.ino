
int COMEDOR = 2;//caracter A-a
int CUARTO1 = 3;//caracter B-b
int CUARTO2 = 4;//caracter C-c
int CUARTO3 = 5;//caracter D-d
int BANIO = 6;//caracter H-h
int COCINA = 7;//caracter E-e
int PASILLO = 8;//caracter F-f
int VENTILADOR = 9;//caracter G-g

int Trigger = 11;   //Pin digital 2 para el Trigger del sensor ultrasonico
int Echo = 10;   //Pin digital 3 para el Echo del sensor ultrasonico

int PARLANTE = 13;
int FRECUENCIA = 2020;
void setup() {
  Serial.begin(9600);
  pinMode(COMEDOR, OUTPUT);
  pinMode(CUARTO1, OUTPUT);
  pinMode(CUARTO2, OUTPUT);
  pinMode(CUARTO3, OUTPUT);
  pinMode(BANIO, OUTPUT);
  pinMode(VENTILADOR, OUTPUT);
  pinMode(PASILLO, OUTPUT);
  pinMode(COCINA, OUTPUT);

  //configucion de ultrasonico
  pinMode(Trigger, OUTPUT); //pin como salida
  pinMode(Echo, INPUT);  //pin como entrada
  digitalWrite(Trigger, LOW);//Inicializamos el pin con 0

}


void loop() {
  if (sensor_alarma() <= 10) {
    encender_alarma();

  }

  if (Serial.available() > 0) {
    char opcion = Serial.read();

    switch (opcion) {
      case 'A':
        encender(COMEDOR);
        break;
      case 'a':
        apagar(COMEDOR);
        break;

      case 'B':
        encender(CUARTO1);
        break;
      case 'b':
        apagar(CUARTO1);
        break;

      case 'C':
        encender(CUARTO2);
        break;
      case 'c':
        apagar(CUARTO2);
        break;

      case 'D':
        encender(CUARTO3);
        break;
      case 'd':
        apagar(CUARTO3);
        break;

      case 'H':
        encender(BANIO);
        break;
      case 'h':
        apagar(BANIO);
        break;

      case 'E':
        encender(COCINA);
        break;
      case 'e':
        apagar(COCINA);
        break;

      case 'F':
        encender(PASILLO);
        break;
      case 'f':
        apagar(PASILLO);
        break;

      case 'G':
        encender(VENTILADOR);
        break;
      case 'g':
        apagar(VENTILADOR);
        break;



    }
  }


}

int encender(int cuarto) {
  digitalWrite(cuarto, HIGH);


}

int apagar(int cuarto) {
  digitalWrite(cuarto, LOW);
}

int sensor_alarma() {
  long t; //timepo que demora en llegar el eco
  long d; //distancia en centimetros

  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger, LOW);

  t = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
  d = t / 59;           //escalamos el tiempo a una distancia en cm
  delay(100);          //Hacemos una pausa de 100ms
  return d;
}

int encender_alarma() {
  tone(PARLANTE, FRECUENCIA);

  encender(COMEDOR);
  encender(CUARTO1);
  encender(CUARTO2);
  encender(CUARTO3);
  encender(BANIO);
  encender(COCINA);
  encender(PASILLO);
  delay(500);
  noTone(PARLANTE);
  apagar(COMEDOR);
  apagar(CUARTO1);
  apagar(CUARTO2);
  apagar(CUARTO3);
  apagar(BANIO);
  apagar(COCINA);
  apagar(PASILLO);
  
}
