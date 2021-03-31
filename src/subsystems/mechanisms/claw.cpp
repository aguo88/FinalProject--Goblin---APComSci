#include "main.h"
#include "subsytemHeaders/globals.hpp"
#include "subsytemHeaders/PID.hpp"
#include "subsytemHeaders/mechanisms/claw.hpp"

//creates object of PID class
PID* clawPID = new PID(10, 0, 0, 0, 0);

//boolean to be set true in autoTask
bool autoClaw;

//boolean to be set true once claw has come close enough to object to be picked up
bool aquiredObject;

//set claw motor power
void control(double power) {
  clawMotor.move(power);
}

//method to use PID setTarget method to set motor power
//uses setTarget method to open claw
void openClaw() {
  clawPID->setTarget(-100);
  control(clawPID->PIDcount());
}

//method to use PID setTarget method to set motor power
//uses setTarget method to close claw
void closeClaw() {
  clawPID->setTarget(0);
  control(clawPID->PIDcount());
}

//updates PID setCounts method
void updatePID() {
  clawPID->setCounts(clawMotor.get_position());
}

//distance sensor method
//if the distance from object is less than 50, aquiredObject is set to true
void checkClaw() {
  if(distanceSensor.get() < 50) {
    aquiredObject = true;
  } else {
    aquiredObject = false;
  }
}

//autoClaw control
void clawControl() {
  updatePID();
  if(autoClaw) {
    // std::cout << distanceSensor.get() << std::endl;
    std::cout << clawMotor.get_position() << std::endl;
    //if distance to object is less than 75, the claw is closed
    if(distanceSensor.get() < 75) {
      closeClaw();
    } else {
      openClaw();
    }
  } else {
    //manual claw control
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) == 1) {
      openClaw();
    }
    else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1) == 1){
      closeClaw();
    }
  }
  checkClaw();
}
