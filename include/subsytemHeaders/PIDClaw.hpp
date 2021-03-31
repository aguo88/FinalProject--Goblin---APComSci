#include "main.h"
#include  "subsytemHeaders/PID.hpp"

class PIDClaw : public PID {


  private:

  public:
  pros::Motor secondMotor();
  PIDClaw(double kP, double kI, double kD, double setPoint, int counts);
  double PIDcount();
};
