#include <Servo.h>
#include "Actividad.hpp"


void setup() {
  pinMode(pinSensorSupIzq, INPUT);
  pinMode(pinSensorSupDer, INPUT);
  pinMode(pinSensorInfDer, INPUT);
  pinMode(pinSensorInfIzq, INPUT);

  pinMode(pinServoColatitud, OUTPUT);
  pinMode(pinServoAzimutal, OUTPUT);
  
  ServoColatitud.attach(pinServoColatitud); 
  ServoColatitud.attach(pinServoAzimutal);

  ServoColatitud.write(colatitud); 
  ServoColatitud.write(azimutal);
}

void loop() {
  
}
