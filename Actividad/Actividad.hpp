#include <Servo.h>

Servo ServoColatitud;
Servo ServoAzimutal;


int colatitud = 90;
int azimutal = 90;

int pinServoColatitud = 1;
int pinServoAzimutal = 2;

int sensorSupIzq = A0; 
int sensorSupDer = A1;
int sensorInfIzq = A2;
int sensorInfDer = A3;

//A partir de este valor se considera que el sensor "lee"
int LimiteSensorSupIzq = 100;
int LimiteSensorSupDer = 100;
int LimiteSensorInfIzq = 100;
int LimiteSensorInfDer = 100;

void subir(){
  if(colatitud < 180){
  colatitud +=1;
  }
  ServoColatitud.write(colatitud); 
  ServoColatitud.write(azimutal);
}

void bajar(int cant){
  if(colatitud > 0){
  colatitud -=1;
  }
  ServoColatitud.write(colatitud); 
  ServoColatitud.write(azimutal);
}

void rotarDerecha(int cant){
  if(azimutal < 180){
  azimutal += 1;
  }
  ServoColatitud.write(colatitud); 
  ServoColatitud.write(azimutal);
}

void rotarIzquierda(int cant){
  if(azimutal > 0){
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