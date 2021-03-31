#include "main.h"
#include "subsytemHeaders/globals.hpp"
#include "subsytemHeaders/PID.hpp"

static int maxArmDegMovement = 1;

//creates object of PID class
PID* armPID = new PID(10, 0, 0, 0, 0);

//method to control arm power
void autoControl(double power) {
  armMotor.move(power);
}

//method to set arm degrees using PID stTarget method
void setArmDeg(int degrees) {
  armPID->setTarget(degrees);
}

//updates PID setCounts method
void updateArmPID() {
  armPID->setCounts(armMotor.get_position());
}

//Always under PID loop
//manual arm control using PID
void armControl() {
  updateArmPID();
  std::cout << "Motor Position: " << armMotor.get_position() << std::endl;
  //Manual & Preset Control
  if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_A) == 1 && armPID->getTarget() - 2 > 0) {
    //Move down (manual)
    if(armPID->getTarget() + maxArmDegMovement < 0)
      setArmDeg(0);
    else
      setArmDeg(armPID->getTarget() - maxArmDegMovement);
  } else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_B) == 1 && armPID->getTarget() + maxArmDegMovement < 200) {
    //Move up (manual)
    if(armPID->getTarget() + maxArmDegMovement > 200)
      setArmDeg(200);
    else
      setArmDeg(armPID->getTarget() + maxArmDegMovement);
  }
   else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_X) == 1) {
    //Move to 90 deg (preset)
    setArmDeg(200);
  } else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y) == 1) {
    //Move to 0 deg (preset)
    setArmDeg(0);
  }
  autoControl(armPID->PIDcount());
}
