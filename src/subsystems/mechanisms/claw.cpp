#include "main.h"
#include "subsytemHeaders/globals.hpp"
#include "subsytemHeaders/PID.hpp"

PID* clawPID = new PID(2, 0, 0, 0, clawMotor);
bool autoClaw = true;

void control(double power) {
  clawMotor.move(power);
}

void openClaw() {
  clawPID->setTarget(-100);
  control(clawPID->PIDdegree());
}

void closeClaw() {
  clawPID->setTarget(0);
  control(clawPID->PIDdegree());
}

void clawControl() {
  if(!autoClaw) {
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) == 1) {
      openClaw();
    }
    else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1) == 1){
      closeClaw();
    }
  } else {
    if(distanceSensor.get() < 100) {
      closeClaw();
    } else {
      openClaw();
    }
  }
}
