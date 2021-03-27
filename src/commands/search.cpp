#include "main.h"
#include "commandHeaders/search.hpp"
#include "subsytemHeaders/PID.hpp"
#include "subsytemHeaders/globals.hpp"
#include "subsytemHeaders/sensors/vision.hpp"
#include "subsytemHeaders/mechanisms/drivetrain.hpp"

void Search::searchGameObject() {
  int error = 160 -  getXCord();
  setDriveMotors(error * 1, error * -1);
}
