#include "main.h"
#include "subsytemHeaders/constants.hpp"

//(port, gearset, reversed, encoder units)
pros::Motor* leftDriveMotor = new pros::Motor(LEFT_DRIVE_PORT, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor* rightDriveMotor = new pros::Motor(RIGHT_DRIVE_PORT, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor* armMotor = new pros::Motor(ARM_PORT, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor* clawMotor = new pros::Motor(CLAW_PORT, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_DEGREES);

pros::Vision* visionCam = new pros::Vision(CAM_PORT);

//(Master for 1, partner for 2)
pros::Controller* controller = new pros::Controller(pros::E_CONTROLLER_MASTER);

pros::Imu* gyro = new pros::Imu(GYRO_PORT);
