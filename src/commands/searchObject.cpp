#include "main.h"
#include "commandHeaders/SearchObject.hpp"
#include "subsytemHeaders/globals.hpp"
#include "subsytemHeaders/constants.hpp"
#include "subsytemHeaders/mechanisms/drivetrain.hpp"
#include "subsytemHeaders/sensors/vision.hpp"
#include "commandHeaders/autoDrive.hpp"
#include "commandHeaders/search.hpp"

void SearchObject::foundGameObject() {
  double degrees = getAngle();
  searchGameObject();
  if (degrees < 170 && degrees > 150) {
    gameObjectFound = true;
  }
  //use  pid from drivetrain to turn towards object
  //when drivetrain angle matches degrees, set foundGameObject to true
  if (gameObjectFound == true) {
    setDriveMotors(0, 0);
    AutoDrive::autodrive();

  }
  //will then call autoDrive method

}
