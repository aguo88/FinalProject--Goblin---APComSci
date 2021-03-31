#include "main.h"
#include "subsytemHeaders/PID.hpp"
#include "subsytemHeaders/globals.hpp"
#include "subsytemHeaders/sensors/vision.hpp"
#include "subsytemHeaders/mechanisms/drivetrain.hpp"
#include "subsytemHeaders/mechanisms/claw.hpp"
#include "subsytemHeaders/mechanisms/arm.hpp"
#include "subsytemHeaders/math.hpp"
#include "subsytemHeaders/constants.hpp"

bool runAutoCommands;


/*
searches for game object and dirves forwards once found
power is calculated using the objXCord
object is "found" if the objXcord is within the window of 145 and 175 pixel on the vison sensor
if object is not found, the motors will be set so that the robot spinds in circles looking for object
*/
void searchGameObject() {
  int objXCord = getXCord();
  double power = (160 - objXCord)/160.0;
  if(objXCord > 145 && objXCord < 175) {
    //drive forward
    setDriveMotors(-power + 0.4, power + 0.4);
    std::cout << "found it" <<std::endl;
  } else {
    setDriveMotors(-power, power);
  }

  std::cout << objXCord <<std::endl;
}

/*
sets R2 to set runAutoCommands to true and L2 to set runAutoCommands to false
sets autoClaw to true once runAutoCommands is true
sets arm degree if auquiredObject is true
*/
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
