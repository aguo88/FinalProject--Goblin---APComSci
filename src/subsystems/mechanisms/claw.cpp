#include "main.h"
#include "subsytemHeaders/globals.hpp"
#include "subsytemHeaders/PID.hpp"

PID* clawPID = new PID(2, 0, 0, 0, clawMotor);

void control(double power) {
  clawMotor.move(power);
}

void clawControl() {
  if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) == 1) {
    clawPID->setTarget(-100);
  }
  else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1) == 1){
    clawPID->setTarget(0);
  }
  control(clawPID->PIDdegree());
}
