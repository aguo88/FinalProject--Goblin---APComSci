#include "main.h"
#include "subsytemHeaders/PID.hpp"

//Inherits from the PID Class
class PIDClaw: public PID {

  public:
  //constructor:
  PIDClaw(double kP, double kI, double kD, double setPoint, int counts);

  //Overriden method
  double PIDcount();
};
