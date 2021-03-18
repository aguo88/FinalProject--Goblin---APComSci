#include "main.h"
#include "subsytemHeaders/PID.hpp"
#include "subsytemHeaders/constants.hpp"

PID::PID(double p, double i, double d, double target, pros::Motor otherMotor)
{
    //p, i, d are tuning values
    this->p = p;
    this->i = i;
    this->d = d;
    this->target = target;
    sum = 0.0, last = 0.0;
    pros::Motor* motor = &otherMotor;
}

double PID::PIDcount(int target) {
  this->setError(target - this->motor().get_position());
  this->sum += this->getError() * ROBOT_DELAY;
  double derivative = (this->getError() - this->last) / ROBOT_DELAY;
  double power = this->p * getError() + i*this->sum + d*derivative;
  this->last = derivative;
  return power;
}

double PID::getP() {
  return this->p;
}

void PID::setP(double p) {
  this->p = p;
}

double PID::getI() {
  return this->i;
}

void PID::setI(double i) {
  this->i = i;
}

double PID::getD() {
  return this->d;
}

void PID::setD(double d) {
  this->d = d;
}

double PID::getError() {
  return this->error;
}

void PID::setError(double error) {
  this->error = error;
}

double PID::getTarget() {
  return this->target;
}

void PID::setTarget(double target) {
  this->target = target;
}
