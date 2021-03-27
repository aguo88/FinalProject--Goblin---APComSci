#include "main.h"
#include "commandHeaders/searchGoal.hpp"
#include "subsytemHeaders/globals.hpp"
#include "subsytemHeaders/constants.hpp"
#include "subsytemHeaders/mechanisms/drivetrain.hpp"
#include "subsytemHeaders/sensors/vision.hpp"

SearchGoal::SearchGoal(double motorPower) {
  this->motorPower = motorPower;
}

void SearchGoal::searchingGoal() {
  setDriveMotors(motorPower, motorPower * -1);
}

void SearchGoal::foundGoal() {
  double degrees = getAngle();
  //will then call autoDrive method
}
