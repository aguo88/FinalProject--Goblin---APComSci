#include "main.h"

class PID
{
  private:
  double p, i, d, error, target, counts;

  public:
  double sum, last;

  //constructor:
  PID(double kP, double kI, double kD, double setPoint, double counts);

  //getters and stters for private instance variables:
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

  //Returns the power to set to the motor(s) after calculations
  double PIDcount();
};
