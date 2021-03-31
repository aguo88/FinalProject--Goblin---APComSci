#include "main.h"
#include "subsytemHeaders/PIDClaw.hpp"
#include "subsytemHeaders/constants.hpp"

PIDClaw(double kP, double kI, double kD, double setPoint, int counts)
{
    //p, i, d are tuning values
    this->p = p;
    this->i = i;
    this->d = d;
    this->target = target;
    this->counts = counts;
    sum = 0.0, last = 0.0;
}

double PIDClaw::PIDcount() {
  int objXCord = getXCord();
  double power = (160 - objXCord)/160.0;
  if(objXCord > 145 && objXCord < 175) {
    //drive forward
    return (power + 0.4);
  } else {
    return (power);
  }
}
