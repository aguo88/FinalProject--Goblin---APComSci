#include "main.h"
#include "commandHeaders/autoDrive.hpp"
#include "subsytemHeaders/mechanisms/drivetrain.hpp"
#include "subsytemHeaders/sensors/vision.hpp"
#include "commandHeaders/SearchObject.hpp"

void AutoDrive::autoDrive() {
  int distance = checkDistance();
  double degrees = getAngle();
  if (distance == 1) { // test value
    setDriveMotors(1,1); // test values
    if (degrees < 170 && degrees > 150) {
      foundGameObject();
    }
  }
  else if (distance == -1 ){
    setDriveMotors(-1,-1);
  }
  else {
    setDriveMotors(0, 0);
    //calls auto claw and arm
  }
}
