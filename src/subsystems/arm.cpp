#include "main.h"
#include "subsytemheaders/globals.hpp"

void armcontrol() {
  int buttonAVal = controller.get_analog(pros::E_CONTROLLER_BUTTON_A);
  int buttonBVal = controller.get_analog(pros::E_CONTROLLER_BUTTON_B);


  while(true) {
    if (buttonAVal == 1) {
      armMotor.moveVoltage(12000);
    } else if (buttonBVal == 1) {
      armMotor.moveVoltage(-12000);
    } else {
      armMotor.moveVoltage(0);
    }

    pros::delay(10);
  }
}
