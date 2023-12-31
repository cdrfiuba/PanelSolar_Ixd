#include <Servo.h>

Servo ServoColatitud;
Servo ServoAzimutal;

int colatitud = 90; //sube baja
int azimutal = 90; //derecha izquierda

int pinServoColatitud = 10;
int pinServoAzimutal = 11;

int pasoServoColatitud = 1;
int pasoServoAzimutal = 1;

int limiteColatitudSup = 180;
int limiteColatitudInf = 0;

int limiteAzimutalSup = 180;
int limiteAzimutalInf = 0;

int pinSensorSupIzq = A1; 
int pinSensorSupDer = A2;
int pinSensorInfIzq = A3;
int pinSensorInfDer = A4;

//A partir de este valor se considera que el sensor "lee"
int LimiteSensorSupIzq = 100;
int LimiteSensorSupDer = 100;
int LimiteSensorInfIzq = 100;
int LimiteSensorInfDer = 100;

void setup() {
  pinMode(pinSensorSupIzq, INPUT);
  pinMode(pinSensorSupDer, INPUT);
  pinMode(pinSensorInfDer, INPUT);
  pinMode(pinSensorInfIzq, INPUT);

  pinMode(pinServoColatitud, OUTPUT);
  pinMode(pinServoAzimutal, OUTPUT);
  
  ServoColatitud.attach(pinServoColatitud); 
  ServoColatitud.attach(pinServoAzimutal);

  moverServos();
}

void loop() {

  if(leeSensorSupIzq){
    subir(pasoServoColatitud);
    rotarIzquierda(pasoServoAzimutal);
  }
  if(leeSensorSupDer){
    subir(pasoServoColatitud);
    rotarDerecha(pasoServoAzimutal);
  }
  if(leeSensorInfIzq){
    bajar(pasoServoColatitud);
    rotarIzquierda(pasoServoAzimutal);
  }
  if(leeSensorInfDer){
    bajar(pasoServoColatitud);
    rotarDerecha(pasoServoAzimutal);
  }

  moverServos();
}

void subir(int cant){
  if(colatitud < limiteColatitudSup && colatitud + cant < limiteColatitudSup){
  colatitud += cant;
  }
  else if(colatitud < limiteColatitudSup){
  colatitud = limiteColatitudSup;
  }
}

void bajar(int cant){
  if(colatitud > limiteColatitudInf && colatitud - cant > limiteColatitudInf){
  colatitud -= cant;
  }
  else if(colatitud > limiteColatitudInf){
  colatitud = limiteColatitudInf;
  }
  
}

void rotarDerecha(int cant){
  if(azimutal < limiteAzimutalSup && azimutal + cant < limiteAzimutalSup){
  azimutal += cant;
  }
  else if(azimutal < limiteAzimutalSup){
  azimutal = limiteAzimutalSup;
  }
}

void rotarIzquierda(int cant){
  if(azimutal > limiteAzimutalInf && azimutal - cant > limiteAzimutalInf){
  azimutal -= cant;
  }
  else if(azimutal > limiteAzimutalInf){
  azimutal = limiteAzimutalInf;
  }
}

bool leeSensorSupIzq(){
  int val = analogRead(pinSensorSupIzq);
  
  if(val > LimiteSensorSupIzq) return true;
  else return false;
}

bool leeSensorSupDer(){
  int val = analogRead(pinSensorSupDer);
  
  if(val > LimiteSensorSupDer) return true;
  else return false;
}

bool leeSensorInfIzq(){
  int val = analogRead(pinSensorInfIzq);
  
  if(val > LimiteSensorInfIzq) return true;
  else return false;
}

bool leeSensorInfDer(){
  int val = analogRead(pinSensorInfDer);
  
  if(val > LimiteSensorInfDer) return true;
  else return false;
}

void moverServos(){
  ServoColatitud.write(colatitud); 
  ServoColatitud.write(azimutal);
}