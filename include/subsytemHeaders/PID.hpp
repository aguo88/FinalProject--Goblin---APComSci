#include "main.h"

class PID
{
  private:


  public:
  double p, i, d, error, target, counts;
  double sum, last;
  pros::Motor motor();
  PID(double kP, double kI, double kD, double setPoint, double counts);
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
  double getCounts();
  void setCounts(double counts);
  double PIDcount();
  double PIDdegree();
};
