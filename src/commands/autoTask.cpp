#include "main.h"
#include "subsytemHeaders/globals.hpp"
#include "subsytemHeaders/sensors/vision.hpp"
#include "subsytemHeaders/mechanisms/drivetrain.hpp"
#include "subsytemHeaders/mechanisms/claw.hpp"
#include "subsytemHeaders/mechanisms/arm.hpp"
#include "subsytemHeaders/math.hpp"
#include "subsytemHeaders/constants.hpp"
#include "subsytemHeaders/PIDClaw.hpp"

//global to check if automode is to be continued or not
bool runAutoCommands;

//global PIDClaw that controls the drivetrain using the vision sensor
PIDClaw* autoPID = new PIDClaw(1, 0, 0, 160, 0);

void searchGameObject() {
  //sets power to motors to align and drive up to gameObject (ball)
  double power = autoPID->PIDcount();
  setDriveMotors(-power, power);
}

void manageAuto() {
  if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2) == 1) {
    //turns autoMode ON
    runAutoCommands = true;
  } else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2) == 1) {
    //turns autoMode OFF
    runAutoCommands = false;
  }

  //If autoMode is ON
  if(runAutoCommands) {
    //Claw will automatically grab gameObject when detected
    autoClaw = true;
    if(!aquiredObject) {
      //if the robot has not aquired an object, then the arm is set to the ground level and begins searching
      setArmDeg(0);
      searchGameObject();
    } else {
      //if the robot has aquired an object, the arm is raised off the ground
      setArmDeg(250);
    }
  } else {
    //turns off claw auto
    autoClaw = false;
  }
}
