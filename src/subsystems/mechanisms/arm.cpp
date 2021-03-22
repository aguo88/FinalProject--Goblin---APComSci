#include "main.h"
#include "subsytemHeaders/globals.hpp"
#include "subsytemHeaders/PID.hpp"

static int maxArmDegMovement = 1;

PID* armPID = new PID(0, 0, 0, 0, armMotor);

void autoControl(double power) {
  armMotor.move(power);
}

void setArmDeg(int degrees) {
  armPID->setTarget(degrees);
}

//Always under PID loop
void armControl() {
  //Manual & Preset Control
  if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_A) == 1 && armPID->getTarget() - 2 > 0) {
    //Move down (manual)
    if(armPID->getTarget() + maxArmDegMovement < 0)
      setArmDeg(0);
    else
      setArmDeg(armPID->getTarget() - maxArmDegMovement);
  } else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_B) == 1 && armPID->getTarget() + maxArmDegMovement < 90) {
    //Move up (manual)
    if(armPID->getTarget() + maxArmDegMovement > 90)
      setArmDeg(90);
    else
      setArmDeg(armPID->getTarget() + maxArmDegMovement);
  } else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_X) == 1) {
    //Move to 90 deg (preset)
    setArmDeg(90);
  } else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y) == 1) {
    //Move to 0 deg (preset)
    setArmDeg(0);
  }
  autoControl(armPID->PIDcount());
}
