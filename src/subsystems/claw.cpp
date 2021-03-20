#include "main.h"
#include "subsytemheaders/globals.hpp"


void clawControl() {
  if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_X) == 1) {
    clawMotor.move_velocity(100);
  }
  else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y) == 1){
    clawMotor.move_velocity(-100);
  }
  else {
    clawMotor.move_velocity(0);
  }
}
