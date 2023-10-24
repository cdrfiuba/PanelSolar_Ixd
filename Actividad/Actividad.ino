#include <Servo.h>
#include "Actividad.hpp"


void setup() {
  pinMode(sensorSupIzq, INPUT);
  pinMode(sensorSupDer, INPUT);
  pinMode(sensorInfDer, INPUT);
  pinMode(sensorInfIzq, INPUT);

  pinMode(pinServoColatitud, OUTPUT);
  pinMode(pinServoAzimutal, OUTPUT);
  
  ServoColatitud.attach(pinServoColatitud); 
  ServoColatitud.attach(pinServoAzimutal);

  ServoColatitud.write(colatitud); 
  ServoColatitud.write(azimutal);
}

void loop() {
  
}
