#include <Servo.h>

Servo ServoColatitud;
Servo ServoAzimutal;

int colatitud = 90; //sube baja
int azimutal = 90; //derecha izquierda

int pinServoColatitud = 1;
int pinServoAzimutal = 2;

int pasoServoColatitud = 1;
int pasoServoAzimutal = 1;

int limiteColatitudSup = 180;
int limiteColatitudInf = 0;

int limiteAzimutalSup = 180;
int limiteAzimutalInf = 0;

int sensorSupIzq = A0; 
int sensorSupDer = A1;
int sensorInfIzq = A2;
int sensorInfDer = A3;

//A partir de este valor se considera que el sensor "lee"
int LimiteSensorSupIzq = 100;
int LimiteSensorSupDer = 100;
int LimiteSensorInfIzq = 100;
int LimiteSensorInfDer = 100;

void setup() {
  pinMode(sensorSupIzq, INPUT);
  pinMode(sensorSupDer, INPUT);
  pinMode(sensorInfDer, INPUT);
  pinMode(sensorInfIzq, INPUT);

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
  int val = analogRead(sensorSupIzq);
  
  if(val > LimiteSensorSupIzq) return true;
  else return false;
}

bool leeSensorSupDer(){
  int val = analogRead(sensorSupDer);
  
  if(val > LimiteSensorSupDer) return true;
  else return false;
}

bool leeSensorInfIzq(){
  int val = analogRead(sensorInfIzq);
  
  if(val > LimiteSensorInfIzq) return true;
  else return false;
}

bool leeSensorInfDer(){
  int val = analogRead(sensorInfDer);
  
  if(val > LimiteSensorInfDer) return true;
  else return false;
}

void moverServos(){
  ServoColatitud.write(colatitud); 
  ServoColatitud.write(azimutal);
}