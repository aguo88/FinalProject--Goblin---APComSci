#include "main.h"
#include "subsytemheaders/globals.hpp"
#include "subsytemHeaders/PID.hpp"

static int maxArmDegMovement = 1;

PID armPID(0, 0, 0, 0, armMotor);

void autoControl(double power) {
  armMotor.move(power);
}

//Always under PID loop
void armControl() {
  //Manual & Preset Control
  if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_A) == 1 && armPID.getTarget() - 2 > 0) {
    //Move down (manual)
    if(armPID.getTarget() + maxArmDegMovement < 0)
      armPID.setTarget(0);
    else
      armPID.setTarget(armPID.getTarget() - maxArmDegMovement);
  } else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_A) == 1 && armPID.getTarget() + maxArmDegMovement < 90) {
    //Move up (manual)
    if(armPID.getTarget() + maxArmDegMovement > 90)
      armPID.setTarget(90);
    else
      armPID.setTarget(armPID.getTarget() + maxArmDegMovement);
  } else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_X) == 1) {
    //Move to 90 deg (preset)
    armPID.setTarget(90);
  } else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y) == 1) {
    //Move to 0 deg (preset)
    armPID.setTarget(0);
  }
  autoControl(armPID.PIDcount());
}
