#include "main.h"
#include "subsytemHeaders/globals.hpp"
#include "subsytemHeaders/PID.hpp"

PID clawPID(0, 0, 0, 0, clawMotor);

void autoControl(double power) {
  clawMotor.move(clawPID.PIDdegree());
}

void clawControl() {
  if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) == 1) {
    clawPID.setTarget(120);
  }
  else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1) == 1){
    clawPID.setTarget(0);
  }
}
