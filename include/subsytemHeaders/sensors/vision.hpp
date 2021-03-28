#include "main.h"

int CURRENT_ID;

//X & Y pos of object in cam FOV
int currentTargetX;
int currentTargetY;

void setVision();
double getAngle();
void findObjects();
double getArea();
double getAngle();
double getDistance();
int getXCord();
int getYCord();
int checkDistance();
void clearVision();
void checkExposure(int exposure);
