#include "main.h"
#include "commandHeaders/SearchObject.hpp"
#include "subsytemHeaders/globals.hpp"
#include "subsytemHeaders/constants.hpp"
#include "subsytemHeaders/mechanisms/drivetrain.hpp"
#include "subsytemHeaders/sensors/vision.hpp"
#include "commandHeaders/autoDrive.hpp"
#include "commandHeaders/search.hpp"

void foundGameObject() {
  double degrees = getAngle();
  searchGameObject();
  if (degrees < 170 && degrees > 150) {
    objectFound = true;
  }
  //use  pid from drivetrain to turn towards object
  //when drivetrain angle matches degrees, set foundGameObject to true
  if (objectFound == true) {
    setDriveMotors(0, 0);
    autoDrive();

  }
  //will then call autoDrive method

}
