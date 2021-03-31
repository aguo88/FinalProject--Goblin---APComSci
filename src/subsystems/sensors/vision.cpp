#include "main.h"
#include "subsytemHeaders/globals.hpp"

//minimum area of acceptable object
const int MIN_SIZE = 5000;
//maximum area of acceptable object
const int MAX_SIZE = 6000;
pros::vision_object_s_t currentObj;

//method to set currentObj to the current vison sensor sig1
void findObject() {
  currentObj = visionCam.get_by_sig(0, 1);
}

//returns area of current obejct
double getArea() {
  return currentObj.width * currentObj.height;
}

//returns angle of current object
double getAngle() {
  return currentObj.y_middle_coord;
}

//returns x coordinate of current object
int getXCord() {
  return currentObj.x_middle_coord;
}

//returns y coordinate of current obejct
int getYCord() {
  return currentObj.y_middle_coord;
}

//returns -1 if obejct is to close
//returns 0 if object distance is just right
//returns 1 if obejct is too far
int checkDistance() {
  int area = getArea();
  if(area > MAX_SIZE) {
    //too close
    return -1;
  } else if(area <= MAX_SIZE && area >= MIN_SIZE) {
    //just right
    return 0;
  } else {
    //too far
    return 1;
  }
}

//method to be called and looped in main 
void setVision() {
  // checkExposure(50);
  findObject();
}
