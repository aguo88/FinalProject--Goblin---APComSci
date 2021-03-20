#include "main.h"
#include "subsytemheaders/constants.hpp"

//(port, gearset, reversed, encoder units)
pros::Motor leftDriveMotor(LEFT_DRIVE_PORT, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor rightDriveMotor(RIGHT_DRIVE_PORT, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor armMotor(ARM_PORT, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor clawMotor(CLAW_PORT, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_OPEN);

pros::Vision visionCam(CAM_PORT);

//(Master for 1, partner for 2)
pros::Controller controller(pros::E_CONTROLLER_MASTER);

pros::Imu gyro(GYRO_PORT);
