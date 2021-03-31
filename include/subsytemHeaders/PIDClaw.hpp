#include "main.h"
#include  "subsytemHeaders/PID.hpp"

class PIDClaw : public PID {


  private:

  public:

  PIDClaw(double kP, double kI, double kD, double setPoint, double counts, pros::Motor motor);
  :PID(kP, kI, kD, setPoint, counts);

  pros::Motor motor();

  double PIDcount();

};
