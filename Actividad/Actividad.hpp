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

int pinSensorSupIzq = A1; 
int pinSensorSupDer = A2;
int pinSensorInfIzq = A3;
int pinSensorInfDer = A4;

//A partir de este valor se considera que el sensor "lee"
int LimiteSensorSupIzq = 100;
int LimiteSensorSupDer = 100;
int LimiteSensorInfIzq = 100;
int LimiteSensorInfDer = 100;

void subirPanel(){
  if(colatitud < limiteColatitudSup){
  colatitud +=1;
  }
  ServoColatitud.write(colatitud); 
  ServoColatitud.write(azimutal);
}

void bajarPanel(){
  if(colatitud > limiteColatitudInf){
  colatitud -=1;
  }
  ServoColatitud.write(colatitud); 
  ServoColatitud.write(azimutal);
}

void rotarPanelDerecha(){
  if(azimutal < limiteAzimutalSup){
  azimutal += 1;
  }
  ServoColatitud.write(colatitud); 
  ServoColatitud.write(azimutal);
}

void rotarPanelIzquierda(){
  if(azimutal > limiteAzimutalInf){
  azimutal -= 1;
  }
  ServoColatitud.write(colatitud); 
  ServoColatitud.write(azimutal);
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