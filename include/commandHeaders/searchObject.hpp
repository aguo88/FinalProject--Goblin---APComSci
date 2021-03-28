#include "main.h"

class SearchObject {
  private:
  double motorPower;

  public:
  void searchGameObject();
  void foundGameObject();
  bool gameObjectFound;
  SearchObject(double power);

};
