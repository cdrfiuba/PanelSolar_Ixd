#include <Servo.h>

Servo ServoColatitud;
Servo ServoAzimutal;


int colatitud = 90;
int azimutal = 90;

int limiteColatitudSup = 180;
int limiteColatitudInf = 0;

int limiteAzimutalSup = 180;
int limiteAzimutalInf = 0;

int pinServoColatitud = 10;
int pinServoAzimutal = 11;

int sensorSupIzq = A1; 
int sensorSupDer = A2;
int sensorInfIzq = A3;
int sensorInfDer = A4;

//A partir de este valor se considera que el sensor "lee"
int LimiteSensorSupIzq = 100;
int LimiteSensorSupDer = 100;
int LimiteSensorInfIzq = 100;
int LimiteSensorInfDer = 100;

void subir(){
  if(colatitud < limiteColatitudSup){
  colatitud +=1;
  }
  ServoColatitud.write(colatitud); 
  ServoColatitud.write(azimutal);
}

void bajar(){
  if(colatitud > limiteColatitudInf){
  colatitud -=1;
  }
  ServoColatitud.write(colatitud); 
  ServoColatitud.write(azimutal);
}

void rotarDerecha(){
  if(azimutal < limiteAzimutalSup){
  azimutal += 1;
  }
  ServoColatitud.write(colatitud); 
  ServoColatitud.write(azimutal);
}

void rotarIzquierda(){
  if(azimutal > limiteAzimutalInf){
  azimutal -= 1;
  }
  ServoColatitud.write(colatitud); 
  ServoColatitud.write(azimutal);
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