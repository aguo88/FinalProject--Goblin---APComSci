#include "main.h"

class SearchGoal  {
  private:
  double motorPower;

  public:
  void searchingGoal();
  void foundGoal();
  bool gameGoalFound;
  SearchGoal(double power);
};
