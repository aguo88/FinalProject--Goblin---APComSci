#include "main.h"
#include "commandHeaders/SearchObject.hpp"
#include "subsytemHeaders/globals.hpp"
#include "subsytemHeaders/constants.hpp"
#include "subsytemHeaders/mechanisms/drivetrain.hpp"
#include "subsytemHeaders/sensors/vision.hpp"

SearchObject::SearchObject(double motorPower){
  this->motorPower = motorPower;
}

void SearchObject::searchGameObject() {
  setDriveMotors(motorPower, motorPower * -1);
}

void SearchObject::foundGameObject() {
  double degrees = getAngle();
  if (degrees < 170 && degrees > 150) {
    gameObjectFound = true;
  }
  //use  pid from drivetrain to turn towards object
  //when drivetrain angle matches degrees, set foundGameObject to true
  if (gameObjectFound == true) {
    setDriveMotors(0, 0);
  }
  //will then call autoDrive method
}
