#include "main.h"
#include "subsytemHeaders/PIDClaw.hpp"
#include "subsytemHeaders/constants.hpp"
#include "subsytemHeaders/sensors/vision.hpp"

PIDClaw::PIDClaw(double kP, double kI, double kD, double setPoint, int counts)
  :PID(kP, kI, kD, setPoint, counts)
{
    sum = 0.0, last = 0.0;
}

double PIDClaw::PIDcount() {
  int objXCord = getXCord();
  this->setError(this->getTarget() - objXCord);
  double power = (this->getError()/160.0) * getP();
  if(objXCord > 145 && objXCord < 175) {
    //drive forward
    return (power + 0.4);
  } else {
    return (power);
  }
}
