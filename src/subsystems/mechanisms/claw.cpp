#include "main.h"
#include "subsytemHeaders/globals.hpp"
#include "subsytemHeaders/PID.hpp"
#include "subsytemHeaders/mechanisms/claw.hpp"

PID* clawPID = new PID(10, 0, 0, 0, 0);
bool autoClaw;
bool aquiredObject;

void control(double power) {
  clawMotor.move(power);
}

void openClaw() {
  clawPID->setTarget(-100);
  control(clawPID->PIDcount());
}

void closeClaw() {
  clawPID->setTarget(0);
  control(clawPID->PIDcount());
}

void updatePID() {
  clawPID->setCounts(clawMotor.get_position());
}

void checkClaw() {
  if(distanceSensor.get() < 50) {
    aquiredObject = true;
  } else {
    aquiredObject = false;
  }
}

void clawControl() {
  updatePID();
  // std::cout << autoClaw << std::endl;
  if(autoClaw) {
    // std::cout << distanceSensor.get() << std::endl;
    std::cout << clawMotor.get_position() << std::endl;
    if(distanceSensor.get() < 75) {
      closeClaw();
    } else {
      openClaw();
    }
  } else {
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) == 1) {
      openClaw();
    }
    else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1) == 1){
      closeClaw();
    }
  }
  checkClaw();
}
