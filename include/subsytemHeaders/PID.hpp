#include "main.h"

class PID
{
  private:
  double p, i, d, error, target;

  public:
  double sum, last;
  pros::Motor motor();
  PID(double kP, double kI, double kD, double setPoint, pros::Motor motor);
  double getP();
  void setP(double p);
  double getI();
  void setI(double i);
  double getD();
  void setD(double d);
  double getError();
  void setError(double error);
  double getTarget();
  void setTarget(double target);
  double PIDcount();
  double PIDdegree();
};
