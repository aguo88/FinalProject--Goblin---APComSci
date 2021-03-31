#include "main.h"
#include "subsytemHeaders/PID.hpp"

class PIDClaw: public PID {

  public:
  PIDClaw(double kP, double kI, double kD, double setPoint, int counts);
  double PIDcount();
};
