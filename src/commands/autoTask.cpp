#include "main.h"
#include "subsytemHeaders/PID.hpp"
#include "subsytemHeaders/globals.hpp"
#include "subsytemHeaders/sensors/vision.hpp"
#include "subsytemHeaders/mechanisms/drivetrain.hpp"
#include "subsytemHeaders/mechanisms/claw.hpp"
#include "subsytemHeaders/math.hpp"
#include "subsytemHeaders/constants.hpp"

bool runAutoCommands;

void searchGameObject() {
  autoClaw = true;
  int objXCord = getXCord();
  double power = (160 - objXCord)/160.0 * 0.7;
  if(objXCord > 155 && objXCord < 165) {
    //drive forward
    power += 0.4;
    std::cout << "found it" <<std::endl;
  }
  std::cout << power <<std::endl;
  setDriveMotors(-power, power);
}

void manageAuto() {
  if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2) == 1) {
    runAutoCommands = true;
  } else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2) == 1) {
    runAutoCommands = false;
  }
  if(runAutoCommands) {
    if(!aquiredObject) {
      searchGameObject();
    }
  }
}
