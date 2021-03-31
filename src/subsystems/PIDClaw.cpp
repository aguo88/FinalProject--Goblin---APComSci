#include "main.h"
#include "subsytemHeaders/PIDClaw.hpp"
#include "subsytemHeaders/constants.hpp"
#include "subsytemHeaders/sensors/vision.hpp"

//constructor calls superclass constructor
PIDClaw::PIDClaw(double kP, double kI, double kD, double setPoint, int counts)
  :PID(kP, kI, kD, setPoint, counts)//'super' call
{
    //initializes values
    sum = 0.0, last = 0.0;
}

//Overrides PIDcount in the PID superclass
double PIDClaw::PIDcount() {
  /*
    gets X cord of the object in the FOV of the vision sensor
    if object not in FOV it will be 0
  */
  int objXCord = getXCord();
  //calculates error
  this->setError(this->getTarget() - objXCord);
  //calculates power using proportional control
  double power = (this->getError()/160.0) * getP();
  if(objXCord > 145 && objXCord < 175) {//30 pixels of flexibility
    //drive forward
    return (power + 0.4);
  } else {
    //keep finding object (spinning)
    return (power);
  }
}
