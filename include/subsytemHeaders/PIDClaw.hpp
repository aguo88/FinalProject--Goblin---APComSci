#include "main.h"
#include  "subsytemHeaders/PID.hpp"

class PIDClaw : public PID {


  private:

  public:
  pros::Motor motor();
  PIDClaw(double kP, double kI, double kD, double setPoint, double counts, pros::Motor motor);
  double PIDcount();

};
