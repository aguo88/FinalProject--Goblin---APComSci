#include "main.h"
#include "subsytemHeaders/PID.hpp"
#include "subsytemHeaders/constants.hpp"

PID::PID(double p, double i, double d, double target, double counts)
{
    //p, i, d are tuning values
    this->p = p;
    this->i = i;
    this->d = d;
    this->target = target;
    this->counts = counts;
    sum = 0.0, last = 0.0;
}

double PID::PIDcount() {
  //calculates error:
  this->setError(this->target - this->counts);
  //calculates sum for integral
  this->sum += this->getError() * ROBOT_DELAY;
  //calculates derivative using last(derivative)
  double derivative = (this->getError() - this->last) / ROBOT_DELAY;
  //calculates power
  double power = this->p * getError() + i*this->sum + d*derivative;
  this->last = derivative;
  return power;
}

//returns P value
double PID::getP() {
  return this->p;
}

//sets P value
void PID::setP(double p) {
  this->p = p;
}

//returns I value
double PID::getI() {
  return this->i;
}

//sets I value
void PID::setI(double i) {
  this->i = i;
}

//returns D value
double PID::getD() {
  return this->d;
}

//set D value
void PID::setD(double d) {
  this->d = d;
}

//returns error
double PID::getError() {
  return this->error;
}

//sets error
void PID::setError(double error) {
  this->error = error;
}

//returns target
double PID::getTarget() {
  return this->target;
}

//sets target
void PID::setTarget(double target) {
  this->target = target;
}

//returns counts
double PID::getCounts() {
  return this->counts;
}

//sets counts
void PID::setCounts(double counts) {
  this->counts = counts;
}
