#include "main.h"
#include "subsytemHeaders/PIDClaw.hpp"
#include "subsytemHeaders/constants.hpp"

<<<<<<< HEAD
PIDClaw::PIDClaw(double kP, double kI, double kD, double setPoint, double counts, pros::Motor motor)
:PID(kP, kI, kD, setPoint, counts);
=======
PIDClaw(double kP, double kI, double kD, double setPoint, int counts)
>>>>>>> 3bbb3aedf9c6aa94ab3057ddacbe39fb86253bb2
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
