#include "main.h"
#include "subsytemHeaders/globals.hpp"
#include "subsytemHeaders/sensors/vision.hpp"
#include "subsytemHeaders/mechanisms/drivetrain.hpp"
#include "subsytemHeaders/mechanisms/claw.hpp"
#include "subsytemHeaders/mechanisms/arm.hpp"
#include "subsytemHeaders/math.hpp"
#include "subsytemHeaders/constants.hpp"
#include "subsytemHeaders/PIDClaw.hpp"

bool runAutoCommands;
PIDClaw* autoPID = new PIDClaw(1, 0, 0, 160, 0);

void searchGameObject() {
  double power = autoPID->PIDcount();
  setDriveMotors(-power, power);
  // int objXCord = getXCord();
  // double power = (160 - objXCord)/160.0;
  // if(objXCord > 145 && objXCord < 175) {
  //   //drive forward
  //   // power += 0.4;
  //   setDriveMotors(-power + 0.4, power + 0.4);
  //   std::cout << "found it" <<std::endl;
  // } else {
  //   setDriveMotors(-power, power);
  // }
  //
  // std::cout << objXCord <<std::endl;
}

void manageAuto() {
  if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2) == 1) {
    runAutoCommands = true;
  } else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2) == 1) {
    runAutoCommands = false;
  }
  if(runAutoCommands) {
    autoClaw = true;
    if(!aquiredObject) {
      setArmDeg(0);
      searchGameObject();
    } else {
      setArmDeg(250);
    }
  } else {
    autoClaw = false;
  }
}
