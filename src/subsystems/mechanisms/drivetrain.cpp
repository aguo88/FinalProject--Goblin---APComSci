#include "main.h"
#include "subsytemHeaders/globals.hpp"
#include "subsytemHeaders/constants.hpp"
#include "subsytemHeaders/math.hpp"

//DRIVER CONTROL FUNCTIONS
void setDriveMotors(double leftVoltage, double rightVoltage) {
  //motorSet?
  // std::cout << "power: " << leftVoltage <<std::endl;
  leftDriveMotor.move(leftVoltage * MOTOR_SCALE);
  rightDriveMotor.move(rightVoltage * MOTOR_SCALE);
}

void setDrive() {
  /*
  get joystick values from controller
  set up as kaj drive controls
  */
  double leftJoystickVal = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y)/127.0;
  double rightJoystickVal = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X)/127.0;

  //cube them?
  leftJoystickVal = pow(leftJoystickVal, 3);
  rightJoystickVal = pow(rightJoystickVal, 3);

  //accounts for deadzones
  // leftJoystickVal = std::abs(leftJoystickVal) < 0.1? 0.0 : leftJoystickVal;
  // rightJoystickVal = std::abs(rightJoystickVal) < 0.1? 0.0 : rightJoystickVal;

  //calculates individual motor voltage
  double leftPower = leftJoystickVal + rightJoystickVal;
  double rightPower = leftJoystickVal - rightJoystickVal;

  //keeps signs
  int leftSign = getSign(leftPower);
  int rightSign = getSign(rightPower);

  //Check if exceeding -1 or 1
  leftPower = std::abs(leftPower) > 1.0 ? 1.0 * leftSign : leftPower;
  rightPower = std::abs(rightPower) > 1.0 ? 1.0 * rightSign : rightPower;

  setDriveMotors(leftPower, rightPower);
  std::cout << "L: " << leftPower << " R: " << rightPower << std::endl;
}
