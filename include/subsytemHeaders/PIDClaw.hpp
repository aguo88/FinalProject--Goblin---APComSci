#include "main.h"
#include  "subsytemHeaders/PID.hpp"

class PIDClaw : public PID {


  private:

  public:
<<<<<<< HEAD

  PIDClaw(double kP, double kI, double kD, double setPoint, double counts, pros::Motor motor);
  :PID(kP, kI, kD, setPoint, counts);

  pros::Motor motor();

=======
  pros::Motor secondMotor();
  PIDClaw(double kP, double kI, double kD, double setPoint, int counts);
>>>>>>> 3bbb3aedf9c6aa94ab3057ddacbe39fb86253bb2
  double PIDcount();
};
