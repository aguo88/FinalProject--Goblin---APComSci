#include "main.h"
#include "subsytemHeaders/PIDClaw.hpp"
#include "subsytemHeaders/constants.hpp"

PIDClaw::PIDClaw(double kP, double kI, double kD, double setPoint, double counts, pros::Motor motor)
:PID(kP, kI, kD, setPoint, counts);
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
  this->setError(this->target - this->counts);
  this->sum += this->getError() * ROBOT_DELAY;
  double derivative = (this->getError() - this->last) / ROBOT_DELAY;
  double power = this->p * getError() + i*this->sum + d*derivative;
  this->last = derivative;
  return power;
}
