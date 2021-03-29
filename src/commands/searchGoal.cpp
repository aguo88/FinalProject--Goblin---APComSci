#include "main.h"
#include "commandHeaders/searchGoal.hpp"
#include "subsytemHeaders/globals.hpp"
#include "subsytemHeaders/constants.hpp"
#include "subsytemHeaders/mechanisms/drivetrain.hpp"
#include "subsytemHeaders/sensors/vision.hpp"
#include "commandHeaders/autoTask.hpp"


void searchingGoal() {
  int objXCord = getXCord();
  double power = (160 - objXCord)/160.0;
  if(objXCord > 145 && objXCord < 175) {
    //drive forward
    // power += 0.4;
    setDriveMotors(-power + 0.4, power + 0.4);
    std::cout << "found it" <<std::endl;
  } else {
    setDriveMotors(-power, power);
  }

  std::cout << objXCord <<std::endl;
}

void foundGoal() {

}
