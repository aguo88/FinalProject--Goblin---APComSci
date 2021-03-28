#include "main.h"
#include "commandHeaders/searchGoal.hpp"
#include "subsytemHeaders/globals.hpp"
#include "subsytemHeaders/constants.hpp"
#include "subsytemHeaders/mechanisms/drivetrain.hpp"
#include "subsytemHeaders/sensors/vision.hpp"


void SearchGoal::foundGoal() {
  double degrees = getAngle();
  if (degrees < 170 && degrees > 150) {
    gameGoalFound = true;
  }
  //use  pid from drivetrain to turn towards object
  //when drivetrain angle matches degrees, set foundGameObject to true
  if (gameGoalFound == true) {
    setDriveMotors(0, 0);
  }
  //will then call autoDrive method
}
